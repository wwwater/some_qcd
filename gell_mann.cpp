#include <blitz/array.h>
#include <vector>
#include "GM.h"

using namespace blitz;

typedef complex<float> cf;

bool diag_matrix (Array <cf,2> matrix)
{
    for (int i=0; i<matrix.rows(); i++)
    {
        for (int j=0; j<matrix.cols(); j++)
        {
            if (i!=j && matrix(i,j)!=cf(0,0))
            {
                return false;
            }
        }
    }
    return true;
}

cf trace (Array <cf,2> matrix)
{
    complex <float> sum (0,0);
    for (int i=0; i<matrix.rows(); i++) sum+=matrix(i,i);
    return sum;
}

Array <cf,2> mult ( Array<cf,2> a, Array<cf,2> b)
{
    if (a.cols()==b.rows())
    {
        int n=a.rows();
        Array <cf,2> c(a.rows(),b.cols());
        c=cf(0,0);
        for (int i=0; i<a.rows(); i++)
        {
            for (int k=0; k<b.cols(); k++)
            {
                cf sum_p (0,0);
                for (int j=0; j<a.cols(); j++) sum_p+=a(i,j)*b(j,k);
                c(i,k)=sum_p;
            }
        }
        return c;
    }
    else
    {
        Array <cf,2> c(0,0);
        return c;
    }
}

Array <cf,2> make_bc_matrix (vector < Array<cf,2> > lambda)
{
    Array <cf,2> bc_matrix (lambda.size(),lambda.size());
    Array <cf,2> sum_a(3,3);
    for (int b=0; b<lambda.size(); b++)
    {
        for (int c=0; c<lambda.size(); c++)
        {
            sum_a = cf(0,0);
            for (int a=0; a<lambda.size(); a++)
            {
                sum_a+=mult(mult(lambda.at(a),lambda.at(b)),mult(lambda.at(a),lambda.at(c)));
            }
            bc_matrix(b,c)=trace(sum_a);
        }
    }
    return bc_matrix;
}

int main()
{
    vector < Array<cf,2> > lambda = get_lambda();
    Array <cf,2> sum_a (3,3);
    sum_a = cf(0,0);
    for (int i =0; i<lambda.size(); i++)
    {
        cout << lambda.at(i)<<" "<<diag_matrix(lambda.at(i))<<" "<< trace(lambda.at(i))<<endl;
        sum_a+=mult(lambda.at(i),lambda.at(i));
    }
    cout<<trace(sum_a)<<endl;

    Array <complex <float>,2> bc_matrix = make_bc_matrix (lambda);
    cout<<bc_matrix<<" "<<trace(bc_matrix)<<endl;
    return 0;
}
