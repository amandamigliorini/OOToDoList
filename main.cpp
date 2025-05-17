#include <iostream>
#include "Task.h"
#include "ToDoList.h"

using namespace std;

// Main function
//Here is the starting function of the application
// it starts the toDoList object and run
int main()
{
    ToDoList toDoList;
    toDoList.run();
    return 0;
}