#include<bits/stdc++.h>

using namespace std;

double fibonacci(int value){//Only works with positive integer.

    //Base case
    if(value == 0){
        return 0;
    }if(value<3){
        return 1;
    }
    //Base case

    //Recursion
    return fibonacci(value -1)+fibonacci(value -2);
    //Recursion
}
int main(){
    int input;
    cin>>input;
    double output = fibonacci(input);
    cout<<"Result:"<<output<<endl;
    return 1;
}
