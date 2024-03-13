//map -
//1-> maps are used to replicate associative array
//2-> <map> header file must be included

// 1- at() and []- used to display value at given index
/*
#include <iostream>
#include <map>
using namespace std;
int main()
{
    // method 1 to initialze
    map<int, string> customer = {{100, "amit"}, {123, "ayush"}, {145, "rahul"}, {171, "aish"}, {200, "ajay"}};

    // method 2 to initialze
    // map <int,string> customer ;
    // customer[100] = "amit";
    // customer[123] = "ayush";
    // customer[145] = "rahul";
    // customer[171] = "aish";
    // customer[200] = "ajay";

    // to print data using at() and []
    // cout<<customer[100]<<endl;
    // cout<<customer[123]<<endl;
    // cout<<customer.at(145)<<endl;
    // cout<<customer.at(171)<<endl;
    // cout<<customer.at(200)<<endl;

    // to print values using iterator 
    map <int , string > :: iterator it;
    for (it = customer.begin();it!= customer.end();it++)
    {
        cout<<it->second<<" "; //it->first will print index
    }
    return 0;
}
*/
// 2- size() - return the no. of value (pairs) in map
/*
#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<int, string> customer = {{100, "amit"}, {123, "ayush"}, {145, "rahul"}, {171, "aish"}, {200, "ajay"}};
    cout<<"size is : "<<customer.size();
    return 0;
}
*/
// 3- empty() -> return 0 if map is not empty 
//return 1 if map is empty
/*
#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<int, string> customer1 = {{100, "amit"}, {123, "ayush"}, {145, "rahul"}, {171, "aish"}, {200, "ajay"}};
    map<int, string> customer2; 
    cout<<customer1.empty()<<endl;
    cout<<customer2.empty()<<endl;
    
    return 0;
}
*/
// 4-clear () -> clears all values from map
/*
#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<int, string> customer = {{100, "amit"}, {123, "ayush"}, {145, "rahul"}, {171, "aish"}, {200, "ajay"}};
    cout<<"size is : "<<customer.size()<<endl;
    customer.clear(); //clears all values
    cout<<"size is : "<<customer.size()<<endl;
    map <int , string > :: iterator it;
    for (it = customer.begin();it!= customer.end();it++)
    {
        cout<<it->second<<" "; //nothing will print now
    }
    return 0;
}
*/


//how to take and display value from user 
//note key will arrange in ascending order itself
#include<iostream>
#include<map>
using namespace std ;

int main ()
{
    map <string , int > name ;
    for (int i = 0; i < 3; i++)
    {
        string x ;
        int y;
        cin>>x>>y;
        name.insert(pair<string, int>(x,y)) ;
    }
    map <string , int > :: iterator it ;
    for (it  = name.begin(); it != name.end(); it++)
    {
        // cout<<it->first<<endl;
        cout<<it->second<<endl;
    }
    
    return 0 ;
}