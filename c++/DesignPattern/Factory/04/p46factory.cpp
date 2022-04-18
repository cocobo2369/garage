#include <iostream>

using namespace std;

class Text
{
public:
    string printText()
    {
        return "안녕하세요";
    }
};


class Factory
{
public:
    static Text getInstance()
    {
        cout << "팩토리 객체를 생성하여 반환합니다." << endl;
        return Text();
    }
};


class Hello
{
    //class의 멤버로 auto 자료형 사용은 불가능하다.
public :
    string greeting()
    {
        auto h1 = Factory::getInstance();
        return h1.printText();
    }

};



int main()
{
    Hello h1;
    cout << h1.greeting() << endl;

    return 0;
}