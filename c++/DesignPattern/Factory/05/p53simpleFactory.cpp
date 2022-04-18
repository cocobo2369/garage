#include <iostream>

using namespace std;
class Text{

public:
    virtual string printText(){
        return "꽁";
    }

};

class TextKor : public Text
{
public:
    virtual string printText()
    {
        return "안녕하세요";
    }
};

class TextEng  : public Text
{
public :
    virtual string printText()
    {
        return "Hello~!";
    }
};

class Hello
{
    //class의 멤버로 auto 자료형 사용은 불가능하다.
public :
enum country
{
    KOREAN,
    ENGLISH,
    ETC
};
    string greeting(country type)
    {
        Text * h1 = simpleFactoryFunc(type);
        return h1->printText();
    }

    Text * simpleFactoryFunc(country type){
        if(type == KOREAN){
            cout << "팩토리 객체 KOR를 생성하여 반환합니다." << endl;
            return new TextKor();
        }
        else if(type == ENGLISH){
            cout << "팩토리 객체 ENG를 생성하여 반환합니다." << endl;
            return new TextEng();
        }
        else{
            cout << "팩토리 객체 DEFAULT를 생성하여 반환합니다." << endl;
            return new Text();
        }
    }

};

int main()
{
    Hello h1;
    cout << h1.greeting(Hello::ETC) << endl;
    cout << h1.greeting(Hello::ENGLISH) << endl;
    cout << h1.greeting(Hello::KOREAN) << endl;
    return 0;
}