// 1- b) operator overloading
//Operator overloading is a compile-time polymorphism in which the operator is
//overloaded to provide the special meaning to the user-defined data type.
//Operator overloading is used to overload or redefines most of the operators
//available in C++. It is used to perform the operation on the user-defined
//data type.
// a) binary operator overloading -> only 1 argument
/*
#include <iostream>
using namespace std;
class complex
{
   int a,b;
   public :
   void setdata(int x , int y){
     a=x ,b=y;
   }
   void showdata(){
     cout<<"complex no. is : "<<a <<" + "<<b<<" i "<<endl;
   }
complex operator +(complex u )//can give only 1 argu. in binary ope. overloading
  {
    complex temp;
    temp.a = a+ u.a;
    temp.b = b+ u.b;
    return temp;
  }
};
int main ()
{
   complex c1,c2,c3;
   c1.setdata(1,2);
   c2.setdata(2,3);
  c3=c1+c2; // OR
  //c3=c1.operator+(c2);
   c3.showdata();
   return 0 ;
}
*/
// b ) unary operator overloading-> no argument
/*
#include <iostream>
using namespace std;
class complex
{
  int a,b;
  public :
  void setdata(int x , int y )
  {
    a=x, b=y;
  }
  void showdata()
  {
    cout<<"complex no. is : "<<a <<" + "<<b<<" i "<<endl;
  }
  complex operator-()
  {
    complex temp ;
    temp.a= -a;
    temp.b= -b;
    return temp;
  }
};
int main(int argc, char const *argv[]) {
    complex c1,c2;
    c1.setdata(3,4);
    //  c2 = c1.operator-();
    //OR
    c2= -c1; // c1 is calling object and value store in  c2
    c2.showdata();
    return 0;
}
*/
// overloading pre increament
/*
#include <iostream>
using namespace std;
class Integer
{
  int a ;
  public :
  void setdata(int x){
    a=x;
  }
  void showdata(){
    cout<<"value of a is : "<<a<<endl;
  }
  Integer operator++(){
    Integer i;
    i.a = ++a;
    return (i);
  }
};
int main()
{
    Integer i1,i2;
    i1.setdata(3);
    i1.showdata();// 3 printed
    //i2=i1.operator++(); //or
    i2= ++i1;// first i1 increament then assignesd in i2
    i2.showdata();// i2 becomes 4 now
    return 0;
}
*/

/*
//overloading post increament

#include <iostream>
using namespace std;
class Integer
{
  int a;

public:
  void setdata(int x)
  {
    a = x;
  }
  void showdata()
  {
    cout << "value of a is : " << a << endl;
  }
  Integer operator++(int)
  { // in post inc. we have to write int otherwise
    // compiler will not differentiate btw post and pre increament
    Integer i;
    i.a = a++;
    return (i);
  }
};
int main()
{
  Integer i1, i2;
  i1.setdata(3);
  i1.showdata(); // 3 printed
                 // i2=i1.operator++(3 or any int value doesnt matter); //or
  i2 = i1++;     // first i1 assignesd in i2 , then increament
  i1.showdata(); // 4 printed
  i2.showdata(); // i2 becomes 3 now
  return 0;
}
*/


//  Write a C++ program to find the which date is greater than given date (Assume the 2 dates in one 
// single year only, consider leap year also as an input).
// a. Define a class called day with members as date, month and year.
// b. Define a parameterized constructor to initialize the dates.
// c. Overload > operator using member function to check if date1 > date2.
// d. Write a show_date function to show the date in dd : mm : yyyy format.
// Output expected :
// Enter date 1 :
// The date = 23
// month = 05
// year = 2019
// Enter date 2 :
// The date = 02
// month = 02
// year = 2019
// ********** First Date **********
// Date is 23 : 5 : 2019
// ********** Second Date **********
// Date is 2 : 2 : 2019
// ********** Result **********
// Date 23:05:2019 is greater than 02:02:2019

#include<iostream>
using namespace std ;
class day
{
    private :
    int date , month , year;
    public :
    day (int x , int y , int z)
    {
        date = x;
        month =y;
        year = z;
    }
    void operator > (day u)
    {
        if (month > u.month)
        {
            cout<<"date "<<date<<" : "<<month<<" : "<<year<<" is greater than "<<u.date<<" : "<<u.month<<" : "<<u.year<<endl;
        }

        else if( month == u.month && date > u.date)
        {
            cout<<"date "<<date<<" : "<<month<<" : "<<year<<" is greater than "<<u.date<<" : "<<u.month<<" : "<<u.year<<endl;
        }
        else 
        {
            cout<<"date "<<u.date<<" : "<<u.month<<" : "<<u.year<<" is greater than "<<date<<" : "<<month<<" : "<<year<<endl;
        }
    }
    void display()
    {
        cout<<"date is : \n"<<date<<" : "<<month<<" : "<<year<<endl;
    }   
};
int main ()
{   
    int date1,month1,year1,date2,month2,year2; 
    cout<<"Enter date 1 : "<<endl;
    cout<<"The date = ";
    cin>>date1;
    cout<<"month = ";
    cin>>month1;
    cout<<"year = ";
    cin>>year1;
    cout<<"Enter date 2 : "<<endl;
    cout<<"The date = ";
    cin>>date2;
    cout<<"month = ";
    cin>>month2;
    cout<<"year = ";
    cin>>year2;
    
    day d1(date1,month1,year1);
    day d2(date2,month2,year2);
    cout<<"********** First Date ********** \n";
    d1.display();
    cout<<"********** Second Date ********** \n";
    d2.display();
    cout<<"********** Result ********** \n";
    d1>(d2);
    return 0;
}