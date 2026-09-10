#include <iostream>
#include <vector>
#include <utility>
#include <queue>

class Request {
public:
    std::queue<int> timestamps;
    bool request (int timestamp, int limit){
        // should remove if given timestamp > older timestamp by 60+ (queue)
        // if the current queue is more than the current limit, then pop one from the front;
            
        while (!timestamps.empty() && timestamp - timestamps.front() >= 60) {
            timestamps.pop();

            if (timestamps.size() >= limit){
                return false;
            }
        }
        timestamps.push(timestamp);

        return true;
    }
};

int main () {
    Request test1;

    std::vector<std::pair<int,int>> input = {
        {10, 4},
        {20, 1},
        {30, 5},
        {40, 3}
    };

    for (int i = 0 ;i < input.size(); i++){
        bool result = test1.request(input[i].first, input[i].second);

        std::cout << result << std::endl;
    }

    return 0;
}