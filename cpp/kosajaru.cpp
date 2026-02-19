#include "kosajaru.h"

void dfs(vertex_t curr_vertex, std::vector<std::pair<vertex_t, vertex_t>>& adj_list, std::vector<bool>& visited, std::stack<vertex_t>& visit_stack) {
    visited.at(curr_vertex) = true;
    for(const vertex_t& adj_v : adj_list[curr_vertex]) {
        if(!visited[adj_v])
            dfs(adj_v, adj_list, visited, visit_stack);
    }
    visit_stack.push(curr_vertex);
}

std::vector<std::vector<vertex_t>>kosajaru(vertex_t vertices_count, std::vector<std::pair<vertex_t, vertex_t>>& adj_list) {
    std::vector<bool> visited(vertices_count, false);
    std::stack<vertex_t> visit_stack;
    for(vertex_t i = 0; i < vertices_count; ++i) {
        if(!visited[i]) {
            dfs(i, adj_list, visited, visit_stack);
        }
    }   
}
