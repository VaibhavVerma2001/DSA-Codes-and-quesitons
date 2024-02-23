//constructor overloading-->if class has multiple constructor then that
//constructor will run which has same no. of arguments as objects
/*
#include <iostream>
using namespace std;
class complex
{
   int a,b;
   public :
   complex (int x, int y)// taking 2 arguments
   {
     a=x,b=y;
   }
   complex (int x) //taking 1 argument
   {
     a=x;
     b=0;//if we dont do b=0 then b will have garbage value
   }
   complex ()//default constructor as it has 0 argument
   {
     a=0,b=0;
   }
   void shownumber()
   {
     cout<<"your complex no. is : "<<a<<" + "<<b<<" i"<<endl;
   }
};
  int main()
  {
    complex c1(1,2);
    c1.shownumber();
    complex c2(5);
    c2.shownumber();
    complex c3;
    c3.shownumber();
    return 0;
  }
  */
// constructors with default arguments
// #include <iostream>
// using namespace std;
// class complex
// {
//    int a,b;
//    public :
//    complex (int x, int y=10)// by default b will be 10
//    {
//      a=x,b=y;
//    }
//    void showdata()
//    {
//      cout<<"your complex no. is : "<<a<<" + "<<b<<" i "<<endl;
//    }
// };
// int main(int argc, char const *argv[]) {
//     complex c1(1);//passing only one argument so by default b=10
//     c1.showdata();
//     complex c2(1,4);//passing 2 arguments ,now b=4(overwrites b=10)
//     c2.showdata();
//     return 0;
// }
//initializer -> we can also initialize constructor using initializer
/*
#include<iostream>
using namespace std;

class Point{
private:
int x,y;
public:
Point(int i=0,int j=0):x(i),y(j){}; // initializer

void showData(){
cout<<x<<" "<<y;

}
};

int main(){
Point t1(10,15);
t1.showData();
}
*/
// In the above code, x and y can also be easily initialed inside the constructor. But there are situations where initialization of data members inside constructor doesn’t work and Initializer List must be used. Following are such cases:


// 1) For initialization of non-static const data members

// 2) For initialization of reference members

