#pragma once
#include<iostream>

class Node{
    public:
        int data;
        Node* next;
        Node()
            :next(NULL){}
        Node(int data)
            :next(NULL),data(data){}
};