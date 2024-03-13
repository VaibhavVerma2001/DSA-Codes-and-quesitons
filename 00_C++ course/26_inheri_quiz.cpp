// Q-WAP and make 2 classes as
//1- simple calc and and take 2 no. using a utility do + - * / in it and
// display result using other function
//2- sci cal and take any 2 no. do any sci calculation and display result
// now inherit these classes into hybrid cal class
#include <iostream>
#include <cmath>
using namespace std;
class simpleCal
{
  int a, b;

public:
  void getdatasimple()
  {
    cout << "for simple class " << endl;
    cout << "enter the value of a" << endl;
    cin >> a;
    cout << "enter the value of b" << endl;
    cin >> b;
  }
  void simOperation()
  {
    cout << " value of a + b is : " << a + b << endl;
    cout << " value of a - b is : " << a - b << endl;
    cout << " value of a * b is : " << a * b << endl;
    cout << " value of a / b is : " << (float)a / b << endl;
  }
};
class scientificCal
{
  int a, b;

public:
  void getdatascientific()
  {
    cout << "for scientific class" << endl;
    cout << "enter the value of a " << endl;
    cin >> a;
    cout << "enter the value of b  " << endl;
    cin >> b;
  }
  void sciOperation()
  {
    cout << " value of (a power b ) is : " << pow(a, b) << endl;
    cout << " value of sqrt(a) is : " << sqrt(a) << endl;
    cout << " value of log10(a)  is : " << log10(a) << endl;
    cout << " value of exp(a) is : " << exp(a) << endl;
  }
};
class hybridCal : public simpleCal, public scientificCal
{
};
int main()
{
  hybridCal cal;
  cal.getdatasimple();
  cal.simOperation();
  cal.getdatascientific();
  cal.sciOperation();
  return 0;
}
