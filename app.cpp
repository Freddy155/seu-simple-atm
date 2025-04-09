#include <iostream>
#include <string> // Added string header
using namespace std;

int main() {
    string username = "", pin = "";
    double balance = 0;
    bool loggedIn = false;

    while(true) {
        cout << "\n=== ATM SIMPLE ===\n";
        if(!loggedIn) {
            cout << "1. Register\n2. Login\n3. Exit\nChoose: ";
            int choice;
            cin >> choice;
            cin.ignore(); // Clear the newline character after cin >>

            if(choice == 1) {
                cout << "Create username: ";
                getline(cin, username);

                while(true) {
                    cout << "Create 4-digit PIN: ";
                    getline(cin, pin);
                    if(pin.length() == 4 && pin.find_first_not_of("0123456789") == string::npos) {
                        break;
                    }
                    cout << "Invalid PIN! Use 4 numbers.\n";
                }
                cout << "Account created!\n";

            } else if(choice == 2) {
                string inputUser, inputPin;
                cout << "Username: ";
                getline(cin, inputUser);
                cout << "PIN: ";
                getline(cin, inputPin);

                if(inputUser == username && inputPin == pin) {
                    loggedIn = true;
                    cout << "Login success!\n";
                } else {
                    cout << "Wrong login!\n";
                }

            } else if(choice == 3) {
                break;
            } else {
                cout << "Invalid choice!\n";
            }

        } else { // Logged in menu
            cout << "\n1. Deposit\n2. Withdraw\n3. Check Balance\n4. Logout\nChoose: ";
            int choice;
            cin >> choice;
            cin.ignore(); // Clear the newline character after cin >>

            if(choice == 1) {
                double amount;
                cout << "Enter amount to deposit: $";
                cin >> amount;
                cin.ignore(); // Clear the newline character after cin >>
                if(amount > 0) {
                    balance += amount;
                    cout << "Deposit done!\n";
                } else {
                    cout << "Invalid amount!\n";
                }

            } else if(choice == 2) {
                double amount;
                cout << "Enter amount to withdraw: $";
                cin >> amount;
                cin.ignore(); // Clear the newline character after cin >>
                if(amount > balance) {
                    cout << "Not enough money!\n";
                } else if(amount > 0) {
                    balance -= amount;
                    cout << "Withdrawal done!\n";
                } else {
                    cout << "Invalid amount!\n";
                }

            } else if(choice == 3) {
                cout << "Your balance: $" << balance << "\n";

            } else if(choice == 4) {
                loggedIn = false;
                cout << "Logged out!\n";

            } else {
                cout << "Invalid choice!\n";
            }
        }
    }

    cout << "Goodbye!";
    return 0;
}
