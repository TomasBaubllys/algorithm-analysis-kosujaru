#include "kosajaru.h"
#include <vector>

void dfs(vertex_t curr_vertex, std::vector<std::vector<vertex_t>>& adj_list, std::vector<bool>& visited, std::vector<vertex_t>& visit_stack) {
    visited.at(curr_vertex) = true;
    for(const vertex_t& adj_v : adj_list[curr_vertex]) {
        if(!visited[adj_v])
            dfs(adj_v, adj_list, visited, visit_stack);
    }
    visit_stack.push_back(curr_vertex);
}

std::vector<std::vector<vertex_t>>kosajaru(vertex_t vertices_count, std::vector<std::vector<vertex_t>>& adj_list) {
    std::vector<bool> visited(vertices_count, false);
    std::vector<vertex_t> visit_stack;
    for(vertex_t i = 0; i < vertices_count; ++i) {
        if(!visited[i]) {
            dfs(i, adj_list, visited, visit_stack);
        }
    }

    // reverse the adj_list
    std::vector<std::vector<vertex_t>> rev_adj_list;
    rev_adj_list.reserve(vertices_count);

    for(vertex_t i = 0; i < vertices_count; ++i) {
    	for(const vertex_t& v : adj_list[i]) {
   			rev_adj_list[v].push_back(i);
     	}
    }

    visited.assign(vertices_count, false);

    std::vector<std::vector<vertex_t>> sccs;

    while(!visit_stack.empty()) {
   		vertex_t v = visit_stack.back();
    	visit_stack.pop_back();
     	if(!visited[v]) {
      		std::vector<vertex_t> scc;
        	dfs(v, rev_adj_list, visited, scc);
         	sccs.push_back(std::move(scc));
      	}
    }

    return sccs;
}
