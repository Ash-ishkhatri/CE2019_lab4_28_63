#include"Vertex.h"
#include<iostream>

Vertex::Vertex()
    :next(NULL),nextNeighbour(NULL){}

Vertex::Vertex(int data)   
    :next(NULL),nextNeighbour(NULL),val(data){}