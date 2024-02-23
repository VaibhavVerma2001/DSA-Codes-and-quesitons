// Virtual base classes are used in virtual inheritance in a way of
//preventing multiple “instances” of a given class appearing in an
//inheritance hierarchy when using multiple inheritances.
#include <iostream>
using namespace std;
class student
{
  protected :
  int studentID;
  public :
  void getID(){
    cout<<"enter student ID "<<endl;
    cin>>studentID;
  }
};
class test : virtual public student
{
  protected :
  int marks;
  public :
  void getmarks(){
    cout<<"enter student marks"<<endl;
    cin>>marks;
  }
};
class sports : virtual public student
{
  protected :
  int score;
  public:
  void getscore(){
    cout<<"enter student score "<<endl;
    cin>>score;
  }
};
class result : public test , public sports
{
  public :
  void display()
  {
    cout<<"ID of student is : "<<studentID<<endl;
    cout<<"marks of student is : "<<marks<<endl;
    cout<<"score of student is : "<<score<<endl;
  }
};
int main()
{
  result res;
  res.getID();
  res.getmarks();
  res.getscore();
  res.display();
  return 0;
}
