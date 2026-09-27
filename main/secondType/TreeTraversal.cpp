#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

class Node {
private:
    std::unordered_map<std::string, Node> storage;
    
public:
    std::string id;
    std::string name;
    std::vector<std::string> child_ids;
    
    void put(std::string id, std::unordered_map<std::string, Node> &lookup) {
        storage[id] = lookup.at(id); // no clue
    }

    void getPaths(std::string id, std::string currentPath,
                 std::vector<std::string>& paths) {
        Node& current = storage.at(id);

        if (current.child_ids.empty()) {
          paths.push_back(currentPath + "/" + current.name);
          return;
        }

        for (std::string childId : current.child_ids) {

          std::string newPath = currentPath + "/" + current.name;

          getPaths(childId, newPath, paths);
        }
    }
};

int main() {

    std::unordered_map<std::string, Node> hashmap;

    Node root;
    root.id = "r";
    root.name = "root";
    root.child_ids = {"d1", "f3"};

    Node docs;
    docs.id = "d1";
    docs.name = "docs";
    docs.child_ids = {"f1", "f2"};

    Node todo;
    todo.id = "f3";
    todo.name = "todo.txt";
    todo.child_ids = {};

    Node resume;
    resume.id = "f1";
    resume.name = "resume.pdf";
    resume.child_ids = {};

    Node notes;
    notes.id = "f2";
    notes.name = "notes.txt";
    notes.child_ids = {};

    hashmap[root.id] = root;
    hashmap[docs.id] = docs;
    hashmap[todo.id] = todo;
    hashmap[resume.id] = resume;
    hashmap[notes.id] = notes;

    
    root.put("r", hashmap);
    root.put("d1", hashmap);
    root.put("f3", hashmap);
    root.put("f1", hashmap);
    root.put("f2", hashmap);


    std::vector<std::string> paths;

    root.getPaths("r", "", paths);
    
    for (std::string path : paths) {
        std::cout << path << std::endl;
    }

    return 0;
}