#include "Task.hpp"

Task::Task(const std::string& doTask) {
    description = doTask;
    completed = false;
}

std::string Task::getDescription() const {
    return description;
}

bool Task::isCompleted() const {
    return completed;
}

void Task::markComplete() {
    completed = true;
}