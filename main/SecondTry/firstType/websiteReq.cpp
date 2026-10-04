/*
we record the time of each user's request
given timestamps for one user in increasing order
example : [1,3,5,12,14]
determine whether the user ever mande more than 3 requests
during any 10 second period. return true if yes

approach
store the values in a hashmap
unordered_map <int, std::queue<int>> storage
int oldestReq = storage[0].front();
storage[0].pop();

while (storage.second.size() < 3)
    if (storage.back() - oldestReq <= 10) return false;
return false
*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

class Website {
public:
int userNum = 1;

bool checker(std::vector<int> input) {
  int left = 0;
  for (int right = 0; right < input.size(); right++) {
    while (input[right] - input[left] >= 10)
      left++;
    int requests = right - left + 1;

    if (requests > 3) return true;
  }
  return false;
}

};

int main() {

  Website requests;
  std::vector<int> timestamps = {1, 3, 5, 12, 14};
  std::cout << requests.checker(timestamps) << std::endl;

  return 0;
}