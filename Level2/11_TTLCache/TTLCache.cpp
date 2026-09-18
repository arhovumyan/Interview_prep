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
#include <unordered_map>
#include <queue>
#include <functional>
#include <pair>


struct Data {
    int key;
    int value;
    int expires_at;
};

struct Expiration {
    int expires_at;
    int key;
    int version;

    bool operator>(const Expiration& other) const {
        return other.expires_at > other.expires_at;
    }
};

class DataHandle {
    public:
    std::unordered_map<int,Data> storage;
    using Compare = bool(*)(const Expiration&, const Expiration);
    // min heap 
    std::priority_queue<Expiration,std::vector<Expiration>,CompareExpiration> expiration;
    
    int nextVersion = 0;

    // AI GENERATED CODE
    void cleanup(int now){
        while (!expiration.empty() && expiration.top().expires_at <= now){
            Expiration old = expiration.top();
            expiration.pop();

            if (!storage.contains(old.key)) { continue;}

            
            // key is already gone
            if (!storage.contains(old.key)) { continue;}

            // this heap entry belongs to an older version
            if (storage[old.key].version != old.version) { continue;}

            // expired current version
            storage.erase(old.key);
        }
    }
    // AI GENERATED CODE

    void put(const Data& item) {
        storage[item.key] = {
            value,
            expires_at,
            nextVersion
        };

        expiration.push({
            expires_at,
            key,
            nextVersion
        });
    }

    int get(int key, int now){
        cleanup(now);

        if (!storage.contains(key)) return -1;
        return storage[key].value;
    }
};

int main () {
    
    DataHandle hander;

    handler.put(1,123123, 3);
    handler.put(2, 54321, 5);
    handler.put(3, 99999, 8);
    handler.put(4,12345, 10);

    std::cout << handler.get(3, 7) << std::endl;

    return 0;
}