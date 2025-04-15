#ifndef ISOMORPHISM_VISITOR_HPP
#define ISOMORPHISM_VISITOR_HPP

#include <vector>
#include <optional>

class AdjacencyMatrixGraph;
class AdjacencyListGraph;

class IsomorphismVisitor {
public:
    // Constructor
    IsomorphismVisitor() = default;

    // Destructor
    ~IsomorphismVisitor() = default;

    std::optional<std::vector<int>> visit(const AdjacencyMatrixGraph& graph1, const AdjacencyMatrixGraph& graph2) const;
    std::optional<std::vector<int>> visit(const AdjacencyListGraph& graph1, const AdjacencyListGraph& graph2) const;
};

#endif // ISOMORPHISM_VISITOR_HPP