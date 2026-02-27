#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ---------------- Base Task Class ----------------
class Task {
protected:
    string title;
    string deadline;
    string status;   // Pending / Completed
    int priority;    // 1=High, 2=Medium, 3=Low
    int timeSpent;   // minutes

public:
    Task(string t, string d, int p) : title(t), deadline(d), priority(p), status("Pending"), timeSpent(0) {}
    virtual void display() {
        cout << "Task: " << title << " | Deadline: " << deadline
             << " | Priority: " << priority << " | Status: " << status << endl;
    }
    void markComplete() { status = "Completed"; }
    void addTime(int minutes) { timeSpent += minutes; }
};

// ---------------- Priority Matrix (Inheritance) ----------------
class UrgentImportantTask : public Task {
public:
    UrgentImportantTask(string t, string d) : Task(t, d, 1) {}
    void display() override {
        cout << "[Urgent & Important] ";
        Task::display();
    }
};

class NotUrgentImportantTask : public Task {
public:
    NotUrgentImportantTask(string t, string d) : Task(t, d, 2) {}
    void display() override {
        cout << "[Not Urgent but Important] ";
        Task::display();
    }
};

// ---------------- Subject & Syllabus Tracker ----------------
class Subject {
    string name;
    int totalChapters;
    int completedChapters;
    vector<Task*> tasks;

public:
    Subject(string n, int chapters) : name(n), totalChapters(chapters), completedChapters(0) {}
    void addTask(Task* t) { tasks.push_back(t); }
    void completeChapter() { if(completedChapters < totalChapters) completedChapters++; }
    void showProgress() {
        cout << "Subject: " << name << " | Chapters: " << completedChapters << "/" << totalChapters << endl;
    }
};

// ---------------- GPA Predictor ----------------
class GPAPredictor {
public:
    // Simple GPA calculation
    double calculateGPA(int marks[], int subjects) {
        int sum = 0;
        for(int i=0; i<subjects; i++) sum += marks[i];
        return (double)sum / subjects / 20.0; // scale to GPA (0-4)
    }

    // Weighted GPA calculation (function overloading)
    double calculateGPA(float weightedMarks[], int credits[], int subjects) {
        float total = 0, totalCredits = 0;
        for(int i=0; i<subjects; i++) {
            total += weightedMarks[i] * credits[i];
            totalCredits += credits[i];
        }
        return total / totalCredits;
    }
};

// ---------------- Goal Tracker ----------------
class Goal {
    string goalTitle;
    int targetTasks;
    int completedTasks;

public:
    Goal(string title, int target) : goalTitle(title), targetTasks(target), completedTasks(0) {}
    void completeTask() { if(completedTasks < targetTasks) completedTasks++; }
    void showProgress() {
        cout << "Goal: " << goalTitle << " | Progress: " << completedTasks << "/" << targetTasks;
        cout << " (" << (completedTasks*100/targetTasks) << "%)" << endl;
    }
};

// ---------------- Planner ----------------
class Planner {
    vector<Task*> dailyTasks;
    vector<Task*> weeklyTasks;
    vector<Subject*> subjects;
    vector<Goal*> goals;

public:
    void addDailyTask(Task* t) { dailyTasks.push_back(t); }
    void addWeeklyTask(Task* t) { weeklyTasks.push_back(t); }
    void addSubject(Subject* s) { subjects.push_back(s); }
    void addGoal(Goal* g) { goals.push_back(g); }

    void showDailyReport() {
        cout << "\n--- Daily Tasks ---\n";
        for(auto t : dailyTasks) t->display();
    }

    void showWeeklyReport() {
        cout << "\n--- Weekly Tasks ---\n";
        for(auto t : weeklyTasks) t->display();
    }

    void showGoals() {
        cout << "\n--- Goals ---\n";
        for(auto g : goals) g->showProgress();
    }

    void showSubjects() {
        cout << "\n--- Subjects ---\n";
        for(auto s : subjects) s->showProgress();
    }
};

// ---------------- Main ----------------
int main() {
    Planner planner;

    // Add subjects
    Subject* math = new Subject("Math", 10);
    Subject* physics = new Subject("Physics", 8);
    planner.addSubject(math);
    planner.addSubject(physics);

    // Add tasks
    Task* t1 = new UrgentImportantTask("Finish Math Assignment", "2026-03-01");
    Task* t2 = new NotUrgentImportantTask("Read Physics Chapter", "2026-03-05");
    planner.addDailyTask(t1);
    planner.addWeeklyTask(t2);

    // Add goals
    Goal* g1 = new Goal("Complete 5 chapters this week", 5);
    planner.addGoal(g1);

    // GPA Predictor demo
    GPAPredictor gpa;
    int marks[3] = {80, 75, 90};
    cout << "\nExpected GPA: " << gpa.calculateGPA(marks, 3) << endl;

    // Reports
    planner.showDailyReport();
    planner.showWeeklyReport();
    planner.showSubjects();
    planner.showGoals();

    return 0;
}
