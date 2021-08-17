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

        // saugat's part

        // for dispalying the whole graph
        void neighbour(int val);
        bool neighbour(int val1,int val2);
        // displays the number of vertices in graph
        int numVertices();
        // displays the number of edges in graph
        int numEdges();
        // return total edges incoming
        int indegree(int val);
        // return total edges outgoing 
        int outdegree(int val);
        // sum of outgoing and incoming edges
        int degree(int val);

        // generating a random graph
        void generateRandomGraph(int numVertices , int numEdges);
};