#include <iostream>
#include <string>
#include "SinglyLinkedList.h"
#include "PlannedQueue.h"
#include "UndoStack.h"
using namespace std;

int main() {
    SinglyLinkedList log;
    PlannedQueue planner;
    UndoStack undo;
    int choice;
    
    do {
        cout << "\n===== FITNESS TRACKER =====\n";
        cout << "1.  Add Workout Log\n";
        cout << "2.  View All Logs (Linked List)\n";
        cout << "3.  Sort by Date (Bubble Sort)\n";
        cout << "4.  Sort by Duration (Bubble Sort)\n";
        cout << "5.  Sort by Distance (Bubble Sort)\n";
        cout << "6.  Undo Last Workout (Stack)\n";
        cout << "7.  Search by Type (Linear Search)\n";
        cout << "8.  Add to Weekly Plan (Queue)\n";
        cout << "9.  View Weekly Plan (Queue)\n";
        cout << "10. Complete First Planned (Dequeue)\n";
        cout << "11. Show Progress Summary\n";
        cout << "0.  Exit\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();
        
        switch(choice) {
            case 1: {
                Workout w;
                cout << "Date (YYYY-MM-DD): ";
                getline(cin, w.date);
                cout << "Type (Running/Cycling/Gym): ";
                getline(cin, w.type);
                cout << "Duration (minutes): ";
                cin >> w.duration;
                if(w.type == "Gym" || w.type == "gym") {
                    cout << "Sets: ";
                    cin >> w.sets;
                    cout << "Reps: ";
                    cin >> w.reps;
                    w.distance = 0;
                } else {
                    cout << "Distance (km): ";
                    cin >> w.distance;
                    w.sets = 0;
                    w.reps = 0;
                }
                cin.ignore();
                log.insertLast(w);
                undo.push(w);
                cout << "Workout added!\n";
                break;
            }
            case 2: {
                log.display();
                break;
            }
            case 3: {
                log.sortByDate();
                break;
            }
            case 4: {
                log.sortByDuration();
                break;
            }
            case 5: {
                log.sortByDistance();
                break;
            }
            case 6: {
                if(undo.isEmpty()) {
                    cout << "Nothing to undo.\n";
                } else {
                    Workout last = undo.pop();
                    bool deleted = log.deleteLast();
                    if(deleted) {
                        cout << "Undo successful! Removed workout: "
                             << last.date << " | " << last.type << endl;
                    } else {
                        cout << "Undo failed.\n";
                    }
                }
                break;
            }
            case 7: {
                string t;
                cout << "Enter type (Running/Cycling/Gym): ";
                getline(cin, t);
                log.searchByType(t);
                break;
            }
            case 8: {
                Workout p;
                cout << "Plan Date (YYYY-MM-DD): ";
                getline(cin, p.date);
                cout << "Type (Running/Cycling/Gym): ";
                getline(cin, p.type);
                cout << "Duration (minutes): ";
                cin >> p.duration;
                cin.ignore();
                p.distance = 0; p.sets = 0; p.reps = 0;
                planner.enqueue(p);
                break;
            }
            case 9: {
                planner.displayPlan();
                break;
            }
            case 10: {
                if(planner.isEmpty()) {
                    cout << "No planned workouts to complete.\n";
                } else {
                    planner.dequeue();
                }
                break;
            }
            case 11: {
                cout << "\n===== PROGRESS SUMMARY =====\n";
                cout << "Running sessions: " << log.countByType("Running") << endl;
                cout << "Cycling sessions: " << log.countByType("Cycling") << endl;
                cout << "Gym sessions: " << log.countByType("Gym") << endl;
                cout << "Total distance: " << log.totalDistance() << " km\n";
                cout << "Total duration: " << log.totalDuration() << " minutes\n";
                break;
            }
            case 0: {
                cout << "Exiting Fitness Tracker. Goodbye!\n";
                break;
            }
            default: {
                cout << "Invalid choice. Try again.\n";
                break;
            }
        }
    } while(choice != 0);
    
    return 0;
}