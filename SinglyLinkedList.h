#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H
#include "Workout.h"

class Node {
public:
    Workout data;
    Node* next;
    Node(Workout w);
};

class SinglyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;
public:
    SinglyLinkedList();
    ~SinglyLinkedList();
    void insertLast(Workout w);
    bool deleteLast();   
    void display();
    void sortByDate();
    void sortByDuration();
    void sortByDistance();
    void searchByType(string type);
    double totalDistance();
    int totalDuration();
    int countByType(string type);
};
#endif