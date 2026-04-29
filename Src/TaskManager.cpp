#include <iostream>
#include <vector>
#include "TaskManager.hpp"

void TaskManager::addTask(const std::string& description) {
    Task newTask(description);
    tasksList.push_back(newTask);
    std::cout << description << " is added to your tasks list." << std:: endl;
}

void TaskManager::viewTasks() {
    if (tasksList.size() == 0) {
        std::cout << "No Tasks Available!" << std::endl;
    } else {std::cout << std::endl;
    std::cout << "Tasks List:" << std::endl;
    }
    
    for (int i = 0; i < tasksList.size(); i++) {
        std::cout << i << "." << " ";
        if (tasksList[i].isCompleted()) {
            std::cout << "[completed] ";
        } else {
            std::cout << "[not completed] ";
        }
        std::cout << tasksList[i].getDescription() << std::endl;
    }
}

bool TaskManager::isEmpty() const{
    return tasksList.empty();
}

void TaskManager::completeTask(int index) {
    if (index < 0 || index >= tasksList.size()) {
        std::cout << "INVALID TASK NUMBER!" << std::endl;
        return;
    } else {
        tasksList[index].markComplete();
        std::cout << "You completed task number " << index << std::endl;
    }
}

void TaskManager::deleteTask(int index) {
    if (index >=0 && index < tasksList.size()) {
        tasksList.erase(tasksList.begin() + index);
        std::cout << "Task number " << index << " is deleted" << std::endl;
    } else {
        std::cout << "INVALID TASK NUMBER!" << std::endl;
    }
}