#include <list>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <utility>

class LRU {
    public:
    std::unordered_map<int,int> cache;
    std::list<int> order;

    int capacity;

    LRU(int cap){
        capacity = cap;
    }

    void put(int key, int value){
        order.remove(key);
        cache[key] = value;
        order.push_front(key);

        if (capacity < cache.size()){
            int leastUsed = order.back();
            order.pop_back();
            cache.erase(leastUsed);
        }
    }

    int getter(int key){
        if (!cache.contains(key)) return -1;

        order.remove(key);
        order.push_front(key);

        return cache[key];
    }
};

int main () {
    LRU metadata(5);

    std::vector<std::pair<int,int>> input = {
        {1,4},
        {2,42},
        {3,41},
        {4,12224},
        {5,412},
        {6,234},
        {7,98},
        {8,4356},
        {9,415},
        {10,4},
        {11,123},
        {12,5},
    };

    for (int i = 0; i < input.size(); i++){
        metadata.put(input[i].first, input[i].second);
    }

    for (int i = 0; i < input.size(); i++){
        std::cout << "The value for key: " << input[i].first 
        << ", is " << metadata.getter(input[i].first) << std::endl;
    }
    
    std::cout << metadata.getter(3) << std::endl;
    
    return 0;
}

