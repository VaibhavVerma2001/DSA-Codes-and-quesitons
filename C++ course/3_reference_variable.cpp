#include<iostream>
using namespace std;
    int main() {
    float a = 34.4f;
    long double b=34.4l;
    cout<<"size of 34.4 is :"<<sizeof(34.4)<<endl;
    cout<<"size of 34.4f is :"<<sizeof(34.4f)<<endl;
    cout<<"size of 34.4F is :"<<sizeof(34.4F)<<endl;
    cout<<"size of 34.4l is :"<<sizeof(34.4l)<<endl;
    cout<<"size of 34.4L is :"<<sizeof(34.4L)<<endl;
    return 0;
}
/*
// c++ reference
    float  x =10;
    float &y = x ;
    cout<<x<<endl;
    cout<<y<<endl;
    return 0;
  }
*/
