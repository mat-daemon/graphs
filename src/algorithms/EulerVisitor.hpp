#ifndef EULERVISITOR_HPP
#define EULERVISITOR_HPP

#include <vector>
#include <optional>

class AdjacencyMatrixGraph;
class AdjacencyListGraph;

class EulerVisitor {
public:
    // Constructor
    EulerVisitor() = default;

    // Destructor
    ~EulerVisitor() = default;

    std::optional<std::vector<int>> visit(const AdjacencyMatrixGraph& graph) const;
    std::optional<std::vector<int>> visit(const AdjacencyListGraph& graph) const;
};

#endif // EULERVISITOR_HPP