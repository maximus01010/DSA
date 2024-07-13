#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int d){
        this->data=d;
        this->next=NULL;
    }
};
node* linkedlist(node* head){
    int data;
    cout<<"enter data"<<endl;
    cin>>data;
    head=new node(data);
    if(data==-1){
        return NULL;
    }
    head->next=linkedlist(head->next);
    return head;
}
void Print(node* head){
    node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    node* head=NULL;
    head=linkedlist(head);
    Print(head);
}