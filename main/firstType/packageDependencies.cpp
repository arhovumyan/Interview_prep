/*
DESCRIPTION

we have packages
each package depends on other packages
A depends on B and C
B depends on D
C depends on nothing
D depends on nothing

receive the packageID and return the number of packages it directly
depends on

like this 
A -> 2
B -> 1
C -> 0
D -> 0

SOLVING PLAN

since you will have a nestes "list" of packages
and you need to track which one they are depending on
you can create a struct that will store the package id and a vector
you can create a function that would put all the information into
a hashmap
then you need a function that would accept what package name was 
passed in, ask what its dependencies are and return them

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <unordered_set>

struct Packs {
    std::string package_id;
    std::vector<std::string> dependencies;
};

class Package {
private:
    std::unordered_map<std::string,
    std::vector<std::string>> packages;

    void dfs(std::string package_id, 
        std::unordered_set<std::string>& seen){
        for (std::string dependency : packages[package_id]) {
            if (!seen.contains(dependency)){
                seen.insert(dependency);
                dfs(dependency, seen);
            }
        }
    }
public:
    void put(Packs& packs){
        packages[packs.package_id] = packs.dependencies;
    }
    
    int numOfDependencies(std::string package_id){
        std::unordered_set<std::string> seen;

        dfs(package_id, seen);

        return seen.size();
    }
};

int main () {
    Package pack;
    
    Packs A = {"A", {"B", "C"}};
    Packs B = {"B", {"D"}};
    Packs C = {"C", {"E"}};
    Packs D = {"D", {}};
    Packs E = {"E", {}};

    pack.put(A);
    pack.put(B);
    pack.put(C);
    pack.put(D);
    pack.put(E);

    std::vector<std::string> ids = {"A", "B", "C", "D", "E"};

    for (int i = 0; i < ids.size(); i++){
        std::cout << "For " << ids[i] << " -> " << pack.numOfDependencies(ids[i]) << std::endl;
    }

    return 0;
}