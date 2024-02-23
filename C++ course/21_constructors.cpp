//constructor ex -1
/*
#include <iostream>
using namespace std;
class complex
{
   int a,b ;
   public :
   complex ()//constructor --> since name of functn is same as class
   {
     cout<<"hello world"<<endl;
   }
};
int main() {
  complex c1,c2,c3;//as object created program invoke for c1,c2,c3
  return 0;
}
*/
// example 2
/*
#include <iostream>
using namespace std;
class complex
{
   int a,b;
 public:
   complex ()//type -> default constructor
   {
     a=10,b=0;
   }
   void shownumber()
   {
      cout<<"complex no. is "<<a<<" + "<<b<<"i"<<endl;
   }
};
int main()
{
  complex c;//constructor ,hence initialised at time of creating object
  c.shownumber();
  return 0;
}
*/
//wap to take 2 points and find distance between them using constructor 
#include <iostream>
#include <cmath>
using namespace std;
class point
{
   int a,b;
   friend void distance(point  , point );
   public :
   point (int x , int y)
   {
     a=x,b=y;
   }
};
    void distance(point u , point v)
    {
      int x=((v.a-u.a)*(v.a-u.a));
      int y=((v.b-u.b)*(v.b-u.b));
      float dis=sqrt(x+y);
      cout<<"distance between points is :"<<dis<<endl;
    }
   int main ()
{
   point p1(4,6);
   point p2(1,2);
   distance(p1,p2);
   return 0 ;
}
