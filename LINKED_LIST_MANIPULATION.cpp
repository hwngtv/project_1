//C++
#include <bits/stdc++.h>
using namespace std;
struct node{
    int key;
    node *next;
};
int n;
node* makenode(int x){
    node *temp=new node;
    temp->next=NULL;
    temp->key=x;
    return temp;
}
node* add(node*head,int x){
    node*temp=makenode(x);
    head->next=temp;
    return temp;
}
bool exist(node*head,int x){
    while(head!=NULL){
        if(head->key==x)return true;
        head=head->next;
    }
    return false;
}
node* addlast(node*head,int x){
    while(head->next!=NULL)head=head->next;
    node *temp=makenode(x);
    head->next=temp;
    return temp;
}
node *addfirst(node*head,int x){
    node*temp=makenode(x);
    temp->next=head;
    return temp;
}
node *addafter(node*head,int u,int v){
    while(head->key!=u)head=head->next;
    node*temp=makenode(v);
    temp->next=head->next;
    head->next=temp;
    return temp;
}
node *addbefore(node* head, int u, int v){
    node* temp = makenode(v);
    if(head->key == u){
        temp->next = head;
        return temp;
    }
    node* current = head;
    while(current->next != NULL && current->next->key != u){
        current = current->next;
    }
    if(current->next != NULL){
        temp->next = current->next;
        current->next = temp;
    }
    return head;
}
node* removee(node*head,int x){
    if(head->key==x)return head->next;
    node*temp=head;
    while(temp->next->key!=x)temp=temp->next;
    temp->next=temp->next->next;
    return head;
}
node* reversee(node* head){
    node* prev = NULL;
    node* current = head;
    node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}
int main()
{
    cin>>n;
    int x;cin>>x;
    node *head=makenode(x);
    node*temp=head;
    for(int i=1;i<n;i++){
        cin>>x;
        temp=add(temp,x);
    }

    string s;
    while(1){
        cin>>s;
        int a,b;
        if(s=="#")break;
        if(s=="addlast"){    temp=head;
            cin>>a;
            if(!exist(temp,a)) temp=addlast(temp,a);
        }
        else if(s=="addfirst"){
            cin>>a;
            if(!exist(head,a))
            head=addfirst(head,a);
        }
        else if(s=="addafter"){    temp=head;
            cin>>b>>a;
            if(!exist(temp,b)&&exist(temp,a))
            temp=addafter(temp,a,b);
        }
       else if(s=="addbefore"){    temp=head;
            cin>>b>>a;
            if(!exist(temp,b)&&exist(temp,a))
            temp=addbefore(temp,a,b);
        }
      else if(s=="remove"){
            cin>>a;
            if(exist(head,a))
            head=removee(head,a);
        }
      else if(s=="reverse"){

            head=reversee(head);
        }
    }


    while(head!=NULL){
        cout<<head->key<<" ";
        head=head->next;
    }
}
