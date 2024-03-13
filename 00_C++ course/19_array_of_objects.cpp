//array of objects and passing objects as function
// example 1 --> array of objects
/*
#include <iostream>
using namespace std;
class employee {
    int id;
    float salary;
    public:
    void getinfo()
    {
      cout<<"enter id "<<endl;
      cin>>id;
      cout<<"enter salary "<<endl;
      cin>>salary;
    }
    void showinfo()
    {
      cout<<"the id is :"<<id<<endl;
      cout<<"the salary is :"<<salary<<endl;
    }
};
int main()
{
    employee e[3];
    for (int i = 0; i <3; i++) {
      cout<<"enter details of "<<i+1<<" employee"<<endl;
      e[i].getinfo();
    }
    for (int i = 0; i <3; i++) {
      cout<<"details of "<<i+1<<" employee are "<<endl;
      e[i].showinfo();
    }
    return 0;
}
*/
// example 2--> passing objects as functions
/*
#include <iostream>
using namespace std;
class complex{
 int a,b;
public:
  void getnumber(int x, int y)
  {
    a=x,b=y;
  }
  void displaynumber()
  {
    cout<<"complex no. is "<<a<<" + "<<b<<"i"<<endl;
  }
  void sum (complex u, complex v)//passing objects as function
  {
    cout<<"sum :"<<endl;
    a=u.a+v.a;
    b=u.b+v.b;
  }
};
int main() {
  complex c1,c2,c3;
  c1.getnumber(3,4);
  c1.displaynumber();
  c2.getnumber(4,5);
  c2.displaynumber();
  c3.sum(c1,c2);
  c3.displaynumber();
  return 0;
}
*/
// same previous program to take info from user

#include <iostream>
using namespace std;
class complex{
 int a,b;
public:
  void getnumber()
  {
    cout<<"enter values of a and b"<<endl;
    cin>>a>>b;
  }
  void displaynumber()
  {
    cout<<"complex no. is "<<a<<" + "<<b<<"i"<<endl;
  }
  void sum (complex u, complex v)//passing objects as function
  {
    cout<<"sum :"<<endl;
    a=u.a+v.a;
    b=u.b+v.b;
  }
};
int main() {
  complex c1,c2,c3;
  c1.getnumber();
  c1.displaynumber();
  c2.getnumber();
  c2.displaynumber();
  c3.sum(c1,c2);
  c3.displaynumber();
  return 0;
}
