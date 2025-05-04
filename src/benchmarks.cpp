#include <iostream>
#include <chrono>
#include <cmath>
#include "graphs/AdjacencyMatrixGraph.hpp"
#include "graphs/AdjacencyListGraph.hpp"
#include "algorithms/EulerVisitor.hpp"
#include "algorithms/HamiltonVisitor.hpp"
#include "algorithms/IsomorphismVisitor.hpp"


const int NR_OF_EXPERIMENTS = 30;

int main() {
    // Euler, AdjacencyMatrixGraph

    // different graph sizes
    for (int i = 1000; i < 10000; i += 500) {
        std::vector<int> experiments(NR_OF_EXPERIMENTS);
        for (int j = 0; j < NR_OF_EXPERIMENTS; ++j) {
            // create a random graph
            AdjacencyMatrixGraph graph(2 * (int)std::sqrt((float)i), i, true);
            EulerVisitor eulerVisitor;
            auto start = std::chrono::high_resolution_clock::now();
            auto eulerPath = eulerVisitor.visit(graph).value_or(std::vector<int>{});
            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
            experiments[j] = elapsed.count();
        }
        std::cout << "Euler, AdjacencyMatrixGraph, nr_edges: " << i << ", average time: ";
        double sum = 0;
        for (int j = 0; j < NR_OF_EXPERIMENTS; ++j) {
            sum += experiments[j];
        }
        std::cout << sum / NR_OF_EXPERIMENTS << " ns" << std::endl;
    }

    // Euler, AdjacencyListGraph
    for (int i = 1000; i < 10000; i += 500) {
        std::vector<int> experiments(NR_OF_EXPERIMENTS);
        for (int j = 0; j < NR_OF_EXPERIMENTS; ++j) {
            // create a random graph
            AdjacencyListGraph graph(2 * (int)std::sqrt((float)i), i, true);
            EulerVisitor eulerVisitor;
            auto start = std::chrono::high_resolution_clock::now();
            auto eulerPath = eulerVisitor.visit(graph).value_or(std::vector<int>{});
            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
            experiments[j] = elapsed.count();
        }
        std::cout << "Euler, AdjacencyListGraph, nr_edges: " << i << ", average time: ";
        double sum = 0;
        for (int j = 0; j < NR_OF_EXPERIMENTS; ++j) {
            sum += experiments[j];
        }
        std::cout << sum / NR_OF_EXPERIMENTS << " ns" << std::endl;
    }

    // Hamilton, AdjacencyMatrixGraph
    for (int i = 3; i <= 15; i++) {
        std::vector<int> experiments(NR_OF_EXPERIMENTS);
        for (int j = 0; j < NR_OF_EXPERIMENTS; ++j) {
            // create a random graph
            AdjacencyMatrixGraph graph(i, i * i/4, true);
            HamiltonVisitor hamiltonVisitor;
            auto start = std::chrono::high_resolution_clock::now();
            auto hamiltonPath = hamiltonVisitor.visit(graph).value_or(std::vector<int>{});
            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
            experiments[j] = elapsed.count();
        }
        std::cout << "Hamilton, AdjacencyMatrixGraph, nr_vertices: " << i << ", average time: ";
        double sum = 0;
        for (int j = 0; j < NR_OF_EXPERIMENTS; ++j) {
            sum += experiments[j];
        }
        std::cout << sum / NR_OF_EXPERIMENTS << " ns" << std::endl;
    }

    // Hamilton, AdjacencyListGraph
    for (int i = 3; i <= 15; i++) {
        std::vector<int> experiments(NR_OF_EXPERIMENTS);
        for (int j = 0; j < NR_OF_EXPERIMENTS; ++j) {
            // create a random graph
            AdjacencyListGraph graph(i, i * i/4, true);
            HamiltonVisitor hamiltonVisitor;
            auto start = std::chrono::high_resolution_clock::now();
            auto hamiltonPath = hamiltonVisitor.visit(graph).value_or(std::vector<int>{});
            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
            experiments[j] = elapsed.count();
        }
        std::cout << "Hamilton, AdjacencyListGraph, nr_vertices: " << i << ", average time: ";
        double sum = 0;
        for (int j = 0; j < NR_OF_EXPERIMENTS; ++j) {
            sum += experiments[j];
        }
        std::cout << sum / NR_OF_EXPERIMENTS << " ns" << std::endl;
    }

    // Isomorphism, AdjacencyMatrixGraph
    for (int i = 3; i <= 15; i++) {
        std::vector<int> experiments(NR_OF_EXPERIMENTS);
        for (int j = 0; j < NR_OF_EXPERIMENTS; ++j) {
            // create a random graph
            AdjacencyMatrixGraph graph1(i, i * i/4, true);
            AdjacencyMatrixGraph graph2(i, i * i/4, true);
            IsomorphismVisitor isomorphismVisitor;
            auto start = std::chrono::high_resolution_clock::now();
            auto isomorphic = isomorphismVisitor.visit(graph1, graph2).value_or(std::vector<int>{});
            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
            experiments[j] = elapsed.count();
        }
        std::cout << "Isomorphism, AdjacencyMatrixGraph, nr_vertices: " << i << ", average time: ";
        double sum = 0;
        for (int j = 0; j < NR_OF_EXPERIMENTS; ++j) {
            sum += experiments[j];
        }
        std::cout << sum / NR_OF_EXPERIMENTS << " ns" << std::endl;
    }

    // Isomorphism, AdjacencyListGraph
    for (int i = 3; i <= 15; i++) {
        std::vector<int> experiments(NR_OF_EXPERIMENTS);
        for (int j = 0; j < NR_OF_EXPERIMENTS; ++j) {
            // create a random graph
            AdjacencyListGraph graph1(i, i * i/4, true);
            AdjacencyListGraph graph2(i, i * i/4, true);
            IsomorphismVisitor isomorphismVisitor;
            auto start = std::chrono::high_resolution_clock::now();
            auto isomorphic = isomorphismVisitor.visit(graph1, graph2).value_or(std::vector<int>{});
            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
            experiments[j] = elapsed.count();
        }
        std::cout << "Isomorphism, AdjacencyListGraph, vertices: " << i << ", average time: ";
        double sum = 0;
        for (int j = 0; j < NR_OF_EXPERIMENTS; ++j) {
            sum += experiments[j];
        }
        std::cout << sum / NR_OF_EXPERIMENTS << " ns" << std::endl;
    }
}