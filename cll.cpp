#include<iostream>
using namespace std;
struct node{
    int data;
    node* link;
    node* last;
}*head,*item,*p,*pre;
class Cll{
    public:
    Cll(){
        item = new node;
        item->data = 0;
        item->link = NULL;
        item->last = NULL;
        head = item;
    }
    void insert(){
        item = new node;
        cout<<"Enter element to be inserted";
        cin>>item->data;
        item->link = NULL;
        item->last = NULL;
        if(head->link == NULL){
            head->link = item;
            item->link = item;
            head->last = item;
        }
        else{
            p = head->link;
            pre = NULL;
            while(p->link != head->link && item->data<p->data){
                pre = p;
                p = p->link;
            }
            if(p->link == head->link && p->data<item->data && head->last == p){
                item->link = p->link;
                p->link = item;
                head->last = item;
            }
            else if(p->link == head->link && p->data>item->data){

            }

        }

    }
}