#pragma once

#include <vector>
#include <string>
#include <list>
#include <memory>
#include "Visitor.hpp"


class Graph
{
    public:
        void buildGraphFromFile(std::string, int);
        void buildRandomGraph(int);
        int getNumberOfVertices();
        virtual void accept(Visitor&) = 0;
    protected:
        virtual void addEdge(int, int, int) = 0;
        virtual void reserveMemoryForVertices(int) = 0;
    private:
        int numberOfVertices;
};


class GraphWithAdjMatrix : public Graph
{
    public:
        void accept(Visitor&);
        const std::vector<std::vector<int>>& getAdjacencyMatrix();
    protected:
        void addEdge(int, int, int) override;
        void reserveMemoryForVertices(int) override;
    private:
        std::vector<std::vector<int>> adjacencyMatrix;
};


class GraphWithAdjList : public Graph
{
    public:
        void accept(Visitor&);
        const std::vector<std::list<int>>& getAdjacencyList();
    protected:
        void addEdge(int, int, int) override;
        void reserveMemoryForVertices(int) override;
    private:
        std::vector<std::list<int>> adjacencyList;
};
