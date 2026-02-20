#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <cstdint>
#include <vector>
#include <iostream>

using vertex_t = uint32_t;
using edge_t = uint32_t;

class Graph {
	private:
		vertex_t vertices_count;
		std::vector<std::vector<vertex_t>> adj_list;

	public:
		Graph();

		Graph(vertex_t vertices_count, std::vector<std::vector<vertex_t>>& adj_list);

		Graph(vertex_t vertices_count, std::vector<std::vector<vertex_t>>&& adj_list);

		~Graph();

		std::vector<std::vector<vertex_t>>& get_adj_list_ref();

		vertex_t get_vertices_count();

		void print_graph();

		Graph load_from_file();

		void save_to_file();
};

#endif // GRAPH_H_INCLUDED
