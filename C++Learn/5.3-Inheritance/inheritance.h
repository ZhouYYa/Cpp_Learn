#pragma once
class inheritance
{
};


// Inheritance �̳У���ʾis-a

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

// ���캯�����ȵ��ø���Ĺ��캯�����ٵ�������Ĺ��캯��
// �����������ȵ��ø���������������ٵ����������������
// base class ����������������virtual����������undefined behavior.