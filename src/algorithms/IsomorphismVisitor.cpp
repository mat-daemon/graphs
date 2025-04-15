#include "IsomorphismVisitor.hpp"
#include "../graphs/AdjacencyMatrixGraph.hpp"
#include "../graphs/AdjacencyListGraph.hpp"
#include <iostream>
#include <algorithm>
#include <numeric>

std::optional<std::vector<int>> IsomorphismVisitor::visit(const AdjacencyMatrixGraph& graph1, const AdjacencyMatrixGraph& graph2) const {
    std::cout << "Visiting AdjacencyMatrixGraph for isomorphism." << std::endl;
    // Implement the isomorphism logic for AdjacencyMatrixGraph
    const auto& adjacencyMatrix1 = graph1.getAdjacencyMatrix();
    const auto& adjacencyMatrix2 = graph2.getAdjacencyMatrix();
    int numVertices1 = graph1.getNumVertices();
    int numVertices2 = graph2.getNumVertices();

    if (numVertices1 != numVertices2) {
        return std::nullopt; // Not isomorphic
    }

    // Check degree sequences
    std::vector<int> degreeSequence1(numVertices1, 0);
    std::vector<int> degreeSequence2(numVertices2, 0);
    for (int i = 0; i < numVertices1; ++i) {
        for (int j = 0; j < numVertices1; ++j) {
            if (adjacencyMatrix1[i][j] != 0) {
                degreeSequence1[i]++;
            }
            if (adjacencyMatrix2[i][j] != 0) {
                degreeSequence2[i]++;
            }
        }
    }
    std::sort(degreeSequence1.begin(), degreeSequence1.end());
    std::sort(degreeSequence2.begin(), degreeSequence2.end());
    if (degreeSequence1 != degreeSequence2) {
        return std::nullopt; // Not isomorphic
    }
    // Check adjacency matrix
    std::vector<int> mapping(numVertices1);
    std::iota(mapping.begin(), mapping.end(), 0);
    do {
        bool isIsomorphic = true;
        for (int i = 0; i < numVertices1; ++i) {
            for (int j = 0; j < numVertices1; ++j) {
                if (adjacencyMatrix1[i][j] != adjacencyMatrix2[mapping[i]][mapping[j]]) {
                    isIsomorphic = false;
                    break;
                }
            }
            if (!isIsomorphic) {
                break;
            }
        }
        if (isIsomorphic) {
            return mapping; // Isomorphic
        }
    } while (std::next_permutation(mapping.begin(), mapping.end()));
    return std::nullopt; // Not isomorphic
}

std::optional<std::vector<int>> IsomorphismVisitor::visit(const AdjacencyListGraph& graph1, const AdjacencyListGraph& graph2) const {
    std::cout << "Visiting AdjacencyListGraph for isomorphism." << std::endl;
    // Implement the isomorphism logic for AdjacencyListGraph
    const auto& adjacencyList1 = graph1.getAdjacencyList();
    const auto& adjacencyList2 = graph2.getAdjacencyList();
    int numVertices1 = graph1.getNumVertices();
    int numVertices2 = graph2.getNumVertices();

    if (numVertices1 != numVertices2) {
        return std::nullopt; // Not isomorphic
    }

    // Check degree sequences
    std::vector<int> degreeSequence1(numVertices1, 0);
    std::vector<int> degreeSequence2(numVertices2, 0);
    for (int i = 0; i < numVertices1; ++i) {
        for (const auto& ind : adjacencyList1[i]) {
            degreeSequence1[i]++;
        }
        for (const auto& ind : adjacencyList2[i]) {
            degreeSequence2[i]++;
        }
    }
    std::sort(degreeSequence1.begin(), degreeSequence1.end());
    std::sort(degreeSequence2.begin(), degreeSequence2.end());
    if (degreeSequence1 != degreeSequence2) {
        return std::nullopt; // Not isomorphic
    }

    // Check adjacency list
    std::vector<int> mapping(numVertices1);
    std::iota(mapping.begin(), mapping.end(), 0);
    do {
        bool isIsomorphic = true;
        for (int i = 0; i < numVertices1; ++i) {
            for (const auto& ind : adjacencyList1[i]) {
                if (std::find(adjacencyList2[mapping[i]].begin(), adjacencyList2[mapping[i]].end(), mapping[ind]) == adjacencyList2[mapping[i]].end()) {
                    isIsomorphic = false;
                    break;
                }
            }
            if (!isIsomorphic) {
                break;
            }
        }
        if (isIsomorphic) {
            return mapping; // Isomorphic
        }
    } while (std::next_permutation(mapping.begin(), mapping.end()));
    
    return std::nullopt; // Not isomorphic
}