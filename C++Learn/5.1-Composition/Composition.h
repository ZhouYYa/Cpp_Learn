#pragma once
class Composition
{
};

// Composition ���� ��ʾhas-a
template <class T, class Sequnce = deque<T> >
class queue {
    //...
protected:
    Sequence c;
public:
    bool empty() const (return c.empty());
    size_type size() const { return c.size(); }
};

// ���ģʽ��Adapter
template <class T>
class queue {
    //...
protected:
    deque<T> c;
public:
    bool empty() const (return c.empty());
    size_type size() const { return c.size(); }
};
// container <->----->  component 
// ���Ϲ�ϵ�µĹ����������
// 1. �ȵ���component�Ĺ��죬�ٵ���container�Ĺ���
// 2. �ȵ���component���������ٵ���container������