#ifndef BINSEARCHTREE_H
#define BINSEARCHTREE_H
#include <QString>
#include <QVector>
#include "node.h"
class bst{

    node * root=nullptr;

public:
    bst(){}

    void fill(QVector<std::pair<int,QString>>data)
    {
        for(auto& i:data)
            insert(root,i.first,i.second);
        qDebug()<<root;
    }

    void insert(int key,QString str)
    {
        insert(root,key,str);
    }
    void insert(node *& v,int key,QString str)
    {
        if(v==nullptr)
        {
            v=new node(key,str);
            qDebug()<<key<<" "<<str<<" "<<v<<" "<<root;
            return;
        }
        if(key<=v->key)
        {
            insert(v->left,key,str);
            return;
        }
        insert(v->right,key,str);
    }

    QString find(int key)
    {
        return find(root,key);
    }
    QString find(node * v,int key)
    {
        if(v==nullptr)
            return "";
        if(v->key==key)
            return v->str;
        if(key<=v->key)
        {
            return find(v->left,key);

        }
        return find(v->right,key);

    }
void remove(int key,bool left=false)
{
    node * pred=nullptr;
    return remove(key,root,pred,left);
}

void remove(int key, node *v,node *& pred,bool left)
    {
        if(v==nullptr)
            return;

        if(key==v->key)//Found
        {
            if(v->left==v->right&&v->left==nullptr)//leave
            {
                delete v;

                if(pred==nullptr)// 1 v
                {
                    root=nullptr;
                    return;
                }

                if(left)
                    pred->left=nullptr;
                else
                    pred->right=nullptr;
            }
            else if(v->left==nullptr)//without left
            {
                if(pred==nullptr)//Root
                {
                    root=v->right;
                }
                else
                {
                    if(left)
                        pred->left=v->right;
                    else
                        pred->right=v->right;
                }
                delete v;
            }
            else if(v->right==nullptr)//without right
            {
                if(pred==nullptr)//Root
                {
                    root=v->left;
                }
                else
                {
                    if(left)
                        pred->left=v->left;
                    else
                        pred->right=v->left;
                }
                delete v;
            }
            else //Normal
            {
                node * Successor = v->right;//Find minimal in right subtree
                while(Successor->left!=nullptr)
                    Successor=Successor->left;

                v->key=Successor->key;
                v->str=Successor->str;
                remove(Successor->key,v->right,v,true); //delete old version
            }

            return;
        }
        if(key<v->key)
        {
            remove(key,v->left,v,true);
                return;
        }
        remove(key,v->right,v,false);
    }

    int height(node * v)
    {
        if(v==nullptr)
            return 0;
        return std::max(height(v->left),height(v->right))+1;
    }

    void balance()
    {
        return balance(root);
    }
    void balance(node *& v)
    {
        if(v==nullptr)return;

        int delta=height(v->left)-height(v->right);

        if(delta>1)
        {
            if(height(v->left->right)>height(v->left->left))
                Lrotate(v->left);
            Rrotate(v);
        }
        if(delta<-1)
        {
            if(height(v->right->left)>height(v->right->right))
                Rrotate(v->right);
            Lrotate(v);
        }

        balance(v->left);
        balance(v->right);

    }


    void Lrotate(node *&v)
    {
        node * temp=v->right;
        v->right=temp->left;
        temp->left=v;
        v=temp;
    }

    void Rrotate(node *&v)
    {
        node * temp=v->left;
        v->left=temp->right;
        temp->right=v;
        v=temp;
    }

    int leaves()
    {
        return leaves(root);
    }

    int leaves(node * v)
    {
        if(v==nullptr)return 0;
        if(v->left==v->right&& v->left==nullptr)
            return 1;
        return leaves(v->left)+leaves(v->right);
    }
    //orders
    void prefOrder(QString& way)
    {
        prefOrder(root,way);
    }
    void prefOrder(node * v, QString& way)
    {
        if(v==nullptr)return;
        way+=QString::fromStdString("{"+std::to_string(v->key))+", "+v->str+"}\n";
        prefOrder(v->left,way);
        prefOrder(v->right,way);
    }

    void infOrder(QString& way)
    {
        infOrder(root,way);
    }
    void infOrder(node * v, QString& way)
    {
        if(v==nullptr)return;

        infOrder(v->left,way);
        way+=QString::fromStdString("{"+std::to_string(v->key))+", "+v->str+"}\n";
        infOrder(v->right,way);
    }

    void postfOrder(QString& way)
    {
        postfOrder(root,way);
    }
    void postfOrder(node * v, QString& way)
    {
        if(v==nullptr)return;

        postfOrder(v->left,way);

        postfOrder(v->right,way);
        way+=QString::fromStdString("{"+std::to_string(v->key))+", "+v->str+"}\n";
    }
    node* getRoot() const
    {
        return root;
    }
};



#endif // BINSEARCHTREE_H
