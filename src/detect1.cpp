#include "detect1.h"
#include <iostream>
#include <boost/array.hpp>
#include <vector>
detect1::detect1()
{
    //ctor
}
void detect1::state(double acc[], double T, bool& current_state){
    ac = {acc[0], acc[1], acc[2]};
    if(v.size() == 16)
        v.erase(v.begin());
    v.push_back(ac);
    avg(v, 0, 5, avgd);
    for(int i = 0; i < 3; i++)
    {
      delta[i] = v[5][i] - avg[i];
    }

    current_state = (delta[0] > T) || (delta[1] > T) || (delta[2] > T);

}
void detect1::avg(vec v, int begin, int end, double* avgd){
    double sum[3];

    for (int i = begin; i < end; i++)
        for (int j = 0; j < 3; j++)
           {
             sum[j] += v[i][j];
             if (i == end -1)
                {sum[j] /= (end-begin);
                *(avgd + j) = sum[j];
                }
           }


}
detect1::~detect1()
{
    //delete q;
    //dtor
}
