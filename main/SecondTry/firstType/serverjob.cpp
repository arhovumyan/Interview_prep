/*
given a list of jobs that need to run on a server
given start time and end time
for example {[1,6],[6,9],[4,7]}
two jobs conflict if they are running at the same time
return true if they overlap

approach
you can store the end times in a minHeap of queue of vector
this way you can sort them in increasing order and pop whenever
you dont need them anymore
*/

#include <queue>
#include <vector>
#include <utility>
#include <functional>
#include <iostream>
#include <algorithm>

class Server {
public:
  
  int checker(std::vector<std::pair<int,int>> input) {
    std::sort(input.begin(), input.end());
    std::priority_queue<int, std::vector<int>, std::greater<int>> endTimes;
    int currentMax = 0;

    for (auto job : input) {
      int startTime = job.first;
      int endTime = job.second;

      while (!endTimes.empty() && endTimes.top() <= startTime) {
        endTimes.pop();
      }

      /*
      if (!endTimes.empty()) return true;
      */

      endTimes.push(endTime);
      currentMax = std::max(currentMax, (int)endTimes.size());
      }
    return currentMax;
  }
};

int main() {
  Server server1;
  std::vector<std::pair<int, int>> list = {{1, 6}, {5, 9}, {4,7}};
  
  std::cout << server1.checker(list) << std::endl;

  return 0;
}