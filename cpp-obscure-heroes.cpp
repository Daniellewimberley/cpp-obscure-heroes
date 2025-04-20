#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

const int SIZE = 10;

// Parallel arrays
string names[SIZE] = {
    "Squirrel Girl", "Arm-Fall-Off-Boy", "The Tick", "Matter-Eater Lad", "Dogwelder",
    "Color Kid", "Zeitgeist", "Doorman", "Hellcow", "Razorback"
};

string powers[SIZE] = {
    "Control Squirrels", "Detachable Limbs", "Super Strength", "Eat Anything", "Welds Dogs to People",
    "Color Manipulation", "Acid Vomit", "Teleportation", "Vampire Cow Powers", "Electric Boar Powers"
};

string weaknesses[SIZE] = {
    "Time Limits", "Heavy Objects", "Poor Judgment", "Stomach Aches", "Legal Issues",
    "Color Blindness", "Weak Constitution", "Needs Doorway", "Sunlight", "Static Shock"
};

// Multidimensional array: [0] = Year, [1] = Universe (0=Marvel, 1=DC, 2=Other)
int miscInfo[SIZE][2] = {
    {1992, 0}, {1989, 1}, {1986, 2}, {1962, 1}, {1996, 1},
    {1966, 1}, {2001, 0}, {1989, 2}, {1975, 0}, {1977, 2}
};

// Convert universe int to string
string getUniverse(int code) {
    switch (code) {
        case 0: return "Marvel";
        case 1: return "DC";
        case 2: return "Other";
        default: return "Unknown";
    }
}

// Display all superheroes
void displayAll(bool toUpper = true) {
    cout << "\n--- Superhero Database ---\n";
    for (int i = 0; i < SIZE; i++) {
        string name = names[i];
        string power = powers[i];
        string weak = weaknesses[i];

        if (toUpper) {
            transform(name.begin(), name.end(), name.begin(), ::toupper);
            transform(power.begin(), power.end(), power.begin(), ::toupper);
            transform(weak.begin(), weak.end(), weak.begin(), ::toupper);
        } else {
            transform(name.begin(), name.end(), name.begin(), ::tolower);
            transform(power.begin(), power.end(), power.begin(), ::tolower);
            transform(weak.begin(), weak.end(), weak.begin(), ::tolower);
        }

        cout << name << " | " << power << " | " << weak
             << " | " << miscInfo[i][0] << " | " << getUniverse(miscInfo[i][1]) << endl;
    }
}

// Case-insensitive string comparison helper
bool compareIgnoreCase(string a, string b) {
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(b.begin(), b.end(), b.begin(), ::tolower);
    return a == b;
}

// Search by name
void searchByName() {
    string query;
    cout << "Enter superhero name to search: ";
    getline(cin, query);
    bool found = false;

    for (int i = 0; i < SIZE; i++) {
        if (compareIgnoreCase(names[i], query)) {
            cout << "\nFound: " << names[i] << " | " << powers[i]
                 << " | " << weaknesses[i] << " | "
                 << miscInfo[i][0] << " | " << getUniverse(miscInfo[i][1]) << endl;
            found = true;
        }
    }

    if (!found)
        cout << "No superhero found with that name.\n";
}

// Search by power
void searchByPower() {
    string query;
    cout << "Enter superpower keyword: ";
    getline(cin, query);
    transform(query.begin(), query.end(), query.begin(), ::tolower);

    bool found = false;
    for (int i = 0; i < SIZE; i++) {
        string power = powers[i];
        transform(power.begin(), power.end(), power.begin(), ::tolower);

        if (power.find(query) != string::npos) {
            cout << names[i] << " | " << powers[i] << " | "
                 << weaknesses[i] << " | " << miscInfo[i][0] << " | "
                 << getUniverse(miscInfo[i][1]) << endl;
            found = true;
        }
    }

    if (!found)
        cout << "No superhero found with that power.\n";
}

// Alphabetical sort by name
void sortByName() {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            if (names[j] < names[i]) {
                swap(names[i], names[j]);
                swap(powers[i], powers[j]);
                swap(weaknesses[i], weaknesses[j]);
                swap(miscInfo[i][0], miscInfo[j][0]);
                swap(miscInfo[i][1], miscInfo[j][1]);
            }
        }
    }
    cout << "\nDatabase sorted alphabetically by name.\n";
}

int main() {
    int choice;
    do {
        cout << "\n--- Obscure Superhero Database ---\n";
        cout << "1. Search by Name\n";
        cout << "2. Search by Superpower\n";
        cout << "3. Sort Alphabetically\n";
        cout << "4. Display All (Uppercase)\n";
        cout << "5. Display All (Lowercase)\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();  // flush newline

        switch (choice) {
            case 1:
                searchByName();
                break;
            case 2:
                searchByPower();
                break;
            case 3:
                sortByName();
                break;
            case 4:
                displayAll(true);
                break;
            case 5:
                displayAll(false);
                break;
            case 0:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid option.\n";
        }

    } while (choice != 0);

    return 0;
}
