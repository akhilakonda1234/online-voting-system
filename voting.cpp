#include <iostream>
#include <fstream>
#include <set>
using namespace std;

int main()
{
    int choice;
    string name, password;

    int bjp = 0, congress = 0, aap = 0, tmc = 0, bsp = 0;

    set<string> votedUsers;

    // Load votes
    ifstream fin("votes.txt");
    if (fin.is_open())
    {
        fin >> bjp >> congress >> aap >> tmc >> bsp;
        fin.close();
    }

    // Load users
    ifstream fin2("users.txt");
    string user;
    while (fin2 >> user)
    {
        votedUsers.insert(user);
    }
    fin2.close();

    while (true)
    {
        cout << "\n\n";
        cout << "Enter name (or type exit): ";
        cin >> name;

        if (name == "exit")
            break;

        cout << "Password (admin123 for admin / 0 for user): ";
        cin >> password;

        bool isAdmin = (password == "admin123");

        if (isAdmin)
        {
            cout << "\n ADMIN PANEL\n";
            cout << "BJP: " << bjp << endl;
            cout << "Congress: " << congress << endl;
            cout << "AAP: " << aap << endl;
            cout << "TMC: " << tmc << endl;
            cout << "BSP: " << bsp << endl;
            continue;
        }

        if (votedUsers.count(name))
        {
            cout << " Already voted!\n";
            continue;
        }

        cout << "\n--- VOTING MENU ---\n";
        cout << "1. BJP\n";
        cout << "2. Congress\n";
        cout << "3. AAP\n";
        cout << "4. TMC\n";
        cout << "5. BSP\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) bjp++;
        else if (choice == 2) congress++;
        else if (choice == 3) aap++;
        else if (choice == 4) tmc++;
        else if (choice == 5) bsp++;
        else
        {
            cout << "Invalid vote!\n";
            continue;
        }

        votedUsers.insert(name);

        cout << " Vote recorded!\n";
    }

    // Save votes
    ofstream fout("votes.txt");
    fout << bjp << " " << congress << " " << aap << " " << tmc << " " << bsp;
    fout.close();

    // Save users
    ofstream fout2("users.txt");
    for (auto &u : votedUsers)
        fout2 << u << endl;

    fout2.close();

    cout << "\nSystem closed.\n";

    return 0;
}