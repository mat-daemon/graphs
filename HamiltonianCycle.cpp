#include "HamiltonianCycle.hpp"
#include "Graph.hpp"
#include <iostream>
#include <algorithm>


using Path = std::vector<int>;


bool HamiltonianCycleFinder::hamiltonian(const std::vector<std::vector<int>>& graph, int numberOfVertices, Path& path, int pos)
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

bool HamiltonianCycleFinder::hamiltonian(const std::vector<std::list<int>>& graph, int numberOfVertices, Path& path, int pos)
{
    if(pos == numberOfVertices)
    {
        return std::find(graph[path[numberOfVertices-1]].begin(), graph[path[numberOfVertices-1]].end(), path[0]) != graph[numberOfVertices-1].end();
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

int HamiltonianCycleFinder::isValidVertex(const std::vector<std::vector<int>>& graph, int numberOfVertices, Path& path, int pos, int v)
{
    if (graph[path[pos - 1]][v] == 0)
        return false;

    for(int i=0; i<pos; i++)
    {
        if(v == path[i]) return false;
    }
    return true;
}

int HamiltonianCycleFinder::isValidVertex(const std::vector<std::list<int>>& graph, int numberOfVertices, Path& path, int pos, int v)
{
    if (std::find(graph[path[pos-1]].begin(), graph[path[pos-1]].end(), v) == graph[path[pos-1]].end())
        return false;
    
    for(int i=0; i<pos; i++)
    {
        if(v == path[i]) return false;
    }
    return true;
}

void HamiltonianCycleFinder::visitGraphWithAdjMatrix(GraphWithAdjMatrix& graph)
{
    int numberOfVertices = graph.getNumberOfVertices();

    Path path(numberOfVertices, -1);
    path[0] = 0;

    if(hamiltonian(graph.getAdjacencyMatrix(), numberOfVertices, path, 1))
    {
        std::cout<<"Found cycle:\n";
        for(int i=0; i<numberOfVertices; i++)
        {
            std::cout<<path[i]<<" ";
        }
        std::cout<<"\n";
    }
    else
    {
        std::cout<<"Cycle not found\n";
    }

}

void HamiltonianCycleFinder::visitGraphWithAdjList(GraphWithAdjList& graph)
{
    int numberOfVertices = graph.getNumberOfVertices();

    Path path(numberOfVertices, -1);
    path[0] = 0;

    if(hamiltonian(graph.getAdjacencyList(), numberOfVertices, path, 1))
    {
        std::cout<<"Found cycle:\n";
        for(int i=0; i<numberOfVertices; i++)
        {
            std::cout<<path[i]<<" ";
        }
        std::cout<<"\n";
    }
    else
    {
        std::cout<<"Cycle not found\n";
    }
}
