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

struct Request {
    int userId;
    int timestamp;
};

class Requests {
private:
    const int LIMIT = 3;
    std::unodered_map<int, std::queue<int>> userRequests;
public:
    bool reqLimit (Request req){
        std::queue<int>& q = userRequests[req.userId];
        while (!q.empty() && req.timestamp - q.front() >= 10) {
            q.pop();
        }

        if (q.size() >= LIMIT) return false;

        q.push(req.timestamp);

        return true;
    }
};

int main () {
    Requests req;
    std::queue<pair<int,int>> requests;

    requests.push({1,4});
    requests.push({1,5});
    requests.push({1,6});
    requests.push({2,5});
    requests.push({2,7});
    requests.push({4,5});
    requests.push({2,10});
    requests.push({1,23});

    while (!requests.empty()) {

        std::cout << req.reqLimit(requests.front().first,
        requests.front().second) << std::endl;

        requests.pop();
    }

    return 0;
}