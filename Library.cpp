#include <iostream>
#include <string>
using namespace std;

string adminUser = "ShahirKhaled";
string adminPassword = "Shahir123";

string user = "Najm";
string password = "Najm123";

int length = 2;

string books[5][4] = {
    {"c++", "Najm", "2023", "$10"},
    {"c++", "Najm", "2023", "$10"}
};

void showAll() {
    cout << "Here is a list of all available books\n";
    for (int i = 0; i < length; i++) {
        cout << "\nName\tAuthor\tYear\tPrice\n";
        for (int j = 0; j < 4; j++) cout << books[i][j] << "\t";
        cout << endl;
    }
}

void editElement(int index) {
    cout << "Please enter the name of the book: ";
    cin >> books[index][0];
    cout << "Please enter the author of the book: ";
    cin >> books[index][1];
    cout << "Please enter the year of the book: ";
    cin >> books[index][2];
    cout << "Please enter the price of the book: ";
    cin >> books[index][3];
}

bool authUser(string userName, string password) {
    int attempts = 3;

    for (int i = 0; i < 1; i++) {
        string inputUserName;
        string inputPassword;
        cout << "\nPlease enter your Username: ";
        cin >> inputUserName;
        cout << "Please enter your password: ";
        cin >> inputPassword;
        if (inputUserName != userName || inputPassword != password) {
            attempts--;
            if (attempts < 1) {
                cout << "Sorry! You are out of attempts :(\n";
                cout << "Please restart the program!";
                return false;
            }
            i--;
            cout << "Wrong Input! Please try again!";
            cout << "\nNumber of attempts left: " << attempts << "\n\n";
        }
    }
}

int main() {
    
    int currentUser;
    int currentStatus;

    cout << "\tWelcome to Shahir's Teams' library! :)\n\n";
    cout << "Press 1 if you are an admin, 2 if you are a user: ";
    cin >> currentUser;
    
    switch (currentUser) {
        case 1:
            int index;
            int currentAction;
            currentStatus = authUser(adminUser, adminPassword);
            if (!currentStatus) return 0;
            
            cout << "Hello Admin! We have " << length << " books.\n\n";
            cout << "What do you want to do?\n\n";
            cout << "1. For creating new entry.\n";
            cout << "2. For editing existing entries.\n";
            cout << "3. For showing all entries.\n";
            cin >> currentAction;
            
            switch (currentAction) {
                case 1:
                    editElement(length);
                    length++;
                    showAll();
                    break;
                
                case 2:
                    cout << "Of our " << length << " books, which one do you want to edit? ";
                    cin >> index;
                    
                    editElement(index - 1);
                    
                    cout << "Changes saved successfully! Thank you :)\n\n";
                    
                    showAll();
                    break;
                
                case 3:
                    showAll();
                    break;
            }
            break;
            
        case 2:
            currentStatus = authUser(user, password);
            if (!currentStatus) return 0;
            showAll();
            break;
    }

    return 0;
}
