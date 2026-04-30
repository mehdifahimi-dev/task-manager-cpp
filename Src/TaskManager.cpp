#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "TaskManager.hpp"

void TaskManager::addTask(const std::string& description) {
    Task newTask(description);
    tasksList.push_back(newTask);
    saveToFile();
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
        saveToFile();
        std::cout << "You completed task number " << index << std::endl;
    }
}

void TaskManager::deleteTask(int index) {
    if (index >=0 && index < tasksList.size()) {
        tasksList.erase(tasksList.begin() + index);
        saveToFile();
        std::cout << "Task number " << index << " is deleted" << std::endl;
    } else {
        std::cout << "INVALID TASK NUMBER!" << std::endl;
    }
}

void TaskManager::saveToFile() {
    std::ofstream file("tasks.txt");
    for (size_t i = 0; i < tasksList.size(); i++) {
        std::string description = tasksList[i].getDescription();
        bool completed = tasksList[i].isCompleted();
        int status;
        if (completed) {
            status = 1;
        } else {
            status = 0;
        }
        file << description << "|" << status << std::endl;
    }
}

void TaskManager::loadFromFile() {
    std::ifstream file("tasks.txt");
    if (!file.is_open()) {
        return;
    }

    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string description;
        std::string status;

        std::getline(ss, description, '|');
        std::getline(ss, status);

        Task newTask(description);

        if (status == "1") {
            newTask.markComplete();
        }

        tasksList.push_back(newTask);
    }

}