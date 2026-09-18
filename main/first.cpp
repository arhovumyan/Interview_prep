// Given: list of rental cars, each of them have start and end time
// Return: return true if any of the two reservations overlap
/*
Approach: create a struct with those two inputs
in the object we will pass in a vector of vectors that will contains two values
we will have a function that takes these values and sorts them in a vector of pairs
in an increasing order.
there will be another bool vector that iterates through the stored vector and 
compares the i.first with i-1.second and in case we see that the prev second 
time is less than the current first, we return a false.
*/

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

struct Reservation {
    int startTime;
    int endTime;
};

std::vector<std::pair<int,int>> storage;

void put(Reservation car){
    storage.push_back({car.startTime, car.endTime});
}

int checker() {
    // sort our storage
    std::sort(storage.begin(), storage.end());
    // min heap
    std::priority_queue<int,std::vector<int>,std::greater<int>> cars;

    for (int i = 0; i < storage.size(); i++){
        int start = storage[i].first;
        int end = storage[i].second;

        if (!cars.empty() && cars.top() <= start) cars.pop();

        cars.push(end);
    }

    return cars.size();
}

int main () {

    Reservation car1 = {1,1};
    Reservation car2 = {2,3};
    Reservation car4 = {4,5};
    Reservation car3 = {6,56};
    Reservation car5 = {1000,1023};

    put(car1);
    put(car2);
    put(car3);
    put(car4);
    put(car5);

    std::cout << checker() << std::endl;

    return 0;
}