#import<bits/stdc++.h>

using namespace std;

string stringConcatenation(string &textOne,string textTwo){
    return textOne+textTwo;
}

int main(){
    cout<<"--------------------------SUBSTRING--------------------------"<<endl;
    string text = "HelloWorld!";
    string anotherText = ", Hello World!";
    cout<<"Main String: "<<text<<endl;
    cout<<"S//S: "<<stringConcatenation(text,anotherText)<<endl;
}

