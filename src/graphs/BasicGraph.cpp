#include "BasicGraph.hpp"

BasicGraph::BasicGraph(int vertices) : _numVertices(vertices) {}

int BasicGraph::getNumVertices() const {
    return _numVertices;
}
