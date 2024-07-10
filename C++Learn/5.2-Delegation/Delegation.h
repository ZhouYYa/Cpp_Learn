#pragma once
class Delegation
{
};
// Delegate Î¯ÍÐ£¬composition by reference.
class StringRep;
class String {
public:
    String();
    String(const char* s);
    String& operator=(const String& s);
    ~String();

private:
    StringRep* rep; // pimpl   pointer to implementaion
};

class StringRep {
    friend class String;
public:
    StringRep();
    ~StringRep();

};


//copy on wirte.