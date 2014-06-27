#include <blitz/array.h>
#include <vector>  

using namespace blitz;
vector < Array<complex<float>,2> > get_lambda()
{
		vector < Array<complex<float>,2> > lambda(8);
    for (int i =0; i<lambda.size(); i++) lambda.at(i).resize(3,3);
	
    lambda.at(0)= complex<float>(0,0), complex<float>(1,0), complex<float>(0,0),
    complex<float>(1,0), complex<float>(0,0), complex<float>(0,0),
    complex<float>(0,0), complex<float>(0,0), complex<float>(0,0);

    lambda.at(1)= complex<float>(0,0), complex<float>(0,-1), complex<float>(0,0),
    complex<float>(0,1), complex<float>(0,0), complex<float>(0,0),
    complex<float>(0,0), complex<float>(0,0), complex<float>(0,0);

    lambda.at(2)= complex<float>(1,0), complex<float>(0,0), complex<float>(0,0),
    complex<float>(0,0), complex<float>(-1,0), complex<float>(0,0),
    complex<float>(0,0), complex<float>(0,0), complex<float>(0,0);

    lambda.at(3)= complex<float>(0,0), complex<float>(0,0), complex<float>(1,0),
    complex<float>(0,0), complex<float>(0,0), complex<float>(0,0),
    complex<float>(1,0), complex<float>(0,0), complex<float>(0,0);

    lambda.at(4)= complex<float>(0,0), complex<float>(0,0), complex<float>(0,-1),
    complex<float>(0,0), complex<float>(0,0), complex<float>(0,0),
    complex<float>(0,1), complex<float>(0,0), complex<float>(0,0);

    lambda.at(5)= complex<float>(0,0), complex<float>(0,0), complex<float>(0,0),
    complex<float>(0,0), complex<float>(0,0), complex<float>(1,0),
    complex<float>(0,0), complex<float>(1,0), complex<float>(0,0);

    lambda.at(6)= complex<float>(0,0), complex<float>(0,0), complex<float>(0,0),
    complex<float>(0,0), complex<float>(0,0), complex<float>(0,-1),
    complex<float>(0,0), complex<float>(0,1), complex<float>(0,0);

    lambda.at(7)= complex<float>(1/sqrt(3),0), complex<float>(0,0), complex<float>(0,0),
    complex<float>(0,0), complex<float>(1/sqrt(3),0), complex<float>(0,0),
    complex<float>(0,0), complex<float>(0,0), complex<float>(-2/sqrt(3),0);


		Array<complex<float>,2> coef(3,3);
		coef = complex<float>(0.5,0);
		for (int i=0;i<lambda.size();i++) lambda.at(i)*=coef;

return lambda;
}
