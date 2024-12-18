#include<bits/stdc++.h>

using namespace std;

string subString(string &text,int initial,int length){
    string result="";
    for(int i=initial; i<initial+length;i++){
        result+=text[i];
    }
    return result;
}

int indexing(string text, string pattern){
    int index=-1;
    for(int i=0;i<=text.length()-pattern.size();i++){
        if(subString(text, i, pattern.size())==pattern){
            index=i;
        }
    }
    return index;
}
int indexingTwo(string text, string pattern){//with out using substring
    int index=-1;
    for(int i=0;i<=text.size()-pattern.size();i++){
        int j = 0;
        while(j<pattern.size()&&text[i+j]==pattern[j]){
            j++;
        }
        if(pattern.size()==j){
            index=i;
        }
    }
    return index;
}


int main(){
    cout<<"--------------------------INDEXING--------------------------"<<endl;
    string text = "XABYABZ";
    cout<<"Main String: "<<text<<endl;
    cout<<"Last YABZ are in: "<<indexingTwo(text, "YABZ")<<endl;
    cout<<"Last ABZ are in: "<<indexing(text, "ABZ")<<endl;
}
