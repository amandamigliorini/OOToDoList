#ifndef TODOLIST_H
#define TODOLIST_H

#include <vector>
#include <fstream>
#include "Task.h"

// ToDoList class creation
//the methods are on ToDoList.cpp
class ToDoList {
private:
    std::vector<Task> tasks;

public:
    void displayMenu();
    void addTask();
    void deleteTask();
    void displayTasks();
    void markTaskCompleted();
    void editTask();
    void saveTasks() const;
    void loadTasks();
    void run();
};

#endif
