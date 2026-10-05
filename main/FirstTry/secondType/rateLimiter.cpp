/*
you are building a rate limiter
you will be passed in the id of the user and the timestamp. 
something like this    std::cout << limiter.allow(1,1) << std::end;
you can only have 3 requests in a 10 second time window at most 
*/

/*
PLAN
create a class that stores the userId and timestamp of each request
create a function that will stack all the current requests on top of each other
when we hit a limit of 3, we hit the ceiling and we can no longer accept more requests
    unless the currentTimeWindow - firstRequestWindow <= 10

lets understand how we should store these values that are passed in to us
you will need to store all the requests one by one for each id
how about you store the currentRequests mapped to the id and it's timestamp 
so for this you will need to store a std::pair<int,std::vector<int,int>> userRequests
the int in the pair will store the requestID and the vector will store the userId and the reqTimestamp

WHAT DS TO USE
since we need to pop all the old timstamps(smaller numbers that are appearing int he beginning)
we can use a min-heap, then track our currentReqTime compared with the initial req's timestamp
you can compare like this, the latestElement.timestamp - firstElement.timestamp
if their difference is > 10, then we pop the first element, if not, keep stacking reqs in
we keep stacking while we have not reached our req limit, once we reach our cap, we pop the first element

*/
#include <vector>
#include <queue>
#include <iostream>
#include <functional>

class RateLimiter {
private: 
    static const int MAX_REQUESTS = 3;
    
    // this is for storing all the accepted requests as {timestamp, userId}
    std::priority_queue<
        std::pair<int,int>, // what to store
        std::vector<std::pair<int,int>>, // how to store it 
        std::greater<std::pair<int,int>>  // how to compare it
    > minHeap;

public: 
    void addRequest(int id, int time){
        minHeap.push({time,id});
    }

    bool allow(int userId, int timestamp){

        // store the requests temporarily while we inspect them
        std::vector<std::pair<int,int>> temp;
        int userRequestCount = 0;
        // {{1,1}, {}}
        // {1,1} {2,1} {2,2} {5,1} {6,2} {7,1} {11,1} {12,2} {15,1} {16,3}
        // look through the heap
        while (!minHeap.empty()){
            auto current = minHeap.top();
            minHeap.pop();
            if (timestamp - current.first < 10){
                // count if our userIds match
                if (current.second == userId) userRequestCount++; 
                temp.push_back(current);
            }
        }

        for (auto request : temp) minHeap.push(request);
            
        if (userRequestCount >= MAX_REQUESTS) return false;

        addRequest(userId, timestamp);

        return true;
    }
};

int main () {
    RateLimiter limiter;

    std::cout << limiter.allow(1, 1) << std::endl;   // true
    std::cout << limiter.allow(1, 2) << std::endl;   // true
    std::cout << limiter.allow(1, 5) << std::endl;   // true
    std::cout << limiter.allow(1, 6) << std::endl;   // false

    std::cout << limiter.allow(2, 6) << std::endl;   // true

    return 0;
}