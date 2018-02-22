template <typename T>
class hashmap
{
private:
    int* data;
    int current_size;
    T hashfunc(int key, int current_size);
public:
    hashmap() : current_size(40) {
        data = new int[current_size];
    }
    
    
};
    
    
