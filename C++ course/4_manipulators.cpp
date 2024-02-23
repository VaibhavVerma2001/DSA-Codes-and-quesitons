//manipulators --> setw()is most common which can set width,included in <iomanip>
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
int a=5,b=10,c=100,d=44444;
cout<<"the value of a without manipulator is :"<<a<<endl;
cout<<"the value of b without manipulator is :"<<b<<endl;
cout<<"the value of c without manipulator is :"<<c<<endl;
cout<<"the value of d without manipulator is :"<<d<<endl;

cout<<"the value of a  manipulator is :"<<setw(5)<<a<<endl; //sets width 5 char space right align
cout<<"the value of b  manipulator is :"<<setw(5)<<b<<endl;
cout<<"the value of c  manipulator is :"<<setw(5)<<c<<endl;
cout<<"the value of d  manipulator is :"<<setw(5)<<d<<endl;

cout<<"the value of a  manipulator is :"<<setw(10)<<a<<endl; //now sets width 10 char space right align
cout<<"the value of b  manipulator is :"<<setw(10)<<b<<endl;
cout<<"the value of c  manipulator is :"<<setw(10)<<c<<endl;
cout<<"the value of d  manipulator is :"<<setw(10)<<d<<endl;

  return 0;
}
