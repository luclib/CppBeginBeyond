#include <iostream>
#include <vector>

class Move {
private:
    int *data;
public:
    int get_data_value(){
        return *data;
    }
    void set_data_value(int d){
        *data = d;
    }
    Move(int d){
        data = new int;
        *data = d;
        std::cout << "Constructor for: " << data
            << std::endl;
    }
    Move(const Move &source)
        : data{source.data} {
        std::cout << "Copy constructor - deep"
            << std::endl;
    }
    // Move(Move &&source) noexcept
    //     :data {source.data}{
    //         source.data = nullptr;
    //         std::cout << "Move constructor -moving resource: " << std::endl;
    // }
   ~Move(){  
        if(data != nullptr){
            std::cout << "Destructor freeing data for: " << *data << std::endl;
        }
        else {
            std::cout << "Destructor freeing data for nullptr" << std::endl;
        }       
    };
};

int main () { 
    std::vector<Move> vec;
    vec.push_back(Move{10}); // No variable name creates temp object (i.e. an r-value)
    vec.push_back(Move{20});
    // vec.push_back(Move{30});
    // vec.push_back(Move{40});
    // vec.push_back(Move{50});
    // vec.push_back(Move{60});
    // vec.push_back(Move{70});
    // vec.push_back(Move{80});
    return 0;
}