//structure example 1
/*
#include <iostream>
using namespace std;
struct complex {
    private ://now a&b are private,only function can change them
    int a,b;
    public :
    void set_data(int x, int y)//only this fun can change value of a &b
    {
      a=x;
      b=y;
    }
    void show_data()
    {
      cout<<"a ="<<a<<endl;
      cout<<"b ="<<b<<endl;
    }
};
    int main()
    {
      struct complex c1;
      c1.set_data(3,4);
      c1.show_data();
      return 0;
    }
*/
// class example 2
/*
#include <iostream>
using namespace std;
class complex {
    private ://now a&b are private,only function can change them
    int a,b;
    public :
    void set_data(int x, int y)//only this fun can change value of a &b
    {
      a=x;
      b=y;
    }
    void show_data()
    {
      cout<<"a ="<<a<<endl;
      cout<<"b ="<<b<<endl;
    }
};
    int main()
    {
      class complex c1;// c1 is object now not member
      c1.set_data(3,4);
      c1.show_data();
      return 0;
    }
*/
// classes example 2 ,defining function outside classes using ::
/*
#include <iostream>
using namespace std;
class employee
{
private:
  int a, b, c;

public:
  int d, e;
  void getdata(int a, int b, int c);
  void showdata()
  {
    cout << "value of a is :" << a << endl;
    cout << "value of b is :" << b << endl;
    cout << "value of c is :" << c << endl;
    cout << "value of d is :" << d << endl;
    cout << "value of e is :" << e << endl;
  }
};
void employee ::getdata(int x, int y, int z)
{
  a = x;
  b = y;
  c = z;
}
int main()
{
  class employee harry; // can write employee harry only also
//harry.a =100;//error--> a is private so we cant change it directly
  harry.d = 34;
  harry.e = 89;
  harry.getdata(1, 2, 4); //a,b,c can be change only my objects of class
  harry.showdata();
  return 0;
}
*/
//array of classes
/*
#include <iostream>
using namespace std;
class student
{
public:// make them public otherwise they will be private by default 'f'
  char name[20];
  int roll;
  float marks;
};
int main()
{
student s[3];
for (int i = 0; i < 3; i++)
{
  cout << "enter details of student " << i<<endl;
  cin >> s[i].name;
  cin >> s[i].roll;
  cin >> s[i].marks;
}
for (int i = 0; i < 3; i++)
{cout<<"details of student "<<i<<" are :"<<endl;
  cout << s[i].name<<endl;
  cout << s[i].roll<<endl;
  cout << s[i].marks<<endl;
}
return 0;
}
*/
// example of class taking info from user
#include <iostream>
using namespace std;
class data{
    private :
    int employeeid;
    float salary;
    public :
    char name[20];
    int room;
    void getinfo()
    {
      cout<<"enter employee name "<<endl;
      cin.getline(name,20);
      cout<<"enter employee id "<<endl;
      cin>>employeeid;
      cout<<"enter employee salary "<<endl;
      cin>>salary;
      cout<<"enter employee room "<<endl;
      cin>>room;
    }
    void displayinfo()
    {
      cout<<"employee name is :"<<name<<endl;
      cout<<"employee id is :"<<employeeid<<endl;
      cout<<"employee salary is :"<<salary<<endl;
      cout<<"employee room is :"<<room<<endl;
    }
};
int main()
 {
    class data E1;
    E1.getinfo();
    E1.displayinfo();

  return 0;
}
