// destructor in c++ ->1 Destructors (C++ only) Destructors are usually used to deallocate memory and do other cleanup for a class object and its class members when the object is destroyed. A destructor is called for a class object when that object passes out of scope or is explicitly deleted.
//2- name is same as class with ~ at the begining
//3- it takes no argument , i.e; no overloading is possible
//4- it can never be static and cant have more than one destructor in a class.

//eg-1
/*
#include<iostream>
using namespace std ;
class complex 
{
    int a , b ;
    public :
    complex(int x , int y)
    {
       a=x,b=y;
       cout<<"constructor is called : "<<endl;
       cout<<"complex no. is : "<<a<<" + "<<b<<" i "<<endl;
    }
    ~complex()
    {
        cout<<"destructor is called "<<endl;
    }

};
int main ()
{
    complex c1(3,4);
    
    return 0;
}
*/
//eg-2 -> first constructor is called for last object then secnd last , and so on ...

#include <iostream>
using namespace std;

class A
{
    int id;
    static int count  ;

public:
    A()
    {
        count++;
        id = count;
        cout << "constructor for id " << id << endl;
    }
    ~A()
    {
        cout << "destructor for id " << id << endl;
    }
};

    int A :: count = 0;
int main()
{
    A a[3];
    return 0;
}



