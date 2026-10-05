/*
DESCIRPTION

a company stores its org chart as a list of employees
each employee has an employee_Id and a manager_id
the CEO is the only one who's manager_id is -1

{1, -1}
{2, 1}
{3, 1}
{4, 2}
{5, 2}
{6, 3}

receive the employee_Id and return the list of mangers above them
start with the direct manager and end wit the ceo

APPROACH

since you will be given the emp_id, you will have to iterate up
this means take what you get, and start going up until the current
employee's manager_id == -1

{1, -1}, {2, 1}, {3, 1}, {4, 2}, {5, 2}, {6, 3}
            1
          / |
        2   3
      / |   |
    4   5   6

*/

#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <unordered_set>

struct Employee {
    int employee_id;
    int manager_id;
};

std::unordered_map<int, int> employees;

// stores everyone in a hashmap
void storingEmployees(Employee worker) {
    employees[worker.employee_id] = worker.manager_id;
}

// sees who is managing the current emp
std::queue<int> roster(int employee_id) {
    std::queue<int> managers;
    while (employees[employee_id] != -1) {

        employee_id = employees[employee_id];
        managers.push(employee_id);
    }
    return managers;
}

// sees the first common manager emp1 and emp2 have
int closestManager(int employee1, int employee2) {
    std::unordered_set<int> managers1;

    while (true) {
        managers1.insert(employee1);
        if (employees[employee1] == -1) break;
        // emp1 = its manager, keep doing than until emp_id = -1 
        employee1 = employees[employee1];
    }

    while (true) {
        if (managers1.contains(employee2)) return employee2;
        if (employees[employee2] == -1) break;
        employee2 = employees[employee2];
    }
    return -1;
}

int main() {

    std::vector<Employee> input = {
        {1, -1},
        {2, 1},
        {3, 1},
        {4, 2},
        {5, 2},
        {6, 3}
    };

    for (Employee worker : input) {
        storingEmployees(worker);
    }

    std::queue<int> managers = roster(4);

    std::cout << "Managers of employee 4:" << std::endl;

    while (!managers.empty()) {
        std::cout << managers.front() << std::endl;
        managers.pop();
    }

    std::cout << "Closest common manager of 4 and 5: "
              << closestManager(4, 5)
              << std::endl;

    std::cout << "Closest common manager of 4 and 6: "
              << closestManager(4, 6)
              << std::endl;

    return 0;
}