#include <iostream>
using namespace std;
class distance
{
    int kilo, meter;

public:
    distance()
    {
        kilo = 0;
        meter = 0;
    }
    distance(int x, int y)
    {
        kilo = x;
        meter = y;
    }
    void displayadd()
    {
        cout << kilo " kilometers " << meter << " meters " << endl;
    }
    distance operator+(distance ob);
    // distance operator-(distance ob1);
};
distance distance::operator+(distance ob)
{
    distance t;
    t.kilo = kilo + ob.kilo;
    t.meter = meter + ob.meter;
    if (t.meter >= 1000)
    {
        t.kilo = t.kilo + 1;
        t.meter = t.meter - 1000;
        return t;
    }
    else
    {
        return t;
    }
}
int main()
{
    distance d1;
    distance d2(2,500);

    return 0;
}