/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;
struct node
{
    int data;
    node *prev;
    node *next;
}*item,*temp;
struct lists
{
  int count;
  node *head;
  node *rear;
}*headnode;
class dlll
{
    public:
    dlll()
    {
        headnode=new lists;
        headnode->count=0;
        headnode->head=NULL;
        headnode->rear=NULL;
    }
    void insertbeg()
    {
        item=new node;
        cout<<"enter the value "<<endl;
        cin>>item->data;
        item->prev=NULL;
        item->next=NULL;
        if(headnode->head==NULL)
        {
            headnode->head=item;
            headnode->rear=item;
        }
        else
        {
         headnode->head->prev=item;
         item->next=headnode->head;
         headnode->head=item;
        }
        headnode->count++;
    }
    void insertend()
    {
        item=new node;
        cout<<"enter the value "<<endl;
        cin>>item->data;
        item->prev=NULL;
        item->next=NULL;
        if(headnode->head=NULL)
        {
            headnode->head=item;
            headnode->rear=item;
        }
        else
        {
            headnode->rear->next=item;
            item->prev=headnode->rear;
            headnode->rear=item;
        }
        headnode->count++;
    }
    void insertany()
    {
        int pos;
        cout<<"enter the position you need to insert"<<endl;
        cin>>pos;
        item=new node;
        cout<<"enter the value "<<endl;
        cin>>item->data;
        item->prev=NULL;
        item->next=NULL;
        if(pos<0||pos>headnode->count)
        {
            cout<<"invalid position";
        }
        else if(pos==0)
        {
            headnode->head=item;
            headnode->rear=item;
            headnode->count++;
        }
        else if(pos==headnode->count)
        {
            headnode->rear->next=item;
            item->prev=headnode->rear;
            headnode->rear=item;
            headnode->count++;
        }
        else
        {
            int p1;
            p1=0;
            temp=headnode->head;
            while(p1<pos)
            {
                temp=temp->next;
                p1++;
            }
            item->prev=temp->prev;
            item->next=temp->prev->next;
            temp->prev->next=item;
            temp->prev=item;
            headnode->count++;
        }
    }
    void del()
    {
     int key;
     cout<<"enter the key"<<endl;
     cin>>key;
     temp=headnode->head;
     if(headnode->count==0)
     {
         cout<<"cant delete"<<endl;
     }
     else
     {
     while(temp!=NULL)
     {
          if(temp->data==key)
          {
              if(temp->prev!=NULL)
              {
                  temp->prev->next=temp->next;
              }
              if(temp->next!=NULL)
              {
                   temp->next->prev=temp->prev;
              }
              if(temp->prev==NULL)
              {
                   headnode->head=temp->next;
              }
              if(temp->next==NULL)
              {
                  headnode->rear=temp->prev;
              }
              headnode->count--;
          }
          temp=temp->next;
     }
     }
    }
    void headtorear()
    {
        temp=headnode->head;
        while(temp!=NULL)
        {
            cout<<"data==";
            cout<<temp->data;
            temp=temp->next;
        }
    }
    void reartohead()
    {
        temp=headnode->rear;
        while(temp!=NULL)
        {
            cout<<"data==";
            cout<<temp->data;
            temp=temp->next;
        }
    }
};
int main()
{
    int opt;
    char ch;
    dlll d; 
    do
    {
        cout<<"ente rhte opotipo"<<endl;
        cout<<"1.insertbeg 2.insertend 3.del 4.headtorer 5.rer to head 6.insert ant"<<endl;
        cin>>opt;
        switch(opt)
        {
            case 1:
            d.insertbeg();
                   break;
            case 2:
            d.insertend();
                    break;
            case 3:
            d.del();
                    break;
            case 4:
            
            d.headtorear();
                    break;
            case 5:
            d.reartohead();
                    break;
                    case 6:
                    d.insertany();
                    break;
                    default:
      cout<<"invalid";
        }
        cout<<"do yo want to cont "<<endl;
        cin>>ch;
    }while(ch=='y');
    return 0;
}