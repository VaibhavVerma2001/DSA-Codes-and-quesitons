/* Q-1 print rectangular pattern
****
****
****
****
****
*/
/*
#include <iostream>
using namespace std;
int main()
{
    int i,j,row,col;
    cout<<"enter rows"<<endl;
    cin>>row;
    cout<<"enter columns"<<endl;
    cin>>col;
    for ( i = 0; i <row ; i++)
   {
      for(j=0;j<col;j++)
      {
       cout<<"*";
      }
      cout<<endl;
   }
     return 0;
} */
/* Q-2 triangular pattern
*
**
***
****
*****
*/
#include <iostream>
using namespace std;
int main()
{
    int i,j,row,col;
    cout<<"enter rows"<<endl;
    cin>>row;
    cout<<"enter columns"<<endl;
    cin>>col;
    for ( i = 1; i <row ; i++)
   {
      for(j=1;j<=i;j++)
      {
       cout<<"*";
      }
      cout<<endl;
   }
     return 0;
}
