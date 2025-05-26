from manim import *
import oi

n = 5
E = [(0,1), (0,2), (0,3), (1,2), (2,3), (2,4)]
pos1 = [(-1, 0.5), (0, 0.5), (0, -0.5), (-1, -0.5), (1, -0.5)]
pos2 = [(-2, -0.4), (-1, 0.4), (0, 0.4), (1, -0.4), (2, -0.4)]
pos3 = [(-2, -0.4), (-1, 0.4), (0, 0.4), (2, -0.4), (1, -0.25)]

class DAG1(Scene):
    def construct(self):
        G1 = oi.Graph(n, E, pos1, directed=True)
        self.add(*G1.mV, *G1.mE)

class DAG2(Scene):
    def construct(self):
        G1 = oi.Graph(n, E, pos1, directed=True)
        G2 = oi.Graph(n, E, pos2, directed=True)
        self.play(map(FadeIn, G1.mV + G1.mE))
        self.play(
            [Transform(v1, v2) for v1, v2 in zip(G1.mV, G2.mV)] +
            [Transform(e1, e2) for e1, e2 in zip(G1.mE, G2.mE)],
            run_time=3
        )
        self.pause(6)
        self.play(map(FadeOut, G1.mV + G1.mE))

class DAG3(Scene):
    def construct(self):
        G2 = oi.Graph(n, E, pos2, directed=True)
        G3 = oi.Graph(n, E, pos3, directed=True)
        G4 = oi.Graph(n, E, pos2, directed=True)
        self.play(
            [Transform(v1, v2) for v1, v2 in zip(G2.mV, G3.mV)] +
            [Transform(e1, e2) for e1, e2 in zip(G2.mE, G3.mE)],
            run_time=2
        )
        self.pause(3)
        self.play(
            [Transform(v1, v2) for v1, v2 in zip(G2.mV, G4.mV)] +
            [Transform(e1, e2) for e1, e2 in zip(G2.mE, G4.mE)],
            run_time=2
        )
        self.pause(3)

if __name__ == '__main__':
    config.frame_width = 3
    oi.render(DAG1, 'dag1')
    config.frame_width = 5
    oi.render(DAG2, 'dag2')
    oi.render(DAG3, 'dag3')
