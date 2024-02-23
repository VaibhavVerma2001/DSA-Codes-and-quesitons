// if-else
/*
#include <iostream>
using namespace std;
int main()
 {
     int age;
     cout<<"enter your age \n";
     cin>>age;
     if(age>18)
     {
       cout<<"you can vote";
     }
     else if (age==18)
     {
       cout<<"you can vote next year";
     }
     else
     {
       cout<<"you can't vote";
     }

  return 0;
}
*/
//switch case
/*
#include <iostream>
using namespace std;
int main()
    {
    int day;
    cout<<"enter the day"<<endl;
    cin>>day;
    switch (day) {
    case 1:
    cout<<"monday";
    break;
    case 2:
    cout<<"tuesday";
    break;
    case 3:
    cout<<"wedesday";
    break;
    case 4:
    cout<<"thursday";
    break;
    case 5:
    cout<<"friday";
    break;
    case 6:
    cout<<"saturday";
    break;
    case 7:
    cout<<"sunday";
    break;
    default :
    cout<<"there are only 7 days in a week";
    break;
    return 0;
  }


  return 0;
}
*/

//WAP TO FIND MAXIMUM NO. AMONG 3 NUMBERS
#include <iostream>
using namespace std;
int main ()
{
    int a,b,c;
    cout<<"enter 3 numbers"<<endl;
    cin>>a>>b>>c;
    if (a>b)
    {
      if(a>c)
      {
        cout<<"highest no. is:"<<a;
      }
      else
      {
        cout<<"highest no. is :"<<c;
      }
    }
      else if(b>a)
      {
        if(b>c)
        {
          cout<<"highest no. is :"<<b;
        }
       else
       {
          cout<<"highest no. is :"<<c;
       }
      }
      else
      {
        cout<<"all no. are equal";
      }

    return 0 ;
}

// WAP TO FIND THE NO. IS EVEN OR ODD
/*
#include <iostream>
using namespace std ;
int main(int argc, char const *argv[]) {
  int n;
  cout<<"enter no.\n";
  cin>>n;
  if (n%2==0)
  {
    cout<<"no. is even";
  }
  else
  {
    cout<<"no. is odd";
  }
  return 0;
}
*/