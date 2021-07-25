// Given a linkedlist, reverse and print the list. The program should run with O(n) time and space complexity

// Input:10 -> 20 -> 30 -> 40 -> NULL  
// Output:40 -> 30 -> 20 -> 10 -> NULL 
#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node* next;
};
Node* head = NULL;
void insert(int data){
    Node* ptr=new Node;
    ptr->data=data;
    ptr->next=head;
    head=ptr;
}
void display(Node* head){
    Node* ptr=head;
    while(ptr->next!=NULL){
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }
    cout<<ptr->data;
}
void displayReverse(Node* head){
    if(head->next==NULL){
        cout<<head->data;
    }
    else{
        displayReverse(head->next);
        cout<<"->"<<head->data;
    }
}
int main(){
    int n;
    cin>>n;
    while(n){
        int i;
        cin>>i;
        insert(i);
        n--;
    }
    display(head);
    cout<<endl;
    displayReverse(head);
    return 0;
}