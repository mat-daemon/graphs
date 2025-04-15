#ifndef ADJACENCY_MATRIX_GRAPH_HPP
#define ADJACENCY_MATRIX_GRAPH_HPP

#include "BasicGraph.hpp"
#include <vector>
#include <tuple>
#include <string>


class AdjacencyMatrixGraph : public BasicGraph {
    private:
        std::vector<std::vector<int>> _adjacencyMatrix;

    public:
        AdjacencyMatrixGraph(int vertices, std::string filename, bool symmetric = false);
        AdjacencyMatrixGraph(int vertices, const std::vector<std::tuple<int, int>>& edgeList, bool symmetric = false);
        AdjacencyMatrixGraph(int vertices, int edges, bool symmetric = false);

        void addEdge(int src, int dest) override;
        const std::vector<std::vector<int>>& getAdjacencyMatrix() const;
        bool hasEdge(int src, int dest) const override;

        // dbg_print
        void print() const;
};

#endif // ADJACENCY_MATRIX_GRAPH_HPP