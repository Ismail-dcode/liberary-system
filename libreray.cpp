#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class Visitor {
public:
    int id;
    string name;
    string entryTime;

    Visitor(int visitorId, string visitorName, string visitorEntryTime) {
        id = visitorId;
        name = visitorName;
        entryTime = visitorEntryTime;
    }
};

class AttendanceSystem {
private:
    vector<Visitor> visitors;

    string getCurrentTime() {
        time_t now = time(0);
        tm *ltm = localtime(&now);

        char buffer[20];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", ltm);
        return string(buffer);
    }

public:
    void recordEntry(int id, string name) {
        string entryTime = getCurrentTime();
        visitors.emplace_back(id, name, entryTime);
        cout << "Entry recorded successfully for " << name 
             << " at " << entryTime << ".\n";
    }

    void displayVisitors() {
        if (visitors.empty()) {
            cout << "No visitors recorded yet.\n";
            return;
        }

        cout << "Library Attendance:\n";
        for (const auto& visitor : visitors) {
            cout << "ID: " << visitor.id
                 << ", Name: " << visitor.name
                 << ", Entry Time: " << visitor.entryTime << "\n";
        }
    }
};

int main() {
    AttendanceSystem system;
    int choice;

    do {
        cout << "\nLibrary Attendance System\n";
        cout << "1. Record Entry\n";
        cout << "2. Display Visitors\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int id;
            string name;

            cout << "Enter Visitor ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Visitor Name: ";
            getline(cin, name);

            system.recordEntry(id, name);
            break;
        }
        case 2:
            system.displayVisitors();
            break;
        case 3:
            cout << "Exiting the system. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
