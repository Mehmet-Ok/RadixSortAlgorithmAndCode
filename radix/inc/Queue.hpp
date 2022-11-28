#ifndef QUEUE_HPP
#define QUEUE_HPP

#include<iostream>
using namespace std;

class Queue{
    private:
        int front; 
        int back;
        int capacity;
        int lenght;

        int* items;
        void reserve(int newCap);
    public:
        Queue();
        void clear();
        int count() const;
        bool isEmpty() const;
        const int& peek();
        void enqueue(const int& item);
        void dequeue();
        ~Queue();

};
#endif