#include "HamiltonVisitor.hpp"
#include "../graphs/AdjacencyMatrixGraph.hpp"
#include "../graphs/AdjacencyListGraph.hpp"
#include <iostream>
#include <algorithm>
#include <numeric>

using Path = std::vector<int>;

bool HamiltonVisitor::hamiltonian(const std::vector<std::vector<int>>& graph, int numberOfVertices, Path& path, int pos) const
{
    if(pos == numberOfVertices)
    {
        return graph[path[numberOfVertices-1]][path[0]];
    }

    for(int v=1; v<numberOfVertices; v++)
    {
        if(isValidVertex(graph, numberOfVertices, path, pos, v))
        {
            path[pos] = v;
            if(hamiltonian(graph, numberOfVertices, path, pos+1))
            {
                return true;
            }

            path[pos] = -1;
        }
    }
    return false;
}

bool HamiltonVisitor::hamiltonian(const std::vector<std::list<int>>& graph, int numberOfVertices, Path& path, int pos) const
{
    if(pos == numberOfVertices)
    {
        return std::find(graph[path[numberOfVertices-1]].begin(), graph[path[numberOfVertices-1]].end(), path[0]) != graph[path[numberOfVertices-1]].end();
    }

    for(int v=1; v<numberOfVertices; v++)
    {
        if(isValidVertex(graph, numberOfVertices, path, pos, v))
        {
            path[pos] = v;
            if(hamiltonian(graph, numberOfVertices, path, pos+1))
            {
                return true;
            }

            path[pos] = -1;
        }
    }
    return false;
}

int HamiltonVisitor::isValidVertex(const std::vector<std::vector<int>>& graph, int numberOfVertices, Path& path, int pos, int v) const
{
    if (graph[path[pos - 1]][v] == 0)
        return false;

    for(int i=0; i<pos; i++)
    {
        if(v == path[i]) return false;
    }
    return true;
}

int HamiltonVisitor::isValidVertex(const std::vector<std::list<int>>& graph, int numberOfVertices, Path& path, int pos, int v) const
{
    if (std::find(graph[path[pos-1]].begin(), graph[path[pos-1]].end(), v) == graph[path[pos-1]].end())
        return false;
    
    for(int i=0; i<pos; i++)
    {
        if(v == path[i]) return false;
    }
    return true;
}

std::optional<std::vector<int>> HamiltonVisitor::visit(const AdjacencyMatrixGraph& graph) const
{
    int numVertices = graph.getNumVertices();
    Path path(numVertices, -1);
    path[0] = 0; // Start from the first vertex
    if (hamiltonian(graph.getAdjacencyMatrix(), numVertices, path, 1)) {
        return path;
    }
    return std::nullopt; // No Hamiltonian cycle found
}

std::optional<std::vector<int>> HamiltonVisitor::visit(const AdjacencyListGraph& graph) const
{
    int numVertices = graph.getNumVertices();
    Path path(numVertices, -1);
    path[0] = 0; // Start from the first vertex
    if (hamiltonian(graph.getAdjacencyList(), numVertices, path, 1)) {
        return path;
    }
    return std::nullopt; // No Hamiltonian cycle found
}