//polymorphism -> one name multiple form
// 1- compile time polymorphism
//a) function overloading
//b) operator overloading
//2- run time polymorphism
//a)-virtual function
//1- a) function overloading
// example 1
/*
#include <iostream>
using namespace std;
    int sum(int a, int b){
      cout<<"taking 2 arguments sum is :"<<endl;
      return a+b;
    }
    int sum(int a, int b, int c){
      cout<<"taking 3 arguments sum is :"<<endl;
      return a+b+c;
    }
int main()
{
    cout<<sum(2,3)<<endl;// compiler itself see no. of arguments given by user
                        // and then run function according to them
    cout<<sum(2,3,5);
    return 0;
}
*/
// function overloading example 2
/*
#include <iostream>
using namespace std;
void volume(int a)
{
  cout << "volume of cube is : " << (a * a * a) << endl;
}
void volume(int l, int b, int h)
{
  cout << "volume of cuboid is : " << (l * b * h) << endl;
}
void volume(int r, int h)
{
  cout << "volume of cylinder is : " << (3.14 * r * r * h) << endl;
}
int main()
{
  volume(5);
  volume(2, 3, 4);
  volume(2, 3);
  return 0;
}
*/
// ex -> 3 of function overloading in class
#include <iostream>
using namespace std;
class A
{
public:
  float volume(double a) // cube
  {
    return (a * a * a);
  }
  float volume(double a, double b) // cylinder
  {
    return (3.14 * a * a * b);
  }
  float volume(double a, double b, double c) // cuboid
  {
    return (a * b * c);
  }
};
int main()
{
  A vol;
  cout << "volume of cube is :" << vol.volume(5) << endl;
  cout << "volume of cylinder is :" << vol.volume(2, 3) << endl;
  cout << "volume of cuboid is :" << vol.volume(2, 3, 4);
  return 0;
}
