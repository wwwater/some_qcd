#include <vector>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <cstdlib>

#include "boost/random.hpp"
#include "boost/generator_iterator.hpp"

typedef boost::mt19937 RNGType;
RNGType rng(time(0));
boost::uniform_real<> ztu( 0.0, 1.0 );
boost::variate_generator< RNGType, boost::uniform_real<> > from0to1(rng, ztu);

boost::uniform_real<> utu( -5.0, 5.0 );
boost::variate_generator< RNGType, boost::uniform_real<> > fromneg2to2(rng, utu);

using namespace std;




//Begin: WS parameters ************
const double R_Cu=4.2; 
const double a_Cu=0.596;

const double R_Au=6.38;
const double a_Au=0.535;

const double R_Pb=6.62;
const double a_Pb=0.546;
//End: WS parameter ***************

const double a_WS=a_Pb;
const double R_WS=R_Pb;
const double Normalization_WS = 1.0+exp(-R_WS/a_WS);
const int N_WS=208;

double ws (double r)//r in units of R_WS
{
    double potential = 1.0/(1.0+exp((r*R_WS-R_WS)/a_WS));
    return potential; // *Normalization_WS;
}

int main()
{
    FILE *f;
    f = fopen("ws_208.txt","w");
    int n = 0;
    //fprintf(f,"%3s %6s %6s %6s %6s %6s %6s\n","n","r","p","ws(r)","x","y","z");
    //while (n<N_WS)
    while (n<10000)
    {
        double x = fromneg2to2();
        double y = fromneg2to2();
        double z = fromneg2to2();
        double p = from0to1();
        double r = sqrt(x*x+y*y+z*z);
        if (p<ws(r))
        {
            n++;
            fprintf(f,"%3d %6.3f %6.3f %5.3f %6.3f %6.3f %6.3f\n",n,r,p,ws(r),x,y,z);
        }
    }
    fclose(f);
    return 0;
}
