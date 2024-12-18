#include<bits\stdc++.h>

using namespace std;

int main(){
    int sizeOfArray;
    cout<<"----------------Largest element in array----------------"<<endl;
    cout<<"Array size:"<<endl;
    cin>>sizeOfArray;
    int anArray[sizeOfArray];
    cout<<"The Array:"<<endl;
    for(int i=0; i<sizeOfArray; i++){
        cin>>anArray[i];
    }
    int maxValue = anArray[0];
    int loc = 0;
    for(int i=1; i<sizeOfArray; i++){
        if(maxValue<anArray[i]){
            maxValue=anArray[i];
            loc = i;
        }
    }
    cout<<"The Max value is "<<maxValue<<" And the index is "<<loc<<endl;
}
