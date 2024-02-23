//ambiguity-->if there are more than one functions of same name in class and
//then we inherit into other class then we have to specify compiler that
// which class function we want to use in derived class

//CASE 1-> when there is no function with same name in derived class as base
 //class
 /*
#include <iostream>
using namespace std;
class base1
{
  public :
  void greet()
  {
    cout<<"how r u ?"<<endl;
  }
};
class base2
{
  public :
  void greet()
  {
    cout<<"kaise ho ?"<<endl;
  }
};
class derived : public base1, public base2
{
};
int main ()
{
   base1 b1;
   b1.greet();
   base2 b2;
   b2.greet();
   derived der;
  // der.greet();//error :'greet' is ambiguous ,bec derived class has 2 greet()now
  //so we have to tell compiler which greet functn to use
   return 0;
}
*/
// solving above program ambiguity
/*
#include <iostream>
using namespace std;
class base1
{
  public :
  void greet()
  {
    cout<<"how r u ?"<<endl;
  }
};
class base2
{
  public :
  void greet()
  {
    cout<<"kaise ho ?"<<endl;
  }
};
class derived : public base1, public base2
{
  public :
  void greet()
  {
    base1:: greet();// ambiguity resolve ,now it will use greet of base1 class
  }
};
int main ()
{
   base1 b1;
   b1.greet();
   base2 b2;
   b2.greet();
   derived der;
   der.greet();// greet of base1 class now
   return 0;
}
*/
//CASE 2-> if there is same name function in derived class then
//ambiguity will resolve itself and compiler will use functions
// of derived class
/*
#include <iostream>
using namespace std;
class base1
{
  public :
  void greet()
  {
    cout<<"how r u ?"<<endl;
  }
};
class base2
{
  public :
  void greet()
  {
    cout<<"kaise ho ?"<<endl;
  }
};
class derived : public base1, public base2
{
  public :
  void greet()
  {
    cout<<"hello world"<<endl;
  }
};
int main ()
{
   base1 b1;
   b1.greet();
   base2 b2;
   b2.greet();
   derived der;
   der.greet();
   return 0;
}
*/
//ex-> 2 if class has its own function of same name as inherited
//by other class then compiler will run its own function
#include <iostream>
using namespace std;
class base1
{
  public :
  void greet(){
    cout<<"how are u?"<<endl;
  }
};
class base2: public base1
{
   public :
   void greet(){
     cout<<"kaise ho aap?"<<endl;
   }
};
class derived :  public base2
{
public:
 void greet(){
   cout<<"hi"<<endl;
 }
} ;
int main() {
  base1 b1;
  b1.greet();
  base2 b2;
  b2.greet();//base2 will run its own greet() , not of base1 (inherited)
  derived der;
  der.greet();//derived class will run its greet()
  return 0;
}
