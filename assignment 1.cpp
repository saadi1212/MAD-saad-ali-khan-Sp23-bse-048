#include <iostream>
#include <string>

using namespace std;

// Structure for each Task (node in the linked list)
struct Task {
    int taskID;              // Unique ID for each task
    string description;      // Description of the task
    int priority;            // Priority of the task
    Task* next;              // Pointer to the next task (next node in the list)
};

// Function to create a new task node
Task* createTask(int id, string desc, int priority) {
    Task* newTask = new Task();      // Dynamically allocate memory for a new task
    newTask->taskID = id;            // Assign task ID
    newTask->description = desc;     // Assign task description
    newTask->priority = priority;    // Assign task priority
    newTask->next = nullptr;         // Set the next pointer to nullptr (end of the list)
    return newTask;                  // Return the newly created task
}

// Function to add a task to the list, sorted by priority
void addTask(Task*& head, int id, string desc, int priority) {
    Task* newTask = createTask(id, desc, priority);  // Create the new task

    // If the list is empty or the new task has higher priority than the first task
    if (head == nullptr || head->priority < priority) {
        newTask->next = head;  // Insert the new task at the start of the list
        head = newTask;
    } else {
        // Traverse the list to find the correct position for the new task
        Task* temp = head;
        while (temp->next != nullptr && temp->next->priority >= priority) {
            temp = temp->next;  // Move to the next task in the list
        }
        // Insert the new task at the correct position
        newTask->next = temp->next;
        temp->next = newTask;
    }
    cout << "Task added successfully.\n";
}

// Function to view all tasks in the list
void viewTasks(Task* head) {
    if (head == nullptr) {   // Check if the list is empty
        cout << "No tasks available.\n";
        return;
    }

    // Traverse the list and print each task's details
    Task* temp = head;
    while (temp != nullptr) {
        cout << "Task ID: " << temp->taskID << "\nDescription: " << temp->description
             << "\nPriority: " << temp->priority << "\n\n";
        temp = temp->next;  // Move to the next task in the list
    }
}

// Function to remove the task with the highest priority (first task)
void removeHighestPriorityTask(Task*& head) {
    if (head == nullptr) {  // Check if the list is empty
        cout << "No tasks to remove.\n";
        return;
    }

    // Remove the first task (highest priority)
    Task* temp = head;
    head = head->next;  // Move the head to the next task
    cout << "Task with ID " << temp->taskID << " removed.\n";
    delete temp;  // Free memory allocated for the task
}

// Function to remove a specific task by its task ID
void removeTaskByID(Task*& head, int id) {
    if (head == nullptr) {  // Check if the list is empty
        cout << "No tasks to remove.\n";
        return;
    }

    // If the task to be removed is the first one
    if (head->taskID == id) {
        Task* temp = head;
        head = head->next;  // Move the head to the next task
        delete temp;  // Free memory for the task
        cout << "Task with ID " << id << " removed.\n";
        return;
    }

    // Traverse the list to find the task with the given ID
    Task* temp = head;
    while (temp->next != nullptr && temp->next->taskID != id) {
        temp = temp->next;  // Move to the next task
    }

    // If the task is found, remove it
    if (temp->next != nullptr) {
        Task* taskToRemove = temp->next;
        temp->next = taskToRemove->next;
        delete taskToRemove;  // Free memory for the task
        cout << "Task with ID " << id << " removed.\n";
    } else {
        // If the task with the given ID is not found
        cout << "Task with ID " << id << " not found.\n";
    }
}

// Main function to handle the menu-based interaction
int main() {
    Task* head = nullptr;  // Initialize the head of the list to nullptr
    int choice, id, priority;
    string description;

    do {
        // Display the menu
        cout << "\nTask Management System\n";
        cout << "1. Add New Task\n";
        cout << "2. View All Tasks\n";
        cout << "3. Remove Highest Priority Task\n";
        cout << "4. Remove Task by ID\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Add a new task
                cout << "Enter task ID: ";
                cin >> id;
                cin.ignore();  // Ignore newline character left by cin
                cout << "Enter task description: ";
                getline(cin, description);  // Get the task description
                cout << "Enter task priority: ";
                cin >> priority;
                addTask(head, id, description, priority);
                break;

            case 2:
                // View all tasks
                viewTasks(head);
                break;

            case 3:
                // Remove the highest priority task
                removeHighestPriorityTask(head);
                break;

            case 4:
                // Remove a task by its ID
                cout << "Enter task ID to remove: ";
                cin >> id;
                removeTaskByID(head, id);
                break;

            case 5:
                // Exit the program
                cout << "Exiting...\n";
                break;

            default:
                // Handle invalid input
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 5);  // Continue until the user chooses to exit

    return 0;
}
