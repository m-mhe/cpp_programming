#include<bits/stdc++.h>

using namespace std;

int factorial(int value){

    //base case
    if(value == 1 || value == 0){
        return 1;
    }
    //base case

    return (value*factorial(value - 1));
}
int main(){
    int input;
    cin>>input;
    return factorial(input);
}
