#include "common.h"

class A{
    // 外部不可见
    static const int a;    
};
const int A::a = 1;

class B{
    // 外部不可见
    static const int b = 2;
};
const int B::b;


class C{
    // 外部不可见
    enum {c = 3};
    int d[c];
};

inline int max(int x, int y);

int main(){
    A a1;
    B b1;
    C c1;
    const int f = 6;
    const int* const e = &f;
    cout << *e << endl;
}

inline int max(int x, int y){
    return x > y ? x : y;
}