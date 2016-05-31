#include <iostream>
#include <fstream>
#include <sstream>
#include "detect.h"
#include "detect1.h"
#include <cstdlib>
using namespace std;

int main()
{
    detect1 d;

    double a[3];
    bool current_state;
    ifstream myfile("/home/lyw/datasets/pengzhuang/pz1.txt");
    string str((std::istreambuf_iterator<char>(myfile)), std::istreambuf_iterator<char>());
    stringstream ss(str);
    string s;
    string timestamp;
    string sdd;
    int cc = 0;
    while (getline (ss,s,'\n'))
    {   cc ++;
        stringstream sss(s);
        for(int i = 0; i < 4; i++)
        {
            getline(sss, sdd, '\t');
            if(i == 0)
                timestamp = sdd;
            else
                a[i-1] = atof(sdd.c_str());
        }
        d.state(a , 4, current_state);
        if(current_state  == 1 && cc > 5)
            std::cout << timestamp << ": " << current_state << std::endl;

    }
    myfile.close();




    return 0;
}
