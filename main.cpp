#include <iostream>
#include <string>
#include "TaskManager.hpp"

int main () {

    TaskManager task;
    int index;
    int option = 0;

    while (option != 5) {
        std::cout << std::endl;
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Complete Task" << std::endl;
        std::cout << "4. Delete Task" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << std::endl;

        std::cout << "Select an option (1, 2, 3, 4, 5): ";
        std::cin >> option;

        std::string taskDescription;

        if (option == 1) {
            std::cin.ignore();
            std::cout << "Enter your task: ";
            std::getline(std::cin, taskDescription);
            task.addTask(taskDescription);

        } else if (option == 2) {
            task.viewTasks();

        } else if (option == 3) {
            if (task.isEmpty()) {
                std::cout << "No Task To Complete" << std::endl;
            } else {
            std::cout << "Enter the task number: ";
            std::cin >> index;
            task.completeTask(index);
            }

        } else if (option == 4) {
            if (task.isEmpty()) {
                std::cout << "No Task To Delete" << std::endl;
            } else {
            std::cout << "Enter the task number: ";
            std::cin >>  index;
            task.deleteTask(index);
            }

        } else if (option == 5) {
            std::cout << "End of tasks. Good bye!" << std::endl;

        } else {
            std::cout << "INVALID OPTION!" << std::endl;
        }
    }
    return 0;
}