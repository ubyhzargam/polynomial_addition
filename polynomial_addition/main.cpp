//
//  main.cpp
//  polynomial_addition
//
//  Created by Uby H on 12/07/23.
//

#include <iostream>
using namespace std;
struct term
{
    int coeff,exp;
};
struct poly
{
    int n;
    term *t;
};
int main()
{
    int i=0,j=0,k=0,c=0;
    struct poly p1,p2,p3;
    cout<<"Enter the number of non-zero terms in polynomial 1 : "<<endl;
    cin>>p1.n;
    cout<<"Enter the number of non-zero terns in polynomial 2 : "<<endl;
    cin>>p2.n;
    p1.t=new term[p1.n];
    p2.t=new term[p2.n];
    p3.t=new term[p1.n+p2.n];
    cout<<"Enter the first polynomial exponent and it's coefficients in descending order of it's exponent : "<<endl;
    for(;i<p1.n;i++)
        cin>>p1.t[i].exp>>p1.t[i].coeff;
    i=0;
    cout<<"Enter the second polynomial exponent and it's coefficients in descending order of it's exponent : "<<endl;
    for(;j<p2.n;j++)
        cin>>p2.t[j].exp>>p2.t[j].coeff;
    j=0;
    p3.n=p1.n+p2.n;
    while(i<p1.n&&j<p2.n)
    {
        if(p1.t[i].exp>p2.t[j].exp)
        {
            p3.t[k++]=p1.t[i++];
            c++;
        }
        else if(p1.t[i].exp<p2.t[j].exp)
        {
            p3.t[k++]=p2.t[j++];
            c++;
        }
        else
        {
            p3.t[k].exp=p2.t[j].exp;
            p3.t[k++].coeff=p1.t[i++].coeff+p2.t[j++].coeff;
            c++;
        }
    }
    for(;i<p1.n;i++)
    {
        p3.t[k++]=p1.t[i];
        c++;
    }
    for(;j<p2.n;j++)
    {
        p3.t[k++]=p2.t[j];
        c++;
    }
    cout<<"The first polynomial is given by : "<<endl;
    for(i=0;i<p1.n;i++)
    {
        cout<<"Exponent : "<<p1.t[i].exp<<" Coefficient "<<p1.t[i].coeff<<endl;
    }
    cout<<"The second polynomial is given by : "<<endl;
    for(i=0;i<p2.n;i++)
    {
        cout<<"Exponent : "<<p2.t[i].exp<<" Coefficient "<<p2.t[i].coeff<<endl;
    }
    cout<<"The sum of the two polynomials is given by : "<<endl;
    for(i=0;i<c;i++)
    {
        cout<<"Exponent : "<<p3.t[i].exp<<" Coefficient "<<p3.t[i].coeff<<endl;
    }
    return 0;
}
