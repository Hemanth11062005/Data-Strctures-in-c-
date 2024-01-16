#include<iostream>
using namespace std;
struct node{
    int data;
    node *link;
}*item,*p,*head,*pre;
class stack{
    public:
    stack(){
        item = new node;
        item->data = 0;
        item->link = NULL;
        head = item;
    }
    void push(){
        item =new node;
        cout<<"enter number:"<<endl;
        cin>>item->data;
        if(head->link==NULL){
            head->link = item;
            item->link = NULL;
        }
        else{
            p=head->link;
            while(p->link!=NULL){
                p = p->link;
            }
            p->link=item;
            item->link = NULL;
        }
    }
    void pop(){
        //deletion at end;
        if(head->link == NULL){
            cout<<"stack is empty"<<endl;
        }
        else {
        p = head->link;
        pre = head;
        while(p->link!=NULL){
            pre = p;
            p = p->link;
        }
        pre->link == NULL;
        delete p;
        }
    }
    void stacktop(){
        p= head->link;
        if(p == NULL){
            cout<<"stack is empty"<<endl;
        }
        else{
            while(p->link != NULL){
                p = p->link;
            }
            cout<<"Stack top = "<<p->data;
        }
    }
    void disp(){
            p = head->link;
            if(p == NULL){
                cout<<"stack is empty";
            }else{
            while(p!=NULL){
                cout<<p->data<<"\t";
                p = p->link;
            }
        }
    }
};
int main(){
    stack s;
    int ch;
    do{
        cout<<"\n 1:push  2: pop 3: stacktop 4:display"<<endl;
        cin>>ch;
        switch(ch){
            case 1: s.push(); break;
            case 2: s.pop(); break;
            case 3: s.stacktop(); break;
            case 4: s.disp(); break;
        }
    }while(ch>=1);
}