#include<bits/stdc++.h>
using namespace std;

string subString(string &text, int initial, int length){
    string result="";
    for(int i = initial; i<length+initial; i++){
        result+=text[i];
    }
    return result;
}

string insertion(string text, int pos, string subText){
    return subString(text, 0, pos)+subText+subString(text, pos, text.length()-pos);
}

int main(){
    cout<<"-----------------------INSERTION-----------------------"<<endl;
    string mainString = "Hello World!";
    cout<<mainString<<endl;
    string addedString = " C++";
    cout<<insertion(mainString, 5, addedString);
}
