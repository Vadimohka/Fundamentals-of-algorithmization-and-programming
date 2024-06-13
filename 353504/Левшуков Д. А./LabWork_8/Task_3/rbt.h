#ifndef RBT_H
#define RBT_H
#include<memory>
#include<forward_list>
template<typename T, typename T1> class RBT
{
protected:

    struct node
    {
        node*parent=nullptr;
        node* left=nullptr;
        node*right=nullptr;
        bool red;
        T key;
        T1 val;
        node(T key, T val)
        {
            this->key=key;
            this->val=val;
        }
    };
    node *root=nullptr;
public:

    void insert(T key, T1 val)
    {
        node* tmp = root;
        node* p=nullptr;
        while (tmp)
        {
            p=tmp;

            if (tmp->key > key)
                tmp = tmp->left;
            else if (tmp->key < key)
                tmp = tmp->right;
            else
                return;//exist
        }

        tmp = new node(key,val);
        tmp->parent=p;
        tmp->red=true;
        if (p!=nullptr)
        {
            if (tmp->key > p->key)
                p->right = tmp;
            else if (tmp->key < p->key)
                p->left = tmp;
        }
        else
            root = tmp;

        InsCase1(tmp);
    }

    void remove(T key)
    {
        qDebug()<<key;
        node* tmp=findNode(key);
        qDebug()<<tmp;
        if(!tmp)
            return;

        if(!tmp->parent&&!tmp->left&&!tmp->left)
        {
            root=nullptr;
            qDebug()<<" del root";
            return;
        }

        if(tmp->left&&tmp->right)
        {
            node* to_swap=tmp->left;
            while(to_swap->right)
                to_swap=to_swap->right;

            tmp->val=to_swap->val;
            tmp->key=to_swap->key;
            tmp=to_swap;
        }

        node * c;
        if(tmp->left)
            c=tmp->left;
        else
            c=tmp->right;

        if(!c)
        {
            if(!tmp->red)
                DelCase1(tmp);

            node*p=tmp->parent;
            if(p->left==tmp)
                p->left=c;
            else
                p->right=c;
        }
        else
        {
            c->parent=tmp->parent;
            node*p=tmp->parent;
            if(tmp->parent)
            {
                if(tmp==p->left)
                    p->left=c;
                else
                    p->right=c;
            }
            else
            {
                root=c;
                if(!tmp->red)
                {
                    if(c->red)
                        c->red=false;
                    else
                        DelCase1(c);
                }
            }
        }
    }

    bool contains(T key)
    {
        return findNode(key);
    }



    size_t size()
    {
        return Size(root);
    }

    class Iterator {
    protected:
        node *cur;
        friend class RBT<T, T1>;
        Iterator(node *root, bool left=true)
        {
            cur =root;
            if(!cur)return;
            if(left)
            {
                while (cur->left)
                    cur = cur->left;
            }
            else
            {
                while (cur->right)
                    cur = cur->right;
            }
        }

        node* right(node *root)
        {
            node *tmp=root;
            if(!tmp)return nullptr;

            while (!tmp->right)
                tmp = tmp->right;
            return tmp;
        }
        node* left(node *root)
        {
            node *tmp=root;
            if(!tmp)return nullptr;
            while (!tmp->left)
                tmp = tmp->left;
            return tmp;
        }
    public:

        node *operator->()
        {
            return cur;
        }

        node &operator*()
        {
            return *cur;
        }

        Iterator &operator++() {
            if (!cur)
                return *this;

            if (cur->right != nullptr) {
                cur = cur->right;

                while (cur->left != nullptr)
                    cur = cur->left;
            } else {
                while (cur->parent != nullptr && cur->parent->right == cur) {
                    cur = cur->parent;
                }
                cur = cur->parent;
            }


            return *this;
        }

        bool operator==(const Iterator &other) {
            return cur == other.cur;
        }

        bool operator!=(const Iterator &other)
        {
            return !(*this == other);
        }

    };

    Iterator begin()
    {
        //qDebug()<<Iterator(Iterator::left(root));
        return Iterator(root,1);
    }

    Iterator end()
    {
        //qDebug()<<Iterator(Iterator::right(root));
        //return Iterator(root,0);
        return Iterator(nullptr);//without move;
    }

protected:

    node * findNode(T key)
    {
        qDebug()<<"ROOT:"<<root<<" "<<"KEY "<<key;
        return find(key,root);
    }

    node *find(T key, node *v)
    {

        if(v==nullptr)return nullptr;
        qDebug()<<v->key<<" "<<key;
        if(v->key==key)return v;
        if(v->key>key)return find(key,v->left);
        if(v->key<key)return find(key,v->right);
    }
    node * grandparent(node *v)//parent parent
    {
        node *p=v->parent;
        if(p&&p->parent)
            return p->parent;
        return nullptr;
    }

    node * uncle(node *v)//sibling of parent
    {
        node * tmp=grandparent(v);
        if(!tmp)
            return nullptr;
        if(tmp->left==v->parent)
            return tmp->right;
        return tmp->left;
    }

    node * sibling(node *v)
    {
        if(!v->parent||!v)
            return nullptr;
        if(v->parent->left==v)
            return v->parent->right;
        return v->parent->left;
    }

    void RotateLeft(node *v)
    {
        node * r=v->right;
        r->parent=v->parent;
        if(v->parent)
        {
            if(v->parent->left==v)
            {
                v->parent->left=r;
            }
            else
                v->parent->right=r;
        }
        else
            root=r;

        v->right=r->left;

        if(r->left)
            r->left->parent=v;

        v->parent=r;
        r->left=v;
    }

    void RotateRight(node *v)
    {
        struct node *left = v->left;

        left->parent = v->parent;
        if (v->parent)
        {
            if (v->parent->left==v)
                v->parent->left = left;
            else
                v->parent->right = left;
        }
        else
            root=left;

        v->left = left->right;
        if (left->right)
            left->right->parent = v;

        v->parent = left;
        left->right = v;
    }

    void InsCase1(node *v)
    {
        if(!v->parent)//root
            v->red=false;
        else
            InsCase2(v);
    }

    void InsCase2(node *v)
    {
        if(!v->parent->red)
        {
            return;
        }
        InsCase3(v);
    }

    void InsCase3(node *v)
    {
        node *u=uncle(v);

        if(u&&u->red)
        {
            v->parent->red=u->red=false;
            node *g=grandparent(v);
            g->red=true;
            InsCase1(g);
        }
        else
            InsCase4(v);
    }

    void InsCase4(node *v)
    {
        node *g=grandparent(v);
        node *p=v->parent;
        node *tmp=v;

        if(v==p->right&&p==g->left)
        {
            RotateLeft(p);
            tmp=v->left;
        }
        else if(v==p->left&&p==g->right)
        {
            RotateRight(p);
            tmp=v->right;
        }

        InsCase5(tmp);
    }

    void InsCase5(node *v)
    {
        node * g = grandparent(v);
        node * p = v->parent;
        p->red = false;
        g->red = true;

        if (v==p->left) {
            RotateRight(g);
        } else {
            RotateLeft(g);
        }
    }

    void DelCase1(node *v)
    {
        if(v->parent)//is root
            DelCase2(v);
    }

    void DelCase2(node *v)
    {
        node * sib=sibling(v);
        node * r=v->parent;//root of sibling and v

        bool red;
        if(sib)
            red=sib->red;
        else
            red=false;
        if(red)
        {
            r->red=true;
            sib->red=false;

            if(v==r->left)
                RotateLeft(r);
            else
                RotateRight(r);
        }

        DelCase3(v);
    }

    void DelCase3(node *v)
    {
        node* s = sibling(v);

        bool sred = s ? s->red : false;
        bool lred = s && s->left ? s->left->red : false;
        bool rred = s && s->right ? s->right->red : false;

        if(!v->parent->red&&!sred&&!lred&&!rred)
        {
            if(s)
                s->red=true;
            DelCase1(v->parent);
        }
        else
            DelCase4(v);
    }

    void DelCase4(node *v)
    {
        node* s = sibling(v);

        bool sred = s ? s->red : false;
        bool lred = s && s->left ? s->left->red : false;
        bool rred = s && s->right ? s->right->red : false;

        if(v->parent->red&&!sred&&!lred&&!rred)
        {
            if(s)
                s->red=true;
            v->parent->red=false;
        }
        else
            DelCase5(v);
    }

    void DelCase5(node *v)
    {
        node * s=sibling(v);
        bool lred = s && s->left ? s->left->red : false;
        bool rred = s && s->right ? s->right->red : false;

        if(!s->red)
        {
            if(v==v->parent->left&&!rred&&lred)
            {
                s->red=true;
                s->left->red=false;
                RotateRight(s);
            }
            else
                if(v==v->parent->right&&!lred&&rred)
                {
                    s->red=true;
                    s->right->red=false;
                    RotateLeft(s);
                }
        }
        DelCase6(v);
    }

    void DelCase6(node *v)
    {
        node *s=sibling(v);
        s->red=v->parent->red;
        v->parent->red=false;

        if(v==v->parent->left)
        {
            if(s->right)
                s->right->red=false;
            RotateLeft(v->parent);
        }
        else
        {
            if(s->left)
                s->left->red=false;
            RotateRight(v->parent);
        }
    }

    int Size(node* n)
    {
        if (n == nullptr)
            return 0;
        return 1 + Size(n->left) + Size(n->right);
    }

};

template <typename T, typename T1> class Map: public RBT<T, T1> {
    using RBT = RBT<T, T1>;
public:
    Map()
    {
        f.resize((int)1e6);
    }
    T1& operator[](const T& key)
    {
        auto t = RBT::findNode(key);
        if(t)
            return t->val;
        return RBT::insert(key, T1())->val;
    }
    const T1 operator[](const T& key) const
    {
        return *this[key];
    }

    int hash(T key)
    {
        return (int)key%(int)1e6;
    }

    void insert(T key,T1 val)
    {
        qDebug()<<key<<" "<<hash(key);
        RBT::insert(hash(key), val);
    }

private:
    std::forward_list<std::pair<const T,bool>>f;
};

template <typename T> class Set: public RBT<T, bool> {
    using RBT = RBT<T, bool>;
public:
    Set()
    {
        f.resize((int)1e6);
    }
    int hash(T key)
    {
        return (int)key%(int)1e6;
    }
    void insert(T&& val)
    {

        RBT::insert(hash(val), false);
    }
private:
    std::forward_list<std::pair<const T,bool>>f;
};
#endif // RBT_H
