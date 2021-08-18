#include"graph.h"
#include<stdlib.h>

Graph::Graph(){
    head = NULL;
    Directed = false;
    numberOfVertices = 0;
}
Graph::Graph(int i){
    head = NULL;
    Directed = i;
    numberOfVertices = 0;
}

bool Graph::isEmpty(){
    return head == NULL;
}

bool Graph::isDirected(){
    return this->Directed;
}

void Graph::addVertex(int val){
    Vertex* v = getVertex(val);
    if(v != NULL){
        std::cout << "Vertex " << val << " already available in the graph\n";
        return;
    }
    v = new Vertex(val);
    v->next = head;
    head = v;
    numberOfVertices++;
    std::cout << "added vertex " << val << "\n";
}

Vertex* Graph::getVertex(int val){
    Vertex* temp = head;
    while(temp != NULL){
        if(temp -> val == val){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}


void Graph::addEdge_helper(Vertex* firstVertex , Vertex* secondVertex){
    Vertex* tempFirst = new Vertex(firstVertex->val);
    Vertex* tempSecond = new Vertex(secondVertex->val);

    tempSecond -> nextNeighbour = firstVertex -> nextNeighbour;
    firstVertex -> nextNeighbour = tempSecond;
}

void Graph::addEdge(int first , int second){
    Vertex* firstVertex = getVertex(first);
    Vertex* secondVertex = getVertex(second);
    if(firstVertex == NULL || secondVertex == NULL){
        if(firstVertex == NULL && secondVertex == NULL){
            std::cout << "Vertex " << first << " and " << second << " doesnot exist"<<std::endl;
        }else if(firstVertex == NULL){
            std::cout << "Vertex " << first << " doesnot exist"<<std::endl;
        }else if(secondVertex == NULL){
            std::cout << "Vertex " << second << " doesnot exist"<<std::endl;
        }
        return;
    }else if(neighbour(first,second)){
        std::cout << "The vertices " << first << " and " << second << " are already connected with edge\n";
        return;
    }
    if(!this->isDirected()){
        addEdge_helper(firstVertex,secondVertex);
        if(!neighbour(second,first)){
            addEdge_helper(secondVertex,firstVertex);
        }
        std::cout << "added edge " << first << "---" << second << "\n";
    }else{
        addEdge_helper(firstVertex,secondVertex);
        std::cout << "added edge " << first << "---" << second << "\n";
    }
}


void Graph::removeEdge_helper(Vertex* firstVertex,Vertex* secondVertex){
    Vertex* temp = firstVertex -> nextNeighbour;
    Vertex* predecessor = firstVertex;
    while(temp != NULL){
        if(temp->val == secondVertex->val){
            Vertex* toBeDeleted = temp;
            predecessor->nextNeighbour = temp -> nextNeighbour;
            delete toBeDeleted;
            break;
        }
        predecessor = temp;
        temp = temp -> nextNeighbour;
    }
}


void Graph::removeEdge(int first,int second){
    Vertex* firstVertex = getVertex(first);
    Vertex* secondVertex = getVertex(second);

    if(firstVertex == NULL || secondVertex == NULL){
        if(firstVertex == NULL && secondVertex == NULL){
            std::cout << "Vertex " << first << " and " << second << " doesnot exist"<<std::endl;
        }else if(firstVertex == NULL){
            std::cout << "Vertex " << first << " doesnot exist"<<std::endl;
        }else if(secondVertex == NULL){
            std::cout << "Vertex " << second << " doesnot exist"<<std::endl;
        }
        return;
    }else if(!neighbour(first,second)){
        std::cout << "The vertices " << first << " and " << second << " are not connected with edge yet!\n";
        return;
    }
    if(!this->isDirected()){
        removeEdge_helper(firstVertex,secondVertex);
        removeEdge_helper(secondVertex,firstVertex);
        std::cout << "removed edge "<< first << "---" << second << "\n";
    }else{
        removeEdge_helper(firstVertex,secondVertex);
        std::cout << "removed edge "<< first << "---" << second << "\n";
    }
}

void Graph::removeVertex_undirected(Vertex* v){
    Vertex* temp = v->nextNeighbour;
    while(temp != NULL){
        removeEdge_helper(getVertex(temp->val),v);
        removeEdge_helper(v,temp);
        temp = temp->nextNeighbour;
    }
    if(head->val == v->val){
        Vertex* toBeDeleted = head;
        head = head->next;
        delete toBeDeleted;
        return;
    }
    temp = head->next;
    Vertex* predecessor = head;
    while(temp != NULL){
        if(temp->val == v->val){
            predecessor->next = temp->next;
            delete temp;
            break;
        }
        predecessor = temp;
        temp = temp->next;
    }
}

void Graph::removeVertex_directed(Vertex* v){
    Vertex* temp = v -> nextNeighbour;

    // removing edges directly connected to the vertex v
    while(temp != NULL){
        removeEdge_helper(v,temp);
        temp = temp->nextNeighbour;
    }
    // removing the edge including the vertex v present in the list of other vertices
    temp = head;
    while(temp != NULL){
        // if the vertex temp == v then skip that vertex
        // since we have already removed all edges of this vertex's list
        if(temp->val == v->val){
            temp = temp->next;
            continue;
        }
        Vertex* tempNeighbour = temp->nextNeighbour;
        while(tempNeighbour != NULL){
            if(tempNeighbour->val == v->val){
                removeEdge_helper(temp , tempNeighbour);
            }
            tempNeighbour = tempNeighbour->nextNeighbour;   
        }
        temp = temp->next;
    }

    // finally removing the vertex v
    if(head->val == v->val){
        Vertex* toBeDeleted = head;
        head = head->next;
        delete toBeDeleted;
        return;
    }
    temp = head->next;
    Vertex* predecessor = head;
    while(temp != NULL){
        if(temp->val == v->val){
            predecessor->next = temp->next;
            delete temp;
            break;
        }
        predecessor = temp;
        temp = temp->next;
    }
}

void Graph::removeVertex(int val){
    Vertex* v = getVertex(val);
    if(v == NULL){
        std::cout << "vertex " << val << " doesnot exist\n";
        return;
    }
    if(!this->isDirected()){
        removeVertex_undirected(v);
    }else{
        removeVertex_directed(v);
    }
    numberOfVertices--;
    std::cout << "removed Vertex : "<< val<<"\n";
}

// display graph
void Graph::displayGraph(){
    Vertex* temp = head;
    while(temp != NULL){
        neighbour(temp->val);
        temp = temp->next;
    }
}

void Graph::neighbour(int val){
    Vertex* v = getVertex(val);
    if(v == NULL){
        std::cout << "Vertex" << val << " not found\n";
        return; 
    }
    Vertex* temp = v;
    while(temp != NULL){
        std::cout << temp -> val << "-->";
        temp = temp -> nextNeighbour;
    }
    std::cout << "\n";
}

bool Graph::neighbour(int val1,int val2){
    Vertex* v = getVertex(val1);
    Vertex* temp = v -> nextNeighbour;
    while(temp != NULL){
        if(temp -> val == val2){
            return true;
        }
        temp = temp -> nextNeighbour;
    }
    return false;
}

int Graph::numVertices(){
    return numberOfVertices;
}

int Graph::numEdges(){
    int n=-1;
    int totalEdges = 0;
    Vertex* temp = head;
    while(temp != NULL){
        Vertex* neighborTemp = temp->nextNeighbour;
        while(neighborTemp != NULL){
            totalEdges++;
            neighborTemp = neighborTemp -> nextNeighbour;
        }
        temp = temp->next;
    }
    if(!this->isDirected()){
        n =  totalEdges/2;
    }else{
        n = totalEdges;
    }
    return n;
}

int Graph::indegree(int val){
    Vertex* v = getVertex(val);
    if(v == NULL){
        return -1;
    }
    // undirected
    int n=0;
    Vertex* temp = head;
    while(temp != NULL){
        Vertex* tempNeighbour = temp->nextNeighbour;
        while(tempNeighbour != NULL){
            if(tempNeighbour->val == val){
                n++;
                break;
            }
            tempNeighbour = tempNeighbour->nextNeighbour;
        }
        temp = temp->next;
    }

    return n;
}

int Graph::outdegree(int val){
    Vertex* v = getVertex(val);
    if(v == NULL){
        return -1;
    }
    // undirected
    int n=0;
    Vertex* temp = v->nextNeighbour;
    while(temp != NULL){
        n++;
        temp = temp->nextNeighbour;
    }
    return n;
}

int Graph::degree(int val){
    int n = indegree(val) + outdegree(val);

    if(!isDirected()){
        n = indegree(val);
    }
    return n;
}
// random graph generator
void Graph::generateRandomGraph(int numVertices,int numEdges){
    std::cout << "with " << numVertices << " vertices and "<< numEdges << " edges\n";
    Graph rg(this->isDirected());
    int maxEdges;
    if(rg.isDirected()){
         maxEdges = numVertices * numVertices;
    }else{
         maxEdges = (numVertices * numVertices) - ((numVertices * (numVertices - 1))/2);
    };
    int vertexCount = 0;
    int verticesArrayIndex = 0;
    int vertices[numVertices];

    while(vertexCount != numVertices){
        srand(time_t(0));
        int i = rand() % 50;
        if(rg.getVertex(i) == NULL){
            vertices[verticesArrayIndex] = i; 
            rg.addVertex(i);
            verticesArrayIndex++;
            vertexCount++;
        }
    }
    if(numEdges > maxEdges){
        std::cout << "maxEdges that can be added is " << maxEdges << " so try adding less edges\n";
        return;
    }
    std::cout << "\n";
    int edgeCount = 0;
    while(edgeCount != numEdges){
        Vertex* firstVertex = rg.getVertex(vertices[rand() % numVertices]);
        Vertex* secondVertex = rg.getVertex(vertices[rand() % numVertices]);
        if(!rg.neighbour(firstVertex->val , secondVertex->val)){
            rg.addEdge(firstVertex->val,secondVertex->val);
            edgeCount++;
        }
    }
    std::cout << "\n";
    std::cout << "Randomly generated graph is as follows:\n";
    // rg.neighbour(2);
    rg.displayGraph();
}