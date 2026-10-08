/*
got packages
each can depend on other packages
for example
A depends on B and C
B depends on D
C depends on nothing
D depends on nothing

What I understood
will be given string current_id and string dependencies
will need to return the AMMOUNT of actual packages that
current_id is depending on

APPROACH for the warmup:
write a function that accepts current_id and dependencies queue or vector
make a hasmap so that we can map the current_id to the dependency queue

CORE REQUIREMENT
the whole idea is that you store all the strings one after another even
even tho they are not directly under the current_id

APPROACH FOR THE CORE PROBLEM
you probable need a hash_set since you only wanna count each of them ONCE
maybe you can write a code that recursively iterates though dependencies
one by one and sstores in them in see and in current_id's key value.

*/
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iostream>
#include <string>

class Packages {
public:
    std::unordered_map<std::string, std::queue<std::string>> storage;

    void put(std::string current_id, std::queue<std::string> depPackages) {
        storage[current_id] = depPackages;
    }

    int size(std::string current_id) {
        return storage[current_id].size();
    }

    // AI GENERATED
    int totalDependencies(std::string current_id) {
        std::unordered_set<std::string> visited;
        std::queue<std::string> q;

        q.push(current_id);

        while (!q.empty()) {
            std::string current = q.front();
            q.pop();

            if (visited.contains(current)) {
                continue;
            }

            visited.insert(current);

            std::queue<std::string> deps = storage[current];

            while (!deps.empty()) {
                q.push(deps.front());
                deps.pop();
            }
        }

        return visited.size() - 1;
    }
};

int main() {
    Packages package1;

    std::queue<std::string> input1;
    input1.push("B");
    input1.push("C");

    std::queue<std::string> input2;
    input2.push("D");

    std::queue<std::string> input3;
    input3.push("D");

    package1.put("A", input1);
    package1.put("B", input2);
    package1.put("C", input3);

    std::cout << package1.totalDependencies("A") << std::endl;
    std::cout << package1.totalDependencies("B") << std::endl;
    std::cout << package1.totalDependencies("C") << std::endl;

    return 0;
}