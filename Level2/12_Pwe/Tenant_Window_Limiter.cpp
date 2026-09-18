// each tenant id has its own independent lmit(a pair or a hashmap)
// timestamp is in nondecreasing order so we are supposed to have a minheap probably
#include <deque>
#include <unordered_map>

std::unordered_map<int, std::deque<int>> requests;

class Tenants {
    void put (int id, int timestamp){
        requests.push({id, requestsPerPerson});
    }
    void checker (const People& peeps){
        // if 
    }
};

int main () {
    Tenants tens;

    for (int i = 0; i < tens.size(); i++){

    }
}