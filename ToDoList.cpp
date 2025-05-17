#include "ToDoList.h"
#include <iostream>
#include <fstream>
using namespace std;
// here are the functions/methods of the class ToDoList
//Consult ToDoList.h to see the class created

//Display Menu is the function that will show options to the user 
//Every time the user executes something in the program the menu is displayed again

void ToDoList::displayMenu() {
    cout << "\n\n\n       To-Do List Menu      \n";
    cout << "1. Add Task\n";
    cout << "2. Delete Task\n";
    cout << "3. Display Tasks\n";
    cout << "4. Mark Task as Completed\n";
    cout << "5. Edit Task\n";
    cout << "6. Exit\n";
    cout << "-----------------------------------------\n";
}

//addTask is the function used when the user selects option 1
//it asks the task data
//as a part of the ToDoList Class, this method has access to the std::vector<Task> tasks;
void ToDoList::addTask() {
    string name, description, dueDate;
    cout << "Enter task's name: ";
    getline(cin, name);
    cout << "Enter task's description: ";
    getline(cin, description);
    cout << "Enter task's due date (MM-DD-YYYY): ";
    getline(cin, dueDate);
    tasks.emplace_back(name, description, dueDate);
    cout << "Task added to your To-Do List!" << endl;
}

//method to deleteTask
void ToDoList::deleteTask() {
    //if there is no task a message will be displayed
    if (tasks.empty()) {
        cout << "There is no task to delete" << endl;
        return;
    }
    cout << "Tasks:" << endl;
    for (int i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].getName() << endl;
    }
    cout << "Enter the task number to delete: ";
    int taskNumber;
    cin >> taskNumber;
    if (taskNumber >= 1 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task deleted from your To-Do List!" << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
}

//the method that is used to display tasks
void ToDoList::displayTasks() {
    //if there is no task a message will be displayed
    if (tasks.empty()) {
        cout << "There is no tasks in your To-Do List. Add one to begin your To-Do List" << endl;
        return;
    }
    cout << "\n\nTasks:" << endl;
    //here each task is printed on the console being enumerate using the iterator i
    //it also calls the method displayTask from the class Task
    for (int i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". ";
        tasks[i].displayTask();
    }
    cout << "-----------------------------------------"<< endl;
}

//here is the method to mark a task as completed
void ToDoList::markTaskCompleted() {
    //if there is no task a message will be displayed
    if (tasks.empty()) {
        cout << "There is no tasks to complete." << endl;
        return;
    }
    //displaying the tasks so the user can choose the right one
    cout << "Tasks:" << endl;
    for (int i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].getName() << endl;
    }
    cout << "Enter the task number to mark as completed: ";
    int taskNumber;
    cin >> taskNumber;
    //the code that marks the task as completed.
    //Because the tasks are organized on a vector it has indexes starting on 0
    if (taskNumber >= 1 && taskNumber <= tasks.size()) {
        //The completition uses the index by subtracting 1 from the taskNumber
        tasks[taskNumber - 1].markCompleted();
        cout << "Congrats for completing a task! Keep up the good work" << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
}

void ToDoList::editTask() {
    //if there is no task a message will be displayed
    if (tasks.empty()) {
        cout << "There is no tasks to edit." << endl;
        return;
    }
    cout << "Tasks:" << endl;
    for (int i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].getName() << endl;
    }
    cout << "Enter the task number to edit: ";
    int taskNumber;
    cin >> taskNumber;
    //Similiarly to the completition method the task is edited accessing it by its index
    if (taskNumber >= 1 && taskNumber <= tasks.size()) {
        Task& task = tasks[taskNumber - 1];
        string name, description, dueDate;
        cout << "Enter new task name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter new task description: ";
        getline(cin, description);
        cout << "Enter new task due date: ";
        getline(cin, dueDate);
        //use of the setters of the class Task to update the class
        task.setName(name);
        task.setDescription(description);
        task.setDueDate(dueDate);
        cout << "Your task was updated!" << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
}

//use of ofstream to save the tasks in a .txt file
void ToDoList::saveTasks() const {
    //open or create the tasks.txt file
    ofstream outputFile("tasks.txt");
    if (outputFile.is_open()) {
        //this loop is like a loop for in Javascript.
        //The vector Tasks will be iterate and each task will be saved in the file
        for (const auto& task : tasks) {
            outputFile << task.getName() << "\n";
            outputFile << task.getDescription() << "\n";
            outputFile << task.getDueDate() << "\n";
            outputFile << task.isCompleted() << "\n";
        }
        //closing the file with all tasks saved
        outputFile.close();
        cout << "Updated To-Do List Saved!" << endl;
    } else {
        //cerr is an error code
        cerr << "Unable to open file for saving." << endl;
    }
}

//use of ifstream to load the tasks from a .txt file
void ToDoList::loadTasks() {
    //opening tasks.txt
    ifstream inputFile("tasks.txt");
    if (inputFile.is_open()) {
        string name, description, dueDate;
        bool completed;
        //reads line by line and add name, descriptio, dueDate and completed to a task
        while (getline(inputFile, name)) {
            getline(inputFile, description);
            getline(inputFile, dueDate);
            inputFile >> completed;
            inputFile.ignore();
            tasks.emplace_back(name, description, dueDate);
            if (completed) {
                tasks.back().markCompleted();
            }
        }
        inputFile.close();
        cout << "To-Do List Loaded." << endl;
    } else {
        //cerr is an error code
        cerr << "Unable to open file for loading (file may not exist yet)." << endl;
    }
}

void ToDoList::run() {
    //load tasks if it has from the file
    loadTasks();
    string choiceStr;
    int choice = 0;
    //here is the menu being displayed, the option being choosed
    // it is used a do-while loop 
    //so every time the user executes something, the menu will be displayed again
    do {
        displayMenu();
        cout << "Enter your choice: ";
        getline(cin, choiceStr);
        try {
            choice = stoi(choiceStr);
        } catch (const invalid_argument& e) {
            cout << "Invalid input. Please enter a number between 1 and 6." << endl;
            continue;
        } catch (const out_of_range& e) {
            cout << "Input out of range. Please enter a number between 1 and 6." << endl;
            continue;
        }

        switch (choice) {
            case 1: addTask(); break;
            case 2: deleteTask(); break;
            case 3: displayTasks(); break;
            case 4: markTaskCompleted(); break;
            case 5: editTask(); break;
            case 6: saveTasks(); cout << "Thank you for using the To-Do List App!" << endl; break;
            default: cout << "Invalid choice. Please try again!" << endl;
        }
    } while (choice != 6);
}
