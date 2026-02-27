#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

// ------------------- Subject Class -------------------
class Subject {
private:
string name;
int weaknessLevel;  // 1 (strong) - 10 (weak)
string examDate;    // format DD/MM/YYYY
int hoursCompleted;

public:
Subject(string n, int w, string d) : name(n), weaknessLevel(w), examDate(d), hoursCompleted(0) {}

string getName() { return name; }  
int getWeakness() { return weaknessLevel; }  
string getExamDate() { return examDate; }  
int getHoursCompleted() { return hoursCompleted; }  

void addHours(int h) { hoursCompleted += h; }  

void editSubject(string n, int w, string d) {  
    name = n;  
    weaknessLevel = w;  
    examDate = d;  
}  

void displaySubject() {  
    cout << "Subject: " << name   
         << ", Weakness: " << weaknessLevel   
         << ", Exam: " << examDate   
         << ", Hours Completed: " << hoursCompleted << endl;  
}

};

// ------------------- User Class -------------------
class User {
private:
string name;
string studentID;
vector<Subject> subjects;

public:
User(string n = "", string id = "") : name(n), studentID(id) {}

void createProfile() {  
    cout << "Enter Student Name: ";  
    getline(cin, name);  
    cout << "Enter Student ID: ";  
    getline(cin, studentID);  
    cout << "Profile created successfully!\n\n";  
}  

void displayProfile() {  
    cout << "Student Name: " << name << ", ID: " << studentID << endl;  
}  

// -------- Subject Management --------  
void addSubject() {  
    string n, d;  
    int w;  
    cout << "Enter Subject Name: ";  
    getline(cin, n);  
    cout << "Enter Weakness Level (1-10): ";  
    cin >> w;  
    cin.ignore();  
    cout << "Enter Exam Date (DD/MM/YYYY): ";  
    getline(cin, d);  
    subjects.push_back(Subject(n, w, d));  
    cout << "Subject added successfully!\n";  
}  

void editSubject() {  
    string subjName;  
    cout << "Enter Subject Name to Edit: ";  
    getline(cin, subjName);  
    bool found = false;  
    for (auto &s : subjects) {  
        if (s.getName() == subjName) {  
            string n, d;  
            int w;  
            cout << "Enter New Name: ";  
            getline(cin, n);  
            cout << "Enter New Weakness Level (1-10): ";  
            cin >> w;  
            cin.ignore();  
            cout << "Enter New Exam Date (DD/MM/YYYY): ";  
            getline(cin, d);  
            s.editSubject(n, w, d);  
            cout << "Subject updated!\n";  
            found = true;  
            break;  
        }  
    }  
    if (!found) cout << "Subject not found!\n";  
}  

void deleteSubject() {  
    string subjName;  
    cout << "Enter Subject Name to Delete: ";  
    getline(cin, subjName);  
    auto it = remove_if(subjects.begin(), subjects.end(), [&](Subject &s){ return s.getName() == subjName; });  
    if (it != subjects.end()) {  
        subjects.erase(it, subjects.end());  
        cout << "Subject deleted!\n";  
    } else {  
        cout << "Subject not found!\n";  
    }  
}  

void viewSubjects() {  
    if (subjects.empty()) {  
        cout << "No subjects added.\n";  
        return;  
    }  
    cout << "--- Subjects ---\n";  
    for (auto &s : subjects)  
        s.displaySubject();  
    cout << "----------------\n";  
}  

vector<Subject>& getSubjects() { return subjects; }

};

// ------------------- Planner Abstract Class -------------------
class Planner {
public:
virtual void generateSchedule() = 0; // pure virtual
};

// ------------------- SmartPlanner Class -------------------
class SmartPlanner : public Planner {
private:
vector<Subject>& subjects;
int totalHours;

public:
SmartPlanner(vector<Subject>& s, int h) : subjects(s), totalHours(h) {}

void generateSchedule() override {  
    if (subjects.empty()) {  
        cout << "No subjects to schedule!\n";  
        return;  
    }  

    cout << "\n--- Smart Study Schedule ---\n";  

    // Sort by weakness first, then exam urgency (simulate exam priority: not fully date-aware, just example)  
    sort(subjects.begin(), subjects.end(), [](Subject &a, Subject &b){  
        return a.getWeakness() > b.getWeakness(); // Weak subjects first  
    });  

    int totalWeakness = 0;  
    for (auto &s : subjects) totalWeakness += s.getWeakness();  

    for (auto &s : subjects) {  
        int allocated = (s.getWeakness() * totalHours) / totalWeakness;  
        cout << "Study " << allocated << " hours for " << s.getName() << endl;  

        // AI-like recommendations  
       if  (s.getWeakness() >= 7)  
            cout << ">>> AI Tip: Focus extra on " << s.getName() << " today! It's your weak subject.\n";  
        // Simple exam alert  
        if (!s.getExamDate().empty())  
            cout << ">>> Reminder: " << s.getName() << " exam is on " << s.getExamDate() << ". Prioritize it!\n";  
    }  

    cout << "-----------------------------\n";  
}

};

