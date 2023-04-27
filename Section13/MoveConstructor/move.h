class Move {
private:
    int *data;
public:
    int get_data_value();
    void set_data_value(int);
    Move(int d);                
    Move(const Move &source);   
    Move(Move &&source);        // Move Constructor
    ~Move();               
};