//protected acsess modifier->the only difference btw private and protected
//is that-> protected members can be inherited to other class ,while private
//members cant be inherited
#include <iostream>
using namespace std;
class base
{
  private :
  int a;
  protected :
  int b;
  public :
  int c;
};
int main ()
{
base b1;
// b1.a=5; // error bec a is private
// b1.b=10; //error bec b is protected
b1.c=15; // right ,we can do this bec c is public
// cout<<b1.a<<endl; //error bec a is private
// cout<<b1.b<<endl; //error bec b is protected
cout<<b1.c<<endl;
return 0 ;
}
