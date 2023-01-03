#include <iostream>
#include <memory>

using namespace std;

class abstractclass{
public:
    abstractclass(){}
    virtual ~abstractclass(){
        cout <<"abstract end ===========" << endl;
    }
    void templateMethod(){
        hook1();
        general();
        hook2();
    }

private:
    void general(){
        cout << "general()" << endl;
    };
    virtual void hook1()=0;
    virtual void hook2()=0;
};

class concrete1 : public abstractclass{
public:
    concrete1(){
        cout <<"start concrete1 ===========" << endl;
    }
    ~concrete1(){
        cout <<"end concrete1 ===========" << endl;
    }
private:
    void hook1() override{
        cout << "concrete1 hook1()" << endl; 
    }
    void hook2() override{
        cout << "concrete2 hook2()" << endl;
    }
};


class concrete2 : public abstractclass{
public:
    concrete2(){
        cout <<"start concrete2 ===========" << endl;
    }
    ~concrete2(){
        cout <<"end concrete2 ===========" << endl;
    }
private:
    void hook1() override{
        cout << "concrete2 hook1()" << endl; 
    }
    void hook2() override{
        cout << "concrete2 hook2()" << endl;
    }
};


int main(){

   cout << "template method is forced in complie time" << endl;

   // wrong : unique_ptr<abstractclass> A = make_unique<abstractclass>();
   //순수가상함수를 만들어버려서 컴파일 시 에러가 발생하도록 하는 것도 방법이다.
   unique_ptr<abstractclass> A1 = make_unique<concrete1>();
   A1->templateMethod();
   A1.reset();
   unique_ptr<abstractclass> A2 = make_unique<concrete2>();
   A2->templateMethod();
   A2.reset();
}
