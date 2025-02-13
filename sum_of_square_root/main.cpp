#include<bits/stdc++.h>
using namespace std;

int sumOfSquares(int n) {
if(n == 1) return 1;
else return n*n + sumOfSquares(n-1); }

int main(){
    cout<<sumOfSquares(4);
}
