#include "../include/graph_generator.h"
#include <cstdlib>
#include <random>

Graph Graph_Generator::generate_rand_graph(vertex_t v_count, edge_t e_count, Graph_Attr g_attr) {
	std::random_device rand_dev;
	std::mt19937 generator(rand_dev());
	std::uniform_int_distribution<edge_t> e_count_distr(g_attr.min_edges_per_v, g_attr.max_edges_per_v);
	std::uniform_int_distribution<vertex_t> v_distr(0, v_count - 1);
	
	std::vector<std::vector<vertex_t>> adj_list;
	adj_list.resize(v_count);

	for(vertex_t i = 0; i < v_count; ++i) {
		e_count = e_count_distr(generator);
		for(vertex_t j = 0; j < e_count; ++j) {
			adj_list[i].push_back(v_distr(generator));
		}
	}
	return Graph(v_count, std::move(adj_list));	
}
