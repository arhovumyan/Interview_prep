// description
// servers from 1 - n
// some pairs are connected by a network cable
// cables work in both directions
// message can travel through any numbe of cables

/*
approach

*/
#include <queue>
#include <vector>
#include <utility>
#include <unordered_set>
#include <iostream>

std::vector<std::pair<int, int>> storage;
    
void put(std::pair<int,int> input) {
  storage.push_back({input.first, input.second});
}

// storage       = {{1, 2},{2, 3},{4, 5}}
// passed in     = {1,3}
// toCheck       = {}
// currentServer = 2
// visited       = 1

bool decider(int server1, int server2) {
  std::queue<int> toCheck;
  std::unordered_set<int> visited;

  toCheck.push(server1);
  
  while (!toCheck.empty()) {
    int currentServer = toCheck.front();
    toCheck.pop();

    if (currentServer == server2) return true;
    if (visited.contains(currentServer)) continue;

    visited.insert(currentServer);

    for (auto &currentPair : storage) {
      if (currentPair.first == currentServer) {
        toCheck.push(currentPair.second);
      }
      else if (currentPair.second == currentServer) {
        toCheck.push(currentPair.first);
      }
    }
  }
  return false;
}

int main() {
    put({1, 2});
    put({2, 3});
    put({4, 5});
    
    bool result = decider(1, 3);
    
    std::cout << result << '\n';
}