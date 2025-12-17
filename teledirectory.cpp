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


void add(map<string,string> & TD) {
    string name, no;
    
    cout<<"\nEnter new Name: ";
    getline(cin, name);

    cout<<"\nEnter new No: ";
    getline(cin, no);    
    
    auto state = TD.emplace(name,no);
    
    if(state.second) {
        cout<<"Inserted Successfully";
    }else {
        cout<<"Unsuccessfull (duplicate).";
    }
    
}


void remove(map<string,string> & TD) {
    string name, no;
    
    cout<<"\nEnter Name: ";
    getline(cin, name);
    if(TD.erase(name)) {
        cout<<"Deleted Successfully";
    }else {
        cout<<"Unsuccessful (401).";
    }
}


bool search(map<string,string> & TD) {
    string name;
    
    cout<<"\nEnter new Name: ";
    getline(cin, name);    
    auto it = TD.find(name);
    
    if(it != TD.end()) {
        cout<<"Record Exists."<<endl;
        
        cout<<"Name: "<<it->first;
        cout<<"Phone Number: "<<it->second;
    }
}


int main() {
    
    
    // printMenu();
    
    // name, phone number (local code - number)
    map<string,string> TD {
        {"Ayad", "042-25796115"},{"Bashir", "041-77665585"},{"Khalid", "021-66778000"}, {"Zubair", "051-667788"}
    }; // "Arslan", 042-3576115
    
    
}
