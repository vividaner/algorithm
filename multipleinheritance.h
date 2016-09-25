//
//  multipleinheritance.h
//  algorithm
//
//  Created by DanMiao on 9/16/16.
//  Copyright © 2016 DanMiao. All rights reserved.
//

#ifndef multipleinheritance_h
#define multipleinheritance_h
using namespace std;

class A
{
    int x;
public:
    void setX(int i) {x = i;}
    void print() { cout << x; }
};

class B:  virtual public A
{
public:
    B()  { setX(10); }
};


class C:  virtual public A
{
public:
    C()  { setX(20); }
};

class D: public C, public B {
};

class E
{
    E() {}
    ~E() {
        throw 32;
    }
};

class F
{
    virtual void f();
};

class Size
{
private:
    int* d;
    void f(){cout << endl;}
};




#endif /* multipleinheritance_h */
