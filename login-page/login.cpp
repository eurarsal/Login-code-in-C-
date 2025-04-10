#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void registerUser()
{
    string username, password;

    cout << "\nEnter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    ofstream file("users.txt", ios::app); // Append mode

    if(file.is_open()){ 
        
        file << username << " " << password << endl;
        file.close();
        cout << " Registration successful!\n ";
        
    }
    else
    {
        cout << "Error: Unable to open file!\n";
        return;
    }


}

bool loginUser()
{
    string username, password, storedUser, storedPass;

    cout << "\nEnter your login ID: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    
    
   
        ifstream file("users.txt");
        
        bool loginSuccess = false;
    
        if (!file.is_open()) {
            cout << "File open nahi ho rahi bhai.\n";
            return 1;
        }
    
    
    
        while (file >> storedUser >> storedPass) {
           // cout << "Checking: " << storedUser << " " << storedPass << endl;  // Debug line
            if (username == storedUser && password == storedPass) {
                loginSuccess = true;
                break;
            }
        }
    
        if (loginSuccess) {
            cout << "Login successful!\n";
        } else {
            cout << "Username ya password galat hai.\n";
        }
    
        return 0;
    }
    



int main()
{
    int choice;
    while (true)
    {
        cout << "\n1. Register\n2. Login\n3. Exit\nChoose an option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            registerUser();
            break;
        case 2:
            if (loginUser())
            {
                cout << " Welcome to the system!\n";
            }
            break;
        case 3:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << " Invalid choice! Try again.\n";
        }
    }
}
