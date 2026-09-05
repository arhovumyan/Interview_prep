#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
    public:
    bool interval(std::vector<int> pickup_time,std::vector<int> return_time){
        
        std::vector<int> sortedPickup =  vectorSorter(pickup_time);
        std::vector<int> sortedReturn =  vectorSorter(return_time);
        return sortedPickup.back() > sortedReturn.front();
    }
    std::vector<int> vectorSorter(std::vector<int> vectorToSort){
        std::sort(vectorToSort.begin(), vectorToSort.end());
        return vectorToSort;
    }

    //  std::vector<int> vectorPrinter(std::vector<int> vecty){
    //     std::vector<int> sortedVect;
    //     for(int x : vecty){
    //         std::cout << x << " ";
    //     }
    //     std::cout << std::endl;
    // }

    int usedCars(std::vector<int> pickup_time,std::vector<int> return_time){
        std::vector<int> sortedPickup =  vectorSorter(pickup_time);
        std::vector<int> sortedReturn =  vectorSorter(return_time);

        int pickupIndex = 0;
        int returnIndex = 0;
        int carCount = 0;
        int maxCars = 0;

        while (pickupIndex < sortedPickup.size()){
            if (sortedPickup[pickupIndex] < sortedReturn[returnIndex]){
                carCount++;
                maxCars = std::max(maxCars, carCount);
                pickupIndex++;
            }

            else {
                carCount--;
                returnIndex++;
            }
        }
        return maxCars;
    }

};

int main () {
    Solution intervalTest1;

    std::vector<int> pTime = {1,3,45,6,1,2,3,7};
    std::vector<int> rTime = {6000,300,400,5100,5100,23000,1000};

    std::vector<int> SPickup =  intervalTest1.vectorSorter(pTime);
    std::vector<int> SReturn =  intervalTest1.vectorSorter(rTime);


    // std::cout << intervalTest1.vectorPrinter(pTime) << std::endl;
    // std::cout << intervalTest1.vectorPrinter(rTime) << std::endl;

    std::cout << intervalTest1.interval(pTime, rTime) << std::endl;
    std::cout << intervalTest1.usedCars(pTime, rTime) << std::endl;

    return 0;
}