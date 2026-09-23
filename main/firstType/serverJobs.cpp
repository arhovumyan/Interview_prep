/*
given a list of jobs that need to run on a server
if two jobs are running at the same time, then they conflict
return true if ANY two jobs overlap

the input is like this 
[1, 5]
[6, 9]
[4, 7]
[5,19]
[3, 5]

approach initial thoughts
take the input, you have to store it somewhere, 
first sort them so you can iterate through them
you get this 
[1, 5]
[3, 5]
[4, 7]
[5,19]
[6, 9]
since its a 
pair of integers you can store them in a queue of pairs

now the core problem is different
its asking us to count how many servers are needed at most 
because of the overlaps
*/ 

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <utility>

class Server {
public:

    int checker (std::vector<std::pair<int,int>>& input) {
        std::sort(input.begin(), input.end());
        
        std::priority_queue<int, 
        std::vector<int>, 
        std::greater<int>> servers;

        int maxServers = 0;

        for (int i = 0; i < input.size(); i++) {
            int start = input[i].first;
            int end = input[i].second;

            while (!servers.empty() && servers.top() <= start){
                servers.pop();
            }
            servers.push(end);
            // (int) because the servers.size() is an unsigned int 
            // and you cannot compare it to regular int
            maxServers = std::max(maxServers, (int)servers.size());
        }

        return maxServers;
    }
};

int main() {
    Server input;
    std::vector<std::pair<int,int>> inputting = {
        {1,2},
        {2,5},
        {4,6},
        {43,66},
        {6,8},
        {3,5},
    };

    std::cout << input.checker(inputting) << std::endl;

    return 0;
}