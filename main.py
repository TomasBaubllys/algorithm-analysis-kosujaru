def dfs(current_vertex, edges, visited, stack):
    visited[current_vertex] = True
    for vertex in edges[current_vertex]:
        if not visited[vertex]:
            dfs(vertex, edges, visited, stack)
    stack.append(current_vertex)


def kosajaru(vertices_count, adjacency_list):
    visited = [False] * vertices_count
    stack = []
    for vertex in range(vertices_count):
        if not visited[vertex]:
            dfs(vertex, adjacency_list, visited, stack)

    # reverse the graph
    reversed_adjacency_list = [[] for _ in range(vertices_count)]
    for vertex1 in range(vertices_count):
        for vertex2 in adjacency_list[vertex1]:
            reversed_adjacency_list[vertex2].append(vertex1)

    # process reversed graph
    visited = [False] * vertices_count
    strongly_connected_components = []
    while stack:
        vertex = stack.pop()
        if not visited[vertex]:
            strongly_connected_component = []
            dfs(vertex, reversed_adjacency_list, visited, strongly_connected_component)
            strongly_connected_components.append(strongly_connected_component)

    return strongly_connected_components


if __name__ == "__main__":
    vertex_count = 6
    edges = [[1, 3], [1, 4], [2, 1], [3, 2], [4, 5]]
    adj_list = [[] for _ in range(vertex_count)]
    for vertex1, vertex2 in edges:
        adj_list[vertex1].append(vertex2)

    sccs = kosajaru(vertex_count, adj_list)
    print(sccs)
