#include <iostream>
#include <string>
using namespace std;

string adminUser = "ShahirKhaled";
string adminPassword = "Shahir123";

string user = "someone";
string password = "something";

void authUser(string userName, string password) {
    int attempts = 5;

    for (int i = 0; i < 1; i++) {
        string inputUserName;
        string inputPassword;
        cout << "Please enter your Username: ";
        cin >> inputUserName;
        cout << "Please enter your password: ";
        cin >> inputPassword;
        if (inputUserName != userName && inputPassword != password) {
            attempts--;
            if (attempts < 1) {
                cout << "Sorry! You are out of attempts :(";
                break;
            }
            i--;
            cout << "Wrong Input! Please try again!";
            cout << "\nNumber of attempts left: " << attempts << "\n\n";
        }
    }
}

int main() {
    int currentUser;

    cout << "\tWelcome to Shahir's Teams' library! :)\n";
    cout << "Press 1 if you are an admin, 2 if you are a user: ";
    cin >> currentUser;
    
    switch (currentUser) {
        case 1:
            authUser(adminUser, adminPassword);
            break;
            
        case 2:
            authUser(user, password);
            break;
    }

    return 0;
}
