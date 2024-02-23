// 1- WAP to convert temp. from celcius to fahrenheit
/*
#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
    float celcius;
    cout<<"enter temp. in celcius "<<endl;
    cin>>celcius;
    float fahrenheit = (9*celcius)/5+32;
    cout<<"temp. in fahrenheit is : "<<fahrenheit;
    return 0;
}
*/
// 2- wap to print all prime no. between 1-100
/*
#include <iostream>
using namespace std;
int main ()
{
    for (int n=1 ; n<=100 ; n++)
    {
      int count = 0;
      for (int i=1; i<=n; i++)
      {
        if(n%i==0)
        {
          count++;
        }

      }
      if (count == 2)
      {
        cout<<n<<endl;
      }
    }
    return 0;
}
*/
// 3- wap to write factorial of a program
/*
#include <iostream>
using namespace std;
int main ()
{
    int n ,i,fact = 1;
    cout<<"enter the no."<<endl;
    cin>>n;
    for (i=n;i>0;i--)
    {
      fact = fact*i;
    }
    cout<<"factorial of a prpgram is : "<<fact;
    return 0 ;
}
*/
// program to enter name and id of teacher and student in class
/*
#include <iostream>
using namespace std;
class teacher
{
  char name[20];
  int teacherid;

public:
  void getdata()
  {
    cout << "enter name of teacher" << endl;
    cin.getline(name, 20);
    cout << "enter teacher id " << endl;
    cin >> teacherid;
  }
  void showdata();
};

class student
{
  char name[20];
  int studentid;

public:
  void getdata()
  {
    cout << "enter name of student" << endl;
    cin.getline(name, 20);
    cout << "enter student id " << endl;
    cin >> studentid;
  }
  void showdata();
};
void student :: showdata()
  {
    cout << "student name is :" << name << endl;
    cout << "student id is :" << studentid << endl;
  }
void teacher :: showdata()
  {
    cout << "teacher name is :" << name << endl;
    cout << "teacher id is :" << teacherid << endl;
  }
int main ()
{
  teacher t1;
  student s1;
  t1.getdata();
  t1.showdata();
  s1.getdata();
  s1.showdata();
}
*/
// doubt in size
/*
#include <iostream>
using namespace std;

class student
{
  char name[20];
  int roll;
  int clas;
  char study;
};

int main()
{
  cout << sizeof(student) << endl;
  student s1;
  cout << sizeof(s1);
}
*/
// Q-> wap to swap 2 no. without using third number
//using 3 variables
/*
#include<iostream>
using namespace std;
int main ()
{  
    int a,b;
    cout<<"enter 2 no. "<<endl;
    cin>>a>>b;
    int temp ;
    temp =a;
    a=b;
    b=temp;
    cout<<a <<" "<<b;
    return 0 ;
}
*/
// using 2 variables
/*
#include<iostream>
using namespace std;
int main()
{
int a,b;
cout<<"enter 2 no. \n";
cin>>a>>b; // let a= 4, b= 3
a=a+b; //4+3=7
b=a-b;//7-3=4
a=a-b;//7-4=3   // now a =3, b = 4
cout<<a<<" "<<b;
}
*/
// Q - wap to print greatest no. among 3 numbers
/*
#include <iostream>
using namespace std;
int main()
{
  int a, b, c;
  cout << "Enter first number" << endl;
  cin >> a;
  cout << "Enter first number" << endl;
  cin >> b;
  cout << "Enter first number" << endl;
  cin >> c;

  if (a >= b && a >= c)
  {
    cout << "Largest number" << a<<endl;
  }
  if (b >= a && b >= c)
  {
    cout << "Largest number" << b<<endl;
  }
  if (c >= b && c >= a)
  {
    cout << "Largest number" << c<<endl;
  }
  return 0;
}
*/
/*
#include <iostream>
using namespace std;
int main()
{int a,b,c;
cout<<"Enter first number"<<endl;
cin>>a;
cout<<"Enter second number"<<endl;
cin>>b;
cout<<"Enter third number"<<endl;
cin>>c;

if(a>b && a>c){
    cout<<"Largest number"<<a;
}
if(b>a && b>c){
    cout<<"Largest number"<<b;
}
if(c>b && c>a){
    cout<<"Largest number"<<c;
}
if(a==c && c==b){
    cout<<"All are equal i.e a="<<a<<",b="<<b<<",c="<<c;
}
    return 0;
}
*/
//Q -> wap to print sum of all no. of array
/*
#include <iostream>
using namespace std;
int main()
{
  int size;
  cout << "how many elements u want to insert " << endl;
  cin >> size;
  int arr[size], sum = 0;
  cout << "enter the elements of array " << endl;
  for (int i = 0; i < size; i++)
  {
    cin >> arr[i];
  }
  for (int i = 0; i < size; i++)
  {
    sum = sum + arr[i];
  }
  cout << "sum of elements of array is :" << sum;
}
*/
// wap to get id and units of electric consumer and print its bill using classes
/* 
#include <iostream>
using namespace std;
class elecricityBill
{
  int consumerID;
  int unit;
  int bill;

public:
  void get(int x, int y)
  {
    consumerID = x, unit = y;
  }
  void calc_bill()
  {
    bill = (unit * 5);
  }
  void put()
  {
    cout<<"id of consimer is :"<<consumerID<<endl;
    cout << "total bill is : " << bill << endl;
  }
};
int main()
{
  elecricityBill c1;
  c1.get(1, 100);
  c1.calc_bill();
  c1.put();
  return 0;
}
*/
// how to declare and read string with spaces
/*
#include<iostream>
#include<cstring>
using namespace std;
int main ()
{
    string name;
    cout<<"enter topper name "<<endl;
    getline(cin,name);//if we define array of char then use cin.getline(name,20);
    cout<<name;
    return  0 ;
}
*/
//Q -> wap to substract 2 complex no. using constructor
/*
#include <iostream>
using namespace std;
class complex
{
private:
  int a, b;

public:
  complex() //default constructor 
  {
    a = 0, b = 0;
  }
  complex(int x, int y)
  {
    a = x, b = y;
  }
  void display()
  {
    cout << "complex no. is : " << a << " + " << b << " i " << endl;
  }
  void Difference(complex u, complex v)
  {
    a = u.a - v.a;
    b = u.b - v.b;
  }
};
int main ()
{
    complex c1(3,2) ;
    complex c2(2,1);
    complex c3;//if we not made default constructor then it was giving error
    c3.Difference(c1,c2);
    c3.display();
    return 0 ;
}
*/
// Q-> wap to check no. whether a no. is pailedrome or not
/*
#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
    int n,count =0;
    cout<<"enter the length of word\n";
    cin>>n;
    char a[n+1];
    cout<<"enter the word\n";
    cin>>a;
    for(int i=0;i<n;i++)
    {
      if (a[i]==a[n-1-i])
       {
        count++;
       }
    }
    if(count==n)
    {
      cout<<"pailendrome\n";
    }
    else
    {
      cout<<"not pailendrome";
    }
    return 0 ;
}
*/
// Q-> write a program to calculate product of elements of array
/*
#include<iostream>
using namespace std;
int main ()
{
    int n;
    cout<<"enter the value of n "<<endl;
    cin>>n;
    int arr[n],product = 1;
    cout<<"enter the elements "<<endl;
    for (int  i = 0; i < n; i++)
    {
       cin>>arr[i];
    }
    for (int  i = 0; i < n; i++)
    {
       product = product *arr[i];
    }
    cout<<"product of elements of array is : "<<product<<endl;
    return 0 ;
}
*/
// Q-> wap to find whther a no. is pailndrome or not
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
  int num;
  cout << "enter the number \n";
  cin >> num;
  int n;
  cout << "enter the no. of digits in number \n";
  cin >> n;
  int arr[n], sum = 0;
  cout << "enter the digits \n";
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  for (int i = 0; i < n; i++)
  {
    sum = sum + arr[i] * arr[i] * arr[i];
  }
  if (sum == num)
  {
    cout << "armstrong \n";
  }
  else
  {
    cout << "not armstrong \n";
  }
  return 0;
}