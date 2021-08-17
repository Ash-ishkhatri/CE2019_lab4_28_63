#include"linkedlist.h"

class Stack:public linked_list{
    private:
        linked_list stack_list;
    public:
        bool isEmpty();
        void push(int data);
        bool isAvailable(int data);
        int pop();
        int top();
        void emptyTheStack();
        void displayStack();
        void reverseStack();
        void popNode(int data);
};