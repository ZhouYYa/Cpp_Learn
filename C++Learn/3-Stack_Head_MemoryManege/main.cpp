#include "main.h"


/*
Stack, ������������scope����һ���ڴ�ռ䣬����ú���ʱ������������γ�һ��stack
���������������յĲ������Լ����ص�ַ

�ں����������������κα���������ʹ�õ��ڴ�鶼ȡ��stack��

Heap���ɲ���ϵͳ�ṩ��һ��global�ڴ�ؼ�������ɶ�̬����

class Complex {....};
...
{
    Complex c1(1,2);      c1 ռ�õĿռ�����stack
     
    Complex *p = new Complex(3);  Complex(3) ռ�õĿռ�����heap
}
*/

/*

local object�������ڣ�
{
    Complex c1(1,2);    ���������������֮����ʧ��
}

static local object�������ڣ�
{
    static Complex c2(1, 2); ���������������������Ȼ���ڣ�ֱ���������������
}

global object�������ڣ�
Complex c3(1, 2)     �������������֮�������

heap object�������ڣ�

{
    Complex *p = new Complex;
    ...
    delete p;       ��delete֮�������
}

{
    Complex *p = new Complex;
    ...     
}                   ���ִ����ڴ�й¶���������������Ȼ���ڡ�
                    ��p�����������ˣ�������֮����Ҳ������p��Ҳû����delete p

*/

/*
    new: �ȷ���memory���ٵ���ctor
    delete: �ȵ���dtor�����ͷ�memory

    array new һ��Ҫ����array delete
    String *p = new String[2];
    delete [] p;     // ����3��dtor

    delete p;       //  ����1��dtor
*/

