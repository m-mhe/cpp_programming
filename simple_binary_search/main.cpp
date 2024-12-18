#import<bits/stdc++.h>

using namespace std;

int sBSF(int* theElements, int theElement, int totalElements){
    //int size = sizeof(theElements)/sizeof(theElements[0]); this line is useless so I used pointer for array input in this function parameter
    int high = totalElements-1;
    int low = 0;
    int mid;
    while(high>=low){
        mid=(high+low)/2;
        if(theElements[mid]==theElement){
            return mid;
        }else if(theElements[mid]<theElement){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return -1;
}

int main(){
cout<<"------------------Simple Binary Search------------------";
int size;
cout<<"\nEnter your array size:"<<endl;
cin>>size;
int nums[size];
cout<<"Now enter your array:"<<endl;
for(int i=0; i<size; i++){
    cin>>nums[i];
}
cout<<"Enter the element that you want to find from your array"<<endl;
int num;
cin>>num;
int theResultIndex = sBSF(nums, num, size);
if(theResultIndex!=-1){
    cout<<num<<" found in "<<theResultIndex<<" no. index";
}else{
    cout<<num<<" not found";
}
}
