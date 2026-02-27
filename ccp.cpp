#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <fstream>
using namespace std;

/* ================= TASK CLASS ================= */
class Task {
private:
    string subject;
    string title;
    int difficulty;
    int daysLeft;
    int priority;
    bool completed;

public:
    Task() {}

    Task(string s, string t, int d, int dl) {
        subject = s;
        title = t;
        difficulty = d;
        daysLeft = dl;
        completed = false;
        calculatePriority();
    }

    void calculatePriority() {
        if (daysLeft == 0) daysLeft = 1;
        priority = (difficulty * 2) + (50 / daysLeft);
    }

    int getPriority() const { return priority; }
    string getSubject() const { return subject; }
    string getTitle() const { return title; }
    bool isCompleted() const { return completed; }

    void markCompleted() { completed = true; }

    void display() const {
        cout << subject << " | "
             << title << " | "
             << "Priority: " << priority << " | "
             << (completed ? "Done" : "Pending") << endl;
    }

    bool operator<(const Task& other) const {
        return priority < other.priority;
    }

    string saveFormat() const {
        return subject + "," + title + "," +
               to_string(difficulty) + "," +
               to_string(daysLeft) + "," +
               to_string(completed);
    }
};

/* ================= STUDY PLANNER CLASS ================= */
class StudyPlanner {
private:
    vector<Task> tasks;
    map<string, int> completedSubjects;

public:
    void addTask() {
        string subject, title;
        int difficulty, daysLeft;

        cout << "Enter Subject: ";
        cin >> subject;
       
        cout << "Enter Difficulty (1-5): ";
        cin >> difficulty;
        cout << "Enter Days Left: ";
        cin >> daysLeft;

        Task t(subject, title, difficulty, daysLeft);
        tasks.push_back(t);

        cout << "Task Added!\n";
    }

    void displayTasks() {
        if (tasks.empty()) {
            cout << "No tasks available.\n";
            return;
        }

        for (const auto &t : tasks)
            t.display();
    }

    void markTaskCompleted() {
        string title;
        cout << "Enter title to mark complete: ";
        cin >> title;

        for (auto &t : tasks) {
            if (t.getTitle() == title) {
                t.markCompleted();
                completedSubjects[t.getSubject()]++;
                cout << "Marked Completed!\n";
                return;
            }
        }

        cout << "Task not found.\n";
    }

    void generateAutoSchedule() {
        priority_queue<Task> pq;

        for (const auto &t : tasks)
            if (!t.isCompleted())
                pq.push(t);

        cout << "\n--- Suggested Order of Study ---\n";
        while (!pq.empty()) {
            pq.top().display();
            pq.pop();
        }
    }

    void performanceReport() {
        cout << "\n--- Performance Report ---\n";
        for (auto &p : completedSubjects)
            cout << p.first << " : " << p.second << " tasks completed\n";
    }

    void saveToFile() {
        ofstream file("tasks.txt");
        for (const auto &t : tasks)
            file << t.saveFormat() << endl;
        file.close();
    }
};

/* ================= MAIN FUNCTION ================= */
int main() {
    StudyPlanner planner;
    int choice;

    do {
        cout << "\n===== SMART STUDY PLANNER =====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task Completed\n";
        cout << "4. Generate Auto Schedule\n";
        cout << "5. Performance Report\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            planner.addTask();
            break;
        case 2:
            planner.displayTasks();
            break;
        case 3:
            planner.markTaskCompleted();
            break;
        case 4:
            planner.generateAutoSchedule();
            break;
        case 5:
            planner.performanceReport();
            break;
        case 6:
            planner.saveToFile();
            cout << "Data Saved. Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}