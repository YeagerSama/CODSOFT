#include <iostream>
#include <vector>
#include <string>

using namespace std;

void displayMenu() {
    cout << "To-Do List Manager" << endl;
    cout << "1. Add a task" << endl;
    cout << "2. View tasks" << endl;
    cout << "3. Delete a task" << endl;
    cout << "4. Exit" << endl;
    cout << "Choose an option: ";
}

void addTask(vector<string> &tasks) {
    cout << "Enter a new task: ";
    string task;
    cin.ignore(); // Ignore the newline character left in the buffer
    getline(cin, task);
    tasks.push_back(task);
    cout << "Task added successfully!" << endl;
}

void viewTasks(const vector<string> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
    } else {
        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i] << endl;
        }
    }
}

void deleteTask(vector<string> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks to delete." << endl;
    } else {
        viewTasks(tasks);
        cout << "Enter the task number to delete: ";
        size_t taskNumber;
        cin >> taskNumber;

        if (taskNumber < 1 || taskNumber > tasks.size()) {
            cout << "Invalid task number." << endl;
        } else {
            tasks.erase(tasks.begin() + taskNumber - 1);
            cout << "Task deleted successfully!" << endl;
        }
    }
}

int main() {
    vector<string> tasks;
    int option;

    do {
        displayMenu();
        cin >> option;

        switch (option) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                deleteTask(tasks);
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }

        cout << endl;
    } while (option != 4);

    return 0;
}
