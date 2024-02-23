//declaring and initializing structure
/*
#include <iostream>
using namespace std;
struct mycar{
char name[20];
int seats;
float price;
char color[20];
};
int main()
{
    struct mycar  car1;
    cout<<"enter car name \n";
    cin.getline(car1.name,20);
    cout<<"enter car seats \n";
    cin>>car1.seats;
    cout<<"enter car price \n";
    cin>>car1.price;
    cout<<"enter car color \n";
    cin>>car1.color;
    cout<<"car name is :"<<car1.name<<endl;
    cout<<"car seats are :"<<car1.seats<<endl;
    cout<<"car price is :"<<car1.price<<endl;
    cout<<"car color is :"<<car1.color<<endl;

    return 0;
}
*/
//declaring and initializing array of structures
/*
#include <iostream>
#include <cstring>
using namespace std;
struct mycar{
char name[20];
int seats;
float price;
char color[20];
};
int main()
{
    struct mycar  car[3];
    for(int i=0;i<3;i++)
    {
    cout<<"enter details of car "<<i<<endl;
    cout<<"enter car name \n";
    cin.getline(car[i].name,20);
    cout<<"enter car seats \n";
    cin>>car[i].seats;
    cout<<"enter car price \n";
    cin>>car[i].price;
    cout<<"enter car color \n";
    cin>>car[i].color;
    }
    for (int i=0;i<3;i++)
    {
    cout<<"details of car "<<i<<endl;
    cout<<"car name is :"<<car[i].name<<endl;
    cout<<"car seats are :"<<car[i].seats<<endl;
    cout<<"car price is :"<<car[i].price<<endl;
    cout<<"car color is :"<<car[i].color<<endl;
    }
    return 0;
}
*/
//declaring and initializing union
// all overwrites so only last member gives actual value,other gives garbage

#include <iostream>
using namespace std;
union mycar{
char name[20];
int seats;
float price;
char color[20];
};
int main()
{
    union mycar  car1;
    cout<<"enter car name \n";
    cin.getline(car1.name,20);
    cout<<"enter car seats \n";
    cin>>car1.seats;
    cout<<"enter car price \n";
    cin>>car1.price;
    cout<<"enter car color \n";
    cin>>car1.color;
    cout<<"car name is :"<<car1.name<<endl;
    cout<<"car seats are :"<<car1.seats<<endl;
    cout<<"car price is :"<<car1.price<<endl;
    cout<<"car color is :"<<car1.color<<endl;

    return 0;
}
/*
//so take and display data one by one in union to get correct values
#include <iostream>
using namespace std;
union mycar{
char name[20];
int seats;
float price;
char color[20];
};
int main()
{
    union mycar  car1;
    cout<<"enter car name \n";
    cin.getline(car1.name,20);
    cout<<"car name is :"<<car1.name<<endl;
    cout<<"enter car seats \n";
    cin>>car1.seats;
    cout<<"car seats are :"<<car1.seats<<endl;
    cout<<"enter car price \n";
    cin>>car1.price;
    cout<<"car price is :"<<car1.price<<endl;
    cout<<"enter car color \n";
    cin>>car1.color;
    cout<<"car color is :"<<car1.color<<endl;
    return 0;
}
*/
