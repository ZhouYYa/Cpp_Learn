#pragma once
class inheritance
{
};


// Inheritance 继承，表示is-a

struct _List_node_base
{
    _List_node_base* _M_next;
    _List_node_base* _M_prev;
};

template<typename _Tp>
struct _list_node
    :publicd _List_node_base
{
    _Tp _M_data;
};

// 构造函数：先调用父类的构造函数，再调用子类的构造函数
// 析构函数：先调用父类的析构函数，再调用子类的析构函数
// base class 的析构函数必须是virtual，否则会出现undefined behavior.