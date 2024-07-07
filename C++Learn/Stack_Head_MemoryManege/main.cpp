#include "main.h"


/*
Stack, 存在于作用域（scope）的一块内存空间，如调用函数时，函数本身会形成一个stack
用来放置它所接收的参数，以及返回地址

在函数本体内声明的任何变量，其所使用的内存块都取自stack。

Heap，由操作系统提供的一块global内存控件，程序可动态分配

class Complex {....};
...
{
    Complex c1(1,2);      c1 占用的空间来自stack
     
    Complex *p = new Complex(3);  Complex(3) 占用的空间来自heap
}
*/

/*

local object的生命期：
{
    Complex c1(1,2);    其生命作用域结束之后消失。
}

static local object的生命期：
{
    static Complex c2(1, 2); 其生命在作用域结束后仍然存在，直到整个程序结束。
}

global object的生命期：
Complex c3(1, 2)     在整个程序结束之后结束。

heap object的生命期：

{
    Complex *p = new Complex;
    ...
    delete p;       在delete之后结束。
}

{
    Complex *p = new Complex;
    ...     
}                   这种存在内存泄露，作用域结束后仍然存在。
                    但p的生命结束了，作用于之外再也看不到p，也没机会delete p

*/

/*
    new: 先分配memory，再调用ctor
    delete: 先调用dtor，再释放memory

    array new 一定要搭配array delete
    String *p = new String[2];
    delete [] p;     // 调用3次dtor

    delete p;       //  调用1次dtor
*/

