#pragma once
class Virutal
{
public:
    virtual void draw() const = 0;
    virtual void error(const std::string& msg);
    int objectId() const;
};

// Inheritance with virtual functions
// non-virtual�������㲻ϣ��derived class���¶��壨override����
// virtual��������ϣ��derived class�������¶��壨override�������Ҷ�������Ĭ�϶���
// virtual��������ϣ��derived classһ��Ҫ���¶��壨override�������Ҷ���û��Ĭ�϶���


// Template Method