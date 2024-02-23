// write a function to add 2 numbers
/*
#include <iostream>
using namespace std;
int sum(int a, int b)
{
    return (a + b);
}
int main()
{
    cout << sum(31, 30) << endl;
    cout << sum(100, 50);
    return 0;
}
*/
// write a function to take and  display name and id of student
/*
#include<iostream>
#include<cstring>
using namespace std;
void getdata(string name , int id)
{
    cout<<"student name is : "<<name<<endl;
    cout<<"student id is : "<<id<<endl;
}
int main ()
{
    getdata("vaibhav",21);
    return 0 ;
}
*/
//compiler will automatically call function of same data type we pass to func
// this is also called function overloading
/* 
#include <iostream>
using namespace std;
int sum(int a, int b)
{
    return (a + b);
}
double sum(double a, double b)
{
    return (a + b);
}
int main()
{
    cout << sum(31, 30) << endl;
    cout << sum(100.5, 50.3);
    return 0;
}
*/
/* inline function-C++ inline function is powerful concept that is commonly used with classes. If a function is inline, the compiler places a copy of the code of that function at each point where the function is called at compile time. ... The compiler can ignore the inline qualifier in case defined function is more than a line.*/
//ex -1

#include<iostream>
using namespace std;
inline int sum(int a, int b)
{
    return (a+b);
}
int main()
{
    cout<<sum(5,6)<<endl;
    cout<<sum(5,8)<<endl;
    return 0 ;
}
