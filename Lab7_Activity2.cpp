
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std;

struct Node {
    string data;
    Node* next;
};

// Linked queue operations
void enqueue(Node*& front, Node*& rear, string name) {
    Node* newNode = new Node{name, nullptr};

    if (rear == nullptr) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

string dequeue(Node*& front, Node*& rear) {
    if (front == nullptr)
        return "";

    Node* oldFront = front;
    string name = oldFront->data;

    front = front->next;

    if (front == nullptr)
        rear = nullptr;

    delete oldFront;

    return name;
}

void displayQueue(Node* front) {
    if (front == nullptr) {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << "Waiting customers: ";

    Node* current = front;

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    cout << endl;
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;

    // TODO 1: Enqueue five customers
    enqueue(front, rear, "Ali");
    enqueue(front, rear, "John");
    enqueue(front, rear, "Sara");
    enqueue(front, rear, "David");
    enqueue(front, rear, "Emma");

    // TODO 2: Display initial queue
    displayQueue(front);

    // TODO 3: Serve customers until queue is empty
    while (front != nullptr) {

        cout << "Now serving: " << front->data << endl;

        // Simulate 10 seconds of service
        this_thread::sleep_for(chrono::seconds(10));

        // Remove the served customer
        string name = dequeue(front, rear);

        cout << "Service completed: "
             << name << " (10 seconds)" << endl;
    }

    // TODO 4: Announce completion
    cout << "All customers have been served." << endl;

    // TODO 5: Display final queue
    displayQueue(front);

    return 0;
}