// ------------------- Progress Tracker -------------------
class ProgressTracker {
private:
vector<Subject>& subjects;

public:
ProgressTracker(vector<Subject>& s) : subjects(s) {}

void markProgress() {  
    string subjName;  
    int hours;  
    cout << "Enter Subject Name to Mark Progress: ";  
    getline(cin, subjName);  
    bool found = false;  
    for (auto &s : subjects) {  
        if (s.getName() == subjName) {  
            cout << "Enter hours studied today: ";  
            cin >> hours;  
            cin.ignore();  
            s.addHours(hours);  
            cout << "Progress updated!\n";  
            found = true;  
            break;  
        }  
    }  
    if (!found) cout << "Subject not found!\n";  
}  

void showProgress() {  
    cout << "\n--- Study Progress ---\n";  
    for (auto &s : subjects) {  
        cout << s.getName() << " -> Hours Completed: " << s.getHoursCompleted() << endl;  
    }  
    cout << "---------------------\n";  
}

};

// ------------------- Main -------------------
int main() {
vector<User> students;
int choice;

do {  
    cout << "\n--- Smart Study Planner Menu ---\n";  
    cout << "1. Create Student Profile\n";  
    cout << "2. Manage Subjects\n";  
    cout << "3. Generate Smart Schedule\n";  
    cout << "4. Mark Progress\n";  
    cout << "5. View Progress\n";  
    cout << "6. View Student Profile\n";  
    cout << "7. Exit\n";  
    cout << "Enter Choice: ";  
    cin >> choice;  
    cin.ignore();  

    static User* currentUser = nullptr;  

    switch(choice) {  
        case 1: {  
            User u;  
            u.createProfile();  
            students.push_back(u);  
            currentUser = &students.back(); // current active user  
            break;  
        }  

        case 2: {  
            if (!currentUser) {  
                cout << "Create a student profile first!\n";  
                break;  
            }  
            int subChoice;  
            do {  
                cout << "\n--- Subject Management ---\n";  
                cout << "1. Add Subject\n2. Edit Subject\n3. Delete Subject\n4. View Subjects\n5. Back\n";  
                cout << "Choice: ";  
                cin >> subChoice;  
                cin.ignore();  
                switch(subChoice) {  
                    case 1: currentUser->addSubject(); break;  
                    case 2: currentUser->editSubject(); break;  
                    case 3: currentUser->deleteSubject(); break;  
                    case 4: currentUser->viewSubjects(); break;  
                    case 5: break;  
                    default: cout << "Invalid!\n";   
                }  
            } while(subChoice != 5);  
            break;  
        }  

        case 3: {  
            if (!currentUser) {  
                cout << "Create a student profile first!\n";  
                break;  
            }  
            int totalH;  
            cout << "Enter total available study hours today: ";  
            cin >> totalH;  
            cin.ignore();  
            SmartPlanner sp(currentUser->getSubjects(), totalH);  
            sp.generateSchedule();  
            break;  
        }  

        case 4: {  
            if (!currentUser) {  
                cout << "Create a student profile first!\n";  
                break;  
            }  
            ProgressTracker pt(currentUser->getSubjects());  
            pt.markProgress();  
            break;  
        }  

        case 5: {  
            if (!currentUser) {  
                cout << "Create a student profile first!\n";  
                break;  
            }  
            ProgressTracker pt(currentUser->getSubjects());  
            pt.showProgress();  
            break;  
        }  

        case 6: {  
            if (!currentUser) {  
                cout << "Create a student profile first!\n";  
                break;  
            }  
            currentUser->displayProfile();  
            currentUser->viewSubjects();  
            break;  
        }  

        case 7: cout << "Exiting...\n"; break;  
        default: cout << "Invalid Choice!\n";  
    }  

} while(choice != 7);  

return 0;

}