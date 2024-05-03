#include <iostream>

class Expression{//abstract class
public:
    virtual double evalute()=0;//Full virtual
};

class Number:public Expression{
private:
    double ch;
public:
    double evalute() override
    {
        return ch;
    }
    Number(double num)
    {
        ch=num;
    }
};

class BinaryOperation:public Expression{
private:
    Expression *a,*b;
    char type;
public:
    BinaryOperation(Expression* l,char t,Expression *r){
        type=t;
        a=l;
        b=r;
    }
    ~BinaryOperation(){
        delete a;
        delete b;
        a=b=nullptr;
    }
    double evalute() override
    {
        if(type=='+')
            return a->evalute()+b->evalute();
        if(type=='-')
            return a->evalute()-b->evalute();
        if(type=='*')
            return a->evalute()*b->evalute();
        if(type=='/')
        {
            double res;
            try
            {
                res=a->evalute()/b->evalute();
            }
            catch(...)
            {
                std::cout<<"Right argument = 0";
                return 0;
            }
            return res;
        }

    }

};

char a[10];
bool check_equals(Expression const* left, Expression const* right)
{
    bool check=(*((auto)left))==(*((auto)right));
    return check;
    std::cout<<*left<<" "<<*right<<"\n";
    std::cout << "a == b == " << ((void*)left == (void*)right) << std::endl;
 return ((void(*(*(&)[2]))(const Expression&))left)[0][0] == ((void(*(*(&)[2]))(const Expression&))right)[0][0];


}


int main()
{
    auto *ch1=new Number(14.123123);
    auto *ch2=new Number(88.6666666);
    auto *bin_op1=new BinaryOperation(ch1,'+',ch2);
    auto *bin_op2=new BinaryOperation(ch2,'-',ch1);
    auto *bin_op3=new BinaryOperation(bin_op1,'*',bin_op2);

    //a[0]=a[1]=1000;
    std::cout<<'\n'<<check_equals(ch1,ch2);
    std::cout<<'\n'<<check_equals(ch1,bin_op1);
    std::cout<<'\n'<<check_equals(ch1,bin_op2);
    std::cout<<'\n'<<check_equals(ch1,bin_op3);
    std::cout<<'\n'<<check_equals(ch2,bin_op1);
    std::cout<<'\n'<<check_equals(ch2,bin_op2);
    std::cout<<'\n'<<check_equals(ch2,bin_op3);
    //std::cout<<'\n'<<size_t(a)<<" "<<*((size_t*)(a))<<" "<<sizeof(a);
}
