#pragma once

#include"Vertex.h"
#include"node.h"

class linked_list{
    private:
        Node* head;
        Node* tail;

    public:
        linked_list();
        bool isEmpty();
        void addToHead(int data);
        void traverse();
        bool search(int data);
        void addToTail(int data);
        int removeFromHead();
        void emptyTheList();
        void reverse();
        int getHead();
        int getTail();
        void display();
        void removeNode(int data);
};

