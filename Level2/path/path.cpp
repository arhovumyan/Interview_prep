#include <unordered_set>
#include <queue>
#include <iostream>
#include <vector>

struct Reacher {
    std::vector<std::vector<int>> graphic;
    int A;
    int B;
};

class Path {
    /*In the function, you start with A, you see whats located in
    the vector[A], you store that in a queue, and start iterating. (done so far)
    you keep iterating until you reach B, when you do so, you return true,
    in case you dont reach it at all, you return false. how does that sound ?*/
    public:
    bool checking(const Reacher& input) {

        std::unordered_set<int> seen;
        std::queue<int> currentPath;

        int  graphicSize = input. graphic.size();

        for (int i = 0 ; i <  graphicSize; i++){
            if (input. graphic[i] == input. graphic[input.A]){
                for (int x : input. graphic[i]){
                    // just to check if we've seen it already
                    if (seen.contains(x)) return false;
                    currentPath.push(x);
                    //store in the hashset so you dont repeat yourself
                    seen.insert(x);
                }
            }
            else continue;
        }

        while (!currentPath.empty()){
            if (currentPath.front() == input.B) return true;
            
            currentPath.pop();
        }
        
        return false;
    }

};

int main () {
    Reacher test;
    Path path;

    test.graphic = {
        {1, 2},  // node 0
        {4},     // node 1
        {},      // node 2
        {},      // node 3
        {}       // node 4
    };

    test.A = 1;
    test.B = 4;

    bool result = path.checking(test);

    std::cout << std::boolalpha << result << std::endl;

    return 0;
}