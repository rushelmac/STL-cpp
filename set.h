#include<iostream>
using namespace std;
template <typename T>
class node
{
    T data;
    node *left,*right;
public:
    node()
    {
        data=0;
        left=right=NULL;
    }
    node(T d)
    {
        data=d;
        left=right=NULL;
    }
    ~node()
    {
        delete left;
        delete right;
    }
    void setdata(T d)
    {
        data=d;
    }
    void setleft(node* l)
    {
        left=l;
    }
    void setright(node* r)
    {
        right=r;
    }
    
    node* getleft()
    {
        return left;
    }
    node* getright()
    {
        return right;
    }
    T getdata()
    {
        return data;
    }
};

template <typename T>
class Set
{
    node<T> *root;
    int size1;
public:
    Set()
    {
        root=NULL;
        size1=0;
    }
  
    void insert(T);
    bool search(T);  
    void display(node<T>*); //inorder traversal
    node<T>* getroot()
    {
        return root;
    } 
    int size()
    {
        return size1;
    }
    bool empty()
    {
        return root==NULL;
    }
    
};

template <typename T>
void Set<T>::insert(T d)
{
    if(search(d)==true)
        return;
    else
    {
        int flg=0;
        node<T> *a,*b;
        while(1)
        {
            if(root==NULL)
            {
                a=new node<T>(d);
                root=a;
                break;
            }
            else
            {
                b=root;
                while(1)
                {
                    if(d<b->getdata())
                    {
                        if(b->getleft()==NULL)
                        {
                            a=new node<T>(d);
                            b->setleft(a);
                            flg=1;
                            break;
                        }
                        else
                            b=b->getleft();
                    }
                    else
                    {
                        if(d>b->getdata())
                        {
                            if(b->getright()==NULL)
                            {
                                a=new node<T>(d);
                                b->setright(a);
                                flg=1;
                                break;
                            }
                            else
                                b=b->getright();
                        }
                    }
                }
                if(flg==1)
                    break;
            }
        }
    }
    size1++;
}
template <typename T>
bool Set<T>::search(T sv)
{
    if(root==NULL)
        return false;
    node<T> *a=root;
    int flg=0;
    while(1)
    {
        if(sv==a->getdata())
        {
            flg=1;
            break;
        }
        else if(sv<a->getdata())
        {
            if(a->getleft()==NULL)
                break;
            else
            {   
                a=a->getleft();
            }
        }
        else if(sv>a->getdata())
        {
            if(a->getright()==NULL)
                break;
            else
            {
                a=a->getright();
            }
        }
    }
    return flg==1;
}



template <typename T>
void Set<T>::display(node<T>* curr)
{
    if(curr==NULL)    
        return ;
    else
    {
        display(curr->getleft());
        cout<<curr->getdata()<<" ";
        display(curr->getright());
    }
}
