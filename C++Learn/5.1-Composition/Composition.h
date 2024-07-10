#pragma once
class Composition
{
};

// Composition 复合 表示has-a
template <class T, class Sequnce = deque<T> >
class queue {
    //...
protected:
    Sequence c;
public:
    bool empty() const (return c.empty());
    size_type size() const { return c.size(); }
};

// 设计模式：Adapter
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
// 复合关系下的构造和析构：
// 1. 先调用component的构造，再调用container的构造
// 2. 先调用component的析构，再调用container的析构