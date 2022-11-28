#ifndef RADIX_HPP
#define RADIX_HPP

#include "Queue.hpp"
#include<cmath>

class Radix{
    private:
        int* numbers;
        int lenght;
        Queue** queues;
        int maxStep;

        int maxStepNumber(); //max basamak sayisini bulur
        int stepCount(int); //basamak sayisi bulur
        int* queueCurrentLenght();
    public:
        Radix(int*,int);
        int* sort();
        ~Radix();
};

#endif