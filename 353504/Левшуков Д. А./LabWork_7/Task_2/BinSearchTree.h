#ifndef BINSEARCHTREE_H
#define BINSEARCHTREE_H
#include <QString>
#include <QVector>
class bst{
    struct node
    {
        int key;
        QString str;
        node * left=nullptr;
        node * right=nullptr;
        node(int key, QString s){this->key=key;str=s;}
    };
    node * root=nullptr;

public:
    bst(){}

    void fill(QVector<std::pair<int,QString>>data)
    {
        for(auto i:data)
            insert(i.first,i.second);
    }

    void insert(node * v=root,int key,QString str)
    {
        if(v==nullptr)
        {
            v=new node(key,str);
            return;
        }
        if(key<=v->key)
        {
            insert(v->left,key,str);
            return;
        }
        insert(v->right,key,str);
    }

    QString find(node * v =root,int key)
    {
        if(v==nullptr)
            return "";
        if(v->key==key)
            return v->str;
        if(key<=v->key)
        {
            find(v->left,key);
            return;
        }
        find(v->right,key);

    }

    void remove(int key, node *v=root,node * pred=nullptr,bool left=false)
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
                Data * Successor = v->right;//Find minimal in right subtree
                while(Successor->left!=nullptr)
                    Successor=Successor->left;

                v->key=Successor->key;
                v->info=Successor->info;
                remove(Successor->key,v->right,tree,true); //delete old version
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

    void balance(node * v=root)
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
                Rrotate(v->left);
            Lrotate(v);
        }

        balance(v->left);
        balance(v->right);

    }


    void Lrotate(node *v)
    {
        node * temp=v->right;
        v->right=temp->left;
        temp->left=v;
        v=temp;
    }

    void Rrotate(node *v)
    {
        node * temp=v->left;
        v->left=temp->right;
        temp->right=v;
        v=temp;
    }

    int leaves()
    {

    }

    //orders
    void prefOrder(node * v, QString& way)
    {
        if(v==nullptr)return;
        way+=QString::fromStdString("{"+std::to_string(v->key))+", "+v->info+"}";
        prefOrder(v->left,way);
        prefOrder(v->right,way);
    }

    void infOrder(node * v, QVector<QString>& way)
    {
        if(v==nullptr)return;

        infOrder(v->left,way);
        way+=QString::fromStdString("{"+std::to_string(v->key))+", "+v->info+"}";
        inffOrder(v->right,way);
    }

    void postfOrder(node * v, QVector<QString>& way)
    {
        if(v==nullptr)return;

        postfOrder(v->left,way);

        postfOrder(v->right,way);
        way+=QString::fromStdString("{"+std::to_string(v->key))+", "+v->info+"}";
    }
};

#endif // BINSEARCHTREE_H
