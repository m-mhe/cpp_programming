#include<bits/stdc++.h>

using namespace std;

string subString(string &text,int initial,int length){
    string result="";
    for(int i=initial; i<initial+length;i++){
        result+=text[i];
    }
    return result;
}

int indexingTwo(string text, string pattern){//with out using substring
    int index=-1;
    for(int i=0;i<=text.size()-pattern.size();i++){
        int j = 0;
        while(j<pattern.size()&&text[i+j]==pattern[j]){
            j++;
        }
        if(pattern.size()==j){
            return index;
        }
    }
    return index;
}

string deletion(string text,int position,int length){
    return subString(text, 0, position)+subString(text, position+length, text.length()-(position+length));
}

string deletionInLoop(string text, string pattern){
    int k = indexingTwo(text, pattern);
    while(k!=-1){
        text = deletion(text, k, pattern.length());
        k=indexingTwo(text, pattern);
    }
    return text;
}

int main(){
    cout<<"--------------------------DELETION_IN_LOOP--------------------------"<<endl;
    string message = "XAAABBBY";
    cout<<message<<endl;
    cout<<deletionInLoop(message, "AB")<<endl;
}


