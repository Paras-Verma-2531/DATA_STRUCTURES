#include <iostream>
using namespace std;
class indexoverloading
{
    int a[100];

public:
    void init()
    {
        for (int i = 0; i < 100; i++)
        {
            a[i] = i;
        }
    }
    // int get(int t)
    // {
    //     return a[t];
    // }
    int operator[](int k)
    {
        return a[k];
    }
    
    
};
int main()
{
   
    indexoverloading ob1;
    ob1.init();

    // int k=ob1.get(2);
    int k = ob1[1];
    cout<< k << endl;
    return 0;
}
// a[2]
