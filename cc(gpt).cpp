#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Task {
protected:
    string title;
    string subject;
    string deadline;
    bool completed;

public:
    Task(string t, string s, string d) {
        title = t;
        subject = s;
        deadline = d;
        completed = false;
    }

    virtual string getPriority() {
        return "Normal";
    }

    void markCompleted() {
        completed = true;
    }

    bool isCompleted() {
        return completed;
    }

    string getTitle() {
        return title;
    }

    virtual void display() {
        cout << "Task: " << title << endl;
        cout << "Subject: " << subject << endl;
        cout << "Deadline (DD-MM-YYYY): " << deadline << endl;
        cout << "Priority: " << getPriority() << endl;
        cout << "Status: " << (completed ? "Completed" : "Pending") << endl;
        cout << "---------------------------\n";
    }
};

class UrgentTask : public Task {
public:
    UrgentTask(string t, string s, string d) : Task(t, s, d) {}

    string getPriority() override {
        return "Urgent";
    }
};

class NormalTask : public Task {
public:
    NormalTask(string t, string s, string d) : Task(t, s, d) {}

    string getPriority() override {
        return "Important";
    }
};

class Goal {
    string name;
    int progress;

public:
    Goal(string n) {
        name = n;
        progress = 0;
    }

    void updateProgress(int value) {
        progress += value;
        if (progress > 100) progress = 100;
    }

    void display() {
        cout << "Goal: " << name << endl;
        cout << "Progress: " << progress << "%\n";
        cout << "-------------------\n";
    }
};

class Chapter {
    string name;
    bool completed;

public:
    Chapter(string n) {
        name = n;
        completed = false;
    }

    void markDone() {
        completed = true;
    }

    bool isDone() {
        return completed;
    }

    string getName() {
        return name;
    }
};

class SyllabusTracker {
    vector<Chapter> chapters;

public:
    void addChapter(string name) {
        chapters.push_back(Chapter(name));
    }

    void completeChapter(int index) {
        if (index >= 0 && index < chapters.size())
            chapters[index].markDone();
    }

    void showProgress() {
        int done = 0;

        for (auto &c : chapters)
            if (c.isDone())
                done++;

        int percent = (chapters.size() == 0) ? 0 : (done * 100 / chapters.size());

        cout << "\nSyllabus Progress: " << percent << "%\n";

        int bars = percent / 10;
        cout << "[";
        for (int i = 0; i < bars; i++) cout << "#";
        for (int i = bars; i < 10; i++) cout << "-";
        cout << "]\n";

        cout << "Completed " << done << " of " << chapters.size() << " chapters\n";
    }

    void listChapters() {
        for (int i = 0; i < chapters.size(); i++) {
            cout << i << ". " << chapters[i].getName()
                 << " (" << (chapters[i].isDone() ? "Done" : "Pending") << ")\n";
        }
    }
};

class GPAPredictor {
public:
    double calculateGPA(double marks) {
        return (marks / 100) * 4.0;
    }

    double calculateGPA(double mid, double final, double assignment) {
        double total = mid * 0.3 + final * 0.5 + assignment * 0.2;
        return (total / 100) * 4.0;
    }
};

class Planner {
    vector<Task*> tasks;
    vector<Goal> goals;
    SyllabusTracker syllabus;

public:

    void addTask() {
        string title, subject, deadline;
        int type;

        cin.ignore();

        cout << "Task title: ";
        getline(cin, title);

        cout << "Subject: ";
        getline(cin, subject);

        cout << "Deadline (DD-MM-YYYY): ";
        getline(cin, deadline);

        cout << "1. Urgent Task\n2. Important Task\nChoice: ";
        cin >> type;

        if (type == 1)
            tasks.push_back(new UrgentTask(title, subject, deadline));
        else
            tasks.push_back(new NormalTask(title, subject, deadline));
    }

    void viewTasks() {
        cout << "\n1. All Tasks\n2. Pending\n3. Completed\nChoice: ";
        int ch;
        cin >> ch;

        for (auto t : tasks) {

            if (ch == 1)
                t->display();

            else if (ch == 2 && !t->isCompleted())
                t->display();

            else if (ch == 3 && t->isCompleted())
                t->display();
        }
    }

    void completeTask() {
        for (int i = 0; i < tasks.size(); i++) {
            cout << i << ". " << tasks[i]->getTitle() << endl;
        }

        int index;
        cout << "Select task index: ";
        cin >> index;

        if (index >= 0 && index < tasks.size()) {
            tasks[index]->markCompleted();
            cout << "Task marked completed\n";
        }
    }

    void addGoal() {
        cin.ignore();
        string name;

        cout << "Enter goal: ";
        getline(cin, name);

        goals.push_back(Goal(name));
    }

    void showGoals() {
        for (auto &g : goals)
            g.display();
    }

    void syllabusMenu() {
        int ch;

        cout << "\n1 Add Chapter\n2 Complete Chapter\n3 View Progress\nChoice: ";
        cin >> ch;

        if (ch == 1) {
            cin.ignore();
            string name;
            cout << "Chapter name: ";
            getline(cin, name);
            syllabus.addChapter(name);
        }

        else if (ch == 2) {
            syllabus.listChapters();
            int i;
            cout << "Index: ";
            cin >> i;
            syllabus.completeChapter(i);
        }

        else
            syllabus.showProgress();
    }

    void predictGPA() {
        GPAPredictor g;
        int ch;

        cout << "1 Simple GPA\n2 Expected GPA\nChoice: ";
        cin >> ch;

        if (ch == 1) {
            double m;
            cout << "Enter marks: ";
            cin >> m;

            cout << "GPA: " << fixed << setprecision(2)
                 << g.calculateGPA(m) << endl;
        }

        else {
            double mid, final, assign;

            cout << "Midterm marks: ";
            cin >> mid;

            cout << "Expected final marks: ";
            cin >> final;

            cout << "Assignment marks: ";
            cin >> assign;

            cout << "Expected GPA: "
                 << g.calculateGPA(mid, final, assign) << endl;
        }
    }

    void dashboard() {

        int pending = 0;

        for (auto t : tasks)
            if (!t->isCompleted())
                pending++;

        cout << "\n----- DASHBOARD -----\n";
        cout << "Total Tasks: " << tasks.size() << endl;
        cout << "Pending Tasks: " << pending << endl;
        cout << "Goals: " << goals.size() << endl;
        cout << "---------------------\n";
    }
};

int main() {

    Planner planner;
    int choice;

    while (true) {

        cout << "\n===== SMART STUDY PLANNER =====\n";

        cout << "1 Dashboard\n";
        cout << "2 Add Task\n";
        cout << "3 View Tasks\n";
        cout << "4 Complete Task\n";
        cout << "5 Manage Goals\n";
        cout << "6 Syllabus Tracker\n";
        cout << "7 GPA Predictor\n";
        cout << "8 Exit\n";

        cout << "Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            planner.dashboard();
            break;

        case 2:
            planner.addTask();
            break;

        case 3:
            planner.viewTasks();
            break;

        case 4:
            planner.completeTask();
            break;

        case 5:
            planner.addGoal();
            planner.showGoals();
            break;

        case 6:
            planner.syllabusMenu();
            break;

        case 7:
            planner.predictGPA();
            break;

        case 8:
            return 0;
        }
    }
}