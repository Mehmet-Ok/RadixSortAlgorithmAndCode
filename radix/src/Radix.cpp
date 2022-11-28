#include "Radix.hpp"

//private
int Radix::maxStepNumber(){ 
    int max = 0;
    for(int i = 0; i<lenght;i++)
        if(stepCount(numbers[i])>max) max = stepCount(numbers[i]);
    return max;
}   

int Radix::stepCount(int num){
    num = abs(num);
    int step = 0;
    while (num>0)
    {
        step++;
        num /= 10;
    }
    return step;
}


//public
Radix::Radix(int* numbers, int lenght){
    this->numbers = numbers;
    this->lenght = lenght;
    for(int i = 0; i<lenght; i++)
        this->numbers[i] = numbers[i];
    Queue **queues = new Queue*[10];
    for(int i = 0; i < 10; i++)
        queues[i] = new Queue();
    maxStep = maxStepNumber();
}

int* Radix::queueCurrenLenght(){
    int* lenghts = new int[10];
    for(int i = 0; i < 10; i++)
        lenghts[i] = queues[i]->count();
    return lenghts;
}

int* Radix::sort(){
    int numIndex = stepValue = num =0;

    //dizinin bir kere isleme alinmasi
    for(; numIndex<lenght; numIndex++)
    {
        stepValue = numbers[numIndex] % 10;
        num = numbers[numIndex];
        queues[stepValue]->enqueue(num);
    }

    stepValue = num =0;
    for(int i = 1;i<maxStep; i++)
    {
        int* qCurrenLenghts = queueCurrenLenght();
        for(int index = 0; index<10; index++)
        {
            int len = qCurrenLenghts[index];
            for(;len>0;len--)
            {
                num = queues[index]->peek();
                queues[index]->dequeue();
                stepValue = (num/(int)pow(10,i))%10;
                queues[stepValue]->enqueue(num);
            }
        }
        delete [] qCurrenLenghts;
    }

    int* ordered = new int[lenght];
    numIndex = 0;
    num = 0;
    for(int i = 0; i<10; i++)
    {
        while(!queues[i]->isEmpty()){
            num =queues[i]->peek();
            ordered[numIndex] = num;
            numIndex++;
            queues[i]->dequeue();
        }
    }
    return ordered;
}

Radix::~Radix(){
    delete [] numbers;
    for(int i = 0; i<10; i++)
        delete queues[i];
    delete [] queues;
}

