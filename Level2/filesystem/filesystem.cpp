#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

// files are directories are are stored as nodes with id, size, and child_ids
// input root_id, output total file size beneath that root

struct Worker {
    int id;
    int salary;
    std::vector<int> workerIDs;
};

class Files {
    public:
    int pyramid(std::vector<Worker>& allWorkersNode, int currentWorkerID){
        std::queue<int> workersToVisit;
        std::unordered_map<int,Worker> allWorkers;
        for (Worker currentWorker : allWorkersNode){
            allWorkers[currentWorker.id] = currentWorker;
        }
        std::unordered_set<int> visitedIDs;
        workersToVisit.push(currentWorkerID);
        
        int totalSum = 0;
        
        while (!workersToVisit.empty()){
            int currentID = workersToVisit.front();
            workersToVisit.pop();
            
            if (visitedIDs.contains(currentID)){continue;}
            else { visitedIDs.insert(currentID);}

            Worker currentWorker = allWorkers[currentID];

            totalSum += currentWorker.salary;

            for (int underWorkerID : currentWorker.workerIDs){
                workersToVisit.push(underWorkerID);
            }
        }
        return totalSum;
    }
};

int main () {
    std::vector<Worker> workers = {
        {1, 100, {2, 3}},
        {2, 60,  {4}},
        {3, 70,  {}},
        {4, 40,  {}}
    };

    Files company;

    int result = company.pyramid(workers, 1);


    std::cout << "Total salary: " << result << std::endl;

    return 0;
}