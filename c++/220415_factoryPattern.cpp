#include <iostream>
#include <math.h>

using namespace std;


class Point
{
    float x;
    float y;

    //Point내에서 friend로 선언된 class는 protected, private 까지 접근이 가능하다!
    //일종의 whitelist
    friend class PointFactory;

protected :
    Point(const float x, const float y) : x(x),y(y){}

public:
    void printPoint(){
        cout << "x : " << x << endl;
        cout << "y : " << y << endl;
    }
};

class PointFactory
{
public:
    static Point Cartesian(float x, float y)
    {
        return {x,y};
    }

    static Point Polar(float r, float theta)
    {
        return { r*cos(theta), r*sin(theta) };
    }
};

int main()
{
    //생성자가 드러나지 않음, 코드의 가독성도 좋음
    Point p1 = PointFactory::Cartesian(1.3,2.5);
    p1.printPoint();

    auto p2 = PointFactory::Polar(2,0.5);
    p2.printPoint();

    return 0;
}