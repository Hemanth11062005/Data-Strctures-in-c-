#include<iostream>
using namespace std;
struct node
{
    int data;
    node *link;
}*temp,*item,*head;
class sll
{
    public:
    sll()
    {
        item=new node();
        item->data=0;
        item->link=NULL;
        head=item;
    }
    void insbeg()
    {
        item=new node();
        cout<<"Enter data:";
        cin>>item->data;
        item->link=head->link;
        head=item;
    }
    void display()
    {
        temp=head->link;
        while(temp!=NULL)
        {
            cout<<"\t"<<temp->data;
            temp=temp->link;
        }

    }
};
int main()
{
    sll s;
    int ch;
    do{
    cout<<"ENter choice: 1:insbeg() 2:display()";
    cin>>ch;
        switch(ch)
        {
            case 1: s.insbeg(); break;
            case 2: s.display(); break;
        }
    }while(ch>=1);
}