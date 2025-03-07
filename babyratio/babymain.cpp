#include <iostream>
#include "babyratio.hpp"

using namespace std;

int main() {
    rational a(2,-4);
    rational b(-8,-16);
    a.mul(b).print();
    cout<<endl;
    a.print();
    b.print();

}