#import<bits/stdc++.h>

using namespace std;

string subString(string &text,int initial,int length){
    string result="";
    for(int i=initial; i<initial+length;i++){
        result+=text[i];
    }
    return result;
}

int main(){
    cout<<"--------------------------SUBSTRING--------------------------"<<endl;
    string text = "HelloWorld!";
    cout<<"Main String: "<<text<<endl;
    cout<<"Sub String: "<<subString(text,2,4)<<endl;
}
