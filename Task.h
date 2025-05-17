#ifndef TASK_H
#define TASK_H

#include <string>

// Task class creation
//the methods are on Task.cpp
class Task {
    private:
        std::string name;
        std::string description;
        std::string dueDate;
        bool completed;

    public:
        // Construtor
        Task(const std::string& name, const std::string& description, const std::string& dueDate);

        // Getters
        std::string getName() const;
        std::string getDescription() const;
        std::string getDueDate() const;
        bool isCompleted() const;

        // Setters
        void setName(const std::string& name);
        void setDescription(const std::string& description);
        void setDueDate(const std::string& dueDate);

        // Completition and display
        void markCompleted();
        void displayTask() const;
};

#endif
