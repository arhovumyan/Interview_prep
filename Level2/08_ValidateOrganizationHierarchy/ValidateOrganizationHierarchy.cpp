#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

struct Employees {
    int id;
    std::vector<int> directReports;
};

class Company {
public:
    bool checkForCycle(int currentID, 
        std::unordered_map<int, Employees>& employeeByID,
        std::unordered_set<int>& currentPath,
        std::unordered_set<int>& visited){
            if (currentPath.contains(currentID)) return true;

            if (visited.contains(currentID)) return false;

            currentPath.insert(currentID);

            for (int employeeID : employeeByID[currentID].directReports){
                if (checkForCycle(employeeID, employeeByID, currentPath, visited)) 
                    return true;
            }

            currentPath.erase(currentID);
            visited.insert(currentID);

            return false;
        }

    bool checker(std::vector<Employees> workers) {

        std::unordered_set<int> seen;
        std::unordered_set<int> pathNow;
        std::unordered_set<int> visited;
        std::unordered_map<int,Employees> employeeByID;

        int rootCounter = 0;
        
        // Store all employee IDs
        for (int i = 0; i < workers.size(); i++) {
            employeeByID[workers[i].id] = workers[i];
        }

        // Check direct reports(people that work under that person)
        for (int i = 0; i < workers.size(); i++) {
            for (int employeeID : workers[i].directReports) {

                // Employee does not exist
                if (!employeeByID.contains(employeeID))
                    return false;

                // Employee has multiple managers
                if (seen.contains(employeeID))
                    return false;

                seen.insert(employeeID);
            }
        }

        // Check for exactly one root
        for (int i = 0; i < workers.size(); i++) {
            if (!seen.contains(workers[i].id))
                rootCounter++;
        }

        if (rootCounter != 1)
            return false;

        // for starting the checkForCylce recursion
        for (int i = 0; i < workers.size();i++){
            if (checkForCycle(workers[i].id, employeeByID, pathNow, visited))
            return false;
        }

        return true;
    }
};

int main () {
    std::vector<Employees> workers = {
        {1, {2, 3}},
        {2, {4, 6}},
        {3, {6}},
        {4, {}},
        {5, {}},
        {6, {}}
    };
    Company company;

    std::cout << company.checker(workers) << std::endl;

    return 0;
}


