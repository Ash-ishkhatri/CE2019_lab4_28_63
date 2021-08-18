#include<iostream>
#include"graph.h"

int main(){

    std::cout << "Undirected graph created\n";
    // Graph g(1); //for directed graph
    Graph g; // for undirected graph
    std::cout << g.isEmpty() << "\n"; //displays 1 since the graph is empty
    std::cout << "\n";

    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    g.addVertex(5);

    std::cout << "\n";
    std::cout << g.isEmpty() << "\n"; //displays 0 since the graph is non-empty
    std::cout << "\n\n";

    g.addEdge(1,4);
    g.addEdge(1,5);
    g.addEdge(3,2);
    g.addEdge(4,3);
    g.addEdge(5,3);

    std::cout << "\n";
    std::cout << "Graph:\n";
    g.displayGraph();
    std::cout << "\n";

    std::cout << "\n";
    std::cout << "Indegree of 3 is: "<<g.indegree(3) << std::endl;
    std::cout << "outdegree of 3 is: "<<g.outdegree(3) << std::endl;
    std::cout << "degree of 3 : "<<g.degree(3) << std::endl;
    std::cout << "\n";

    std::cout << "\n";
    std::cout << "Vertices  = " << g.numVertices() << std::endl;
    std::cout << "Edges  = " << g.numEdges() << std::endl;
    std::cout << "\n";

    std::cout << "\n";
    std::cout << "neighbours : ";
    g.neighbour(1);
    std::cout << "\n"; 

    g.removeVertex(4);
    
    std::cout << "\n";
    std::cout << "Graph:\n";
    g.displayGraph();
    std::cout << "\n";
    
    std::cout << "\n";
    std::cout << "Indegree of 3 is: "<<g.indegree(3) << std::endl;
    std::cout << "outdegree of 3 is: "<<g.outdegree(3) << std::endl;
    std::cout << "degree of 3 : "<<g.degree(3) << std::endl;
    std::cout << "\n";

    g.removeVertex(5);
    g.removeVertex(2);
    g.removeVertex(1);
    g.removeVertex(3);

    std::cout << "\n";
    std::cout << "Indegree of 3 is: "<<g.indegree(3) << std::endl;
    std::cout << "outdegree of 3 is: "<<g.outdegree(3) << std::endl;
    std::cout << "degree of 3 : "<<g.degree(3) << std::endl;
    std::cout << "\n";

    std::cout << "\n";
    std::cout << "Vertices  = " << g.numVertices() << std::endl;
    std::cout << "Edges  = " << g.numEdges() << std::endl;
    std::cout << "\n";



    std::cout << "-----------------------------------------\n";
    // To generate a random graph with the same property ie. directed as g in the top of this program
    std::cout << "Generating random undirected graph:";
    g.generateRandomGraph(5,5);

    return 0;
}
