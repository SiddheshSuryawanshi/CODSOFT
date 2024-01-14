#include <iostream>
#include <vector>
#include <string>

class Task {
public:
    std::string taskDescription;
    bool isTaskCompleted;

    Task(const std::string& desc) : taskDescription(desc), isTaskCompleted(false) {}
};

class ToDoManager {
private:
    std::vector<Task> taskList;

public:
    void addNewTask(const std::string& taskDesc) {
        taskList.push_back(Task(taskDesc));
        std::cout << "Task successfully added!\n";
    }

    void displayTasks() {
        if (taskList.empty()) {
            std::cout << "No tasks found.\n";
        } else {
            std::cout << "\n=== Your Task List ===\n";
            for (size_t i = 0; i < taskList.size(); ++i) {
                std::string status = taskList[i].isTaskCompleted ? "Completed" : "Pending";
                std::cout << i + 1 << ". " << taskList[i].taskDescription << " - " << status << "\n";
            }
        }
    }

    void markTaskAsCompleted(size_t taskIndex) {
        if (taskIndex > 0 && taskIndex <= taskList.size()) {
            taskList[taskIndex - 1].isTaskCompleted = true;
            std::cout << "Task marked as completed.\n";
        } else {
            std::cout << "Invalid task index.\n";
        }
    }

    void deleteTask(size_t taskIndex) {
        if (taskIndex > 0 && taskIndex <= taskList.size()) {
            taskList.erase(taskList.begin() + taskIndex - 1);
            std::cout << "Task removed successfully.\n";
        } else {
            std::cout << "Invalid task index.\n";
        }
    }
};

int main() {
    ToDoManager taskManager;

    while (true) {
        std::cout << "\n=== Task Manager ===\n";
        std::cout << "1. Add New Task\n";
        std::cout << "2. Display Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Delete Task\n";
        std::cout << "0. Exit\n";

        int userChoice;
        std::cout << "Enter your choice (0-4): ";
        std::cin >> userChoice;

        switch (userChoice) {
            case 0:
                std::cout << "Exiting the task manager.\n";
                return 0;
            case 1: {
                std::string taskDescription;
                std::cout << "Enter the task description: ";
                std::cin.ignore(); // Clear the newline character from the buffer
                std::getline(std::cin, taskDescription);
                taskManager.addNewTask(taskDescription);
                break;
            }
            case 2:
                taskManager.displayTasks();
                break;
            case 3: {
                size_t taskIndex;
                std::cout << "Enter the task index to mark as completed: ";
                std::cin >> taskIndex;
                taskManager.markTaskAsCompleted(taskIndex);
                break;
            }
            case 4: {
                size_t taskIndex;
                std::cout << "Enter the task index to delete: ";
                std::cin >> taskIndex;
                taskManager.deleteTask(taskIndex);
                break;
            }
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
