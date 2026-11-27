#include <iostream>
#include <utility>
#include <vector>

int main() {
    int vertexCount;
    std::cout << "Number of vertices (0-100): ";
    if (!(std::cin >> vertexCount) || vertexCount < 0 || vertexCount > 100) {
        std::cout << "Vertex count must be between 0 and 100.\n";
        return 1;
    }

    int edgeCount;
    std::cout << "Number of edges (0-10000): ";
    if (!(std::cin >> edgeCount) || edgeCount < 0 || edgeCount > 10000
        || (vertexCount == 0 && edgeCount > 0)) {
        std::cout << "Invalid edge count for this graph.\n";
        return 1;
    }

    std::vector<std::pair<int, int>> edges;
    edges.reserve(static_cast<std::size_t>(edgeCount));
    std::cout << "Enter each undirected edge as two vertex numbers (0 to "
              << (vertexCount > 0 ? vertexCount - 1 : 0) << "):\n";
    for (int i = 0; i < edgeCount; ++i) {
        int from, to;
        if (!(std::cin >> from >> to) || from < 0 || from >= vertexCount
            || to < 0 || to >= vertexCount) {
            std::cout << "Edge endpoints must name existing vertices.\n";
            return 1;
        }
        edges.emplace_back(from, to);
    }

    std::cout << "Vertices: ";
    for (int vertex = 0; vertex < vertexCount; ++vertex) std::cout << vertex << ' ';
    std::cout << "\nEdges:\n";
    if (edges.empty()) std::cout << "(none)\n";
    for (const auto& edge : edges) {
        std::cout << edge.first << " -- " << edge.second << '\n';
    }
}
