/*
Description
simplify
we receive millions of timstamps every second
limiter allows at most 100k in the most recent 60 seconds
many events can have exactly the same timestamps,
that meanas storing one queue entry for eveyr single
event would waste a huge amount of space

Approach
*/

#include <unordered_map>
#include <queue>
#define LIMIT 100000

class Events {
public:
  int total = 0;

  std::unordered_map<int, int> storage; // timestamps and amt of reqs
  std::queue<int> timestamps; // timestamps in order

  bool record(int timestamp) {
    /* any time our timestamps are not empty
    and every time the distance between the given
    timestamp is  and oldest timestamp are more older
    than 60 we remoe the oldes one from our current total count,
    remove it from the timestamp queue and from the hashmap */
    while (!timestamps.empty() && timestamp - timestamps.front() >= 60) {

      int old = timestamps.front();
      total -= storage[old];
      storage.erase(old);
      timestamps.pop();
    }

    if (total >= LIMIT)
      return false;

    if (!storage.contains(timestamp))
      timestamps.push(timestamp);

    storage[timestamp]++;
    total++;
    
    return true;
  }
};