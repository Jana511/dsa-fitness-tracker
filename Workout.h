#ifndef WORKOUT_H
#define WORKOUT_H
#include <string>
using namespace std;

struct Workout {
    string date;      // "2025-04-05"
    string type;      // "Running", "Cycling", "Gym"
    int duration;     // minutes
    int distance;     // km (Gym  0)
    int sets;         // Gym 
    int reps;         // Gym 
};
#endif