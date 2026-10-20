#ifndef PLANNEDQUEUE_H
#define PLANNEDQUEUE_H
#include "Workout.h"
#include <iostream>
using namespace std;

class PlannedQueue {
private:
    Workout plans[7];
    int front, rear, count;
public:
    PlannedQueue() : front(0), rear(-1), count(0) {}
    bool isFull() { return count == 7; }
    bool isEmpty() { return count == 0; }
    void enqueue(Workout w) {
        if(isFull()) {
            cout << "Weekly plan full.\n";
            return;
        }
        rear = (rear+1)%7;
        plans[rear] = w;
        count++;
    }
    void dequeue() {
        if(isEmpty()) return;
        front = (front+1)%7;
        count--;
    }
    void displayPlan() {
        if(isEmpty()) { cout << "No planned workouts.\n"; return; }
        int idx = front;
        for(int i=0; i<count; i++) {
            Workout w = plans[idx];
            cout << w.date << " : " << w.type << " (" << w.duration << " min)\n";
            idx = (idx+1)%7;
        }
    }
};
#endif