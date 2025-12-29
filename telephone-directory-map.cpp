// Develop a telephone directory
// make all CRUD operation functions
// use <map>
#include <iostream>
#include <map>
using namespace std;

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

// #1 - Display Records
void displayRecords(const map<string, string> &TD) {
  cout << "\nTelephone Directory Records: \n";
  for (const auto &entry : TD) {
    cout << "---------------------\n";
    cout << "Name: " << entry.first << endl;
    cout << "Phone Number: " << entry.second << endl;
    cout << "-----------------------\n";
  }
  cout << "End of Records.\n" << endl;
}

// #2 - Add Record
void addRecord(map<string, string> &TD) {
  string name, no;

  cout << "\nEnter new Name: ";
  getline(cin, name);

  cout << "\nEnter new No: ";
  getline(cin, no);

  auto state = TD.emplace(name, no);

  if (state.second) {
    cout << "Inserted Successfully" << endl;
  } else {
    cout << "Unsuccessfull (duplicate)." << endl;
  }
}

// #3 - Update Record
void updateRecord(map<string, string> &TD) {
  string name, no;

  cout << "\nEnter existing Name: ";
  getline(cin, name);

  auto it = TD.find(name); // store iterator

  if (it != TD.end()) {
    cout << "\nEnter new No: ";
    getline(cin, no);
    it->second = no;
    cout << "Updated Successfully" << endl;
  } else {
    cout << "Unsuccessful (404)." << endl;
  }
}

// #4 - Remove Record
void removeRecord(map<string, string> &TD) {
  string name, no;

  cout << "\nEnter Name: ";
  getline(cin, name);
  if (TD.erase(name)) {
    cout << "Deleted Successfully" << endl;
  } else {
    cout << "Unsuccessful (401)." << endl;
  }
}

// #5 - Search Record
void searchRecord(map<string, string> &TD) {
  string name;

  cout << "\nEnter new Name: ";
  getline(cin, name);
  auto it = TD.find(name);

  if (it != TD.end()) {
    cout << "Record Exists." << endl;
    cout << "Name: " << it->first;
    cout << "Phone Number: " << it->second;
    cout << endl;
  } else {
    cout << "Record does not exist." << endl;
  }
}

// #6 - Search by Local Number
void searchByLocalNumber(map<string, string> &TD) {
  string localCode;

  cout << "\nEnter Local Code: ";
  getline(cin, localCode);

  bool found = false;
  for (const auto &entry : TD) {
    if (entry.second.substr(0, localCode.length()) == localCode) {
      cout << "Name: " << entry.first << ", Phone Number: " << entry.second
           << endl;
      found = true;
      break; // to find only the first matching record
    }
  }

  if (!found) {
    cout << "No records found with the given local code." << endl;
  } else {
    cout << "Search completed." << endl;
  }
}

void MenuHandler(map<string, string> &TD) {
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
  // name, phone number (local code - number)
  map<string, string> TD{{"Ayad", "042-25796115"},
                         {"Bashir", "041-77665585"},
                         {"Khalid", "021-66778000"},
                         {"Zubair", "051-667788"}}; // "Arslan", 042-3576115

  MenuHandler(TD);
}
