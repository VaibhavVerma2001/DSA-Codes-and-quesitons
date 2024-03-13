// constructor in inherirance 

//order of call and execution
//1-> call of construtcor = child -> parent 
//2-> but execution of constructor = parent -> child
//3-> call of distructor = child -> parent (same as of costructor)
//4-> execution of destructor = child -> parent (reverse of costructor)

//ex-1
/*
#include<iostream>
using namespace std ;
class A
{
    public :
    A ()
    {
        cout<<"A constructor \n";
    }
    ~A ()
    {
        cout<<"A distructor \n";
    }
};
class B : public A
{
    public :
    B ()
    {
        cout<<"B constructor \n";
    }
    ~B ()
    {
        cout<<"B distructor \n";
    }
};
class C :  public B
{
    public :
    C ()
    {
        cout<<"C constructor \n";
    }
    ~C ()
    {
        cout<<"C distructor \n";
    }
};
int main ()
{
    C c1;
    return 0 ;
}
*/

//RULE -> if there is no default constructor in base class , then we have to make constructor in child class as well as we have to call constructor of base class and pass necessary argument in that. 

//ex-1 
/*
#include<iostream>
using namespace std ;
class A
{
    public :
    A ()
    { }
};
class B : public A
{
    public :
    B () : A()  // compiler will automatically make/call default constructor of base class.
    { }

};
int main ()
{
    B b1;
    return 0 ;
}
*/

//ex-2 but if there is no default constructor in base class then we have to make it in derived class
/*
#include<iostream>
using namespace std ;
class A
{
    int a ;
    public : 
    A (int k)
    {
        a=k;
    }
};
class B : public A
{
    int b ;
    public : 
    B (int x , int y ) : A(x) // passes x to k , then k to a . // we have to call cons. of base class bec no default const. is there in base class
    {
        b = y; // a was private to we cant use that here directly 
    } 
};
int main ()
{
    B b(2,3); // now a and b becomes 2 and 3 respectively 
    return 0 ;
}
*/


//in above example if a was not private
#include<iostream>
using namespace std ;
class A
{
    public : 
    int a ;
    A (int k)
    {
        a=k;
    }
};
class B : public A
{
    int b ;
    public : 
    B (int x , int y ) : A(x) 
    { 
        a=x; // a inherited , so we can use here 
        b = y; 
    } 
    void display ()
    {
        cout<<"value of a and b is : "<<a<<" "<<b<<endl;
    }
};
int main ()
{
    B b(2,3); // now a and b becomes 2 and 3 respectively 
    b.display();
    return 0 ;
}