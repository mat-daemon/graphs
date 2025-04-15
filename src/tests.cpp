#include <iostream>
#include "graphs/AdjacencyMatrixGraph.hpp"
#include "graphs/AdjacencyListGraph.hpp"
#include "algorithms/EulerVisitor.hpp"
#include "algorithms/HamiltonVisitor.hpp"
#include "algorithms/IsomorphismVisitor.hpp"

int main() {
    AdjacencyMatrixGraph graph1a(17, "datasets/aves-barn-swallow-contact-network.edges", true);
    AdjacencyMatrixGraph graph2a(17, "datasets/aves-barn-swallow-contact-network.edges");

    AdjacencyMatrixGraph graph1b(17, "datasets/aves-barn-swallow-non-physical.edges", true);
    AdjacencyMatrixGraph graph2b(17, "datasets/aves-barn-swallow-non-physical.edges");

    AdjacencyMatrixGraph graph1c(20, "datasets/aves-geese-female-foraging.edges", true);
    AdjacencyMatrixGraph graph2c(20, "datasets/aves-geese-female-foraging.edges");

    AdjacencyMatrixGraph graph1d(23, "datasets/aves-geese-male-foraging.edges", true);
    AdjacencyMatrixGraph graph2d(23, "datasets/aves-geese-male-foraging.edges");
    
    std::cout << "Adjacency Matrix Graphs 1a:" << std::endl;
    graph1a.print();
    std::cout << "Adjacency Matrix Graphs 2a:" << std::endl;
    graph2a.print();
    std::cout << "Adjacency Matrix Graphs 1b:" << std::endl;
    graph1b.print();
    std::cout << "Adjacency Matrix Graphs 2b:" << std::endl;
    graph2b.print();
    std::cout << "Adjacency Matrix Graphs 1c:" << std::endl;
    graph1c.print();
    std::cout << "Adjacency Matrix Graphs 2c:" << std::endl;
    graph2c.print();
    std::cout << "Adjacency Matrix Graphs 1d:" << std::endl;
    graph1d.print();
    std::cout << "Adjacency Matrix Graphs 2d:" << std::endl;
    graph2d.print();

    AdjacencyListGraph graph3a(17, "datasets/aves-barn-swallow-contact-network.edges", true);
    AdjacencyListGraph graph4a(17, "datasets/aves-barn-swallow-contact-network.edges");

    AdjacencyListGraph graph3b(17, "datasets/aves-barn-swallow-non-physical.edges", true);
    AdjacencyListGraph graph4b(17, "datasets/aves-barn-swallow-non-physical.edges");

    AdjacencyListGraph graph3c(20, "datasets/aves-geese-female-foraging.edges", true);
    AdjacencyListGraph graph4c(20, "datasets/aves-geese-female-foraging.edges");

    AdjacencyListGraph graph3d(23, "datasets/aves-geese-male-foraging.edges", true);
    AdjacencyListGraph graph4d(23, "datasets/aves-geese-male-foraging.edges");
    
    std::cout << "Adjacency List Graphs 3a:" << std::endl;
    graph3a.print();
    std::cout << "Adjacency List Graphs 4a:" << std::endl;
    graph4a.print();
    std::cout << "Adjacency List Graphs 3b:" << std::endl;
    graph3b.print();
    std::cout << "Adjacency List Graphs 4b:" << std::endl;
    graph4b.print();
    std::cout << "Adjacency List Graphs 3c:" << std::endl;
    graph3c.print();
    std::cout << "Adjacency List Graphs 4c:" << std::endl;
    graph4c.print();
    std::cout << "Adjacency List Graphs 3d:" << std::endl;
    graph3d.print();
    std::cout << "Adjacency List Graphs 4d:" << std::endl;
    graph4d.print();
    
    EulerVisitor eulerVisitor;
    auto eulerPath1a = eulerVisitor.visit(graph1a).value_or(std::vector<int>{});
    auto eulerPath2a = eulerVisitor.visit(graph2a).value_or(std::vector<int>{});
    auto eulerPath1b = eulerVisitor.visit(graph1b).value_or(std::vector<int>{});
    auto eulerPath2b = eulerVisitor.visit(graph2b).value_or(std::vector<int>{});
    auto eulerPath1c = eulerVisitor.visit(graph1c).value_or(std::vector<int>{});
    auto eulerPath2c = eulerVisitor.visit(graph2c).value_or(std::vector<int>{});
    auto eulerPath1d = eulerVisitor.visit(graph1d).value_or(std::vector<int>{});
    auto eulerPath2d = eulerVisitor.visit(graph2d).value_or(std::vector<int>{});

    std::cout << "Euler Path 1a: ";
    for (const auto& node : eulerPath1a) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
    std::cout << "Euler Path 2a: ";
    for (const auto& node : eulerPath2a) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
    std::cout << "Euler Path 1b: ";
    for (const auto& node : eulerPath1b) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
    std::cout << "Euler Path 2b: ";
    for (const auto& node : eulerPath2b) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
    std::cout << "Euler Path 1c: ";
    for (const auto& node : eulerPath1c) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
    std::cout << "Euler Path 2c: ";
    for (const auto& node : eulerPath2c) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
    std::cout << "Euler Path 1d: ";
    for (const auto& node : eulerPath1d) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
    std::cout << "Euler Path 2d: ";
    for (const auto& node : eulerPath2d) {
        std::cout << node << " ";
    }
    std::cout << std::endl;

    auto eulerPath_test1 = eulerVisitor.visit(AdjacencyMatrixGraph(6, {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 0}
    })).value_or(std::vector<int>{});

    for (const auto& node : eulerPath_test1) {
        std::cout << node << " ";
    }
    std::cout << std::endl;

    auto eulerPath_test2 = eulerVisitor.visit(AdjacencyMatrixGraph(6, {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 0}
    }, true)).value_or(std::vector<int>{});

    for (const auto& node : eulerPath_test2) {
        std::cout << node << " ";
    }
    std::cout << std::endl;

    // EULER list case

    auto eulerPath3a = eulerVisitor.visit(graph3a).value_or(std::vector<int>{});
    auto eulerPath4a = eulerVisitor.visit(graph4a).value_or(std::vector<int>{});
    auto eulerPath3b = eulerVisitor.visit(graph3b).value_or(std::vector<int>{});
    auto eulerPath4b = eulerVisitor.visit(graph4b).value_or(std::vector<int>{});
    auto eulerPath3c = eulerVisitor.visit(graph3c).value_or(std::vector<int>{});
    auto eulerPath4c = eulerVisitor.visit(graph4c).value_or(std::vector<int>{});
    auto eulerPath3d = eulerVisitor.visit(graph3d).value_or(std::vector<int>{});
    auto eulerPath4d = eulerVisitor.visit(graph4d).value_or(std::vector<int>{});

    std::cout << "Euler Path 3a: ";
    for (const auto& node : eulerPath3a) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
    std::cout << "Euler Path 4a: ";
    for (const auto& node : eulerPath4a) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
    std::cout << "Euler Path 3b: ";
    for (const auto& node : eulerPath3b) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
    std::cout << "Euler Path 4b: ";
    for (const auto& node : eulerPath4b) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
    std::cout << "Euler Path 3c: ";
    for (const auto& node : eulerPath3c) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
    std::cout << "Euler Path 4c: ";
    for (const auto& node : eulerPath4c) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
    std::cout << "Euler Path 3d: ";
    for (const auto& node : eulerPath3d) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
    std::cout << "Euler Path 4d: ";
    for (const auto& node : eulerPath4d) {
        std::cout << node << " ";
    }
    std::cout << std::endl;

    auto eulerPath_test3 = eulerVisitor.visit(AdjacencyListGraph(6, {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 0}
    })).value_or(std::vector<int>{});

    for (const auto& node : eulerPath_test3) {
        std::cout << node << " ";
    }
    std::cout << std::endl;

    auto eulerPath_test4 = eulerVisitor.visit(AdjacencyListGraph(6, {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 0}
    }, true)).value_or(std::vector<int>{});

    for (const auto& node : eulerPath_test4) {
        std::cout << node << " ";
    }
    std::cout << std::endl;

    // ISOMORPSISM
    IsomorphismVisitor isomorphismVisitor;
    auto isomorphism1 = isomorphismVisitor.visit(
    AdjacencyMatrixGraph(3, {
        {0, 1},
        {1, 2},
        {2, 0},
        {0, 0},
    },
    false),
    AdjacencyMatrixGraph(3, {
        {1, 0},
        {2, 1},
        {0, 2},
        {2, 2},
    },
    false
    )).value_or(std::vector<int>{});

    std::cout << "Isomorphism 1: ";
    for (const auto& node : isomorphism1) {
        std::cout << node << " ";
    }
    std::cout << std::endl;

    // ISOMORPSISM list case

    auto isomorphism2 = isomorphismVisitor.visit(
    AdjacencyListGraph(3, {
        {0, 1},
        {1, 2},
        {2, 0},
        {0, 0},
    },
    false),
    AdjacencyListGraph(3, {
        {1, 0},
        {2, 1},
        {0, 2},
        {2, 2},
    },
    false
    )).value_or(std::vector<int>{});

    std::cout << "Isomorphism 2: ";
    for (const auto& node : isomorphism2) {
        std::cout << node << " ";
    }
    std::cout << std::endl;

    // HAMILTONIAN - MATRIX TEST
    HamiltonVisitor hamiltonVisitor;
    auto hamiltonPath1 = hamiltonVisitor.visit(AdjacencyMatrixGraph(
        7, {
            {0, 1},
            {0, 2},
            {1, 1},
            {1, 2},
            {1, 3},
            {1, 4},
            {2, 3},
            {2, 5},
            {3, 4},
            {3, 5},
            {4, 5},
            {4, 6},
            {5, 6}
        }, true
    )).value_or(std::vector<int>{});
    std::cout << "Hamiltonian Path 1: ";
    for (const auto& node : hamiltonPath1) {
        std::cout << node << " ";
    }
    std::cout << std::endl;

    AdjacencyListGraph graph_helper(
        7, {
            {0, 1},
            {0, 2},
            {1, 1},
            {1, 2},
            {1, 3},
            {1, 4},
            {2, 3},
            {2, 5},
            {3, 4},
            {3, 5},
            {4, 5},
            {4, 6},
            {5, 6}
        }, true
    );

    graph_helper.print();

    auto hamiltonPath2 = hamiltonVisitor.visit(graph_helper).value_or(std::vector<int>{});
    std::cout << "Hamiltonian Path 2: ";
    for (const auto& node : hamiltonPath2) {
        std::cout << node << " ";
    }
    std::cout << std::endl;

    return 0;
}