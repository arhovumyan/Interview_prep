#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

class Server {
    public:
    std::vector<std::pair<int,int>> overlap(std::vector<std::pair<int,int>> schedule){
        // your whole plan is to iterate through the main vector
        // you have a current pair that will be your current window
        // see if schedule[i-1.second] > schedule[i.first]
        //      you store the schedule[i-1.first] and schedule[i.second]
        // as your current window
        std::sort(schedule.begin(), schedule.end());
        std::pair<int,int> currWindow;
        std::vector<std::pair<int,int>> result;

        currWindow.first = schedule[0].first;
        currWindow.second = schedule[0].second;

        for (int i = 1; i < schedule.size();i++){

            if (currWindow.second >= schedule[i].first){
                currWindow.second = std::max(currWindow.second, schedule[i].second);}
            else {
                result.push_back(currWindow);
                currWindow = schedule[i];}
        }

        result.push_back(currWindow);

        return result;
    }
};

int main () {
    Server test1;

    std::vector<std::pair<int,int>> result = test1.overlap({{1,2},{4,5},{1,7},{55,123}});
    
    for (int i = 0; i < result.size(); i++) {
    std::cout << result[i].first << " " << result[i].second << std::endl;
    }
    
    return 0;
}