//1-> pair class template in STL
//2-> pair is used when 2 data has strong association beyteen them
//3-> make_pair() is used to initialize value in same order
//4-> first and second are used to display first and second data of pair 
//5-> no such header file like <pair>
/*
#include <iostream>
using namespace std;
int main()
{
    pair<string, int> p1;
    pair<string, string> p2;
    pair<string, float> p3;
    p1 = make_pair("vaibhav", 21);//make_pair() is used to initialize data
    p2 = make_pair("India", "New delhi");
    p3 = make_pair("c++ book", 500.21f);
    cout<<"pair 1 :"<<endl;
    cout << p1.first << endl; //first is used to display first data of pair
    cout << p1.second << endl;//second is used to display second data of pair
    cout<<"pair 2 :"<<endl;
    cout << p2.first << endl;
    cout << p2.second << endl;
    cout<<"pair 3 :"<<endl;
    cout << p3.first << endl;
    cout << p3.second << endl;
    return 0;
}
*/
//how to pass class data type in pair 
#include<iostream>
using namespace std;
class student 
{
   string role;
   int age ;
   public :
   void getdata(string x , int y)
   {
       role = x ,age = y;
   } 
   void showdata()
   {
       cout<<"Role : "<<role<<endl;
       cout<<"Age :"<<age<<endl;
   }
};
int main ()
{
    pair <string , student> p1; //taking student class datatype
    student s1;
    s1.getdata("coder",19); // initialising data in s1
    p1 = make_pair("Vaibhav verma",s1);//initialising data in pair p1
    cout<<p1.first<<endl;   // printing first data of pair
    (p1.second).showdata(); // printing second data of pair with the help of
                            // showdata() member func of student class                     
    return 0;
}