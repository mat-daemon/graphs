#include "AdjacencyListGraph.hpp"
#include <fstream>
#include <sstream>
#include <limits>
#include <random>
#include <iostream>
#include <algorithm>

AdjacencyListGraph::AdjacencyListGraph(int vertices, std::string filename, bool symmetric)
    : BasicGraph(vertices) {
    _adjacencyList = std::vector<std::list<int>>(vertices);
    std::fstream file(filename, std::ios::in);
    if (file.is_open()) {
        std::string line;
        int src, dest;
        double weight;
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

AdjacencyListGraph::AdjacencyListGraph(int vertices, const std::vector<std::tuple<int, int>>& edgeList, bool symmetric) 
    : BasicGraph(vertices) {
    _adjacencyList = std::vector<std::list<int>>(vertices);
    for (const auto& edge : edgeList) {
        addEdge(std::get<0>(edge), std::get<1>(edge));
        if (symmetric && std::get<0>(edge) != std::get<1>(edge)) {
            addEdge(std::get<1>(edge), std::get<0>(edge));
        }
    }
}

AdjacencyListGraph::AdjacencyListGraph(int vertices, int edges, bool symmetric) 
    : BasicGraph(vertices) {
    if (!symmetric && edges > vertices * vertices) {
        throw std::invalid_argument("Number of edges exceeds possible edges in a directed graph");
    } else if (symmetric && edges > vertices * (vertices + 1) / 2) {
        throw std::invalid_argument("Number of edges exceeds possible edges in an undirected graph");
    }
    _adjacencyList = std::vector<std::list<int>>(vertices);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, vertices - 1);
    for (int i = 0; i < edges; ++i) {
        int src = dist(gen);
        int dest = dist(gen);
        while(_adjacencyList[src].end() != std::find_if(_adjacencyList[src].begin(), _adjacencyList[src].end(), [dest](const auto& ind){ return ind == dest; })){
            src = dist(gen);
            dest = dist(gen);
        }
        addEdge(src, dest);
        if (symmetric && src != dest) {
            addEdge(dest, src);
        }
    }
}

void AdjacencyListGraph::addEdge(int src, int dest) {
    if (src >= 0 && src < _numVertices && dest >= 0 && dest < _numVertices) {
        _adjacencyList[src].emplace_back(dest);
    }
}

const std::vector<std::list<int>>& AdjacencyListGraph::getAdjacencyList() const {
    return _adjacencyList;
}

bool AdjacencyListGraph::hasEdge(int src, int dest) const {
    if (src >= 0 && src < _numVertices && dest >= 0 && dest < _numVertices) {
        return std::find_if(_adjacencyList[src].begin(), _adjacencyList[src].end(), [dest](const auto& ind){ return ind == dest; }) != _adjacencyList[src].end();
    }
    return false;
}

// dbg_print
void AdjacencyListGraph::print() const {
    for (int i = 0; i < _numVertices; ++i) {
        std::cout << i << ": ";
        for (const auto& dest : _adjacencyList[i]) {
            std::cout << "(" << dest << ") ";
        }
        std::cout << std::endl;
    }
}
