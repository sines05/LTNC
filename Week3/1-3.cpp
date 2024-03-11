#include <iostream>

using namespace std;

struct Point {
    double x;
    double y;
};

void Print(Point point)
{
    cout << "(" << point.x << ", " << point.y << ")";
}

void PassByValue(Point point)
{
    point = {10, 20};
}

void PassByReference(Point &point)
{
    point = {10, 20};
}

Point mid_point(const Point &p1, const Point &p2)
{
    Point mid;
    mid.x = (p1.x + p2.x) / 2;
    mid.y = (p1.y + p2.y) / 2;

    return mid;
}


int main()
{
    Point myPoint = {20, 3};

    PassByValue(myPoint);
    Print(myPoint);
    cout << endl;
    PassByReference(myPoint);
    Print(myPoint);
    cout << endl;


    Point p1 = {5, 9};
    Point p2 = {10, 8};
    Point mid = mid_point(p1, p2);
    cout << "(" << mid.x << ", " << mid.y << ")";
}
