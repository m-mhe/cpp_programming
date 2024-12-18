#include<bits/stdc++.h>
#include <cstdlib>
using namespace std;

/*//In C style
struct node{
    int data;
    struct node* next;
};

int main(){
        printf("_-------------------------------------------- LINK LIST USING C --------------------------------------------_\n");
    int lengthOfTheLinkList;
    printf("Set a length for your list: ");
    scanf("%d", &lengthOfTheLinkList);
    struct node* head = NULL;
    struct node* newNode = NULL;
    struct node* temp = NULL;

    //a single node:
    //head = malloc(sizeof(struct node));
    //(*head).data = 401;//Or we can use "->" as "head-> data = 69;"
    //head-> next = NULL;

    //Dynamic sized node:
    for(int i=1;i<=lengthOfTheLinkList; i++){
        newNode = (struct node*)malloc(sizeof(struct node));
        if(newNode == NULL){
            printf("Memory allocation failed.\n"); //In case of an error
            return -1;
        }
        (*newNode).data = i;//Or we can use "->" as "newNode-> data = 69;" // Assign data//(*newNode) is Dereferencing a pointer.
        newNode-> next = NULL; // Initialize the next pointer
        if(head == NULL){
            head = newNode; // Set the first node as the head
        }else{
            (*temp).next = newNode; // Link the new node to the previous node
        }
        temp = newNode; // Move temp to the new node
    }

    temp = head; // Start from the head
    while (temp != NULL) {
        printf("%d, ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    // Free the memory
    temp = head;
    while (temp != NULL) {
        struct node* next = temp->next;
        free(temp);
        temp = next;
    }

    return 0;
}
*/

//in C++ style
struct node{
    int data;
    node* next;
};

int main(){
        printf("_-------------------------------------------- LINK LIST USING C --------------------------------------------_\n");
    int lengthOfTheLinkList;
    cout<<"Set a length for your list: ";
    cin>>lengthOfTheLinkList;
    node* head = NULL;
    node* newNode = NULL;
    node* temp = NULL;

    /* //a single node
    head = malloc(sizeof(struct node));
    (*head).data = 401;//Or we can use "->" as "head-> data = 69;"
    head-> next = NULL;
    */

    //Dynamic sized node
    for(int i=1;i<=lengthOfTheLinkList; i++){
        newNode = new node;
        if(newNode == NULL){
            printf("Memory allocation failed.\n"); //In case of an error
            return -1;
        }
        (*newNode).data = i;//Or we can use "->" as "newNode-> data = 69;" // Assign data
        newNode-> next = NULL; // Initialize the next pointer
        if(head == NULL){
            head = newNode; // Set the first node as the head
        }else{
            (*temp).next = newNode; // Link the new node to the previous node
        }
        temp = newNode; // Move temp to the new node
    }

    temp = head; // Start from the head
    while (temp != NULL) {
        cout<<temp->data<<", ";
        temp = (*temp).next;
    }
    printf("NULL\n");

    // Free the memory
    temp = head;
    while (temp != NULL) {
        node* next = temp->next;
        free(temp);
        temp = next;
    }
    return 402;
}

