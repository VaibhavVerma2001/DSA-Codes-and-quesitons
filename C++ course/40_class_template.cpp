// 2 -> class template(with the hrlp of templates we dont need to make many classes for diff. - diff. datatypes)
//example 1
/*
#include<iostream>
using namespace std;
template <class X>
class sum
{
   private :
   X a,b;
   public :
   void getdata(X x , X y)
   {
       a=x,b=y;
   }
   X add()
   {
     return (a+b);
   }
};
int main ()
{
    sum <int> s1;
    s1.getdata(2,4);
    cout<<s1.add()<<endl;
    sum <float> s2 ;
    s2.getdata(5.2 , 4.5);
    cout<<s2.add()<<endl;
    sum <char> s3;
    s3.getdata('2','3'); //will sum up ascii values
    cout<<s3.add();
    return 0 ;
}
*/
//class templates with multiple parameters
//ex-1
/*
#include<iostream>
using namespace std;
template <class T1, class T2>
class myclass
{
   T1 data1;
   T2 data2;
   public:
   myclass(T1 x , T2 y)
   {
     data1 = x , data2 = y;
   }
   void display ()
   {
     cout<<"data1 : "<<data1<<" "<<"data2 : "<<data2<<endl;
   }
};
int main()
{
    myclass <int , int > obj1 (2,3);
    obj1.display();
    myclass<int , float> obj2 (5,5.5);
    obj2.display();
    myclass <int , char> obj3 (5 ,'d');
    obj3.display();
    return 0;
}
*/
//ex -> 2 class with multiple parameters
/*
#include <iostream>
using namespace std;
template <class X, class Y>
class sum
{
  X a;
  Y b;

public:
  void getdata(X x, Y y)
  {
    a = x, b = y;
  }
  void add()
  {
    cout << "sum is : " << (a + b) << endl;
  }
};
int main()
{
  sum<int, int> s1;
  s1.getdata(1, 3);
  s1.add();
  sum<int, float> s2;
  s2.getdata(5, 5.5);
  s2.add();
  sum<int, char> s3;
  s3.getdata(2, 'c'); //ascii value of c is 99 (99+2=101)
  s3.add();
  return 0;
}
*/
//TEMPLATES WITH DEFAULT PARAMETER
// we can define datatype by default also then we can overwrite them
#include <iostream>
using namespace std;
template <class T1 = int, class T2 = float, class T3 = char>
class value
{
  T1 a;
  T2 b;
  T3 c;
  public:
  value (T1 x, T2 y ,T3 z)
  {
    a=x, b= y, c=z;
  }
  void display()
  {
    cout<<"value of a is :"<<a<<endl;
    cout<<"value of b is :"<<b<<endl;
    cout<<"value of c is :"<<c<<endl;
  }
};
int main ()
{
    value <> v1(4,4.5,'d');//default parameters <> (empty)
    v1.display();
    cout<<endl;
    value <char , int , float> v2('e',6,7.8);//now we overwriten datatypes
    v2.display();
    return 0 ;
}