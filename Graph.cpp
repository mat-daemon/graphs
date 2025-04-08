#include "Graph.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <random>


void Graph::buildGraphFromFile(std::string fileName, int numberOfVertices)
{
    std::ifstream file(fileName);
    
    if (!file) {
        std::cerr << "Failed to open file.\n";
        return;
    }

    this->numberOfVertices = numberOfVertices;
    reserveMemoryForVertices(numberOfVertices);

    std::string row;

    int src_vertex = 0;

    while(std::getline(file, row))
    {
        std::stringstream edges(row);
        int edge;

        int dst_vertex = 0;

        while(edges >> edge)
        {
            addEdge(src_vertex, dst_vertex, edge);
            dst_vertex++;
        }

        src_vertex++;
    }
}

int Graph::getNumberOfVertices()
{
    return numberOfVertices;
}

void Graph::buildRandomGraph(int numberOfVertices)
{
    std::random_device rd;                         
    std::mt19937 gen(rd());                        
    std::uniform_int_distribution<> dist(0, 1);

    reserveMemoryForVertices(numberOfVertices);

    for (int src = 0; src < numberOfVertices; ++src)
    {
        for (int dst = 0; dst < numberOfVertices; ++dst)
        {
            int random_number = dist(gen);
            addEdge(src, dst, random_number);
        }
    }
}

void GraphWithAdjMatrix::accept(Visitor& visitor)
{
    visitor.visitGraphWithAdjMatrix(*this);
}

void GraphWithAdjMatrix::reserveMemoryForVertices(int numberOfVertices)
{
    adjacencyMatrix.resize(numberOfVertices);

    for (int i = 0; i < numberOfVertices; ++i)
    {
        adjacencyMatrix[i].resize(numberOfVertices);
    }
}

void GraphWithAdjMatrix::addEdge(int src, int dst, int edge)
{
    adjacencyMatrix[src][dst] = edge;
}

const std::vector<std::vector<int>>& GraphWithAdjMatrix::getAdjacencyMatrix()
{
    return adjacencyMatrix;
}

const std::vector<std::list<int>>& GraphWithAdjList::getAdjacencyList()
{
    return adjacencyList;
}

void GraphWithAdjList::accept(Visitor& visitor)
{
    visitor.visitGraphWithAdjList(*this);
}

void GraphWithAdjList::reserveMemoryForVertices(int numberOfVertices)
{
    adjacencyList.resize(numberOfVertices);
}

void GraphWithAdjList::addEdge(int src, int dst, int edge)
{
    if(edge == 1) adjacencyList[src].push_back(dst);
}
