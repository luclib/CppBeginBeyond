class Shallow {
private:
    int *data;
public:
    void set_data_value(int d);
    int get_data_value();
    void display_data();
    Shallow(int d);
    Shallow(const Shallow &source);
    ~Shallow();
};