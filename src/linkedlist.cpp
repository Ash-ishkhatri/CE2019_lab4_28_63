#include"linkedlist.h"
#include<iostream>
linked_list::linked_list()
            :head(NULL),tail(NULL){}
bool linked_list::isEmpty(){
    return head == NULL && tail == NULL;
}
void linked_list::addToHead(int data){
    Node* n = new Node(data);
    if(this->isEmpty()){
        tail = n;
    }
    n->next = head;
    head = n;
}
void linked_list::addToTail(int data){
    if(this->isEmpty()){
        addToHead(data);
        return;
    }
    Node* n = new Node(data);
    tail->next = n;
    tail = n;
}
bool linked_list::search(int data){
    Node* temp = head;
    while(temp != NULL){
        if(temp -> data == data){
            return true;
        }
        temp = temp->next;
    }
    return false;
}
int linked_list::removeFromHead(){
    if(this->isEmpty()) return -1;
    int removedData;
    Node* toBeRemoved = head;
    if(head == tail){
        head = head->next;
        removedData = toBeRemoved->data;
        tail = head;
        delete toBeRemoved;
        return removedData;
    }
    head = head->next;
    removedData = toBeRemoved->data;
    delete toBeRemoved;
    return removedData;
}
void linked_list::traverse(){
    Node* temp = head;
    while(temp != NULL){
        std::cout << temp->data << " ";
        temp = temp -> next;
    }
    // std::cout << "\n";
}
void linked_list::emptyTheList(){
    while(!this->isEmpty()){
        removeFromHead();
    }

}
void linked_list::reverse(){
    Node* prev = NULL;
    Node* next = NULL;
    Node* current = head;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int linked_list::getHead(){
    return head -> data;
}
int linked_list::getTail(){
    return tail -> data;
}

void linked_list::display(){
    Node* temp = head;
    while(temp != NULL){
        std::cout << temp->data << " ";
        temp = temp->next;
    }

}
void linked_list::removeNode(int data){
    if(head == tail || head -> data == data){
        removeFromHead();
        return;
    }
    Node* temp = head->next;
    Node* predecessor = head;
    // Node* successor = temp->next;

    while(temp != NULL){
        if(temp->data == data){
            Node* toBeDeleted = temp;
            predecessor->next = temp->next;
            delete toBeDeleted;
        }
        predecessor = temp;
        temp = temp->next;
    }
    
}