#ifndef UNDOSTACK_H
#define UNDOSTACK_H
#include "Workout.h"
#include <iostream>
using namespace std;

const int MAX_UNDO = 100;

class UndoStack {
private:
    Workout stack[MAX_UNDO];
    int top;
public:
    UndoStack() : top(-1) {}
    bool isFull() { return top == MAX_UNDO-1; }
    bool isEmpty() { return top == -1; }
    void push(Workout w) {
        if(isFull()) {
            cout << "Undo stack full! Cannot undo more.\n";
            return;
        }
        stack[++top] = w;
    }
    Workout pop() {
        if(isEmpty()) {
            Workout empty; empty.date = "";
            return empty;
        }
        return stack[top--];
    }
    void clear() { top = -1; }
};
#endif