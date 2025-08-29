#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Task {
public:
    int id;
    string description;
    bool done;

    Task(int id, const string &desc) : id(id), description(desc), done(false) {}
};

class ToDoList {
private:
    vector<Task> tasks;
    int next_id = 1;

public:
    void addTask() {
        cin.ignore(); // clear leftover newline
        string desc;
        cout << "Enter task description: ";
        getline(cin, desc);

        if (desc.empty()) {
            cout << "Task description cannot be empty!\n";
            return;
        }

        tasks.emplace_back(next_id++, desc);
        cout << "Task added successfully.\n";
    }

    void listTasks() const {
        if (tasks.empty()) {
            cout << "No tasks available.\n";
            return;
        }
        cout << "\nYour Tasks:\n";
        for (const auto &task : tasks) {
            cout << task.id << ". [" << (task.done ? 'x' : ' ') << "] " 
                 << task.description << "\n";
        }
    }

    void markDone() {
        if (tasks.empty()) {
            cout << "No tasks available.\n";
            return;
        }

        int id;
        cout << "Enter task ID to mark as done: ";
        if (!(cin >> id)) {
            cout << "Invalid input.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            return;
        }

        for (auto &task : tasks) {
            if (task.id == id) {
                task.done = true;
                cout << "Task " << id << " marked as done.\n";
                return;
            }
        }
        cout << "Task with ID " << id << " not found.\n";
    }

    void removeTask() {
        if (tasks.empty()) {
            cout << "No tasks available.\n";
            return;
        }

        int id;
        cout << "Enter task ID to remove: ";
        if (!(cin >> id)) {
            cout << "Invalid input.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            return;
        }

        for (auto it = tasks.begin(); it != tasks.end(); ++it) {
            if (it->id == id) {
                tasks.erase(it);
                cout << "Task " << id << " removed.\n";
                return;
            }
        }
        cout << "Task with ID " << id << " not found.\n";
    }
};

int getChoice() {
    int choice;
    cout << "\n===== TO-DO LIST MENU =====\n";
    cout << "1. Add Task\n";
    cout << "2. List Tasks\n";
    cout << "3. Mark Task as Done\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
    cout << "Enter choice: ";

    if (!(cin >> choice)) {
        cin.clear();
        cin.ignore(1000, '\n');
        return -1;
    }
    return choice;
}

int main() {
    ToDoList todo;
    int choice;

    do {
        choice = getChoice();
        switch (choice) {
            case 1: todo.addTask(); break;
            case 2: todo.listTasks(); break;
            case 3: todo.markDone(); break;
            case 4: todo.removeTask(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
