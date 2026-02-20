#ifndef GRAPH_GENERATOR_H_INCLUDED
#define GRAPH_GENERATOR_H_INCLUDED

#include "graph.h"
#include <cstdint>

struct Graph_Attr {
	edge_t max_edges_per_v = 1e6;
	edge_t min_edges_per_v = 0;
};

class Graph_Generator {
	public:
		static Graph generate_rand_graph(vertex_t v_count, edge_t e_count, Graph_Attr g_attr);
	private:
		static Graph generate_tree_graph(vertex_t v_count, edge_t e_count, Graph_Attr g_attr);
};

#endif // GRAPH_GENERATOR_H_INCLUDED
