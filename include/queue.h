#include"linkedlist.h"

class Queue:public linked_list{
    private:
        linked_list queue_list;
    public:
        bool isEmpty();
        void enqueue(int data);
        bool isAvailable(int data);
        int dequeue();
        int front();
        int rear();
        void emptyTheQueue();
        void displayQueue();
        void reverseQueue();
};