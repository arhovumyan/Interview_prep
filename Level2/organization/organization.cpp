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
        std::unordered_set<int> seen;
        int rootCounter = 0;
        // a for loop to iterate through the workers
        for (int i = 0; i < workers.size(); i++){
            for (int employeeID : workers[i].directReports){
                if (seen.contains(employeeID)) return false;
                seen.insert(employeeID);
            }
        }
        for (int i = 0 ; i < workers.size(); i++){
            if (!seen.contains(workers[i].id)) rootCounter++;
        }
        if (rootCounter != 1) return false;
        
        return true;
    }
};


int main () {

}





// @new members. Hello everyone, welcome to the team. 
// Everyone on the software team, please put your information in here, 
// This will be used to track our progress over the semester. 
// Once we finish our 2026 comp, I will have more time to set
// up our meetings and we will see who works on what.
// There are TONS of things to work on.

