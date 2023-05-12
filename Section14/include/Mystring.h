#ifndef MYSTRING_H
#define MYSTRING_H

class Mystring {
private:
    char *str;  // C-style string

public:
    Mystring();                         // No-args constructor
    Mystring(const char *s);            // Overloaded constructor
    Mystring(const Mystring &source);   // Copy COnstructor
    ~Mystring();                        // Destructor
    void display() const;
    int get_length() const;             // getters
    const char *get_str() const;
};

#endif