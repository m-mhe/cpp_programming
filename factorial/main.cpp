#include<bits/stdc++.h>

using namespace std;

double factorial(int value){//It doesn't works with negative integer

    //Base case
    if(value <= 1){
        return 1;
    }
    //Base case

    //Recursion
    return (value*factorial(value-1));
    //Recursion
}
int main(){
    int input;
    cin>>input;
    double output = factorial(input);
    cout<<"Result:"<<output<<endl;
    return 1;
}
