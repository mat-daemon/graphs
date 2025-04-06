#pragma once

#include <iostream>


class GraphWithAdjMatrix;
class GraphWithAdjList;


class Visitor
{
    public:
        virtual void visitGraphWithAdjMatrix(GraphWithAdjMatrix&) = 0;
        virtual void visitGraphWithAdjList(GraphWithAdjList&) = 0;
};


class DummyVisitor : public Visitor
{
    public:
        void visitGraphWithAdjMatrix(GraphWithAdjMatrix&) override {std::cout<<"GraphWithAdjMatrix visited\n";}
        void visitGraphWithAdjList(GraphWithAdjList&) override {std::cout<<"GraphWithAdjList visited\n";}
};  