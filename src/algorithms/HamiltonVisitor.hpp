#ifndef HAMILTONVISITOR_HPP
#define HAMILTONVISITOR_HPP

#include <vector>
#include <list>
#include <optional>

class AdjacencyMatrixGraph;
class AdjacencyListGraph;

class HamiltonVisitor {
public:
    // Constructor
    HamiltonVisitor() = default;

    // Destructor
    ~HamiltonVisitor() = default;

    std::optional<std::vector<int>> visit(const AdjacencyMatrixGraph& graph) const;
    std::optional<std::vector<int>> visit(const AdjacencyListGraph& graph) const;

private:
    bool hamiltonian(const std::vector<std::vector<int>>&, int, std::vector<int>&, int) const;
    bool hamiltonian(const std::vector<std::list<int>>&, int, std::vector<int>&, int) const;
    int isValidVertex(const std::vector<std::vector<int>>&, int, std::vector<int>&, int, int) const;
    int isValidVertex(const std::vector<std::list<int>>&, int, std::vector<int>&, int, int) const;
};

#endif // HAMILTONVISITOR_HPP