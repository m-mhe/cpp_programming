#include <bits/stdc++.h>

using namespace std;

/*string linearSearch(int* allItems, int elementToFind, int itemsNumber){ //Do like this
    for(int i=0; i<itemsNumber; i++){
        if(allItems[i]==elementToFind){
            return "Found";
        }
    }
    return "Not found";
}*/

string linearSearch(int* allItems, int elementToFind, int itemsNumber){ //Or like this
    for(int i=0; i<itemsNumber; i++){
        if(*allItems==elementToFind){
            return "Found in: "+to_string(i)+"th index";
        }
        *allItems++;
    }
    return "Not found";
}

int main(){
    cout<<"-------------------------Linear Search-------------------------"<<endl;
    int numberOfItems;
    cout<<"Number of items: ";
    cin>>numberOfItems;
    cout<<"Enter items one by one: "<<endl;
    int items[numberOfItems];
    for(int i=0; i<numberOfItems; i++){
        cin>>items[i];
    }
    cout<<"Which Item you want to find: ";
    int itemToFind;
    cin>>itemToFind;
    cout<<linearSearch(items, itemToFind, numberOfItems)<<endl;
    return 0;
}
