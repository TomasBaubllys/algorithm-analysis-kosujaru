#include "../include/graph_generator.h"
#include <cstdlib>
#include <random>

Graph Graph_Generator::generate_rand_graph(vertex_t v_count, edge_t e_count, Graph_Attr g_attr) {
	std::uniform_int_distribution<edge_t> distr(g_attr.min_edges_per_v, g_attr.max_edges_per_v);
	for(vertex_t i = 0; i < v_count; ++i) {
		e_count =

	}
}
