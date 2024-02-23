#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
    int a=5,*p,**q;
    p=&a;
    q=&p;
    cout<<p<<endl;//both gives add of a
    cout<<&a<<endl;//both gives add of a
    cout<<q<<endl;
    cout<<*p<<endl;//both gives value of a
    cout<<a<<endl;//both gives value of a
    cout<<**q<<endl;//both gives value of a

    return 0;
}
