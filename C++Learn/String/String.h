#ifndef __STRING_H__
#define __STRING_H__

// Big Three
// ������д���ָ���Ա�������������飺 �������졢�������ơ�����
#include <string>
#include <iostream>
class String
{
public:
    String(const char* cstr = 0);    
    String(const String& str);       // ��������
    String& operator = (const String& str);   // ��������
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
    if (this == &str)   // ������Ҹ�ֵ
        return *this;

    delete[] m_data;
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
    return *this;
}


#endif // !__STRING_H__

