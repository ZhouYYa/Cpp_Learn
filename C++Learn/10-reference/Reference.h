#pragma once
class Reference
{
};

int x = 0;
int* p = &x;
int& r = x; // r 代表x，现在r，x都是0.  引用一定要有初值。   
            // sizeof(r) == sizeof(x)
int x2 = 5;                               // &x == &r;
r = x2;         // r不能重新代表其他物体。
int& r2 = r;

// object和其reference的大小相同，地址也相同（全都是假象）

// reference常用在参数传递， pass by reference
// reference通常不用于声明变量，而用于参数类型和返回类型的描述。

double imag(const double& im) {}
double imag(const double im) {}
//      signature    same signature,不能同时存在
// const也是函数签名的一部分