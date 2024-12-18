#include<bits/stdc++.h>

using namespace std;

void boubleSort(int* nums, int Snums){
    bool swaped = false;
    for(int i=0; i<(Snums-1); i++){
        for(int j = 0; j<((Snums-i)-1); j++ ){
            if(nums[j]>nums[(j+1)]){
                swap(nums[j], nums[j+1]);
                swaped = true;
            }
        }
        if(!swaped){
            break;
        }
    }
}

int binarySearch(int* listOfItem, int sizeOfList, int item){
    int high = sizeOfList-1;
    int low = 0;
    int mid;
    while(high>=low){
            mid = (high+low)/2;
            if(listOfItem[mid]==item){
                return mid;
            }else if(listOfItem[mid]<item){
                low = mid+1;
            }else{
                high = mid-1;
            }
    }
    return -1;
}

int main(){
    cout<<"___________________Sort & Search___________________"<<endl<<endl;
    cout<<"How many numbers is in your array? :"<<endl;
    int sizeOfArray;
    cin>>sizeOfArray;
    int theArray[sizeOfArray];
    cout<<"Enter "<<sizeOfArray<<" numbers:"<<endl;
    for(int i=0; i<sizeOfArray; i++){
        cin>>theArray[i];
    }
    cout<<"Your numbers in ascending sorted form:"<<endl;
    //----------------SORT----------------
    boubleSort(theArray, sizeOfArray);
    //----------------SORT----------------
    for(int i=0; i<sizeOfArray; i++){
        cout<<theArray[i]<<" ";
    }
    cout<<endl;
    cout<<"What number do you want to find?:"<<endl;
    int itemToSearch;
    cin>>itemToSearch;
    int index = binarySearch(theArray, sizeOfArray, itemToSearch);
    if(index==-1){
        cout<<"Not found."<<endl;
    }else{
        cout<<"Found in "<<index<<" number index of the sorted list."<<endl;
    }
    cout<<"___________________Sort & Search___________________"<<endl<<endl;
}
