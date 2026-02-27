#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

// --- 1. BASE CLASS: Task (Encapsulation) ---
class Task {
protected:
    string title;
    string deadline;
public:
    Task(string t, string d) : title(t), deadline(d) {}
    virtual void displayTask() = 0; // Pure Virtual Function (Abstraction)
    string getTitle() { return title; }
};

// --- 2. INHERITANCE: Priority Matrix Quadrants ---
class UrgentTask : public Task {
public:
    UrgentTask(string t, string d) : Task(t, d) {}
    void displayTask() override {
        cout << "[!] URGENT & IMPORTANT | " << left << setw(20) << title << " | Due: " << deadline << endl;
    }
};

class NormalTask : public Task {
public:
    NormalTask(string t, string d) : Task(t, d) {}
    void displayTask() override {
        cout << "[ ] Not Urgent/Routine | " << left << setw(20) << title << " | Due: " << deadline << endl;
    }
};

// --- 3. CLASS: Subject & Syllabus Tracker ---
class Subject {
public:
    string name;
    int totalChapters, completedChapters;
    double creditHours, gradePoints;

    Subject() : totalChapters(0), completedChapters(0), creditHours(0), gradePoints(0) {}

    void inputSubject() {
        cout << "Enter Subject Name: "; cin >> name;
        cout << "Credit Hours: "; cin >> creditHours;
        cout << "Total Chapters: "; cin >> totalChapters;
        cout << "Chapters Completed: "; cin >> completedChapters;
        cout << "Current Grade Points (0-4.0): "; cin >> gradePoints;
    }

    void showProgressBar() {
        double percentage = (totalChapters > 0) ? (double)completedChapters / totalChapters * 100 : 0;
        int barWidth = 20;
        cout << left << setw(15) << name << " [";
        int pos = barWidth * (percentage / 100);
        for (int i = 0; i < barWidth; ++i) {
            if (i < pos) cout << "#"; else cout << "-";
        }
        cout << "] " << (int)percentage << "%" << endl;
    }
};

// --- 4. MAIN PROJECT CLASS ---
class SmartStudyManager {
private:
    vector<Task*> tasks;
    vector<Subject> subjects;
    string studentName;

public:
    SmartStudyManager() {
        cout << "========================================" << endl;
        cout << "   WELCOME TO SMART STUDY PLANNER 2.0   " << endl;
        cout << "========================================" << endl;
        cout << "Enter Student Name: "; getline(cin, studentName);
    }

    // --- Feature: Priority Matrix (Adding Tasks) ---
    void addTask() {
        string t, d; int p;
        cout << "\nEnter Task Title: "; cin.ignore(); getline(cin, t);
        cout << "Enter Deadline (DD/MM): "; getline(cin, d);
        cout << "Priority (1: Urgent/Important, 2: Normal): "; cin >> p;

        if (p == 1) tasks.push_back(new UrgentTask(t, d));
        else tasks.push_back(new NormalTask(t, d));
        cout << "Task Saved to Planner!\n";
    }

    // --- Feature: Function Overloading (GPA Predictor) ---
    // Method 1: GPA based on current subjects
    double calculateGPA(vector<Subject>& subs) {
        double totalPoints = 0, totalCredits = 0;
        for (const auto& s : subs) {
            totalPoints += (s.gradePoints * s.creditHours);
            totalCredits += s.creditHours;
        }
        return (totalCredits > 0) ? (totalPoints / totalCredits) : 0.0;
    }

    // Method 2: GPA with a bonus/improvement factor (Overloaded)
    double calculateGPA(vector<Subject>& subs, double improvement) {
        return calculateGPA(subs) + improvement;
    }

    // --- Feature: Daily/Weekly Goal Tracker ---
    void showDashboard() {
        cout << "\n---------- STUDENT DASHBOARD ----------" << endl;
        cout << "Student: " << studentName << endl;
        
        cout << "\n[1] SYLLABUS PROGRESS:" << endl;
        for (auto& s : subjects) s.showProgressBar();

        cout << "\n[2] PRIORITY TASK MATRIX:" << endl;
        for (auto t : tasks) t->displayTask();

        double gpa = calculateGPA(subjects);
        cout << "\n[3] PREDICTED GPA: " << fixed << setprecision(2) << gpa << "/4.0" << endl;
        cout << "---------------------------------------\n";
    }

    void addSubjectData() {
        Subject s;
        s.inputSubject();
        subjects.push_back(s);
    }

    // --- Feature: File Handling (Saving Data) ---
    void saveToFile() {
        ofstream outFile("study_records.txt");
        outFile << "Student: " << studentName << "\n";
        outFile << "GPA: " << calculateGPA(subjects) << "\n";
        outFile << "--- Tasks ---\n";
        for (auto t : tasks) outFile << t->getTitle() << "\n";
        outFile.close();
        cout << "All data synced to 'study_records.txt' successfully.\n";
    }

    ~SmartStudyManager() {
        for (auto t : tasks) delete t; // Memory Cleanup
    }
};

int main() {
    SmartStudyManager myApp;
    int choice;

    do {
        cout << "\n--- MAIN MENU ---";
        cout << "\n1. Add Task to Priority Matrix\n2. Add Subject & Syllabus\n3. View Dashboard & GPA\n4. Save Data\n5. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1: myApp.addTask(); break;
            case 2: myApp.addSubjectData(); break;
            case 3: myApp.showDashboard(); break;
            case 4: myApp.saveToFile(); break;
            case 5: cout << "Happy Studying! Goodbye."; break;
            default: cout << "Invalid Input!";
        }
    } while (choice != 5);

    return 0;
}