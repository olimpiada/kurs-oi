from manim import *
import oi

class DFS1(Scene):
    def dfs(self, G, v, vis):
        vis.add(v)
        self.play(G.mV[v].animate.set_fill(oi.RED))
        for u in G.N[v]:
            if u not in vis:
                e = Line(G.mV[v].get_center(), G.mV[u].get_center(), color=oi.BLUE)
                e.set_z_index(-1)
                self.play(Create(e))
                self.dfs(G, u, vis)
                self.play(Uncreate(e))
            else:
                e = Line(G.mV[v].get_center(), G.mV[u].get_center(), color=oi.RED)
                e.set_z_index(-1)
                self.play(Create(e), run_time=0.5)
                self.play(Uncreate(e), run_time=0.5)
    def construct(self):
        G = oi.Graph(
            [0, 1, 2, 3, 4],
            [(0,1), (0,2), (0,4), (1,2), (1,3), (2,3)],
            [(-1, 0.5, 0), (0, 0.5, 0), (0, -0.5, 0), (1, -0.5, 0), (-1, -0.5, 0)]
        )
        for e in G.mE:
            e.set_z_index(-3)
        self.add(*G.mV, *G.mE)
        self.dfs(G, 0, set())
        self.wait()
        self.play(*[v.animate.set_fill(oi.FOREGROUND) for v in G.mV])
        self.wait()

if __name__ == '__main__':
    print(f"{config.assets_dir=}")
    print(f"{config.images_dir=}")
    print(f"{config.log_dir=}")
    print(f"{config.media_dir=}")
    print(f"{config.partial_movie_dir=}")
    print(f"{config.sections_dir=}")
    print(f"{config.video_dir=}")
    config.frame_width = 3
    config.format = 'gif'
    oi.render(DFS1, 'dfs1')
