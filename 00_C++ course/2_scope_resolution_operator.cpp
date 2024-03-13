#include<iostream>
using namespace std;
int c =50;
int main ()
{
    int a,b,c;
    cout<<"enter the first element:"<<endl;
    cin>>a;
    cout<<"enter the second element:"<<endl;
    cin>>b;
    c=a+b;
    cout<<"the value of local c  is :"<<c<<endl;
    cout<<"the value of global c is :"<<::c<<endl;//:: is scope resolution operator.
                                                  //it is used to display global variable.
    return 0;
}
