//case 1 - primitive type to class type 
// we solve this using constructor 
/*
#include <iostream>
using namespace std;
class complex
{
    int a, b;

public:
    complex() {}  // default constructor
    complex(int x)
    {
        a = x, b = 0;
    }
    void display()
    {
        cout << "complex no. is : " << a << " + " << b << " i " << endl;
    }
};
int main()
{
    complex c1; // default constructor 
    int x = 5;
    c1 = x;//this is like c1.complex(x) |coverted primitive to class type
    c1.display();
    return 0;
}

*/
//example
//program to convert days into years and days

/*
#include<iostream>
using namespace std ;
class days
{
   int year , day;
   public : 
   days () {} // default constructor
   days(int x )
   {
       year = x/365;
       day= x%365;
   }
   void showdata()
   {
       cout<<"years are "<<year<<endl;
       cout<<"days are "<<day<<endl;
   }
};
int main ()
{
    int a ;
    cout<<"enter number of days \n";
    cin>>a;
    days d1;
    d1= a;
    d1.showdata();
    return 0 ;
}

*/

//method -2 -> we can solver by operator overloading also
//program to convert days into years and days using op. overloading
/*
#include<iostream>
using namespace std ;
class days
{
   int year , day;
   public : 
   void operator = (int x )
   {
       year = x/365;
       day= x%365;
   }
   void showdata()
   {
       cout<<"years are "<<year<<endl;
       cout<<"days are "<<day<<endl;
   }
};
int main ()
{
    int a ;
    cout<<"enter number of days \n";
    cin>>a;
    days d1;
    d1= a;
    d1.showdata();
    return 0 ;
}

*/
// case 2 - class type to primitive type
//this is implemented with casting operator
// It must be a class member.
// It must not specify the return value even though it returns the value.
// It must not have any argument.

/*
#include<iostream>
using namespace std ;

class complex 
{
   int a , b ;
   public :
   void getdata(int x , int y)
   {
       a=x, b=y;
   }
   void display()
   {
       cout<<"a = "<<a<<" "<<"b = "<<b<<endl;
   }
   operator int() // casting operator // int is return type
   {
       return (a+b); // or return a , b or anything we want 
   }
};

int main ()
{
    complex c1;
    c1.getdata(3,4);
    c1.display();
    int x ;
    x = c1; // like x = c1.opeartor int () ; // class to primitive type
    cout<<"x = "<<x;
    return 0;
}

*/

// case 3 - one class type to another class type 
// method 1 - using constructor (make constructor for left hand side object)
// method 2 - through casting operator (casting operator for right side object) 

#include<iostream>
using namespace std;

class product // making product class first so that compiler will not give error 
{
   int m , n;
   public :
   void getdata(int x , int y )
   {
       m =x, n =y;
   }
   void showdata()
   {
      cout<<"m = "<<m <<" "<<"n = "<<n<<endl;
   }
   int getm() // to return value of m 
   {
       return (m);
   }
   int getn() // to return value of n
   {
       return (n);
   }
};
class item  // make constructor for left side object in conversion 
{
   int a , b;
   public :
   item () {} //default constructor
   item (product p)
   {
      // a = p.m; error because m and n are private in other class
      // b = p.n; error because m and n are private in other class
      // but can use function we made in public
      a = p.getm();
      b = p.getn();
   }
   void showdata()
   {
       cout<<"a = "<<a<<" "<<"b = "<<b<<endl;
   }

};
int main ()
{
    product p1;
    item i1; // default constructor
    p1.getdata(3,4);
    p1.showdata();    
    i1 = p1;
    i1.showdata();
    return 0;
}
