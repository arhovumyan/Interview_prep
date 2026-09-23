// you are given a root_id and a map of id -> Node
// you need to return the size of that node and all of its descendants. 
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

class Node {
public:
    std::string id;
    int size;
    std::vector<std::string> child_ids;
};

int getTotalSize(const std::string id, const std::unordered_map<std::string, Node>& nodes){
    
    // you can use .at to access the rest of the "node" as long as the value that you
    // pass in is the key. 
    const Node& currNode = nodes.at(id);
    
    int total = currNode.size;

    for (const std::string& child_id : nodes.child_ids){
        total += getTotalSize(child_id, nodes);
    }

    return total;
}

int main() {
    std::unordered_map<std::string, Node> nodes;

    nodes["root"] = {"root", 0, {"a", "b"}};
    nodes["a"] = {"a", 10, {}};
    nodes["b"] = {"b", 0, {"c"}};
    nodes["c"] = {"c", 20, {}};
    
    std::string root_id = "root";

    int total = getTotalSize(root_id, nodes);

    std::cout << total << std::endl;

    return 0;
}
