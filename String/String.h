#pragma once
#include <cstring>

class String {

private:

    size_t m_len;
    char * m_str;

    void copy(const char *, const size_t &);
    String* divide(const char *, const size_t &) const;

public:

    String();

    String(const char * str);

    String(const String & copy);

    ~String();


    const bool operator==(const String &);

    const size_t length() const;
    void print() const;

    void append(const String & str);
    void append(const char * str);
    String substr(const unsigned int & position, const unsigned int & num) const;
    String* split(const char &) const;
    void replace(const char *, const char *);
};
