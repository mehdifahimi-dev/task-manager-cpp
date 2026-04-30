#ifndef TASKMANAGER_HPP
#define TASKMANAGER_HPP

#include <vector>
#include <string>
#include "Task.hpp"

class TaskManager {
 private:
    std::vector<Task> tasksList;
 public:
    void addTask(const std::string& description);
    void viewTasks();
    bool isEmpty() const;
    void completeTask(int index);
    void deleteTask(int index);
    void loadFromFile();
    void saveToFile();
};
#endif