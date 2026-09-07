#include <vector>
#include <iostream>
#include <unordered_set>

struct Employees {
    int id;
    std::vector<int> directReports;
};

class Company {
    public:
    bool checker(std::vector<Employees> workers){
        // you will not accept an id
        // you will accept the workers' vector,
        // will iterate through them
        // store the seen workers in a hashset 
        std::unordered_set<int> pipeline;
        std::unordered_set<int> seen;
        int rootCounter = 0;
        // a for loop to iterate through the workers
        for (int i = 0; i < workers.size(); i++){
            for (int employeeID : workers[i].directReports){
                if (seen.contains(employeeID)) return false;
                pipeline.insert(i);
                seen.insert(employeeID);
            }
        }
        for (int i = 0 ; i < workers.size(); i++){
            if (!seen.contains(workers[i].id) || !pipeline.contains(workers[i].id)) rootCounter++;
        }
        if (rootCounter != 1) return false;

        return true;
    }
};


int main () {
    std::vector<Employees> workers = {
        {1, {2, 3}},
        {2, {4, 58}},
        {3, {6}},
        {4, {}},
        {5, {}},
        {6, {}}
    };
    Company company;

    std::cout << company.checker(workers) << std::endl;

    return 0;
}