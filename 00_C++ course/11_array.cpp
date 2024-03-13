// taking and printing  array values from user
/*
#include <iostream>
using namespace std;
int main()
{
    int a[20],n;
    cout<<"how many elements u want to insert"<<endl;
    cin>>n;
    cout<<"enter the values"<<endl;
    for (int i = 0; i < n; i++)
    {
      cin>>a[i];
    }
    cout<<"you entered the values"<<endl;
    for (int i = 0; i < n; i++)
    {
      cout<<a[i]<<endl;
    }

    return 0;
}
*/
// Q-2 wap to print max and min values of an array
/*
#include <iostream>
#include <climits>//INT_MAX and INT_MIN included in this
using namespace std;
int main()
{
    int a[20],n;
    cout<<"how many elements u want to insert"<<endl;
    cin>>n;
    cout<<"enter the values"<<endl;
    for (int i = 0; i < n; i++)
    {
      cin>>a[i];
    }
    int maxNo,minNo;
    for (int i = 0; i < n; i++)
    {
      maxNo=max(maxNo,a[i]);
      minNo=min(minNo,a[i]);
    }
    cout<<maxNo <<" "<<minNo;
    return 0;
}
*/
// LINEAR SEARCH ,program to find a no. and its position
/*
#include <iostream>
using namespace std;
int main()
{
    int a[20],n;
    cout<<"how many elements u want to insert"<<endl;
    cin>>n;
    cout<<"enter the values"<<endl;
    for (int i = 0; i < n; i++)
    {
      cin>>a[i];
    }
    int key,count =0;
    cout<<"enter the no. u want to search"<<endl;
    cin>>key;
    for (int i = 0; i < n; i++)
    {
      if (a[i]==key)
      {
        cout<<"found at "<<i<<" index"<<endl;
        count++;
      }
    }
    if(count>0)
    {
      cout<<"found "<<count<<" times"<<endl;
    }
    else
    {
      cout<<"not found "<<endl;
    }
    return 0;
  }
*/
//wap- to find vowels in a string

#include <iostream>
using namespace std;
int main()
{
    char str[30];
    int i,count =0;
    cout<<"enter the string"<<endl;
    cin.getline(str,30); // cin.getline(),readed space like gets()
    for(i=0;str[i]!='\0';i++)
    {
      if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')
      {
        cout<<"found at "<<i<<endl;
        count++;
      }
    }
    if (count>0) {
      cout<<"found "<<count<<" times vowels";
    }
    else
    {
      cout<<"not found";
    }
    return 0;
}

// sorting of array
/*
#include <iostream>
using namespace std;
int main()
 {
    int a[20],n,temp;
    cout<<"how many elements u want to insert"<<endl;
    cin>>n;
    cout<<"enter the elements"<<endl;
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
      for(int j=i+1;j<n;j++)
      {
        if(a[i]>a[j])
        {
          temp=a[j];
          a[j]=a[i];
          a[i]=temp;
        }
      }
    }
    cout<<"sorted array is "<<endl;
    for(int i=0;i<n;i++)
    {
      cout<<a[i]<<endl;
    }


    return 0;
}
*/
