#ifndef BASICGRAPH_HPP
#define BASICGRAPH_HPP

class BasicGraph {
    protected: 
        int _numVertices;
    public:
        BasicGraph(int vertices);
        int getNumVertices() const;
        virtual void addEdge(int src, int dest) = 0;
        virtual bool hasEdge(int src, int dest) const = 0;
        virtual ~BasicGraph() = default;
};

#endif // BASICGRAPH_HPP