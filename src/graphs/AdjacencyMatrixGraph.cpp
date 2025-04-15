#include "AdjacencyMatrixGraph.hpp"
#include <fstream>
#include <sstream>
#include <random>
#include <iostream>

AdjacencyMatrixGraph::AdjacencyMatrixGraph(int vertices, std::string filename, bool symmetric)
    : BasicGraph(vertices) {
    _adjacencyMatrix = std::vector<std::vector<int>>(vertices, std::vector<int>(vertices, 0));
    std::fstream file(filename, std::ios::in);
    if (file.is_open()) {
        std::string line;
        int src, dest;
        double weight; // unused, but present in input files
        while(getline(file, line)) {
            std::istringstream iss(line);
            if (iss >> src >> dest >> weight) {
                if (weight != 0.0) {
                    addEdge(src-1, dest-1);
                    if (symmetric && src != dest) {
                        addEdge(dest-1, src-1);
                    }
                }
            }
        }
        file.close();
    } else {
        throw std::runtime_error("Could not open file");
    }
}

AdjacencyMatrixGraph::AdjacencyMatrixGraph(int vertices, const std::vector<std::tuple<int, int>>& edgeList, bool symmetric) 
    : BasicGraph(vertices) {
    _adjacencyMatrix = std::vector<std::vector<int>>(vertices, std::vector<int>(vertices, 0));
    for (const auto& edge : edgeList) {
        addEdge(std::get<0>(edge), std::get<1>(edge));
        if (symmetric && std::get<0>(edge) != std::get<1>(edge)) {
            addEdge(std::get<1>(edge), std::get<0>(edge));
        }
    }
}

AdjacencyMatrixGraph::AdjacencyMatrixGraph(int vertices, int edges, bool symmetric) 
    : BasicGraph(vertices) {
    if (!symmetric && edges > vertices * vertices) {
        throw std::invalid_argument("Number of edges exceeds possible edges in a directed graph");
    } else if (symmetric && edges > vertices * (vertices + 1) / 2) {
        throw std::invalid_argument("Number of edges exceeds possible edges in an undirected graph");
    }
    _adjacencyMatrix = std::vector<std::vector<int>>(vertices, std::vector<int>(vertices, 0));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, vertices - 1);
    for (int i = 0; i < edges; ++i) {
        int src = dist(gen);
        int dest = dist(gen);
        while(hasEdge(src, dest)) {
            src = dist(gen);
            dest = dist(gen);
        }
        addEdge(src, dest);
        if (symmetric && src != dest) {
            addEdge(dest, src);
        }
    }
}

void AdjacencyMatrixGraph::addEdge(int src, int dest) {
    if (src >= 0 && src < _numVertices && dest >= 0 && dest < _numVertices) {
        _adjacencyMatrix[src][dest] = 1;
    }
}

const std::vector<std::vector<int>>& AdjacencyMatrixGraph::getAdjacencyMatrix() const {
    return _adjacencyMatrix;
}

bool AdjacencyMatrixGraph::hasEdge(int src, int dest) const {
    if (src < 0 || src >= _numVertices || dest < 0 || dest >= _numVertices) {
        return false; // Out of bounds
    }
    return _adjacencyMatrix[src][dest] != 0;
}

// dbg_print
void AdjacencyMatrixGraph::print() const {
    for (int i = 0; i < _numVertices; ++i) {
        for (int j = 0; j < _numVertices; ++j) {
            std::cout << _adjacencyMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}