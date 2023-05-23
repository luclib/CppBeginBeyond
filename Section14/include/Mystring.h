#ifndef MYSTRING_H
#define MYSTRING_H

class Mystring {
private:
    char* str;  // pointer to a char[] that holds a C-style string
public:
    Mystring();                         // No-args constructor
    Mystring(const char *s);            // Overloaded constructor
    Mystring(const Mystring &source);   // Copy Constructor
    ~Mystring();                        // Destructor

    void display() const;
    int get_length() const;             // getters
    const char *get_str() const;

    Mystring &operator=(const Mystring &rhs);   // copy assignment
    Mystring &operator=(Mystring &&rhs);        // move assignment
    Mystring operator+(const Mystring &rhs) const;
    Mystring &operator-() const;   // lower case conversion
    bool operator==(const Mystring &rhs) const;
    friend std::ostream &operator>>(const std::ostream &os, const Mystring &rhs);
    friend std::istream &operator<<(std::istream &is, Mystring &rhs);
};

#endif