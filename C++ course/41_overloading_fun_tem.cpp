// if we want to define class function outside class then ->
/*
#include <iostream>
using namespace std;
template <class X>
class base
{
private:
    X a;

public:
    void getadata(X x)
    {
        a = x;
    }
    void display();
};

template <class X>
void base<X>::display()
{
    cout << "value of a is : " << a << endl;
}
int main()
{
    base<int> b1;
    b1.getadata(5);
    b1.display();
    return 0;
}
*/
// overloading function templates (exact function will be given more priority)

#include <iostream>
using namespace std;
void fun(int a)
{
    cout << "exact function , a = " << a << endl;
}
template <class X>
void fun(X a)
{
    cout << "function template , a= " << a << endl;
}

int main()
{
    fun(4);   // exact funtion given more priority
    fun(5.5); // template function because datatype of argument is diff. now
    fun('c'); // template function because datatype of argument is diff. now
    return 0;
}