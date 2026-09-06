#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>

class Delivery {
    public:
    int conflict(std::vector<std::pair<int,int>> reservations){
    // std::vector<int> reservationID(reservation.size());
    // std::iota(reservationID.begin(), reservationID.end(),1);
        std::vector<std::tuple<int,int,int>> withIDs;

        for (int i = 0;i < reservations.size();i++){
            int start = reservations[i].first;
            int end = reservations[i].second;

            withIDs.push_back({start,end,i});
        }

        std::sort(withIDs.begin(),withIDs.end());

        for (int i = 1; i < withIDs.size();i++){
            int currentStart = std::get<0>(withIDs[i]);
            int previousStart = std::get<1>(withIDs[i-1]);

            if (previousStart > currentStart){
                return std::get<2>(withIDs[i]);
            }
        }
        return -1;
    }
};

int main () {
Delivery test1;

std::cout << test1.conflict({{1,3},{4,6},{2,4},{123,56}}) << std::endl;

return 0;

}