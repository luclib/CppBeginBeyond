class Deep {
private:
    int *data;
public:
    int get_data_value();
    void set_data_value(int);
    Deep(int);
    Deep(const Deep &source);
    ~Deep();
};