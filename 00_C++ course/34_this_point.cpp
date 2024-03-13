// this pointer
//1- this is a keyword.this is local object pointer(local variable) in every
//instance member function containing address of the caller object.
//2- 'this' pointer is not available in static member functions as static member
// functions can be called without any object (with class name).
/*
#include <iostream>
using namespace std;
class A
{
   int a;
   public :
   void getdata(int a)
   {
     a=a; // same name , local variable given more priority so both a are of
          // function getdata(), but we want to in member a, so a will give garbage
          // value as we run program . so to overcome this ...use 'this' pointer

   }
   void showdata()
   {
     cout<<"value of a is : "<<a<<endl;
   }
};
int main ()
{
    A a;//garbage value of our value stored in a of getdata() function
       // both a are different
    a.getdata(5);
    a.showdata();
    return 0 ;
}
*/
// to overcome above problem use this pointer
#include <iostream>
using namespace std;
class A
{
   int a;
   public :
   void getdata(int a)
   {
    this-> a=a; // left a is of object  , not a of getdata() function

   }
   void showdata()
   {
     cout<<"value of a is : "<<a<<endl;
   }
};
int main ()
{
    // method 1
    A a1,a2;
    a1.getdata(5);
    a1.showdata();
    //method 2
    A *p= &a2;
    p->getdata(10);
    p->showdata();
    // method 3
    A *q = new A ;
    q->getdata(15);
    q->showdata();
    return 0 ;
}
