// Develop a telephone directory
// make all CRUD operation functions
// use hashmap
#include <iostream>
#include<map>
using namespace std;

string options[] = {"Add", "Delete", "Update", "Search"};

void printMenu() {
    int i = 0;
    
    for(auto a : options) {
        i++;
        cout<<i<<". "<<a<<endl;
    }
}


int main() {
    
    // printMenu();
    
    // name, phone number (local code - number)
    map<string,string> TD; // "Arslan", 042-3576115
    
    
}
