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

void Graph::buildRandomGraph(int numberOfVertices)
{
    int maxEdge = 50;
    std::random_device rd;                         
    std::mt19937 gen(rd());                        
    std::uniform_int_distribution<> dist(1, maxEdge*2);

    reserveMemoryForVertices(numberOfVertices);

    for (int src = 0; src < numberOfVertices; ++src)
    {
        for (int dst = 0; dst < numberOfVertices; ++dst)
        {
            int random_number = dist(gen);

            if(random_number < 50)
            {
                addEdge(src, dst, random_number);
            }
        }
    }
}

void GraphWithAdjMatrix::accept(const std::shared_ptr<Visitor>& visitor)
{
    visitor->visitGraphWithAdjMatrix(*this);
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

void GraphWithAdjList::accept(const std::shared_ptr<Visitor>& visitor)
{
    visitor->visitGraphWithAdjList(*this);
}

void GraphWithAdjList::reserveMemoryForVertices(int numberOfVertices)
{
    adjacencyList.resize(numberOfVertices);
}

void GraphWithAdjList::addEdge(int src, int dst, int edge)
{
    adjacencyList[src].push_back(edge);
}
