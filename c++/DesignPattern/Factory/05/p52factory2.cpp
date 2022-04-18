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

class Factory
{

public:
enum country
{
    KOREAN,
    ENGLISH,
    ETC
};
    static Text * getInstance(country type)
    {
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


class Hello
{
    //class의 멤버로 auto 자료형 사용은 불가능하다.
public :
    string greeting(Factory::country type)
    {
        Text * h1 = Factory::getInstance(type);
        return h1->printText();
    }

};

int main()
{
    Hello h1;
    cout << h1.greeting(Factory::ENGLISH) << endl;
    cout << h1.greeting(Factory::KOREAN) << endl;
    cout << h1.greeting(Factory::ETC) << endl;
    return 0;
}