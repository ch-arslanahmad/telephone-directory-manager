// Develop a telephone directory
// make all CRUD operation functions
// use <set>

// you can either do this with struct/class or STL pair class or STL string
// simply etc

// i will use struct (public members by default)

#include <iostream>
#include <set>
#include <sstream> // for string manipulation
using namespace std;

struct TelephoneRecord {
  string name;
  string telephoneNumber;

  // member initilizor list

  TelephoneRecord(string n, string t) : name(n), telephoneNumber(t) {}

  bool operator<(const TelephoneRecord &other) const {
    if (name == other.name) {
      return telephoneNumber < other.telephoneNumber;
    }
    return name < other.name;
  }

  string toString() const {
    return "Name: " + name + "\nTelephone Number: " + telephoneNumber;
  }
};

string options[] = {"Exit",
                    "Display",
                    "Add",
                    "Update",
                    "Remove",
                    "Search",
                    "Search by Local Number"};

// print the menu (#0)
void printMenu() {
  int i = 0;

  for (auto a : options) {
    cout << i << ". " << a << endl;
    i++;
  }
}

// #1 - displayRecords
void displayRecords(set<TelephoneRecord> &TD) {
  if (TD.empty()) {
    cout << "No records found." << endl;
    return;
  }
  for (const TelephoneRecord &record : TD) {
    cout << record.toString();
    cout << endl;
  }
}

// find utility-function
auto findRecord(TelephoneRecord record, set<TelephoneRecord> &TD) {
  auto it = TD.find(record);
  return it;
}

// find by name only
auto findByName(string name, set<TelephoneRecord> &TD) {
  for (auto it = TD.begin(); it != TD.end(); ++it) {
    if (it->name == name) {
      return it;
    }
  }
  return TD.end();
}

// #2 - Add record
void addRecord(set<TelephoneRecord> &TD) {
  string name, no;

  cout << "\nEnter new Name: ";
  getline(cin, name);

  if (findByName(name, TD) != TD.end()) {
    cout << "Already Exists.";
    return; // exist
  }

  cout << "\nEnter new No: ";
  getline(cin, no);

  // for <set> or <map> it always returns a pair
  // for std::set and std::map (associative containers), emplace always returns
  // a std::pair.
  auto state = TD.emplace(name, no);

  if (state.second) {
    cout << "Inserted Successfully" << endl;
  } else {
    cout << "Unsuccessfull (duplicate)." << endl;
  }
}

// #3 - Update Record
void updateRecord(set<TelephoneRecord> &TD) {
  string name, no;

  cout << "\nEnter existing Name: ";
  getline(cin, name);

  auto it = findByName(name, TD);

  if (it != TD.end()) {
    cout << "\nEnter new No: ";
    getline(cin, no);

    TD.erase(it);         // erase it
    TD.emplace(name, no); // insert it again
    cout << "Updated Successfully" << endl;
  } else {
    cout << "Unsuccessful (404)." << endl;
  }
}

// #4 - Remove Record
void removeRecord(set<TelephoneRecord> &TD) {
  string name, no;
  cout << "\nEnter Name: ";
  getline(cin, name);

  auto it = findByName(name, TD);
  if (it == TD.end()) {
    cout << "Unsuccessful (404)." << endl;
    return;
  }

  TD.erase(it);
  cout << "Deleted Successfully" << endl;
}

// #5 - Search Record
void searchRecord(set<TelephoneRecord> &TD) {
  string name;

  cout << "\nEnter new Name: ";
  getline(cin, name);

  auto it = findByName(name, TD);
  if (it != TD.end()) {
    cout << "Record Exists." << endl;
    cout << "Name: " << it->name << endl;
    cout << "Phone Number: " << it->telephoneNumber << endl;
  } else {
    cout << "Record does not exist." << endl;
  }
}

// #6 - Search by Local Number
void searchByLocalNumber(set<TelephoneRecord> &TD) {
  string localCode;
  cout << "\nEnter Local Code: ";
  getline(cin, localCode);

  bool found = false;

  for (auto record : TD) {

    string set_code = record.telephoneNumber.substr(0, localCode.length());
    if (set_code == localCode) {
      cout << "Name: " << record.name
           << "\nPhone Number: " << record.telephoneNumber << endl;
      found = true;
      break; // to find only the first matching record
    }
  }

  if (!found) {
    cout << "Record does not exist." << endl;
  }
}

void MenuHandler(set<TelephoneRecord> &TD) {
  while (true) {
    printMenu();
    int choice;
    cout << "\nEnter your choice: ";
    cin >> choice;
    cin.ignore(); // to ignore the newline character after integer input
    switch (choice) {
    case 0:
      cout << "Exiting..." << endl;
      return;
      break;
    case 1:
      displayRecords(TD);
      break;
    case 2:
      addRecord(TD);
      break;
    case 3:
      updateRecord(TD);
      break;
    case 4:
      removeRecord(TD);
      break;
    case 5:
      searchRecord(TD);
      break;
    case 6:
      searchByLocalNumber(TD);
      break;
    default:
      cout << "Invalid Choice.";
    }
  }
}

int main() {
  set<TelephoneRecord> TD;

  MenuHandler(TD);

  return 0;
}
