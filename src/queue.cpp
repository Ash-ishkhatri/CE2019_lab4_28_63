#include"queue.h"

bool Queue::isEmpty(){
    return queue_list.isEmpty();
}
void Queue::enqueue(int data){
    queue_list.addToTail(data);
}
bool Queue::isAvailable(int data){
    return queue_list.search(data);
}
int Queue::dequeue(){
    return queue_list.removeFromHead();
}
int Queue::front(){
    return queue_list.getHead();
}
int Queue::rear(){
    return queue_list.getTail();
}
void Queue::emptyTheQueue(){
    queue_list.emptyTheList();
}
void Queue::displayQueue(){
    queue_list.traverse();
}
void Queue::reverseQueue(){
    queue_list.reverse();
}