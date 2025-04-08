#include "Visitor.hpp"
#include <vector>
#include <list>


class HamiltonianCycleFinder : public Visitor
{
    public:
        void visitGraphWithAdjMatrix(GraphWithAdjMatrix&) override;
        void visitGraphWithAdjList(GraphWithAdjList&) override;
    private:
        bool hamiltonian(const std::vector<std::vector<int>>&, int, std::vector<int>&, int);
        bool hamiltonian(const std::vector<std::list<int>>&, int, std::vector<int>&, int);
        int isValidVertex(const std::vector<std::vector<int>>&, int, std::vector<int>&, int, int);
        int isValidVertex(const std::vector<std::list<int>>&, int, std::vector<int>&, int, int);
};