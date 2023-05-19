#include <iostream>
#include <cstring>
#include <Mystring.h>

// No-args constructor
Mystring::Mystring()
    :str{nullptr}{
    str = new char[1]; // Point to char[] with null value
    *str = '\0';
}

// Overloaded construtor
Mystring::Mystring(const char *s)
    : str(nullptr){
        if(s==nullptr){
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[std::strlen(s)+1];
            std::strcpy(str, s);
        }
}

// Copy constructor
Mystring::Mystring(const Mystring &source)
    :str{nullptr}{
        str = new char[std::strlen(source.str)+1];
        std::strcpy(str, source.str);
}

// Destructor
Mystring::~Mystring(){
    if (str == nullptr){
        std::cout << "Calling destructor Mystring : nullptr\n";
    } else {
        std::cout << "Calling destructor for Mystring : " << str << std::endl;
    }
    delete [] str;
}

// Display method
void Mystring::display() const{
    std::cout << str << " : " << get_length() << std::endl;
}

// length getter
int Mystring::get_length() const{
    return std::strlen(str);
}

// string getter
const char *Mystring::get_str() const{
    return str;
}

// copy assignment
Mystring &Mystring::operator=(const Mystring &rhs){
    std::cout << "Copy assignment\n";
    if (this == &rhs)   // If we are the same object
        return *this;   // just return the object
    
    delete [] this->str;  // Use '[]' since str is a char array
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(this->str, rhs.str);

    return *this;
}

// move assignment
Mystring &Mystring::operator=(Mystring &&rhs){
    std::cout << "Using move assignment\n";
    if(this == &rhs)
        return *this;
    delete [] this->str;
    this->str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

// Concatenate
Mystring Mystring::operator+(const Mystring &rhs) const {
    char *buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, str);
    std::strcat(buff, rhs.str);
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

// inversion operator
Mystring &Mystring::operator-() const {
    std::cout << "Converting string to lower case...\n";
    char *buff = new char[std::strlen(this->str)+1];
    std::strcpy(buff, this->str);
    for(int i = 0; i < std::strlen(buff); i++){
        buff[i] = std::tolower(buff[i]);
    }
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

// Equality
bool Mystring::operator==(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) == 0);
}

// Extraction
std::istream &operator>>(std::istream &is, Mystring &rhs){
  char *buff = new char[1000];
  is >> buff;
  rhs = Mystring{buff};
  delete buff;
  return is;
}
// Overloaded Insertion
std::ostream &operator<<(const std::ostream &os, const Mystring &rhs){
    os << rhs.str;
    return os;
}