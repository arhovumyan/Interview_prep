/*
Description

our garage records when each car enters and leaves
we record the arrival and departure time
figure our whether there was a time when two or more 
cars were inside the garage at the same time

Approach

{[1, 4], [5, 8], [3, 6]}

[4,6,8]

you can store the arrival and departure in a pair
you can store the pairs in a vector
you can store the end times in a minHeap
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

struct Parking {
    int arrTime;
    int depTime;
};

std::vector<std::pair<int,int>> parking;
std::priority_queue<int, std::vector<int>,
std::greater<int>> endTimes;
void put(Parking& times){
    parking.push_back({times.arrTime, times.depTime});
}

int collision(){
    std::sort(parking.begin(), parking.end());
    int maxCars = 0;
    
    // you want to go through the parking vector
    for (int i = 0; i < parking.size(); i++){
        int start = parking[i].first;
        int end = parking[i].second;
        while (!endTimes.empty() && start <= endTimes.top()){
            endTimes.pop();
        }
        endTimes.push(end);

        maxCars = std::max(maxCars, (int)endTimes.size());
    }
    // return endTimes.size();
    return maxCars;
}

int main () {

    std::queue<Parking> parkings;

    parkings.push({1,4});
    parkings.push({2,7});
    parkings.push({4,5});
    parkings.push({7,23});

    while (!parkings.empty()){
        put(parkings.front());
        parkings.pop();
    }
    std::cout << collision() << std::endl;

    return 0;
}