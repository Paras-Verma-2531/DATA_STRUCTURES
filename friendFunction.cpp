#include <iostream>
using namespace std;
class Y; // forward declaration
class X
{
    int value1;

public:
    void setdata(int x)
    {
        value1 = x;
    }
    void display()
    {
        cout << "the value of data of X class is " << value1<<endl;
    }
    friend void swap(X &, Y &);
};
class Y
{
    int value2;

public:
    void setdata(int x)
    {
        value2 = x;
    }
    void display()
    {
        cout << "the value of data of Y class is " << value2<<endl;
    }
    friend void swap(X &, Y &);
};
void swap(X &ob, Y &ob1)
{
    int temp;
    temp = ob.value1;
    ob.value1 = ob1.value2;
    ob1.value2 = temp;
}
int main()
{
    X ob1;
    Y ob2;
    ob1.setdata(23);
    ob2.setdata(46);
    swap(ob1,ob2);
    ob1.display();
    ob2.display();

    return 0;
}