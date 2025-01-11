from manim import *
import shutil
from typing import Sequence

config.format = 'gif'
config.transparent = True
config.images_dir = './media'
config.video_dir = './media'
config.log_dir = './logs'
config.partial_movie_dir = './cache'
config.frame_rate = 30

RED = '#ed1b23'
GREEN = '#00a650'
BLUE = '#0894dc'
FOREGROUND_LIGHT = '#1f1f1f'
FOREGROUND_DARK = '#e6e6e6'
FOREGROUND = FOREGROUND_LIGHT
BACKGROUND_LIGHT = '#fafafa'
BACKGROUND_DARK = '#1d2028'
BACKGROUND = BACKGROUND_LIGHT

class Graph:
    def __init__(
            self,
            n: int,
            E: Sequence[tuple[int, int]],
            positions: Sequence[tuple[float, float]],
            directed: bool = False,
        ):
        assert len(positions) == n
        self.V = list(range(n))
        self.E = E
        self.N = [[] for _ in self.V]
        for v, u in E:
            self.N[v].append(u)
            if not directed:
                self.N[u].append(v)

        def Node(v):
            return Dot(point=(*positions[v], 0), color=FOREGROUND)
        self.mV = [Node(v) for v in self.V]

        def Edge(start, end, **kwargs):
            res = Line(
                self.mV[start].get_center(), self.mV[end].get_center(),
                **({'color': FOREGROUND, 'buff': DEFAULT_DOT_RADIUS * 1.5} | kwargs)
            )
            if directed:
                res.add_tip(tip_length=0.15, tip_width=0.15)
            return res
        self.EdgeFactory = Edge

        self.mE = [Edge(v, u) for v, u in E]

def render(scene, name: str) -> None:
    global BACKGROUND, FOREGROUND

    def render(scheme: str):
        with tempconfig({
            'output_file': f'{name}-{scheme}',
            'background_color': BACKGROUND,
            'scene_names': [name],
        }):
            scene().render()
            # render to local directory and copy to `docs/assets` to avoid
            # `mkdocs serve` constantly reloading the page while the video
            # is being rendered
            shutil.copy2(config.output_file, '../docs/assets')

    FOREGROUND, BACKGROUND = FOREGROUND_LIGHT, BACKGROUND_LIGHT
    render('light')
    FOREGROUND, BACKGROUND = FOREGROUND_DARK, BACKGROUND_DARK
    render('dark')
