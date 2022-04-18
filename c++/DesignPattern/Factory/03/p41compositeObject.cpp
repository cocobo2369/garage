#include <iostream>
#include <string>

using namespace std;

class Text
{
public:
    string printText()
    {
        return "안녕하세요";
    }
};

class Hello
{
private:
    Text text;
public  :
    Hello(Text& text):text(text){}

     string greeting()
    {
        return text.printText();
    }
};



int main()
{
    Text text;
    Hello h1(text);
    cout << h1.greeting() << endl;

    return 0;
}