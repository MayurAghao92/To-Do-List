#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task
{
    string description;
    bool completed;
};

class TodoList
{
private:
    vector<Task> tasks;

public:
    // Function to take input
    string getInput(const string &prompt)
    {
        string input;
        cout << prompt;
        getline(cin, input);
        return input;
    }

    // Function to add a task
    void addTask(const string &description)
    {
        Task newTask = {description, false};
        tasks.push_back(newTask);
        cout << "Task added successfully!" << endl;
    }

    // Function to view tasks
    void viewTasks()
    {
        cout << "Tasks:" << endl;
        int index = 1;
        for (const Task &task : tasks)
        {
            cout << index++ << ". " << task.description;
            if (task.completed)
                cout << " (completed)";
            cout << endl;
        }
    }

    // Function to mark a task as completed
    void markCompleted(int index)
    {
        if (index >= 1 && index <= tasks.size())
        {
            tasks[index - 1].completed = true;
            cout << "Task marked as completed!" << endl;
        }
        else
        {
            cout << "Invalid task index!" << endl;
        }
    }

    // Function to remove a task
    void removeTask(int index)
    {
        if (index >= 1 && index <= tasks.size())
        {
            tasks.erase(tasks.begin() + index - 1);
            cout << "Task removed successfully!" << endl;
        }
        else
        {
            cout << "Invalid task index!" << endl;
        }
    }
};

int main()
{
    TodoList todoList;

    while (true)
    {
        cout << "Todo List Menu:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cin >> choice;
        cin.ignore(); // Clear the newline character from the input buffer

        switch (choice)
        {
        case 1:
        {
            string description = todoList.getInput("Enter task description: ");
            todoList.addTask(description);
            break;
        }
        case 2:
            todoList.viewTasks();
            break;
        case 3:
        {
            int index;
            cout << "Enter the index of the task to mark as completed: ";
            cin >> index;
            todoList.markCompleted(index);
            break;
        }
        case 4:
        {
            int index;
            cout << "Enter the index of the task to remove: ";
            cin >> index;
            todoList.removeTask(index);
            break;
        }
        case 5:
            cout << "Exiting program." << endl;
            return 0;
        default:
            cout << "Invalid choice! Please enter a number from 1 to 5." << endl;
        }
    }

    return 0;
}