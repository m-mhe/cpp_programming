#include<bits/stdc++.h>
using namespace std;

string subString(string &text,int initial,int length){
    string result="";
    for(int i=initial; i<initial+length;i++){
        result+=text[i];
    }
    return result;
}

string deletion(string text,int position,int length){
    return subString(text, 0, position)+subString(text, position+length, text.length()-(position+length));
}

int main(){
    cout<<"--------------------------DELETION--------------------------"<<endl;
    string message = "Hello jok World!";
    cout<<message<<endl;
    cout<<deletion(message, 6, 4)<<endl;
}
