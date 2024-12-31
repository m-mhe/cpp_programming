#include<bits/stdc++.h>

using namespace std;

struct date{
    int day;
    int month;
    int year;
};

struct person{
    string name;
    struct date birthDate;
};

int main(){
    int numberOfPeople;
    cout<<"Number of people: ";
    cin>>numberOfPeople;
    struct person persons[numberOfPeople];
    cout<<"Enter info of "<<numberOfPeople<<" persons:"<<endl;
    for(int i=0; i < numberOfPeople; i++){
        cin>>persons[i].name;
        cin>>persons[i].birthDate.day;
        cin>>persons[i].birthDate.month;
        cin>>persons[i].birthDate.year;
    }
    //Finding the youngest
    struct person youngest = persons[0];
    struct person eldest = persons[0];
    for(int i=0; i < numberOfPeople; i++){
            if(persons[i].birthDate.year>youngest.birthDate.year){
                    youngest = persons[i];
            }else if(persons[i].birthDate.year<eldest.birthDate.year){
                eldest = persons[i];
            }
    }
    cout<<"The youngest person's name is "<<youngest.name<<", born in the year "<<youngest.birthDate.year<<"."<<endl;
    cout<<"The eldest person's name is "<<eldest.name<<", born in the year "<<eldest.birthDate.year<<"."<<endl;
}
