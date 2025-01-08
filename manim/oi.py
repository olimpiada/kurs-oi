from manim import *

config.images_dir = '../docs/assets'
config.video_dir = '../docs/assets'
config.log_dir = './logs'
config.partial_movie_dir = './cache'

RED = '#ed1b23'
GREEN = '#00a650'
BLUE = '#0894dc'
BACKGROUND = '#e6e6e6'
FOREGROUND = '#221e1f'

class Graph:
    """An undirected unweighted graph without labels."""
    def __init__(self, V, E, positions):
        assert len(V) == len(positions)
        self.V = V
        self.E = E
        self.N = {v: [] for v in V}
        for v, u in E:
            self.N[v].append(u)
            self.N[u].append(v)
        self.mV = [Dot(point=positions[v], color=FOREGROUND) for v in V]
        self.mE = [
            Line(self.mV[v].get_center(), self.mV[u].get_center(), color=FOREGROUND)
            for v, u in E
        ]

def render(scene_class, name: str) -> None:
    global BACKGROUND, FOREGROUND
    with tempconfig({'output_file': name + '-light', 'background_color': BACKGROUND, 'scene_names': [name]}):
        scene_class().render()
    BACKGROUND, FOREGROUND = FOREGROUND, BACKGROUND
    with tempconfig({'output_file': name + '-dark', 'background_color': BACKGROUND, 'scene_names': [name]}):
        scene_class().render()
    BACKGROUND, FOREGROUND = FOREGROUND, BACKGROUND
