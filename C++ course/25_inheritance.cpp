//single inheritance
/*
#include <iostream>
using namespace std;
class A
{
  int a;
public:
  void fun()
  {
    cout<<"class A ";
  }
};
class B: public A
{
};
int main(int argc, char const *argv[]) {
    B b;
    b.fun();
    return 0;
}
*/
//multi level inheritance
/*
#include <iostream>
using namespace std;
class A
{
   public :
  void Afun()
   {
     cout<<"class A"<<endl;
   }
};
class B : public A //A INHERITED BY B
{
  public:
  void  Bfun ()
    {
      cout<<"class B"<<endl;
    }
};
class C : public B // NOW B INHERITED BY C
{
  public :
void  Cfun()
  {
    cout<<"class C"<<endl;
  }
};
int main()
{
    C c;
    c.Afun(); //C has access to public members of both class A and B
    c.Bfun();
    c.Cfun();
    return 0;
}
*/
// miltiple inheritance
/*
#include <iostream>
using namespace std;
class A
{
   public :
   void Afun()
   {
     cout<<"class A"<<endl;
   }
};
class B
{
  public :
  void Bfun()
  {
    cout<<"class B"<<endl;
  }
};
class C: public A,public B
{
  public:
  void Cfun()
  {
    cout<<"class C"<<endl;
  }
};
int main()
{
    C c ;
    c.Afun();
    c.Bfun();
    c.Cfun();
    return 0;
}
*/
//EXAMPLE ->single inheritance
#include <iostream>
using namespace std;
class base
{
  int data1;
  public :
  int data2;
  void setdata();
  int showdata1();
  int showdata2();
};
void base :: setdata()
{
  data1=10;
  data2=20;
}
int base :: showdata1()
{
  return data1;
}
int base :: showdata2()
{
  return data2;
}
class derived : public base
{
  public :
  int data3;
  void process();
  void display();
};
void derived :: process()
{
  data3 = showdata1()*data2;//cant write data1 directly bec data1 is private
}                      //in base class so it cant be inherited in derived class
void derived :: display()
{
  cout<<"data 1 is :"<<showdata1()<<endl;//cant write data1 directly bec data1 is private
  cout<<"data 2 is :"<<data2<<endl;
  cout<<"data 3 is :"<<data3<<endl;
}
int main()
{
    class derived der;
    der.setdata();
    der.process();
    der.display();
    return 0;
}
