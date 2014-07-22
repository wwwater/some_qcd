#include <vector>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <cstdlib>

#include "boost/random.hpp"
#include "boost/generator_iterator.hpp"

typedef boost::mt19937 RNGType;
RNGType rng(time(0));
boost::uniform_real<> ztu( 0, 1 );
boost::variate_generator< RNGType, boost::uniform_real<> > from0to1(rng, ztu);

boost::uniform_real<> utu( -2, 2 );
boost::variate_generator< RNGType, boost::uniform_real<> > fromneg2to2(rng, utu);

using namespace std;


double ws (double r,int A)//r in units of R
{
    double V0 = 1;//MeV//as if divided by V0
    double a = 0.5;//fm
    double r0 = 1.25;//fm
    double R = r0*pow(A,1/3);
    double potential = V0/(1+exp((r*R-R)/a));
    return potential;
}

int main()
{
    FILE *f;
    f = fopen("ws_208.txt","w");
    int n = 0;
    //fprintf(f,"%3s %6s %6s %6s %6s %6s %6s\n","n","r","p","ws(r)","x","y","z");
    while (n<208)
    {
        float x = fromneg2to2();
        float y = fromneg2to2();
        float z = fromneg2to2();
        float p = from0to1();
        float r = sqrt(x*x+y*y+z*z);
        if (p*ws(0,208)<ws(r,208))
        {
            n++;
            fprintf(f,"%3d %6.3f %6.3f %5.3f %6.3f %6.3f %6.3f\n",n,r,p*ws(0,208),ws(r,208),x,y,z);
        }
    }
    fclose(f);
    return 0;
}
