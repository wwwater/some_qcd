#include <blitz/array.h>
#include <vector>  

using namespace blitz;

typedef complex<float> cf;

vector < Array<cf,2> > get_lambda()
{
		vector < Array<cf,2> > lambda(8);
    for (int i =0; i<lambda.size(); i++) lambda.at(i).resize(3,3);
	
    lambda.at(0)= cf(0,0), cf(1,0), cf(0,0),
    cf(1,0), cf(0,0), cf(0,0),
    cf(0,0), cf(0,0), cf(0,0);

    lambda.at(1)= cf(0,0), cf(0,-1), cf(0,0),
    cf(0,1), cf(0,0), cf(0,0),
    cf(0,0), cf(0,0), cf(0,0);

    lambda.at(2)= cf(1,0), cf(0,0), cf(0,0),
    cf(0,0), cf(-1,0), cf(0,0),
    cf(0,0), cf(0,0), cf(0,0);

    lambda.at(3)= cf(0,0), cf(0,0), cf(1,0),
    cf(0,0), cf(0,0), cf(0,0),
    cf(1,0), cf(0,0), cf(0,0);

    lambda.at(4)= cf(0,0), cf(0,0), cf(0,-1),
    cf(0,0), cf(0,0), cf(0,0),
    cf(0,1), cf(0,0), cf(0,0);

    lambda.at(5)= cf(0,0), cf(0,0), cf(0,0),
    cf(0,0), cf(0,0), cf(1,0),
    cf(0,0), cf(1,0), cf(0,0);

    lambda.at(6)= cf(0,0), cf(0,0), cf(0,0),
    cf(0,0), cf(0,0), cf(0,-1),
    cf(0,0), cf(0,1), cf(0,0);

    lambda.at(7)= cf(1/sqrt(3),0), cf(0,0), cf(0,0),
    cf(0,0), cf(1/sqrt(3),0), cf(0,0),
    cf(0,0), cf(0,0), cf(-2/sqrt(3),0);


		Array<cf,2> coef(3,3);
		coef = cf(0.5,0);
		for (int i=0;i<lambda.size();i++) lambda.at(i)*=coef;

return lambda;
}
