#include "SinglyLinkedList.h"
#include <iostream>
#include <algorithm>
using namespace std;

Node::Node(Workout w) : data(w), next(nullptr) {}

SinglyLinkedList::SinglyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

SinglyLinkedList::~SinglyLinkedList() {
    Node* curr = head;
    while(curr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }   
}

void SinglyLinkedList::insertLast(Workout w) {
    Node* newNode = new Node(w);
    if(!head) head = tail = newNode;
    else {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

bool SinglyLinkedList::deleteLast() {
    if(!head) return false;
    if(size == 1) {
        delete head;
        head = tail = nullptr;
        size = 0;
        return true;
    }
    Node* curr = head;
    while(curr->next != tail) {
        curr = curr->next;
    }
    delete tail;
    tail = curr;
    tail->next = nullptr;
    size--;
    return true;
}

void SinglyLinkedList::display() {
    if(!head) { cout << "No workouts logged.\n"; return; }
    Node* curr = head;
    cout << "\n==== ALL WORKOUTS ====\n";
    while(curr) {
        Workout w = curr->data;
        cout << w.date << " | " << w.type << " | " << w.duration << " min";
        if(w.type != "Gym") cout << " | " << w.distance << " km";
        else cout << " | Sets: " << w.sets << " x " << w.reps;
        cout << endl;
        curr = curr->next;
    }
}

void SinglyLinkedList::sortByDate() {
    if(size < 2) { display(); return; }
    for(int i=0; i<size-1; i++) {
        Node* curr = head;
        for(int j=0; j<size-i-1; j++) {
            if(curr->data.date > curr->next->data.date)
                swap(curr->data, curr->next->data);
            curr = curr->next;
        }
    }
    display();
}

void SinglyLinkedList::sortByDuration() {
    if(size < 2) { display(); return; }
    for(int i=0; i<size-1; i++) {
        Node* curr = head;
        for(int j=0; j<size-i-1; j++) {
            if(curr->data.duration > curr->next->data.duration)
                swap(curr->data, curr->next->data);
            curr = curr->next;
        }
    }
    display();
}

void SinglyLinkedList::sortByDistance() {
    if(size < 2) { display(); return; }
    for(int i=0; i<size-1; i++) {
        Node* curr = head;
        for(int j=0; j<size-i-1; j++) {
            if(curr->data.distance > curr->next->data.distance)
                swap(curr->data, curr->next->data);
            curr = curr->next;
        }
    }
    display();
}

void SinglyLinkedList::searchByType(string type) {
    Node* curr = head;
    bool found = false;
    cout << "\nWorkouts of type '" << type << "':\n";
    while(curr) {
        if(curr->data.type == type) {
            Workout w = curr->data;
            cout << "  " << w.date << " | " << w.duration << " min";
            if(w.type != "Gym") cout << " | " << w.distance << " km";
            else cout << " | Sets:" << w.sets << " x" << w.reps;
            cout << endl;
            found = true;
        }
        curr = curr->next;
    }
    if(!found) cout << "  None found.\n";
}

double SinglyLinkedList::totalDistance() {
    double sum = 0;
    Node* curr = head;
    while(curr) {
        if(curr->data.type != "Gym")
            sum += curr->data.distance;
        curr = curr->next;
    }
    return sum;
}

int SinglyLinkedList::totalDuration() {
    int sum = 0;
    Node* curr = head;
    while(curr) {
        sum += curr->data.duration;
        curr = curr->next;
    }
    return sum;
}

int SinglyLinkedList::countByType(string type) {
    int cnt = 0;
    Node* curr = head;
    while(curr) {
        if(curr->data.type == type) cnt++;
        curr = curr->next;
    }
    return cnt;
}