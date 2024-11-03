// COMSC-210 | lab 27 | Kent Kawashima
// IDE used: Visual Studio Code
#include <iostream>
#include <map> //for map
#include <vector>
#include <tuple> //for std::tuple
using namespace std;

// function prototypes
void addVillager(map<string, tuple<int, string, string>> &);
int printMenu();
void printVillagers(const map<string, tuple<int, string, string>>);
void modifyVillager(map<string, tuple<int, string, string>> &, string); // multipurpose function

/************************************************
 * Function: Main
 ************************************************/
int main()
{
    bool again = true;
    map<string, tuple<int, string, string>> vInfo; // each pair is comprised of a string name(key), struct containing tuple of int/string/string

    do
    {
        switch (printMenu())
        {
        case (1):
            addVillager(vInfo);
            printVillagers(vInfo);
            break;

        case (2):
            modifyVillager(vInfo, "remove");
            printVillagers(vInfo);
            break;

        case (3):
            modifyVillager(vInfo, "increase");
            printVillagers(vInfo);
            break;

        case (4):
            modifyVillager(vInfo, "decrease");
            printVillagers(vInfo);
            break;

        case (5):
            modifyVillager(vInfo, "search");
            break;

        case (6):
            again = false;
            break;
        }
    } while (again);

    return 0;
}

/************************************************
 * Function: Prompt user for specific attributes
 * and later add a villager with these attributes
 * to the map
 *
 * Parameters: &villagers, the map that contains
 * all villagers, passed by reference as assignment
 * to the original map is occurring.
 ************************************************/
void addVillager(map<string, tuple<int, string, string>> &villagers)
{
    string n, s, c;
    int f;

    cout << "Villager Name: ";
    getline(cin, n);

    cout << "Friendship Level: ";
    cin >> f;
    while (f < 1 || f > 10) // simple validation loop
    {
        cout << "ERROR: Friendship must be a number 1-10, try again: ";
        cin >> f;
    }
    cin.ignore();

    cout << "Species: ";
    cin >> s;
    cin.ignore(); // clear for next getline

    cout << "Catchphrase: ";
    getline(cin, c);

    cout << '\n'; //formatting

    villagers[n] = {f, s, c}; // assign to tuple
}

/************************************************
 * Function: Print the menu for the menu-driven
 * program, allowing users to choose functions
 * to invoke on a map
 *
 * Return: c, (choice), integer corresponding to
 * user desires
 ************************************************/
int printMenu()
{
    int c;

    cout << "1. Add Villager\n2. Delete Villager\n3. Increase Friendship\n4. Decrease Friendship\n5. Search for Villager\n6. Exit\n\n";
    cout << "Choice: ";
    cin >> c;
    while (c < 1 || c > 6)
    {
        cout << "ERROR: Choice must be a number 1-6, try again: ";
        cin >> c;
    }
    cin.ignore(100, '\n'); // clear buffer of characters
    cout << '\n';          // formatting
    return (c);
}

/************************************************
 * Function: Print all Villagers in the map
 * formatted in a readable manner.
 *
 * Parameters: villagers, the map that contains
 * all villagers, passed by constant value to ensure
 * no changes are made to the original. Only needs
 * to reference values to print. 
 ************************************************/
void printVillagers(const map<string, tuple<int, string, string>> villagers)
{
    if (villagers.size() > 0)
    {
        cout << "Villager Details: \n";
        for (const auto &a : villagers)                                                                                                                                 // for each villager
            cout << a.first << " [" << "Friendship Level: " << get<0>(a.second) << ", Species: " << get<1>(a.second) << ", Catchphrase: " << get<2>(a.second) << "]\n"; // access specific tuple elements
    }
    else
    {
        cout << "No Villagers yet, try adding some first!\n";
    }
    cout << '\n'; // formatting
}

/************************************************
 * Function: Apply various changes to the villager
 * depending on the specified mode invoked by the
 * programmer (not user), user specifies based
 * on choice number in menu. 
 *
 * Parameters: 
 * &villagers, the map that contains
 * all villagers, passed by reference as assignment
 * to the original map is occurring.
 * mode, the string that determines what operation
 * is done on the villager (add/subtract/remove/find)
 ************************************************/
void modifyVillager(map<string, tuple<int, string, string>> &villagers, string mode)
{
    string buf;
    cout << "Enter name of villager: ";
    getline(cin, buf);

    auto search = villagers.find(buf);
    if (search != villagers.end()) // if villager found in map
    {
        if (mode == "increase") // increase friendship
        {
            if (get<0>(search->second) != 10) // if not about to make invalid
                get<0>(search->second)++;
            else
                cout << "Maximum friendship is level 10.\n";
        }

        else if (mode == "decrease") // decrease
        {
            if (get<0>(search->second) != 0) // if not about to make invalid
                get<0>(search->second)--;
            else
                cout << "Minimum friendship is level 0.\n";
        }

        else if (mode == "remove") // remove
            villagers.erase(buf);

        else if (mode == "search") // search
            cout << "Found " << buf << "'s attributes: [" << "Friendship Level: " << get<0>(search->second) << ", Species: " << get<1>(search->second) << ", Catchphrase: " << get<2>(search->second) << "]\n";
    }
    else
        cout << "ERROR, villager with name " << buf << " not found.\n";
}
