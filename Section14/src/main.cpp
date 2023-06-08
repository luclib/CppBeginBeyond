#include <iostream>
#include <Mystring.h>


int main() {

    // Strea
    Mystring larry{"Larry"};
    Mystring moe {"Moe"};
    Mystring curly;

    std::cout << "Enter the third stooger's first name: ";
    std::cin >> curly;

    std::cout << "The three stoogers are " << larry << ", " << moe << ", and " << curly << std::endl;
    
    std::cout << "\nEnter the three stooges names separated by a space: ";
    std::cin >> larry >> moe << curly;

    std::cout << "The three stooges are " << larry << ", " << moe << ", and " << curly << std::endl;
    /*
    std::cout << std::boolalpha << std::endl;

    Mystring larry {"Larry"};
    Mystring moe {"Moe"};

    Mystring stooges { " is one of the three stooges"};
    Mystring result = larry + stooges;

    result.display();

    result = moe + " is also a stooge";

    result.display();
    */
    

    /* 
    Mystring stooge = larry;
    larry.display();
    moe.display();

    std::cout << (larry == moe) << std::endl;
    std::cout << (larry == stooge) << std::endl;

    larry.display();
    Mystring larry2 = -larry;
    larry2.display();           // larry

    Mystring stooges = larry + "Moe";// ok with member function  
                              // Compiler error
    
    Mystring two_stooges = moe + " " + "Larry";
    two_stooges.display();      
                                                   // Moe Larry
    Mystring three_stooges = moe + " " + larry + " " +  "Curly";
    three_stooges.display();               
    */

    /*
    Mystring a {"Hello"};   // Overloaded constructor
    a = Mystring{"Hola"};   // Overloaded constructor then move assignment
    a = "Bonjour";          // Overloaded constructor then move assignment
    */

    /*
    Mystring a {"Hello"};   // overloaded consturctor
    Mystring b;             // no-args constructor
    b = a;                  // copy assignment
                            // b.operator = (a)
    b = "this is a test";   // b.operator=("This is a test")
    */

    /*
    Mystring empty;
    Mystring kratos("Kratos");
    Mystring stooge{"Kratos"};

    empty.display();
    kratos.display();
    stooge.display();
    */
    
    return 0;
}