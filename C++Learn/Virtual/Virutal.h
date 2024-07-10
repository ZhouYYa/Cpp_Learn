#pragma once
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