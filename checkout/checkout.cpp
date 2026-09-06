#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

class Checkout {
// you got a line
// you start at the first one and give them a kiosk
// then you keep moving
// if the current guy's time is less than the current end time, you add a kiosk
// you keep adding kiosks until your current time is the more that the start time of the latest
/*
    reservations =      ({1,3},{2,5},{4,6},{2,3})

    sortedReservation = ({1},{2},{2},{4})
    minHeap =           ({3},{3},{5},{6})
*/

public:
    std::pair<int, std::pair<int,int>> 
    returnTime(std::vector<std::pair<int,int>> reservations){

    int kiosk = 0;
    int peakStart = 0;
    int peakEnd = 0;

    std::sort(reservations.begin(), reservations.end());
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

        for (int i = 0; i < reservations.size(); i++){

            int start = reservations[i].first;
            int end = reservations[i].second;

            // mean heap is a queue with priority to min numbers so treat it like one
            // remove kiosks that are already free
            while (!minHeap.empty() && minHeap.top() <= start){
                minHeap.pop();
            }

            minHeap.push(end);

            if(minHeap.size() > kiosk){
                kiosk = minHeap.size();
                peakStart = start;
                peakEnd = minHeap.top();
            }
        }
        return {kiosk, {peakStart, peakEnd}};
    }
};

int main () {
    Checkout kiosk;

    std::vector<std::pair<int,int>> line {
        {1,4},
        {3,5},
        {2,6},
        {5,7}
    };

    auto answer = kiosk.returnTime(line);
    std::cout << "Kiosks: " << answer.first << std::endl;

    std::cout << "Peak time: " << answer.second.first
              << " to "
              << answer.second.second
              << std::endl;
    
    return 0;
}