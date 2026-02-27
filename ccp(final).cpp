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
    int weaknessLevel;
    string examDate;
    int hoursCompleted;

public:
    Subject(string n, int w, string d) {
        name = n;
        weaknessLevel = w;
        examDate = d;
        hoursCompleted = 0;
    }

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
        cout << left << setw(15) << name
             << setw(10) << weaknessLevel
             << setw(15) << examDate
             << setw(10) << hoursCompleted << endl;
    }
};

// ------------------- User Class -------------------
class User {
private:
    string name;
    string studentID;
    vector<Subject> subjects;

public:
    User(string n = "", string id = "") {
        name = n;
        studentID = id;
    }

    void createProfile() {
        cout << "Enter Student Name: ";
        getline(cin, name);

        cout << "Enter Student ID: ";
        getline(cin, studentID);

        cout << "Profile created successfully!\n";
    }

    void displayProfile() {
        cout << "\n===== Student Profile =====\n";
        cout << "Name: " << name << endl;
        cout << "ID  : " << studentID << endl;
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
                return;
            }
        }

        cout << "Subject not found!\n";
    }

    void deleteSubject() {
        string subjName;

        cout << "Enter Subject Name to Delete: ";
        getline(cin, subjName);

        auto it = remove_if(subjects.begin(), subjects.end(),
                            [&](Subject &s) { return s.getName() == subjName; });

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

        cout << "\n------ Subjects ------\n";

        cout << left << setw(15) << "Subject"
             << setw(10) << "Weak"
             << setw(15) << "Exam Date"
             << setw(10) << "Hours" << endl;

        cout << "---------------------------------------------\n";

        for (auto &s : subjects)
            s.displaySubject();
    }

    vector<Subject>& getSubjects() {
        return subjects;
    }
};

// ------------------- Abstract Planner -------------------
class Planner {
public:
    virtual void generateSchedule() = 0;
};

// ------------------- SmartPlanner -------------------
class SmartPlanner : public Planner {
private:
    vector<Subject> &subjects;
    int totalHours;

public:
    SmartPlanner(vector<Subject> &s, int h) : subjects(s), totalHours(h) {}

    void generateSchedule() override {

        if (subjects.empty()) {
            cout << "No subjects to schedule!\n";
            return;
        }

        cout << "\n===== Smart Study Schedule =====\n";

        sort(subjects.begin(), subjects.end(),
             [](Subject &a, Subject &b) {
                 return a.getWeakness() > b.getWeakness();
             });

        int totalWeakness = 0;

        for (auto &s : subjects)
            totalWeakness += s.getWeakness();

        for (auto &s : subjects) {

            int allocated = (s.getWeakness() * totalHours) / totalWeakness;

            cout << "Study " << allocated
                 << " hours for " << s.getName() << endl;

            // Smart recommendation
            if (s.getWeakness() >= 8)
                cout << ">>> CRITICAL: Spend extra practice time.\n";
            else if (s.getWeakness() >= 5)
                cout << ">>> Moderate weakness. Practice questions.\n";
            else
                cout << ">>> Strong subject. Quick revision enough.\n";

            cout << ">>> Exam Reminder: " << s.getExamDate() << endl;

            cout << endl;
        }
    }
};

// ------------------- Progress Tracker -------------------
class ProgressTracker {
private:
    vector<Subject> &subjects;

public:
    ProgressTracker(vector<Subject> &s) : subjects(s) {}

    void markProgress() {

        string subjName;
        int hours;

        cout << "Enter Subject Name: ";
        getline(cin, subjName);

        for (auto &s : subjects) {
            if (s.getName() == subjName) {

                cout << "Enter hours studied today: ";
                cin >> hours;
                cin.ignore();

                s.addHours(hours);

                cout << "Progress updated!\n";
                return;
            }
        }

        cout << "Subject not found!\n";
    }

    void showProgress() {

        cout << "\n===== Study Progress =====\n";

        for (auto &s : subjects) {
            cout << s.getName()
                 << " -> Hours Completed: "
                 << s.getHoursCompleted() << endl;
        }
    }

    void showAnalytics() {

        int totalHours = 0;
        int maxWeak = -1;
        string weakSubject = "";

        for (auto &s : subjects) {

            totalHours += s.getHoursCompleted();

            if (s.getWeakness() > maxWeak) {
                maxWeak = s.getWeakness();
                weakSubject = s.getName();
            }
        }

        cout << "\n===== Study Analytics =====\n";

        cout << "Total Study Hours: " << totalHours << endl;

        if (weakSubject != "")
            cout << "Most Weak Subject: " << weakSubject << endl;

        cout << "===========================\n";
    }
};

// ------------------- Main -------------------
int main() {

    vector<User> students;
    User *currentUser = nullptr;

    int choice;

    do {

        cout << "\n========= SMART STUDY PLANNER =========\n";

        cout << "1. Create Student Profile\n";
        cout << "2. Manage Subjects\n";
        cout << "3. Generate Smart Schedule\n";
        cout << "4. Mark Study Progress\n";
        cout << "5. View Progress\n";
        cout << "6. View Study Analytics\n";
        cout << "7. View Student Profile\n";
        cout << "8. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {

        case 1: {
            User u;
            u.createProfile();
            students.push_back(u);
            currentUser = &students.back();
            break;
        }

        case 2: {

            if (!currentUser) {
                cout << "Create profile first!\n";
                break;
            }

            int subChoice;

            do {

                cout << "\n---- Subject Management ----\n";

                cout << "1. Add Subject\n";
                cout << "2. Edit Subject\n";
                cout << "3. Delete Subject\n";
                cout << "4. View Subjects\n";
                cout << "5. Back\n";

                cout << "Choice: ";
                cin >> subChoice;
                cin.ignore();

                switch (subChoice) {

                case 1:
                    currentUser->addSubject();
                    break;

                case 2:
                    currentUser->editSubject();
                    break;

                case 3:
                    currentUser->deleteSubject();
                    break;

                case 4:
                    currentUser->viewSubjects();
                    break;
                }

            } while (subChoice != 5);

            break;
        }

        case 3: {

            if (!currentUser) {
                cout << "Create profile first!\n";
                break;
            }

            int hours;

            cout << "Enter total study hours available today: ";
            cin >> hours;
            cin.ignore();

            SmartPlanner sp(currentUser->getSubjects(), hours);
            sp.generateSchedule();

            break;
        }

        case 4: {

            if (!currentUser) {
                cout << "Create profile first!\n";
                break;
            }

            ProgressTracker pt(currentUser->getSubjects());
            pt.markProgress();

            break;
        }

        case 5: {

            if (!currentUser) {
                cout << "Create profile first!\n";
                break;
            }

            ProgressTracker pt(currentUser->getSubjects());
            pt.showProgress();

            break;
        }

        case 6: {

            if (!currentUser) {
                cout << "Create profile first!\n";
                break;
            }

            ProgressTracker pt(currentUser->getSubjects());
            pt.showAnalytics();

            break;
        }

        case 7: {

            if (!currentUser) {
                cout << "Create profile first!\n";
                break;
            }

            currentUser->displayProfile();
            currentUser->viewSubjects();

            break;
        }

        case 8:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 8);

    return 0;
}