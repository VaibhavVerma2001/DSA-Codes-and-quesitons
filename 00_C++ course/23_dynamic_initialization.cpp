//constructor will run acc to type of data given by user(ex-float or int)
// ex--> SI PROBLEM
/*
#include <iostream>
using namespace std;
class bank
{
  int p;
  float r;
  int t;
  float si;
  float amount;
  public :
  bank (int x, int y, int z)//roi in int (perecenatage) like 4% ,10% etc
  {
  p=x,r=y,t=z;
  si=float(p*r*t)/100;
  amount = si+p;
  }
  bank (int x,float y, int z)//roi in float (fraction) like0.04,0.10 etc
  {
    p=x,r=y,t=z;
    si=(p*r*t);
    amount = si+p;
  }
  void showdata()
  {
    cout <<" SI is :"<<si<<endl;
    cout<<"total amount is :"<<amount<<endl;
  }
};
int main()
{
    bank b1(100,4,1);//compiler will run int r constructor itself
    b1.showdata();
    bank b2(100,.05f,1);//compiler will learn float r constructor itself
    b2.showdata(); // if we write 0.05 only it will give error(float to double)
                  //bec compiler will take it as double by default
    return 0;
}
*/
//copy constructor
//NOTE --> compiler has its own copy constructor so if we dont make a
//copy constructor then compiler will use its copy constructor
#include <iostream>
using namespace std;
class number
{
   int a;
   public :
   number (){//default constructor
     a=0;
   }
   number (int x)
   {
     a=x;
   }
   void display()
   {
     cout<<"the no. is :"<<a<<endl;
   }
 number (number &v)// passing object as function
 {
     cout<<"copy constructor called"<<endl;
     a=v.a;
   }
};
int main()
{
    number x,y,z(45);// if we not made default constructorthen x&y gives error
    x.display();     // bec we not passed any argument to x & y
    y.display();
    z.display();
// let make a copy constructor u which resembles like z (or x or y)
    number u(z);//copying z,copy constructor called
    u.display();//45 printed as z=45
    number z1;//copied at different time of creating object so
    //default cons will be called  
    z1=z;
    z1.display();
    number z2=z;//copied in same line of creating object so our copy con invoked
    z2.display();
    return 0;
}
