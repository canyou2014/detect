#include "detect.h"
#include <iostream>
detect::detect()
{
    count = 0;
    //ctor
}
void detect::state(double* acc, double T, bool& current_state){
    for(int i = 0; i < 3; i++)
    {
        delta[i] = *(acc + i) - avg(sd[i], 5);
        sd[i][count] = *(acc + i);

    }

    if(count < 4) count ++;
    else count = 0;
    current_state = (delta[0] > T) || (delta[1] > T) || (delta[2] > T);


}
double detect::avg(double* x, int len){
    double sum = 0;
    for (int i = 0; i< len; i++)
        sum += *(x + i);
    return sum/len;

}
detect::~detect()
{
    //delete q;
    //dtor
}
