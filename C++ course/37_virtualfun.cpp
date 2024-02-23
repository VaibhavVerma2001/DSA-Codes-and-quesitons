//pointer of base class can store address of obj of derived class.
//but converse is not true
/*
#include <iostream>
using namespace std;
class base
{
    public :
    void fun(){
      cout<<"hello"<<endl;
    }  
};
class derived : public base
{
    public :
    void fun(){
      cout<<"how are you"<<endl;
    }
};
int main ()
{
    base *p,objbase;
    derived objder;
    objbase.fun();//base class
    objder.fun();//derived class
    p = &objder;
    p->fun();//early binding (type of pointer matters), hence base class
    return 0 ;
}
*/
// to solve above problem we use virtual for late binding
// then pointer address will matter not data type
/*
#include <iostream>
using namespace std;
class base
{
public:
  virtual void fun()
  {
    cout << "hello" << endl;
  }
};
class derived : public base
{
public:
  void fun()
  {
    cout << "how are you" << endl;
  }
};
int main()
{
  base *p, objbase;
  derived objder;
  objbase.fun(); //base class
  objder.fun();  //derived class
  p = &objder;
  p->fun();      //late binding (address of pointer matters), hence derived class
  return 0;
}
*/
/*
#include <iostream>
using namespace std;
class base
{
public:
  int var_base;

  void display()
  {
    cout << "value of base class variable is : " << var_base << endl;
  }
};
class derived : public base
{
public:
  int derived_var;

  void display()
  {
    cout << "value of base class variable is : " << var_base << endl;
    cout << "value of derived class variable is : " << derived_var << endl;
  }
};
int main()
{
    
    return 0;
}
*/
// by making function virual compiler create a pointer inside class which stores
// address of array (which contain address of virtual function)
// ex-1 ) no virual fun , so size will be 1 byte (empty class has 1 byte size)
/*
#include<iostream>
using namespace std;
class A
{
   public :
    void f1() {}
    void f2() {}
    void f3() {}
    void f4() {}
};
class B
{
   public :
   void f1() {}
   void f2() {}
   void f4(int x) {}
};
int main ()
{
  A a1;
  B b1;
  cout<<sizeof(a1)<<endl; // 1 byte ,that is ssize of empty class
  cout<<sizeof(b1);// 1 byte ,that is ssize of empty class
  return 0;
}
*/
// ex-2 ) virual fun , so size will be 4 byte (as pointer will be created)
#include<iostream>
using namespace std;
class A
{
   public :
   void f1() {}
   virtual void f2() {}
   virtual void f3() {}
   virtual void f4() {}
};
class B : public A
{
   public :
   void f1() {}
   void f2() {}
   void f4(int x) {}
};
int main ()
{
  A a1;
  B b1;
  cout<<sizeof(a1)<<endl;//4 byte,pointer created by compiler bec of virtual fun
  cout<<sizeof(b1);// 4 byte ,it will inherit pointer of base class
  return 0 ;
}
