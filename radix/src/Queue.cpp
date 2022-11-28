#include "Queue.hpp"

// private
void Queue::reserve(int newCap)
{
    int *temp = new int[newCap];
    for (int i = front, j = 0; i < lenght; j++)
    {
        temp[j] = items[i];
        i = (i + 1) % capacity;
    }
    capacity = newCap;
    delete[] items;
    items = temp;
    front = 0;
    back = lenght - 1;
}

// public
Queue::Queue()
{
    capacity = 20;
    front = 0;
    back = -1;
    lenght = 0;
    items = new int[capacity];
}

void Queue::clear()
{
    front = 0;
    back = -1;
    lenght = 0;
}

int Queue::count() const
{
    return lenght;
}

bool Queue::isEmpty() const
{
    return lenght == 0;
}

const int &Queue::peek()
{
    if (isEmpty())
        throw "Empty list!";
    return items[front];
}

void Queue::enqueue(const int &item)
{
    if (lenght == capacity)
        reserve(2 * capacity);
    back = (back + 1) % capacity;
    items[back] = item;
    lenght++;
}

void Queue::dequeue()
{
    if (isEmpty())
        throw "Empty list!";
    front = (front + 1) % capacity;
    lenght--;
}

Queue::~Queue()
{
    delete[] items;
}