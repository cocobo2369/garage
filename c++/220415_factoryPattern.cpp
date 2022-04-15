#include <iostream>
#include <math.h>

using namespace std;

class Point{
    float x;
    float y;
public :
    Point(const float x, const float y) : x(x),y(y){}
/*
    Point(const float r, const float theta){
        x = r*cos(theta);
        y = r*sin(theta);
    }
error: ‘Point::Point(float, float)’ cannot be overloaded with ‘Point::Point(float, float)’
   11 |     Point(const float r, const float theta){
      |     ^~~~~
note: previous declaration ‘Point::Point(float, float)’
   10 |     Point(const float x, const float y) : x(x),y(y){}
      |     ^~~~~
*/
    void printPoint(){
        cout << "x : " << x << endl;
        cout << "y : " << y << endl;
    }
};

int main(){

    Point p(1.2,2.0);
    p.printPoint();

    return 0;
}