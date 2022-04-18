#include <iostream>
#include <string>

using namespace std;

class Hello
{
public  :
     string greeting()
    {
        return "안녕하세요?";
    }
};

int main()
{
    Hello h1;
    cout << h1.greeting() << endl;

    return 0;
}