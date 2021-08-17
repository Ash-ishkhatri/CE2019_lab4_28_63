#pragma once
#include<iostream>
#include"Vertex.h"
#include"stack.h"
#include"queue.h"

class Graph{
    private:
        Vertex* head;
        bool Directed;
        Stack visitedStack; //using linkedlist to implement stack
        Queue visitedQueue; //using linkedlist to implement queue
        linked_list visited; //using linkedlist instead of array to track visited vertices while traversing
        int numberOfVertices; // keeps count of total number of vertices in graph
        
    public:
        Graph(); //constructor of undirected graph
        Graph(int i); // constructor of directed graph

        //ashish's part
        bool isEmpty(); 
        bool isDirected();
        
        Vertex* getVertex(int val);
        
        void addVertex(int val);
        void addEdge(int first,int second);
        void addEdge_helper(Vertex* firstVertex , Vertex* secondVertex);
        
        void removeEdge(int first,int second);
        void removeEdge_helper(Vertex* firstVertex,Vertex* secondVertex);
        void removeVertex(int val);
        void removeVertex_undirected(Vertex* v );
        void removeVertex_directed(Vertex* v );
        
        void displayGraph();
        // ashish's part end

        // saugat's part comes here

        // generating a random graph
        void generateRandomGraph(int numVertices , int numEdges);
};