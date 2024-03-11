#include <iostream>
#include <string>

using namespace std;

struct Point
{
    double x;
    double y;
};

struct Rect
{
    double x;
    double y;
    double w;
    double h;

    bool Contains(const Point &p) const
    {
        return (p.x >= x && p.x <= (x + w) && p.y <= y && p.y >= (y - h));
    }
};

struct Ship
{
    Rect rect;
    string id;
    double dx;
    double dy;

    void move()
    {
        rect.x += dx;
        rect.y += dy;
    }
};

void Display(const Ship &ship)
{
    cout << "Ship ID: " << ship.id << endl;
    cout << "Ship position: " << "(" << ship.rect.x << ", " << ship.rect.y << ")" << endl;
}

int main()
{
    Ship ship1 = {{10, 20, 30, 40}, "UET" , 2, 5};
    Ship ship2 = {{1, 3, 5, 7}, "UETE" , 6, 9};
    int loop = 0;
    while (loop < 10)
    {
        ship1.move();
        Display(ship1);
        ship2.move();
        Display(ship2);
        ++loop;
    }
    return 0;
}
