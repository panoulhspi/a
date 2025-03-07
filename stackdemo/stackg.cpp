#include <iostream>

using namespace std;

template <typename T>

class stack {
    public:
    stack(int size) {a=new T[size]; top=0; max=size;}
    stack (const stack &s) {
        a=new T[s.max];
        max=s.max;
        top=0;
        for (int i=0; i<s.top; ++i) a[i]=s.a[i];
        top=s.top;
    }
    ~stack() { delete []a;}
    const stack & operator = (const stack &s) {
        delete []a;
        a=new T[s.max];
        max=s.max;
        for (int i=0; i<s.top; ++i) a[i]=s.a[i];
        top=s.top;
        return *this;
    }
    bool empty (){
        return top==0;
    }
    void push (const T &x) {
        a[top++]=x;
    }
    T pop() {
        return a[--top];
    }
    int size() {return top;}

    friend ostream & operator << (ostream &out, const stack &s) {
        out << "[";
        for (int i=0; i<s.top-1; ++i) out<<s.a[i]<<", ";
        if (s.top>0) out<<s.a[s.top-1];
        out << "]";
        return out;
    }
   
    private:
    int top;
    int max;
    T *a;
};
