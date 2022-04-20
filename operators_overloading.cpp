# include <iostream>
using namespace std;
class complex 
{
    public:
    int real,image;
    void display();
    complex operator+(complex c)
{
    complex t;
    t.real=real+c.real;
    t.image=image+c.image;
    return t;
}
};

void complex:: display()
{
    cout<<"the real part is "<<real <<" and  the imaginary part is "<<image<<endl;
}

int main() {
    complex c1,c2,c3;
    c1.real=4;
    c1.image=5;
    c2.real=5;
    c2.image=49;
    c3=c1+c2;// overloading concept
    // c3=c1.add(c2)// c3=c1.operator+(c2);
    c3.display();
    
 return 0 ;
}