#include<bits/stdc++.h>

using namespace std;

void printAList(int* aListToPrint){
    cout<<*aListToPrint<<endl;
    cout<<*aListToPrint++<<endl;
    cout<<*++aListToPrint<<endl;
    cout<<*aListToPrint++<<endl;
    cout<<*++aListToPrint<<endl;
    cout<<"-----------------------"<<endl;
    cout<<sizeof(aListToPrint)/sizeof(aListToPrint[0])<<endl;//sizeof(aListToPrint) = 8(cause 64-bit system), so 8/4 = 2
    int aList[5]={1,4,7,6,89};
    cout<<sizeof(aList)/sizeof(aList[0])<<endl;//it's 20/4 = 5
}

int main(){
    cout<<"----------Pointer Exercise-------------"<<endl;
    string name = "MMHE";
    string* pOfName = &name;//"&" means address
    int lolN = 242001322;
    int* lolA = &lolN;
    cout<<*pOfName<<endl;
    cout<<*lolA<<endl;
    cout<<pOfName<<endl;
    cout<<lolA<<endl;
    cout<<"-----------------------"<<endl;
    int aList[5]={1,4,7,6,89};
    cout<<aList<<endl;
    cout<<aList+1<<endl;
    cout<<aList+2<<endl;
    cout<<aList+3<<endl;
    cout<<aList+4<<endl;
    cout<<aList+5<<endl;//beyond array bound
    cout<<aList+6<<endl;//beyond array bound
    cout<<*(aList+0)<<endl;
    cout<<*(aList+1)<<endl;
    cout<<*(aList+2)<<endl;
    cout<<*(aList+3)<<endl;
    cout<<*(aList+4)<<endl;
    cout<<"-----------------------"<<endl;
    cout<<sizeof(aList)/sizeof(aList[0])<<endl;
    cout<<"-----------------------"<<endl;
    printAList(aList);
    return 0;
}
