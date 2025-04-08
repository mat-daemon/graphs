#include "Graph.hpp"
#include "Visitor.hpp"
#include "HamiltonianCycle.hpp"


int main()
{
    GraphWithAdjMatrix gm;
    GraphWithAdjList gl;

    gm.buildGraphFromFile("graph1.txt", 5);
    gl.buildGraphFromFile("graph1.txt", 5);
    
    HamiltonianCycleFinder hc;

    gm.accept(hc);
    gl.accept(hc);
}
