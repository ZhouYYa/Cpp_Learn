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


// ����::operator new, ::operator delete
// ::operator new[], ::operator delete[]

void* myAlloc(size_t size)
{
    return malloc(size);
}

void* myFree(void* ptr)
{
    return free(ptr);
}

// ���ǲ����Ա�������һ��namespace��
inline void* operator new(size_t size)
{
    cout << "" << endl;
    return myAlloc(size);
}

inline void* operator new[](size_t size)
{
    cout << "" << endl;
    return myAlloc(size);
}

inline void operator delete(void* ptr)
{
    cout << "" << endl;
    return myFree(ptr);
}

inline void operator delete[](void* ptr)
{
    cout << "" << endl;
    return myFree(ptr);
}

// ����member operator new/delete
class Foo {
public:
    void* operator new(size_t);
    void operator delete(void*, size_t); // size_t is optional.

};

// Foo *p = new Foo;   void* mem = operator new(sizeof(Foo));
//                     p = static_cast<Foo*>(mem);
//                     p->Foo::Foo();

// delete p;           p->~Foo();
//                     operator_delete(p);

