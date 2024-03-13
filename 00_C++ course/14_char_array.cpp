// array of characters 
/*
#include<iostream>
using namespace std;
int main ()
{
    char name[20];
    cout<<"enter the name "<<endl;
    cin.getline(name ,20); //cin.getline used in this
    cout<<name;
    return 0 ;
} 
*/
// directly using string 
/*
#include<iostream>
#include<cstring>
using namespace std;
int main ()
{
    string name;
    cout<<"enter name "<<endl;
    getline(cin,name);
    cout<<name;
    return 0;
}
*/
// wap to find a word is pailendrome or not 
#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
    int n,count =0;
    cout<<"enter the length of word\n";
    cin>>n;
    char a[n+1];
    cout<<"enter the word\n";
    cin>>a;
    for(int i=0;i<n;i++)
    {
      if (a[i]==a[n-1-i])
       {
        count++;
       }
    }
    if(count==n)
    {
      cout<<"pailendrome\n";
    }
    else
    {
      cout<<"not pailendrome";
    }
    return 0 ;
}
