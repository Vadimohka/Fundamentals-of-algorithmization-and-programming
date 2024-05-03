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

int main()
{
    Expression *c=new Number(4.5);
    std::cout<<std::endl<<c->evalute()<<std::endl;

    Expression *q=new BinaryOperation(new Number(4.5), '+', new Number(5));
    std::cout<<q->evalute()<<std::endl;
    //return 0;

    Expression *sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    std::cout<<sube->evalute()<<std::endl;

    // потом используем его в выражении для +
    Expression* expr = new BinaryOperation(new Number(3), '+', sube);
    // вычисляем и выводим результат: 25.5
    std::cout << expr->evalute() << std::endl;

    delete expr;
    delete c;
    delete q;
}
