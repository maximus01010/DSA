#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        this->data=d;
        this->next=NULL;
    }
};
void insertathead(Node* &head,int d){
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
}
void insertattail(Node* &tail,int d){
    Node* temp=new Node(d);
    tail->next=temp;
    tail=temp;
}
void insertatmiddle(Node* &head,Node* &tail,int d,int position){
    if(position==1){
        insertathead(head,d);
        return;
    }
    else{
        Node* temp=head;
        int count=1;
        while(count<position-1){
            temp=temp->next;
            count++;
        }
        if(temp->next==NULL){
            insertattail(tail,d);
            return;
        }
        Node* newnode=new Node(d);
        newnode->next=temp->next;
        temp->next=newnode;
    }
}
void Print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    Node* node1=new Node(10);
    Node* head=node1;
    insertathead(head,22);
    insertathead(head,32);
    Print(head);
    Node* tail=node1;
    insertattail(tail,55);
    insertattail(tail,99);
    Print(head);
    insertatmiddle(head,tail,69,2);
    Print(head);
}