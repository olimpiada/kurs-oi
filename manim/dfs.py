from manim import *
import oi

class DFS(Scene):
    def dfs(self, G, v, vis):
        vis.add(v)
        self.play(G.mV[v].animate.set_fill(oi.RED))
        for u in G.N[v]:
            if u not in vis:
                e = G.EdgeFactory(v, u, color=oi.RED)
                e.set_z_index(1)
                self.play(Create(e))
                self.dfs(G, u, vis)
                self.play(Uncreate(e))
            else:
                e = G.EdgeFactory(v, u, color=oi.BLUE)
                e.set_z_index(1)
                self.play(Create(e), run_time=0.5)
                self.play(Uncreate(e), run_time=0.5)
    def construct(self):
        n = 5
        E = [(0,1), (0,2), (0,4), (1,2), (1,3), (2,3)]
        pos = [(-1, 0.5), (0, 0.5), (0, -0.5), (1, -0.5), (-1, -0.5)]

        G = oi.Graph(n, E, pos)
        self.add(*G.mV, *G.mE)
        self.dfs(G, 0, set())
        self.wait()
        self.play(v.animate.set_fill(oi.FOREGROUND) for v in G.mV)
        self.wait()

class DirectedCycles(Scene):
    def enter(self, G, v):
        self.play(G.mV[v].animate.set_fill(oi.RED))
    def leave(self, G, v):
        self.play(G.mV[v].animate.set_fill(oi.BLUE))
    def go_to(self, G, v, u):
        e = G.EdgeFactory(v, u, color=oi.RED)
        self.play(Create(e))
        return e
    def go_back(self, G, e):
        self.play(Uncreate(e))
    def construct(self):
        n = 5
        E = [(0,1), (1,3), (2,1), (3,2), (3,4)]
        pos = [(-1, -0.5), (-0.5, 0.5), (0, -0.5), (0.5, 0.5), (1, -0.5)]
        G = oi.Graph(n, E, pos, directed=True)
        self.add(*G.mV, *G.mE)
        self.enter(G, 0)
        e1 = self.go_to(G, 0, 1)
        self.enter(G, 1)
        e2 = self.go_to(G, 1, 3)
        self.enter(G, 3)
        e3 = self.go_to(G, 3, 4)
        self.enter(G, 4)
        self.leave(G, 4)
        self.go_back(G, e3)
        e4 = self.go_to(G, 3, 2)
        self.enter(G, 2)
        e5 = self.go_to(G, 2, 1)
        self.play(G.mV[1].animate.set_fill(oi.GREEN))
        self.wait()
        e6 = G.EdgeFactory(1, 3, color=oi.GREEN)
        e7 = G.EdgeFactory(3, 2, color=oi.GREEN)
        e8 = G.EdgeFactory(2, 1, color=oi.GREEN)
        self.play(Create(e6), Create(e7), Create(e8))
        self.wait()
        self.play(
            [v.animate.set_fill(oi.FOREGROUND) for v in G.mV] +
            [Uncreate(e1), Uncreate(e2), Uncreate(e4), Uncreate(e5), Uncreate(e6), Uncreate(e7), Uncreate(e8)]
        )
        self.wait()

if __name__ == '__main__':
    config.frame_width = 3
    oi.render(DFS, 'dfs1')
    oi.render(DirectedCycles, 'dfs2')
