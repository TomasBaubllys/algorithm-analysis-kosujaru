import numpy as np


def generate_rand_graph(vertices_count=100000, total_edges=50000):
    edges = np.random.randint(0, vertices_count, size=(total_edges, 2), dtype=np.int32)
    self_loops = edges[:, 0] == edges[:, 1]
    edges = edges[~self_loops]
    return edges


def save_graph(filename, vertices_count, edges):
    np.savez(filename, v_count=vertices_count, edges=edges)


if __name__ == "__main__":
    vertices_count = 5_000_000
    edges_count = 15_000_000_0
    edges = generate_rand_graph(vertices_count, edges_count)
    save_graph("graph.npz", vertices_count, edges)
