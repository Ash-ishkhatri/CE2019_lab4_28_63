#include"stack.h"

bool Stack::isEmpty(){
    return stack_list.isEmpty();
}
void Stack::push(int data){
    stack_list.addToHead(data);
}
bool Stack::isAvailable(int data){
    return stack_list.search(data);
}
int Stack::pop(){
    return stack_list.removeFromHead();
}
int Stack::top(){
    return stack_list.getHead();
}
void Stack::emptyTheStack(){
    stack_list.emptyTheList();
}
void Stack::displayStack(){
    stack_list.traverse();
}
void Stack::reverseStack(){
    stack_list.reverse();
}
void Stack::popNode(int data){
    stack_list.removeNode(data);
}