#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* link;
};
class HashTable{
    
    Node* hashtable[10];
    const int size = 10;
    int hashindex,key;
    public:
    HashTable(){
        for(int i=0;i<size ;i++)
            hashtable[i] = nullptr;
    }
    void insert(){
        cout<<"Enter key to be inserted:"<<endl;
        Node* newnode = new Node;
        cin>>key;
        hashindex = key % size;
        newnode->data = key;
        newnode->link = hashtable[hashindex];
        hashtable[hashindex] = newnode;
    }

    void del(){
        cout<<"Enter key to be del:"<<endl;
        cin>>key;
        hashindex = key % size;
        Node* temp = nullptr;
        Node* delNode = hashtable[hashindex];
        while(delNode!=nullptr){
            if(delNode->data == key){
                if(temp == nullptr)
                    hashtable[hashindex] = delNode->link;
                else
                    temp->link = delNode->link;
            delete delNode;
            break;
            }
                    temp = delNode;
        delNode = delNode->link;

        }
    }

void display(){
    Node* temp;
    for(int i = 0 ;i< size ;i++)
    {
        temp = hashtable[i];
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp = temp->link;
        }
    }
}
};

int main()
{
    HashTable h;
    int x;
    do{
        cout<<"1.insert 2.delete 3 display";
        cin>>x;
        switch(x){
            case 1: h.insert(); break;
            case 2: h.del(); break;
            case 3: h.display(); break;
        }
    }while(x>=1);
}

