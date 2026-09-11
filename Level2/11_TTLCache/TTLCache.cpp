// REQUIREMENTS
// build a key value cache where every stored item has an expiration time
// need a put(key, value, expiration_time) and get(key, now)
// MAIN RULES AND RESTRICTIONS
// must never return an expired data
// THOUGHT PROCESS
// we need to figure out how to store all these values.
// we can store key and value in a hashmap, but we need a third value, expiration date,
// im thinking of a Struct that would contain all these data like this
#include <vector>
#include <iostream>

struct Data {
    int key;
    int value;
    int expires_at;
};


class DataHandle {
    private:
    std::vector<Data> storage;

    public:
    void put(const Data& item) {
        for ( Data& x : storage){
            if (x.key == item.key){
                x = item; 
                return;
            }
        }
        storage.push_back(item);
    }

    int get(int key, int now){
        for (const Data& x : storage){
            if (key == x.key) {
                if (now >= x.expires_at) return -1;
                return x.value;
            }
        }
        return -1;
    }
};

int main () {
    
    std::vector<Data> items = {
    {1, 131232, 3},
    {2, 54321, 5},
    {3, 99999, 8},
    {4, 12345, 10}
    };

    DataHandle handler;

    for (const Data& x : items){
        handler.put(x);
    }

    std::cout << handler.get(3, 79) << std::endl;

    return 0;
}