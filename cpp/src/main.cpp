#include <iostream>
#include "../include/kosajaru.h"
#include "../include/graph_generator.h"

constexpr vertex_t DEFAULT_V_COUNT = 10;

int main() {
    Graph g = Graph_Generator::generate_rand_graph(DEFAULT_V_COUNT, DEFAULT_V_COUNT, {5, 0});
    // g.print_graph();
    std::vector<std::vector<vertex_t>> sccs = kosajaru(g.get_vertices_count(), g.get_adj_list_ref());
    for(auto scc : sccs) {
        for(auto v : scc) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
