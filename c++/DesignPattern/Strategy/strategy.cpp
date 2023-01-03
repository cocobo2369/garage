#include <iostream>
#include <memory>
using namespace std;

class parent{
public:
    parent(){};
    virtual ~parent(){};
    virtual void func()=0;
};

class child1 : public parent{
public:
    child1(){
        cout << "child1 created" << endl;
    }
    void func() override{
        cout <<"child1 func() called" << endl;
    }
};

class child2 : public parent{
public:
    child2(){
        cout << "child2 created" << endl;
    }
    void func() override{
        cout <<"child2 func() called" << endl;
    }
};

class client{
public:
 void contextfunc(){
    P->func();
 }

 void setChild(int type){
    switch(type){
        case 1 :
        P = make_unique<child1>();
        break;
        case 2 :
        P = make_unique<child2>();
        break;
    }
    return;
 }
private:
unique_ptr<parent> P;

};

int main(){
  unique_ptr<client> c = make_unique<client>();
  c->setChild(1);
  c->contextfunc();

  c->setChild(2);
  c->contextfunc();

}