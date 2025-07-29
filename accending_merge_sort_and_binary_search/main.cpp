#include <bits/stdc++.h>

using namespace std;

void printTitle(string message){

    bool isDone = false;

    for(int i = 0; i < 26; i++){
            if(i<25){
                cout<<"=";
            }else{
                if(isDone == false){
                        cout<<message;
                        i=0;
                        isDone = true;
                        }else{
                            cout<<endl;
            }
        }
    }

}

void fillUpArray(int *a, int s){
    for(int i=0; i<s; i++){
        cin>>a[i];
    }
}

void printArray(int *a, int s){
    for(int i=0; i<s; i++){
        cout<<a[i]<<" ";
    }
}

void merge(int *a, int lowerIndex, int midIndex, int higherIndex){
    int nL, nR;

    nL = midIndex - lowerIndex + 1;
    nR = higherIndex - midIndex;

    int lArray[nL], rArray[nR];

    for(int i = 0; i<nL; i++){
        lArray[i] = a[lowerIndex+i];
    }
    for(int i=0; i<nR; i++){
        rArray[i] = a[midIndex+1+i];
    }

    int i = 0, j = 0, k = lowerIndex;

    while(i<nL && j<nR){
        if(lArray[i] <= rArray[j]){
            a[k] = lArray[i];
            i++;
        }else{
            a[k] = rArray[j];
            j++;
        }
        k++;
    }

    while(i<nL){
        a[k] = lArray[i];
        i++;
        k++;
    }
    while(j<nR){
        a[k] = rArray[j];
        j++;
        k++;
    }

}

void mergeSort(int *a, int lowerIndex, int higherIndex){
    if(lowerIndex<higherIndex){
        int midIndex =  (lowerIndex + higherIndex) / 2;
        mergeSort(a, lowerIndex, midIndex);
        mergeSort(a, (midIndex+1), higherIndex);
        merge(a, lowerIndex, midIndex, higherIndex);
    }
}

int binarySearch(int *a, int lowerIndex, int higherIndex, int s){
    if(lowerIndex<=higherIndex){
        int midIndex = (lowerIndex + higherIndex) / 2;
        if(a[midIndex] == s){
            return midIndex;
        }else if(a[midIndex] < s){
            return binarySearch(a, (midIndex + 1), higherIndex, s);
        }else{
            return binarySearch(a, lowerIndex, (midIndex-1), s);
        }
    }
    return -1;
}

int main(){
    printTitle(" Binary search on an array sorted in ascending order using merge sort ");
    int n, s;
    cout<<"Size of your array: ";
    cin>>n;
    int a[n];
    cout<<"Enter your array: ";
    fillUpArray(a, n);
    cout<<"Enter the item you want to find from your array: ";
    cin>>s;
    mergeSort(a, 0, n-1);
    cout<<endl<<"Sorted in ascending order: ";
    printArray(a, n);
    int index = binarySearch(a, 0, n-1, s);
    if(index>=0){
        cout<<endl<<"Found in index "<<index;
    }else{
        cout<<endl<<"Not found!";
    }
    cout<<endl;
    printTitle(" End ");
}


