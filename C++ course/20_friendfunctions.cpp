// friend function example 1
/*
#include <iostream>
using namespace std;
class complex
{
    private :
    int a,b;
    public :
    void setdata(int x, int y)
    {
      a=x,b=y;
    }
    void showdata()
    {
      cout<<"value of a is "<<a<<" value of b is "<<b<<endl;
    }
    friend void fun(complex);//must be declared within class
};
    void fun(complex c)//passing objects as function
                      // dont use :: in defining  friend functions
    {
      cout<<"sum of a and b is "<<c.a+c.b<<endl;//in friend function we
                              // cant use a & b directly so use object dots
    }
  int main() {
    class complex c1,c2,c3;
    c1.setdata(3,4);
    c1.showdata();
    fun(c1);//dont write it as c1.fun(c1) bec it is not member function
            // must write name of object so that compiler know,
            //which object we are passing to function ,like c1,c2 or c3
    return 0;
  }
*/
//friend class--> accessing private data of class with the function,
//of other class (declaring that functions as friend)
/*
#include <iostream>
using namespace std;
class complex;
class calculator
{
 public :
  int sumRealcomplex(complex , complex );//in declaration we only write
                                       //data type
};

class complex
{
   int a,b;
   friend int calculator :: sumRealcomplex(complex , complex );
public :
  void getnumber(int x,int y)
  {
    a=x,b=y;
  }
  void shownumber()
  {
    cout<<"your number is "<<a<<" + "<<b<<" i "<<endl;
  }
};
  int calculator :: sumRealcomplex(complex u, complex v)
  {
    return (u.a + v.a);
  }
int main()
{
  complex u,v;
  u.getnumber(1,4);
  v.getnumber(5,7);
  calculator calc;
  int res=calc.sumRealcomplex(u,v);
  cout<<"the sum of real part of u and v is : "<<res<<endl;
  return 0;
}
*/
//ex 3 --> making whole class as friend

#include <iostream>
using namespace std;
class complex;
class calculator
{
 public :
  int sumRealcomplex(complex , complex );//in declaration we only write
                                       //data type
  int sumComcomplex(complex , complex );
};

class complex
{
   int a,b;
//friend int calculator :: sumRealcomplex(complex , complex );//declared
//friend int calculator :: sumComcomplex(complex , complex );//seperately
// aliter --> declare whole class as friend
friend class calculator;//declared whole calculator class as friend
public :
  void getnumber(int x,int y)
  {
    a=x,b=y;
  }
  void shownumber()
  {
    cout<<"your number is "<<a<<" + "<<b<<" i "<<endl;
  }
};
  int calculator :: sumRealcomplex(complex u, complex v)
  {
    return (u.a + v.a);
  }
  int calculator :: sumComcomplex(complex u, complex v)
  {
    return (u.b + v.b);
  }
int main()
{
  complex u,v;
  u.getnumber(1,4);
  v.getnumber(5,7);
  calculator calc;
  int res=calc.sumRealcomplex(u,v);
  cout<<"the sum of real part of u and v is : "<<res<<endl;
  int com=calc.sumComcomplex(u,v);
  cout<<"the sum of complex part of u and v is : "<<com<<endl;
  return 0;
}
