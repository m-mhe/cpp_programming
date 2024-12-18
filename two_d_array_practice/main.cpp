#include<bits/stdc++.h>

using namespace std;

void printATwoDArray(int theArray[5][5], int m, int n){//cause C++ is in row first order
    for(int i = 0; i<m; i++){
        for(int j =0; j<n; j++){
            cout<<theArray[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
}

void makeEveryElementZero(int theArray[][5], int m, int n){//cause C++ is in row first order
    for(int i = 0; i<m; i++){
        for(int j =0; j<n; j++){
            theArray[i][j]=0;
        }
    }
}

void makeEveryDiagonalValueOne(int theArray[][5], int m, int n){
    for(int i =0; i<m; i++){
        for(int j =0; j<n; j++){
            if(i==j){
                theArray[i][j]=1;
            }else{
                theArray[i][j]=0;
            }
        }
    }
}

void makeEveryDiagonalValueOneforAMatrixWithZeroElement(int theArray[][5], int m, int n){
    //theArray[3][4]=69;
    for(int i =0; i<m; i++){
            theArray[i][i]=1;
    }
}

int theNumberOfNonZeroElements(int theArray[][5], int m, int n){
    int sum=0;
    for(int i=0;  i <m; i++){
        for(int j =0; j<n; j++){
            if(theArray[i][j]!=0){
                sum++;
            }
        }
    }
    return sum;
}

int theNumberOfZeroElements(int theArray[][5], int m, int n){
    int sum=0;
    for(int i=0;  i <m; i++){
        for(int j =0; j<n; j++){
            if(theArray[i][j]==0){
                sum++;
            }
        }
    }
    return sum;
}

int sumOfAboveDiagonal(int theArray[][5], int m, int n){
    int sum=0;
    for(int i=0; i <m-1; i++){
        for(int j =i+1; j<n; j++){
                sum+=theArray[i][j];
        }
    }
    return sum;
}

int sumOfWithDiagonal(int theArray[][5], int m, int n){
    int sum=0;
    for(int i=0; i <m; i++){
        for(int j =i; j<n; j++){
                sum+=theArray[i][j];
        }
    }
    return sum;
}

void write(int theArray[][5], int m, int n){//cause C++ is in row first order
    for(int i = 0; i<m; i++){
        for(int j =0; j<n; j++){
            theArray[i][j]=(i+j)+1;
        }
    }
}

int productOfDiagonal(int theArray[][5], int m, int n){
    //theArray[3][4]=69;
    int prod=1;
    for(int i =0; i<m; i++){
            prod*=theArray[i][i];
    }
    return prod;
}
void printTheValueOfDiagonal(int theArray[][5], int m, int n){
    cout<<"The numbers are in diagonal: ";
    for(int i =0; i<m; i++){
            cout<<theArray[i][i];
    }
    cout<<endl;
}

int main(){
    int theTwoDArray[5][5]={45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,25};
    cout<<"The value in row 5 column 4 is "<<theTwoDArray[4][3]<<endl;//It will print a specific value from 2D array
    int sizeOfRow, sizeOfColumn = sizeof(theTwoDArray)/sizeof(theTwoDArray[0]);
    sizeOfRow = sizeof(theTwoDArray[0])/sizeof(theTwoDArray[0][0]);//Hence the size of row and column are the same
    printATwoDArray(theTwoDArray, sizeOfRow, sizeOfColumn);//Traversing
    /*for(int i = 0; i<sizeOfRow; i++){//You can also do this without using external function.
        for(int j =0; j<sizeOfColumn; j++){
            cout<<theTwoDArray[i][j]<<' ';
        }
        cout<<endl;
    }*/
     makeEveryDiagonalValueOneforAMatrixWithZeroElement(theTwoDArray, sizeOfRow, sizeOfColumn);
    printATwoDArray(theTwoDArray, sizeOfRow, sizeOfColumn);
    makeEveryDiagonalValueOne(theTwoDArray, sizeOfRow, sizeOfColumn);
    printATwoDArray(theTwoDArray, sizeOfRow, sizeOfColumn);//Traversing function
    makeEveryElementZero(theTwoDArray, sizeOfRow, sizeOfColumn);
    printATwoDArray(theTwoDArray, sizeOfRow, sizeOfColumn);
    makeEveryDiagonalValueOneforAMatrixWithZeroElement(theTwoDArray, sizeOfRow, sizeOfColumn);
    printATwoDArray(theTwoDArray, sizeOfRow, sizeOfColumn);
    cout<<"The number of nonzero element in last matrix: "<<theNumberOfNonZeroElements(theTwoDArray, sizeOfRow, sizeOfColumn)<<endl;
    cout<<"And the number of zero element in last matrix: "<<theNumberOfZeroElements(theTwoDArray, sizeOfRow, sizeOfColumn)<<endl;
    cout<<"And the sum of above diagonal elements in last matrix: "<<sumOfAboveDiagonal(theTwoDArray, sizeOfRow, sizeOfColumn)<<endl;
    cout<<"And the sum of with diagonal elements in last matrix: "<<sumOfWithDiagonal(theTwoDArray, sizeOfRow, sizeOfColumn)<<endl;
    write(theTwoDArray, sizeOfRow, sizeOfColumn);
    printATwoDArray(theTwoDArray, sizeOfRow, sizeOfColumn);
    cout<<"And the sum of above diagonal elements in last matrix: "<<sumOfAboveDiagonal(theTwoDArray, sizeOfRow, sizeOfColumn)<<endl;
    printTheValueOfDiagonal(theTwoDArray, sizeOfRow, sizeOfColumn);
    cout<<"And the product of diagonal elements in last matrix: "<<productOfDiagonal(theTwoDArray, sizeOfRow, sizeOfColumn)<<endl;
    cout<<"The Test for column: "<<sizeof(theTwoDArray)/sizeof(theTwoDArray[0])<<", The test for row: "<<sizeof(theTwoDArray[0])/sizeof(theTwoDArray[0][0]);
}


