#include <iostream>
#ifndef CONTEST
#include "fullratio.hpp"
#endif

using namespace std;

rational::rational (int n,int d) {
    nom=n;
    den=d;
}
int rational::gcd (int a,int b){
    a=abs(a);
    b=abs(b);
    while (a>0 && b>0){
    if (a>b) a%=b;
    else b%=a;
    }
    return a+b;
}
rational operator + (const rational &x, const rational &y) {
    int resn=x.nom*y.den+y.nom*x.den;
    int resd=x.den*y.den;
    return rational(resn,resd);
}

rational operator - (const rational &x, const rational &y) {
    int resn=x.nom*y.den-y.nom*x.den;
    int resd=x.den*y.den;
    return rational(resn,resd);
}

rational operator * (const rational &x, const rational &y) {
    int resn=x.nom*y.nom;
    int resd=x.den*y.den;
    return rational(resn,resd);
}

rational operator / (const rational &x, const rational &y) {
    int resn=x.nom*y.den;
    int resd=x.den*y.nom;
    return rational(resn,resd);
}

 std::ostream & operator << (std::ostream &out, const rational &x){
    int resn=x.nom;
    int resd=x.den;
    int mkd=rational::gcd(resn,resd);
    resn/=mkd;
    resd/=mkd;
    if (resn>0 && resd<0 || resn<0 && resd>0) {
        resn=-abs(resn);
        resd=abs(resd);
    }
    else {
        resn=abs(resn);
        resd=abs(resd);
    }
out << resn<<"/"<<resd;
return out;
}

