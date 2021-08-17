#pragma once
#include<iostream>

class Vertex{
    public:
        int val;
        Vertex* next;
        Vertex* nextNeighbour;
        Vertex();
        Vertex(int val);
};


