// a time of every request is recorded
// given timestamps for one user in INCREASING order
// [1,2,5,6,7,18]
// determine whether th euser ever made mode than 3 requests
//  during any 10 second period.
// return true if exceeded the limit

/*
Attack plan
you are accepting a queue of timestamps
keep track of how many requests you have made so far
start iterating through the vector
while your current i - initial < 0 and reqAmt >= 3,
you pop the top element
return true;
*/

#include <queue>
#include <iostream>
#include <unordered_map>

struct Request {
    int userId;
    int timestamp;
};

class Requests {
private:
    const int LIMIT = 3;
    std::unordered_map<int, std::queue<int>> userRequests;

public:
    bool reqLimit(Request req) {    
        while (!userRequests[req.userId].empty() &&
            req.timestamp - userRequests[req.userId].front() >= 10) {
            userRequests[req.userId].pop();
        }

        if (userRequests[req.userId].size() >= LIMIT) return true;

        userRequests[req.userId].push(req.timestamp);
        return false;           
    }
};

int main() {

    Requests req;

    std::queue<Request> requests;

    requests.push({1, 4});
    requests.push({1, 5});
    requests.push({1, 6});
    requests.push({1, 7});   // 4th request within 10 sec -> true
    requests.push({2, 5});
    requests.push({2, 7});
    requests.push({4, 5});
    requests.push({2, 10});
    requests.push({1, 23});

    while (!requests.empty()) {

        std::cout << req.reqLimit(requests.front())
                  << std::endl;

        requests.pop();
    }

    return 0;
}