// pointers to object snd arrow operator
/*
#include <iostream>
using namespace std;
class complex
{
   int a,b;
   public :
   void getdata(int x , int y){
     a=x, b=y;
   }
   void showdata(){
     cout<<"complex no. is :"<<a<<" + "<<b<<" i "<<endl;
   }

};
int main ()
{
   complex c1,c2;
   //method 1
   c1.getdata(1,2);
   c1.showdata();
   //method 2
   complex *p = &c2;
   (*p).getdata(2,3);// use () bec . operator has higher preference
   (*p).showdata();
   //method 3
   complex *q= new complex;
   q->getdata(3,4);
   q->showdata();
   return 0 ;
}
*/
//array of objects without using pointers
/*
#include <iostream>
using namespace std;
class shopItem
{
  int ItemID;
  float price;

public:
  void getdata(int a, float b)
  {
    ItemID = a, price = b;
  }
  void showdata()
  {
    cout << "ID of item is : " << ItemID << endl;
    cout << "Price of item is : " << price << endl;
  }
};
int main()
{
  int n, p;
  float q;
  cout << "enter the value of n " << endl;
  cin >> n;
  shopItem s[n];
  for (int i = 0; i < n; i++)
  {
    cout << "for item " << i + 1 << endl;
    cout << "enter the value of id and price" << endl;
    cin >> p >> q;
    s[i].getdata(p, q);
  }
  for (int i = 0; i < n; i++)
  {
    cout << "for item " << i + 1 << endl;
    s[i].showdata();
  }

  return 0;
}
*/
//array of objects without using pointers
#include <iostream>
using namespace std;
class shopItem
{
  int ItemID;
  float price;

public:
  void getdata(int a, float b)
  {
    ItemID = a, price = b;
  }
  void showdata()
  {
    cout << "ID of item is : " << ItemID << endl;
    cout << "Price of item is : " << price << endl;
  }
};
int main()
{
  int n, p;
  float q;
  cout << "enter the value of n " << endl;
  cin >> n;
  shopItem *ptr = new shopItem [n];
  shopItem *ptrtemp=ptr;// taking address of ptr in ptrtemp ,so that we can use
                        //this after ptr get increased (by ptr++)
  for (int i = 0; i < n; i++)
  {
    cout << "for item " << i + 1 << endl;
    cout << "enter the value of id and price" << endl;
    cin >> p >> q;
    ptr->getdata(p,q);
    ptr++;
  }
  for (int i = 0; i < n; i++)
  {
    cout << "for item " << i + 1 << endl;
    ptrtemp->showdata();
    ptrtemp++;//cant use ptr now bec it will point to some garbage value
              // bec we increased that in above for loop
  }
  return 0;
}
