#ifndef TASK_HPP
#define TASK_HPP

#include <string>

class Task {
 private:
    std::string description;
    bool completed;

 public:
 Task(const std::string& doTask);
 std::string getDescription() const;

 bool isCompleted() const;

 void markComplete();

};

#endif