#include<bits/stdc++.h>
using namespace std;

void findAndSwap(char* listOfItem, int itemNumber, char theLetter){
    for(int i=0;i<itemNumber;i++){
        if(listOfItem[i]==theLetter){
            char temp = listOfItem[0];
            listOfItem[0]=theLetter;
            listOfItem[i]=temp;
        }
    }
}

int main(){
    char letters[]={'C', 'B', 'A', 'E'};
    int sizeOfLetters=sizeof(letters)/sizeof(letters[0]);
    cout<<"--------------------------Find and swap--------------------------"<<endl;
    for(int i =0; i<sizeOfLetters;i++){
        cout<<letters[i];
    }
    cout<<endl;
    findAndSwap(letters, sizeOfLetters, letters[2]);
    for(int i =0; i<sizeOfLetters;i++){
        cout<<letters[i];
    }
    cout<<endl;
}

