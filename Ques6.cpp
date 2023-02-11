#include <bits/stdc++.h>
using namespace std;

template<class T>
class node
{
public:
    T data;
    node* prv;
    node* nxt;
};

template<class T>
class Deque
{
public:
    node<T>* head;
    node<T>* tail;
    int sz;

    Deque()
    {
        head = NULL;
        tail = NULL;
        sz = 0;
    }

    node <T> * CreateNewNode(T value)
    {
        node<T>* newnode = new node<T>;
        newnode->data = value;
        newnode->nxt = NULL;
        newnode->prv = NULL;
        return newnode;
    }

    void push_back(T value)
    {
        node<T>* newnode = CreateNewNode(value);
        if(sz==0)
        {
            head = newnode;
            tail = newnode;
            sz++;
            return;
        }
        tail->nxt = newnode;
        newnode->prv = tail;
        tail = newnode;
        sz++;
    }

    void push_front(T value)
    {
        node<T>* newnode = CreateNewNode(value);
        if(sz==0)
        {
            head = newnode;
            tail = newnode;
            sz++;
            return;
        }
        head->prv = newnode;
        newnode->nxt = head;
        head = newnode;
        sz++;
    }

    void pop_back()
    {
        if(sz==0)
        {
            cout<<"Deque is empty\n";
            return;
        }
        if(sz==1)
        {
            delete tail;
            head = NULL;
            tail = NULL;
            sz--;
            return;
        }
        node<T> *a = tail;
        tail= tail->prv;
        delete a;
        tail->nxt = NULL;
        sz--;
    }

    void pop_front()
    {
        if(sz==0)
        {
            cout<<"Deque is empty\n";
            return;
        }
        if(sz==1)
        {
            delete tail;
            head = NULL;
            tail = NULL;
            sz--;
            return;
        }

        node<T> *a = head;
        head = head->nxt;
        delete a;
        head->prv = NULL;
        sz--;
    }

    T front()
    {
        if(sz==0)
        {
            cout<<"Deque is empty\n";
            return -1;
        }
        return head->data;
    }

    T back()
    {
        if(sz==0)
        {
            cout<<"Deque is empty\n";
            return -1;
        }
        return tail->data;
    }
    int GetSize()
    {
        return sz;
    }

};



int main()
{
    Deque <char>d;
    string word;
    cin>>word;
    int sz = word.size();
    for(int i=0; i<word.size(); i++)
    {
        d.push_back(word[i]);
    }

    for(int i=1; i<sz;)
    {
        if(d.front()==d.back())
        {
            i+=2;
            d.pop_back();
            d.pop_front();
        }
        else
        {
            break;
        }
    }
    if(d.GetSize()<=1)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}
