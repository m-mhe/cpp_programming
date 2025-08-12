#include<bits/stdc++.h>

using namespace std;

void mergeArray(int* arr, int leftIndex, int rightIndex, int midIndex){
    int n1, n2; //Left array size, right array size
    n1 = (midIndex - leftIndex) + 1; //Assigning size
    n2 = rightIndex - midIndex; //Assigning size
    int leftArr[n1], rightArr[n2]; //Making two sub arrays
    for(int i = 0; i<n1; i++){
        leftArr[i] = arr[leftIndex+i]; //Copying in left sub array
    }
    for(int i = 0; i<n2; i++){
        rightArr[i] = arr[(midIndex+1)+i]; //Copying in right sub array
    }
    int i, j, k;
    //Maintaining sub array and main array index
    i = 0; //Left sub array index
    j = 0; //Right sub array index
    k = leftIndex; //Main array index

    while(i<n1 && j<n2){ //Until we reach either end of either L or M, pick larger among
        if(leftArr[i]<=rightArr[j]){
            arr[k] = leftArr[i];
            i++;
        }else{
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    /*
    loop stops as soon as either sub-array runs out of elements. At that point, the other sub-array may still have unmerged items. Those leftover items are already in sorted order,
    so you need these two “copy‑the‑rest” loops to dump them into the merged array. Without them, any elements remaining in L[] or M[] would simply be skipped, and your final arr[p..r]
    would be missing data (and thus not correctly sorted).*/

    /*
    That’s exactly why you need the two “copy the rest” loops afterward: to dump whatever remains in the other array once one side is empty.
    Without them, any leftover elements in the non‑empty half would be skipped.
    */

    while(i<n1){
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = rightArr[j];
        j++;
        k++;
    }

}

void mergeSort(int* arr, int leftIndex, int rightIndex){

    if(leftIndex < rightIndex){
            int midIndex = ((leftIndex+rightIndex)/2); //Integer division
            mergeSort(arr, leftIndex, midIndex); // Recursion
            mergeSort(arr, (midIndex+1), rightIndex);// Recursion
            mergeArray(arr, leftIndex, rightIndex, midIndex);// For sorting and merging.
    }
}



int main(){
    int arrSize;
    cout<<"How long is your array: ";
    cin>>arrSize;
    int arr[arrSize];
    cout<<"Enter your array:"<<endl;
    for(int i = 0; i<arrSize; i++){
        cin>>arr[i];
    }
    mergeSort(arr, 0, arrSize-1);
    cout<<"Here is your sorted array:"<<endl;
    for(int i = 0; i<arrSize; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
