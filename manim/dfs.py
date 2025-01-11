from manim import *
import oi

n = 5
E = [(0,1), (0,2), (0,4), (1,2), (1,3), (2,3)]
pos = [(-1, 0.5), (0, 0.5), (0, -0.5), (1, -0.5), (-1, -0.5)]

class DFS(Scene):
    def dfs(self, G, v, vis):
        vis.add(v)
        self.play(G.mV[v].animate.set_fill(oi.RED))
        for u in G.N[v]:
            if u not in vis:
                e = G.EdgeFactory(v, u, color=oi.BLUE)
                e.set_z_index(1)
                self.play(Create(e))
                self.dfs(G, u, vis)
                self.play(Uncreate(e))
            else:
                e = G.EdgeFactory(v, u, color=oi.RED)
                e.set_z_index(1)
                self.play(Create(e), run_time=0.5)
                self.play(Uncreate(e), run_time=0.5)
    def construct(self):
        G = oi.Graph(n, E, pos)
        self.add(*G.mV, *G.mE)
        self.dfs(G, 0, set())
        self.wait()
        self.play(v.animate.set_fill(oi.FOREGROUND) for v in G.mV)
        self.wait()

if __name__ == '__main__':
    config.frame_width = 3
    oi.render(DFS, 'dfs1')
