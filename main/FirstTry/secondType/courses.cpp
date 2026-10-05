// you need to have a class of courses and list of courses
// they depend on
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

struct Courses {
  std::string classId;
  std::vector<std::string> dependencies;
};

class Prereqs {
private:
  std::unordered_map<std::string, std::vector<std::string>> courses;
  std::vector<std::string> firstYearCourses;
  
public:
  // create a function that will accept these values one by one
  void put(const Courses &course) {
    courses[course.classId] = course.dependencies;}

  std::vector<std::string> initialCourses() {
    for (auto& currCourse : courses)
      if (currCourse.second.empty()) firstYearCourses.push_back(currCourse.first);

    return firstYearCourses;
  }

  std::vector<std::string> getOrder() {
        std::vector<std::string> order; // final course order
        std::unordered_set<std::string> completed; // courses we've already taken

        while (order.size() < courses.size()) {
            bool added = false;
            
            for (auto& [classId, dependencies] : courses) {
                if (completed.contains(classId)) continue;

                bool ready = true;
                for (const auto& dependency : dependencies) 
                    if (!completed.contains(dependency)) { ready = false; break; }

                if (ready) {
                    order.push_back(classId);
                    completed.insert(classId);
                    added = true; }
            }
            if (!added) return {};
        }
        return order;
    }
};

int main() {
  Prereqs pre;
  
  std::unordered_map<std::string, std::vector<std::string>> input = {
      
      {"CS101", {}},
      {"MATH200", {}},
      {"CS201", {"CS101"}},
      {"CS301", {"CS201", "MATH200"}}};

    // c++ 17 syntax with unpacking classId and dependencies within the range based loop
    for (auto [classId, dependencies] : input) {
        Courses c = {classId, dependencies};
        pre.put(c);
    }
      
    auto firstYearCourses = pre.initialCourses();

    
    for (const auto& courses : firstYearCourses)
      std::cout << courses << std::endl;

    std::cout << "\nValid course order:\n";

    auto order = pre.getOrder();

    for (const auto& course : order)
        std::cout << course << std::endl;
    
    return 0;
}

