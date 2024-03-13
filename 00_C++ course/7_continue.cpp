//WAP TO PRINT ALL NO. BTW 0 -100 WHICH ARE NOT DIVISIBLE BY 3
#include <iostream>
using namespace std;
int main()
{
    for (int i = 0; i <=100; i++) {
      if(i%3==0)
      {
        continue;
      }
      cout<<i<<endl;
    }

   return 0;
}
