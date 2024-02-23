#include<iostream>
using namespace std ;

string FindPat(string str1, string str2 , string str3)
{
    string res = "";
    int len1 = str1.length();
    int len2 = str2.length();
    int len3 = str3.length();
    int minOf1_2 = min(len1,len2);
    int len = min(minOf1_2,len3);

    for (int i = 0; i < len; i++)
    {
        if(str1[i] ==  str2[i] && str1[i]==str3[i])
        {
            res.push_back(str1[i]);
        }
        else
        {
            break;
        }
    }
    return res;
}

int main ()
{
    string str1, str2,str3;
    cin>>str1>>str2>>str3;
    cout<<FindPat(str1,str2,str3);
    return 0 ;
}