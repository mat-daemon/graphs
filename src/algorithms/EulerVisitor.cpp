#include "EulerVisitor.hpp"
#include "../graphs/AdjacencyMatrixGraph.hpp"
#include "../graphs/AdjacencyListGraph.hpp"
#include <iostream>
#include <limits>
#include <algorithm>

std::optional<std::vector<int>> EulerVisitor::visit(const AdjacencyMatrixGraph& graph) const {
    std::cout << "Visiting AdjacencyMatrixGraph for Eulerian path/circuit." << std::endl;
    // Implement the Eulerian path or circuit logic for AdjacencyMatrixGraph
    const auto& adjacencyMatrix = graph.getAdjacencyMatrix();
    int numVertices = graph.getNumVertices();
    std::vector<int> eulerPath{};
    std::vector<int> inDegree(numVertices, 0);
    std::vector<int> outDegree(numVertices, 0);
    int numEdges = 0;
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            if (graph.hasEdge(i, j)) {
                outDegree[i]++;
                inDegree[j]++;
                numEdges++;
            }
        }
    }
    // Check if Eulerian path or circuit exists
    int startNodes = 0, endNodes = 0;
    for (int i = 0; i < numVertices; ++i) {
        if (outDegree[i] - inDegree[i] == 1) {
            startNodes++;
        } else if (inDegree[i] - outDegree[i] == 1) {
            endNodes++;
        } else if (inDegree[i] != outDegree[i]) {
            return std::nullopt; // Not Eulerian
        }
    }
    if (startNodes > 1 || endNodes > 1) {
        return std::nullopt; // Not Eulerian
    }
    int start = 0;
    for (int i = 0; i < numVertices; ++i) {
        if (outDegree[i] > inDegree[i]) {
            start = i;
            break;
        }
        if (outDegree[i] > 0) {
            start = i;
        }
    }

    // Hierholzer's algorithm to find Eulerian path/circuit
    std::vector<int> stack;
    stack.push_back(start);

    std::vector<std::vector<int>> adjacencyMatrix_copy;
    adjacencyMatrix_copy.resize(numVertices, std::vector<int>(numVertices, 0));
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            adjacencyMatrix_copy[i][j] = adjacencyMatrix[i][j];
        }
    }
    while (!stack.empty()) {
        int v = stack.back();
        bool hasNext = false;
        for (int u = 0; u < numVertices; ++u) {
            if (adjacencyMatrix_copy[v][u] != 0) {
                stack.push_back(u);
                adjacencyMatrix_copy[v][u] = 0; // Remove edge
                hasNext = true;
                break;
            }
        }
        if (!hasNext) {
            eulerPath.push_back(v);
            stack.pop_back();
        }
    }
    std::reverse(eulerPath.begin(), eulerPath.end());
    if (eulerPath.size() != numEdges + 1) {
        return std::nullopt; // Not Eulerian
    }
    return eulerPath; // Eulerian path/circuit found
}

std::optional<std::vector<int>> EulerVisitor::visit(const AdjacencyListGraph& graph) const {
    // Implement the Eulerian path or circuit logic for AdjacencyListGraph
    std::cout << "Visiting AdjacencyListGraph for Eulerian path/circuit." << std::endl;
    const auto& adjacencyList = graph.getAdjacencyList();
    int numVertices = graph.getNumVertices();
    std::vector<int> eulerPath{};
    std::vector<int> inDegree(numVertices, 0);
    std::vector<int> outDegree(numVertices, 0);
    int numEdges = 0;
    for (int i = 0; i < numVertices; ++i) {
        for (const auto& ind : adjacencyList[i]) {
            outDegree[i]++;
            inDegree[ind]++;
            numEdges++;
        }
    }
    // Check if Eulerian path or circuit exists
    int startNodes = 0, endNodes = 0;
    for (int i = 0; i < numVertices; ++i) {
        if (outDegree[i] - inDegree[i] == 1) {
            startNodes++;
        } else if (inDegree[i] - outDegree[i] == 1) {
            endNodes++;
        } else if (inDegree[i] != outDegree[i]) {
            return std::nullopt; // Not Eulerian
        }
    }
    if (startNodes > 1 || endNodes > 1) {
        return std::nullopt; // Not Eulerian
    }
    int start = 0;
    for (int i = 0; i < numVertices; ++i) {
        if (outDegree[i] > inDegree[i]) {
            start = i;
            break;
        }
        if (outDegree[i] > 0) {
            start = i;
        }
    }

    // Hierholzer's algorithm to find Eulerian path/circuit
    std::vector<int> stack;
    stack.push_back(start);

    std::vector<std::list<int>> adjacencyList_copy(adjacencyList);
    while (!stack.empty()) {
        int v = stack.back();
        if (adjacencyList_copy[v].empty()) {
            eulerPath.push_back(v);
            stack.pop_back();
            continue;
        }
        else {
            auto it = adjacencyList_copy[v].begin();
            stack.push_back(*it);
            adjacencyList_copy[v].erase(it); // Remove edge
        }
    }
    if (eulerPath.size() != numEdges + 1) {
        return std::nullopt; // Not Eulerian
    }
    std::reverse(eulerPath.begin(), eulerPath.end());
    return eulerPath; // Eulerian path/circuit found    
}
