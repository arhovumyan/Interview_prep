/*
at most 20 request in last 10 seconds
the time, timestamps are not guaranteed to be in increasing order.

approach*/
#include <iostream>
#include <vector>
#include <map>

#define LIMIT 20

class Events {
public:
    std::map<int, int> storage;

    bool record(int timestamp) {
        int total = 0;
        // lower_bound means stop at 'x' if you are on 'x' or something bigger than 'x'
        // upper_bound means stop when you are strictly above 'x
        auto start = storage.lower_bound(timestamp - 9);
        auto end = storage.upper_bound(timestamp);

        for (auto it = start; it != end; ++it) {
            total += it->second;
        }

        if (total >= LIMIT)
            return false;

        storage[timestamp]++;
        return true;
    }
};

int main() {
  Events october;
  std::vector<int> storage = {{104, 105, 106, 109, 199, 114}};
  
  for (int i : storage) {
    std::cout << october.record(i) << std::endl;
  }

  return 0; 
}