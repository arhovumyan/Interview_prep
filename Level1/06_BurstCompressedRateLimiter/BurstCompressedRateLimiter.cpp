// you're going to receive requests
// some will be at the same timestamp
// you need to memorize what you store and at what freq each timestamp appears

#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <queue>

class Limiter {
    public:
    std::queue<std::pair<int,int>> requests;
    int total = 0;

   bool decider(int timestamp, int limit){
        // Remove old timestamp groups that are no longer
        // inside the last 60 seconds
        while (!requests.empty() &&
            timestamp - requests.front().first >= 60) {

            // Remove those old requests from the total count
            total -= requests.front().second;

            // Remove the oldest timestamp group from the queue
            requests.pop();
        }

        // If we already reached the limit,
        // reject this new request
        if (total >= limit)
            return false;

        // We are accepting this request,
        // so increase the total number of requests in the window
        total++;

        // If the newest stored timestamp is the same
        // as this new request's timestamp...
        if (!requests.empty() &&
            requests.back().first == timestamp)

            // ...increase the count for that timestamp
            requests.back().second++;

        // Otherwise, this is a new timestamp,
        // so add it with a count of 1
        else
            requests.push({timestamp, 1});

        // Request was accepted
        return true;
    }
};

int main () {
    Limiter rate;

    std::vector<std::pair<int,int>> input = {
        {1, 3},
        {1, 3},
        {3, 3},
        {5, 3},
        {5, 3},
        {10, 3},
        {61, 3},
        {62, 3}
    };

    for (int i = 0 ; i < input.size();i++){
        int timestamp = input[i].first;
        int limit = input[i].second;

        bool result = rate.decider(timestamp, limit);
        std::cout << result << std::endl;
    };

    return 0;
}