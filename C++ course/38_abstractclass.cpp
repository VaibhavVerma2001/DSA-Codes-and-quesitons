//abstract class is a class which has one or more pure virtual function in it .
//we cant create object of abstract class,generally its made to get inherit by other class
/*
#include<iostream>
using namespace std;
class A
{
   public :
   virtual void fun() = 0;
   void f1()
   {
       cout<<"hi"<<endl;
   }
};
class B : public A
{
   public :
   void fun()
   {
       cout<<"hello";
   }
};
int main ()
{
    B b1;
    b1.f1();// inherited 
    b1.fun();// fun of class B (as fun overrided)
    return 0 ;
}
*/
//example of abstract class -> we make abstract class when we dont want to make its object
//but want to inherit some of its properties in other classes
//like here we dont need object of person but want to inherit its properties like name  
//and gender in student and teacher class
#include <iostream>
using namespace std;
class person //abstract class
{
protected:
    char name[20], gender[20]; // protected ,i.e; can be inherited
public:
    virtual void getname() = 0;   //do nothing (pure virtual)function
    virtual void getgender() = 0; //do nothing (pure virtual)function
};
class student : public person
{
public:
    void getname()
    {
        cout << "enter name of student " << endl;
        cin.getline(name, 20);
    }
    void getgender()
    {
        cout << "enter gender of student " << endl;
        cin.getline(gender, 20);
    }
    void display()
    {
        cout << "name of student is :" << name << endl;
        cout << "gender of student is :" << gender << endl;
    }
};
class teacher : public person
{
public:
    void getname()
    {
        cout << "enter name of teacher " << endl;
        cin.getline(name, 20);
    }
    void getgender()
    {
        cout << "enter gender of teacher " << endl;
        cin.getline(gender, 20);
    }
    void display()
    {
        cout << "name of teacher is :" << name << endl;
        cout << "gender of teacher is :" << gender << endl;
    }
};
int main()
{
    student s1;
    teacher t1;
    s1.getname();
    s1.getgender();
    t1.getname();
    t1.getgender();
    s1.display();
    t1.display();
    return 0;
}
