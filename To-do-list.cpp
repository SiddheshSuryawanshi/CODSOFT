#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Task {
    string description;
    bool completed;
};

vector<Task> taskList;

void addTask(const string& taskDescription) {
    taskList.push_back({taskDescription, false});
}

void viewTasks() {
    cout << "To-Do List:\n";
    for (size_t i = 0; i < taskList.size(); ++i) {
        cout << i + 1 << ". " << taskList[i].description 
             << " [" << (taskList[i].completed ? "Completed" : "Pending") << "]\n";
    }
}

void markTaskCompleted(size_t taskNumber) {
    if (taskNumber > 0 && taskNumber <= taskList.size()) {
        taskList[taskNumber - 1].completed = true;
    } else {
        cout << "Invalid task number.\n";
    }
}

void removeTask(size_t taskNumber) {
    if (taskNumber > 0 && taskNumber <= taskList.size()) {
        taskList.erase(taskList.begin() + taskNumber - 1);
    } else {
        cout << "Invalid task number.\n";
    }
}

int main() {
    int action;
    string description;
    size_t taskNumber;

    while (true) {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Select an action: ";
        cin >> action;

        switch (action) {
            case 1:
                cout << "Enter the description of the new task: ";
                cin.ignore();
                getline(cin, description);
                addTask(description);
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                cout << "Enter the number of the task to mark as completed: ";
                cin >> taskNumber;
                markTaskCompleted(taskNumber);
                break;
            case 4:
                cout << "Enter the number of the task to remove: ";
                cin >> taskNumber;
                removeTask(taskNumber);
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid action. Please choose from 1 to 5.\n";
        }
    }

    return 0;
}
