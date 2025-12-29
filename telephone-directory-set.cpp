// Develop a telephone directory
// make all CRUD operation functions
// use <set>

// you can either do this with struct/class or STL pair class or STL string
// simply etc

#include <iostream>
#include <set>
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

void MenuHandler(set<string> &TD) {
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
  set<string> TD;

  return 0;
}