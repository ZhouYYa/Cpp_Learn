#ifndef __STRING_H__
#define __STRING_H__

// Big Three
// 如果类中存在指针成员，必须包含三大块： 拷贝构造、拷贝复制、析构
#include <string>
#include <iostream>
class String
{
public:
    String(const char* cstr = 0);    
    String(const String& str);       // 拷贝构造
    String& operator = (const String& str);   // 拷贝复制
    ~String();

    char* get_c_str() { return m_data; }


private:
    char* m_data;


};

inline String::String(const char* cstr = 0)
{
    if (cstr) {
        m_data = new char[strlen(cstr) + 1];
        strcpy(m_data, cstr);
    }
    else {
        m_data = new char[1];
        *m_data = '\0';
    }
}

inline String::~String()
{
    delete[] m_data;
}

inline String::String(const String& str)
{
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
}

inline String& String::operator=(const String& str)
{
    if (this == &str)   // 检测自我赋值
        return *this;

    delete[] m_data;
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
    return *this;
}


#endif // !__STRING_H__

