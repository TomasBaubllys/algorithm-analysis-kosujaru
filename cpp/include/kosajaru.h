#ifndef KOSAJARU_H_INCLUDED
#define KOSAJARU_H_INCLUDED

#include <vector>
#include <cstdint>
#include <stack>

using vertex_t = uint32_t;

std::vector<std::vector<vertex_t>> kosajaru(vertex_t vertices_count, std::vector<std::vector<vertex_t>>& adj_list);

void dfs(vertex_t curr_vertex, std::vector<std::vector<vertex_t>>& adj_list, std::vector<bool>& visited, std::vector<vertex_t>& visit_stack);

#endif // KOSAJARU_H_INCLUDED
