// static or class member variable belongs to class not to objects and then will be created even if no object is created.
// there will be only one copy of static variable for the whole class 
// they must be defined outside the class
//example 1
/* 
#include<iostream>
using namespace std ;

class account
{
    int balance; // instance member variable
    static float roi ; // static or class member variable
    public :
    void setbalance(int b)
    {
        balance = b;
    }
    void display()
    {
        cout<<"balance and roi are : "<<balance <<"   "<<roi<<endl;
    }
};
// float account :: roi ; // then it will automatically assign roi =0
float account :: roi = 3.5;
int main ()
{
    account a1;
    a1.setbalance(1000);
    a1.display();
    return 0 ;
}
*/

//example 2
/*
#include<iostream>
using namespace std;

class employee
{
    static int id;
    string name;
    float salary;
    public :
    void setdata(string a , float b)
    {
        name = a;
        salary = b;
    }
    void display()
    {
        cout<<"showing result for employee id : "<<id<<endl;
        cout<<"name and salary of employee is : "<<name <<"  "<<salary<<endl;
        id++; // increamenting id
    }
};
int employee :: id = 1; // must be defined outside the class
int main ()
{
    employee emp[3];
    for (int i = 0; i < 3; i++)
    {
        string x ;
        float y;
        cin>>x>>y;
        emp[i].setdata(x , y);
        emp[i].display();
    }
    return 0;
}
*/

//static member functions or class member functions 
// they can be invoked with or without objects 
// they can access only static member of the class 

//example 

#include<iostream>
using namespace std ;

class account
{
    int balance; // instance member variable
    static float roi ; // static or class member variable
    public :
    void setbalance(int b )
    {
        balance = b;
    }
    // we can set static members through instance member functions also
    // void setroi(float b)
    // {
    //     roi = b;
    // }
    static void setroi(float b) // static member function 
    {
        roi = b;
    }

    void display()
    {
        cout<<"balance and roi are : "<<balance <<"   "<<roi<<endl;
    }

};
float account :: roi = 3.5;
int main ()
{
    account a1;
    a1.setbalance(1000);
    //a1.setroi(5); //accessed using insatance member function
    //a1.setroi(5); //static member function can be called using objects also
    a1.setroi(5); // using them without object and with name of class 
    a1.display();
    return 0 ;
}