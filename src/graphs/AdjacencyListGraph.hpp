#ifndef ADJACENCY_LIST_GRAPH_HPP
#define ADJACENCY_LIST_GRAPH_HPP

#include "BasicGraph.hpp"
#include <vector>
#include <list>
#include <tuple>
#include <string>

class AdjacencyListGraph : public BasicGraph {
    private:
        std::vector<std::list<int>> _adjacencyList;

    public:
        AdjacencyListGraph(int vertices, std::string filename, bool symmetric = false);
        AdjacencyListGraph(int vertices, const std::vector<std::tuple<int, int>>& edgeList, bool symmetric = false);
        AdjacencyListGraph(int vertices, int edges, bool symmetric = false);

        void addEdge(int src, int dest) override;
        const std::vector<std::list<int>>& getAdjacencyList() const;
        bool hasEdge(int src, int dest) const override;

        // dbg_print
        void print() const;
};

#endif // ADJACENCY_LIST_GRAPH_HPP