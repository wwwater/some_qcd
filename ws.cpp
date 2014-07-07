#include <vector>
#include <cmath>
#include <iostream>
#include <cstdlib>

using namespace std;

double ws (double r,int A)//r in units of R
{
    double V0 = 1;//MeV//as if divided by V0
    double a = 0.5;//fm
    double r0 = 1.25;//fm
    double R = r0*pow(A,1/3);
    double potential = -V0/(1+exp((r*R-R)/a));
    return potential;
}

int main()
{
    srand (time(NULL));
    int n = 0;
    while (n<208)
    {
        float r = float(rand() % 2001)/1000;
        float y = -float(rand() % 1001)/1000;
        float phi = float(rand() % 2001)/1000*3.141593;
        float theta = float(rand() % 1001)/1000*3.141593;

        if (y>=ws(r,208))
        {
            n++;
            float x = r*cos(phi)*cos(theta);
            float y = r*sin(phi)*cos(theta);
            float z = r*sin(theta);
            cout<<r<<" "<<y<<" "<<ws(r,208)<<" "<<x<<" "<<y<<" "<<z<<endl;
        }
    }
    return 0;
}
