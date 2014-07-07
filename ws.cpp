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
    for (int r = 0; r<10; r++)
    {
        //cout<<ws(r,208)<<" ";
    }
    cout<<endl;

    srand (time(NULL));
    for (int i = 0; i<1000; i++)
    {
        float r = float(rand() % 2000)/1000;
				float y = -float(rand() % 1000)/1000;
        if (y>=ws(r,208)) cout<<r<<" "<<y<<" "<<ws(r,208)<<endl;
				//if (y>=ws(r,208)) cout<<"Bounded"<<endl; 
    }
    return 0;
}
