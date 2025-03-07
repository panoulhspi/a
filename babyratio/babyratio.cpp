#ifndef CONTEST
#include "babyratio.hpp"
#include <iostream>
#endif
using namespace std;

rational::rational (int n,int d) {
    nom = n;
    den = d;
}
int rational::gcd(int a,int b) {
    a=abs(a);
    b=abs(b);
    while (a>0 && b>0){
        if (a>b) a%=b;
        else b%=a;
    }
    return a+b;
}
rational rational::add (rational r) {
int resnom=nom*r.den+r.nom*den;
int resden=den*r.den;
return rational(resnom,resden);
}

rational rational::sub(rational r) {
int resnom=nom*r.den-r.nom*den;
int resden=den*r.den;
return rational(resnom,resden);
}

rational rational::mul(rational r) {
int resnom=nom*r.nom;
int resden=den*r.den;
return rational(resnom,resden);
}

rational rational::div(rational r) {
int resnom=nom*r.den;
int resden=den*r.nom;

return rational(resnom,resden);
}

void rational::print() {
    int resnom=nom;
    int resden=den;
    int mkd=gcd(resnom,resden);
    resnom/=mkd;
    resden/=mkd;
    if (resnom>0 && resden<0 || resnom<0 && resden>0) {
        resnom=-abs(resnom);
        resden=abs(resden);
    }
    else {
        resnom=abs(resnom);
        resden=abs(resden);
    }
    cout<<resnom<<"/"<<resden;
}