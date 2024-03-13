/*
#include <iostream>
using namespace std;
int main()
{
    int i,n,count=0;
    cout<<"enter the number"<<endl;
    cin>>n;
    for(i=1;i<=n;i++)
    {
       if(n%i==0)
      {
       count++;
       cout<<"divisible by"<<i<<endl;
      }
    }
    if(count>2)
    {
      cout<<"no. is not prime"<<endl;
    }
    else
    {
      cout<<"no. is prime"<<endl;
    }
    return 0;
}
*/
// ex-2 -> WAP to find sin, cos ,tan of angle taken in degree
//NOTE 1-> compiler take angles in radians to convert degree into radians
// NOTE 2-> only sin,cos and tan functions are there in cmath

#include <iostream>
#include <cmath>
using namespace std;
int main() 
{
  float degree,radian;
  cout<<"enter angle in degree\n";
  cin>>degree;
  radian = (degree*3.141592)/180;
  cout<<"value of sin is :"<<sin(radian)<<endl;
  cout<<"value of cos is :"<<cos(radian)<<endl;
  cout<<"value of tan is :"<<tan(radian)<<endl;
  cout<<"value of cosec is :"<<1/sin(radian)<<endl;
  cout<<"value of sec is :"<<1/cos(radian)<<endl;
  cout<<"value of cot is :"<<1/tan(radian)<<endl;

  return 0;
}
