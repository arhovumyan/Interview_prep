/*
an event happens, you receive a timestamp
save the event
reomve any events that happened more than 30 seconds ago
return how many events are still within the last 30 seconds
Given: the timestamps will be given in increasing order

APPROACH:
accept the values in a queue
at the same time count the queue,
if the q.front() - q.back() <= 30
    q.push(input)
when its not the case
    q.pop();

return the queue
*/


#include <queue>
#include <iostream>

class Timestamps {
private:
std::queue<int> timestamps;

public:
  int amount = 0;

  void count() {
    amount = 0;
        for (int i = 0; i < timestamps.size(); i++) {
          amount++;
        }
      }

      std::queue<int> storage(int input) {
        while (!timestamps.empty() &&
           input - timestamps.front() >= 30) {
      timestamps.pop();
      
    }
    timestamps.push(input);

  return timestamps;
}
};


int main() {

  Timestamps time;
  
  std::queue<int> result = time.storage(1);
  result = time.storage(4);
  result = time.storage(4);
  result = time.storage(10);
  result = time.storage(31);

  time.count();
  std::cout << time.amount << std::endl;

  while (!result.empty()) {
    std::cout << result.front() << std::endl;
    result.pop();
  }

  return 0;
}