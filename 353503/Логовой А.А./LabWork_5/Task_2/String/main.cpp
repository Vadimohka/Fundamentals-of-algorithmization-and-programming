#include<String.h>
#include<QDebug>

int main(int argc, char *argv[])
{

    String s1;
    qDebug() << "s1:" << s1.c_str();

    const char* cstr = "Hello, World!";
    String s2(cstr);
    qDebug() << "s2:" << s2.c_str();

    String s3(s2);
    qDebug() << "s3:" << s3.c_str();

    String s4("Lorem ipsum", 5);
    qDebug() << "s4:" << s4.c_str();

    s1 = "Assignment";
    qDebug() << "s1:" << s1.c_str();

    return 0;
}
