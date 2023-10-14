#include <iostream>
#include <string>
using namespace std;

string adminUser = "ShahirKhaled";
string adminPassword = "Shahir123";

bool authUser(string userName, string password) {
    string inputUserName;
    string inputPassword;
    cout << "Please enter your Username: ";
    cin >> userName;
    cout << "Please enter your password: ";
    cin >> password;
    bool x = inputUserName == userName;
    cout << x;
    if (inputUserName == userName && inputPassword == password) return true;
    else {
        cout << "Wrong Input! Please try again!";
        return false;
    }
}

struct user {
    string userName;
    string password;
};

int main() {
    int currentUser;
    
    cout << "\tWelcome to Shahir's Teams' library! :)\n";
    cout << "Press 1 if you are an admin, 2 if you are a user: ";
    cin >> currentUser;
    
    switch (currentUser) {
        case 1:
            cout << authUser(adminUser, adminPassword);
            break;
    }

    return 0;
}
