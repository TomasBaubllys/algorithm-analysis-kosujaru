#include "../include/graph.h"

Graph::Graph() {}

Graph::Graph(vertex_t vertices_count, std::vector<std::vector<vertex_t>> adj_list) : vertices_count(vertices_count), adj_list(adj_list) {

}

Graph::~Graph() {}

std::vector<std::vector<vertex_t>>& Graph::get_adj_list_ref() {return this->adj_list;}

vertex_t Graph::get_vertices_count() {return this->vertices_count;}

Graph Graph::load_from_file() {
	return Graph();
}

void Graph::save_to_file() {

}
