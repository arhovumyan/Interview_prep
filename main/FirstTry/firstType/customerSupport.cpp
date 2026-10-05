/*
Description

we receive tickets, every ticket has customer_id
you will receive a vector of customers
you need to see how many unique customers you have

approach
accept the customers in one function
store them in a hashset
if the id is already in the hashset, you add 1 to int uniqueUsers

so int uniqueUsers
then an unordered_set for fast lookup to see whether we have it in the system
if its already in the hashset you keep going

second part
you want to add a ticket to your system
then you want to process it by removing and returning currently
most urgent customer by its ID
the smaller the ID the higher its priority

approach
in our addTicket function we can store our customers
we can probably store it in a hashmap of queues, thats it
then in our processor function
we can sort our hashmap by its priority

*/
#include <vector>
#include <iostream>
#include <queue>
#include <tuple>
#include <utility>


class Customers{
public:
  std::queue<int> result;
  std::priority_queue<std::tuple<int, int, int>,
                      std::vector<std::tuple<int, int, int>>,
                      std::greater<std::tuple<int, int, int>>>
      minHeap;
  int order = 0;

  void addTicket(int priority, int customerId) {
    minHeap.push({priority, customerId, order});
    order++;
  }

  int processNext() {
    auto current = minHeap.top();
    minHeap.pop();
    return std::get<2>(current);
  }
};

int main() {

  Customers input;

  std::vector<std::pair<int, int>> customs{
      {101, 3}, {102, 1}, {103, 2}, {104, 1}};

  for (auto currPair : customs) {
    input.addTicket(currPair.first, currPair.second);
  }
  std::cout << "Currently highest priority ticket is " << input.processNext()
            << std::endl;
  
  return 0;
}