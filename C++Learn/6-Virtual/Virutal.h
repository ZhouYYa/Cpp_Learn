#pragma once

#include <iostream>

class Virutal
{
public:
    virtual void draw() const = 0;
    virtual void error(const std::string& msg);
    int objectId() const;
};

// Inheritance with virtual functions
// non-virtual函数：你不希望derived class重新定义（override）它
// virtual函数：你希望derived class可以重新定义（override）它，且对它已有默认定义
// virtual函数：你希望derived class一定要重新定义（override）它，且对它没有默认定义


// Template Method


// Inheritance + Compositon
namespace IC {
    // 构造顺序： Base -> Componet -> Derived
    class Base {
    public:
        Base() {
            std::cout << "this is Base ctor." << std::endl;
        }
        ~Base() {
            std::cout << "this is Base dtor." << std::endl;
        }
    };

    class Component {
    public:
        Component() {
            std::cout << "this is Component ctor." << std::endl;
        }
        ~Component() {
            std::cout << "this is Component dtor." << std::endl;
        }
        void func() {
            std::cout << "component fun." << std::endl;
        }
    };

    class Derived : public Base {
        friend class Component;
    public:
        Derived() {
            std::cout << "this is Derived ctor." << std::endl;
        }
        ~Derived() {
            std::cout << "this is Derived dtor." << std::endl;
        }
    public:
        Component com;
        void func() {
            std::cout << "Derived func." << std::endl;
            com.func();
        }
    };
}

namespace IC2 {
    // 构造顺序： Componet -> Base -> Derived
    class Component {
    public:
        Component() {
            std::cout << "this is Component ctor." << std::endl;
        }
        ~Component() {
            std::cout << "this is Component dtor." << std::endl;
        }
        void func() {
            std::cout << "component fun." << std::endl;
        }
    };
    class Base {
        friend class Component;
    public:
        Base() {
            std::cout << "this is Base ctor." << std::endl;
        }
        ~Base() {
            std::cout << "this is Base dtor." << std::endl;
        }
        Component com;
        void func() {
            std::cout << "Base func." << std::endl;
            com.func();
        }
        

    };
    class Derived : public Base {
        //friend class Component;
    public:
        Derived() {
            std::cout << "this is Derived ctor." << std::endl;
        }
        ~Derived() {
            std::cout << "this is Derived dtor." << std::endl;
        }
    public:
        //Component com;
        void func() {
            std::cout << "Derived func." << std::endl;
            //com.func();
        }
    };
}


// Delegation + Inheritance
namespace DI {
    class Observer {
    public:
        virtual void update() {};
    };
    class Subject {
        int m_value;
        vector<Observer*> m_views;
    };

    // Composite
    class Component 
    {
        int value;
    public:
        Component(int val) { value = val; }
        virtual void add(Component*) { }
    };

    class Primitive :public Component
    {
    public:
        Primitive(int val) :Component(val) { }
    };

    class Composite :public Component
    {
        vector<Component*> c;
    public:
        Composite(int val) :Component(val) { }
        void add(Composite* e) {
            c.push_back(e);
        }
    };

    // Prototype


}
int main()
{
    IC::Derived a;
    a.func();

    IC2::Derived b;
    b.func();
    return 0;
}