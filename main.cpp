#include "Graph.hpp"
#include "Visitor.hpp"


int main()
{
    GraphWithAdjMatrix g;

    // First option
    g.buildGraphFromFile("graph1.txt", 5);

    // Second option
    // g.buildRandomGraph(5);

    DummyVisitor visitor;
    visitor.visitGraphWithAdjMatrix(g);
}
