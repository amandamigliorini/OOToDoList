#include "Task.h"
#include <iostream>
using namespace std;

// Construtor of the task
Task::Task(const string& name, const string& description, const string& dueDate)
    : name(name), description(description), dueDate(dueDate), completed(false) {}

// Getters
string Task::getName() const {
    return name;
}
string Task::getDescription() const { 
    return description; 
}
string Task::getDueDate() const { 
    return dueDate; 
}
bool Task::isCompleted() const { 
    return completed; 
}

// Setters
// the setters are defining each of the attributes of the class
void Task::setName(const string& name) { 
    this->name = name; 
}
void Task::setDescription(const string& description) { 
    this->description = description; 
}
void Task::setDueDate(const string& dueDate) { 
    this->dueDate = dueDate; 
}

// Concluding a task
void Task::markCompleted() { 
    completed = true; 
}

// Displayng tasks.
void Task::displayTask() const {
    //if the task is completed will be shown as Completed.
    //if the task is not completed will be shown as Pending
    cout << name << " (" << (completed ? "Completed" : "Pending") << ")" << endl
        << "   Due-Date: " << dueDate << endl
            << "   Description: " << description << endl;
}
