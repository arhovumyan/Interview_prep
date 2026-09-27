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
#include <unordered_map>
#include <queue>

struct eachCustomer {
  int cusomer_id;
  int priority;
};

class Customers{
public:
  std::unordered_map<int, int> customers;
  std::priority_queue<std::vector<std::greater<int>>> minheap;

};

int main() {

  Customers input;

  std::vector<int> custos {
    1,2,3,4,5,6, 4, 4,
  };

  std::cout << input.customerSupport(custos) << std::endl;
  
  return 0;
}