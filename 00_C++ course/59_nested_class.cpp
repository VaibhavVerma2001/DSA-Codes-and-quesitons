#include<iostream>
using namespace std ;

class Student 
{  
    private :
    string name;
    int rollno;
    
    class Address
    {
        private :
        string  colony , city , state ;
        public :
        void getaddress()
        {
            cout<<"enter colony , city , state \n";
            cin>>colony>>city>>state;
        }
        void showaddress()
        {
            cout<<"colony = "<<colony<<endl;
            cout<<"city = "<<city<<endl;
            cout<<"state = "<<state<<endl;
        }
    };

    Address add; // object of Address class in private of student class
    public :
    void getinfo()
    {
        cout<<"enter name and roll no. of student \n";
        cin>>name>>rollno;
        add.getaddress(); //using member function of Address class with it's object
    }
    void showinfo()
    {
        cout<<"showing information of student \n";
        cout<<"name = "<<name<<endl;
        cout<<"rollno = "<<rollno<<endl;
        add.showaddress(); //using member function of Address class with it's object
    }
    
};
int main ()
{
    Student s1;
    s1.getinfo();
    s1.showinfo();
    // Student::Address obj; // if address class was public in student class then we had right to create its own object directly using :: operator and use its member fun directly
    return 0 ;
}