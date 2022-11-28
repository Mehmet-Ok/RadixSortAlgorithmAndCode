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
