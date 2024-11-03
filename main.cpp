// COMSC-210 | lab 27 | Kent Kawashima
// IDE used: Visual Studio Code
#include <iostream>
#include <map> //for map
#include <vector>
#include <tuple> //for std::tuple
using namespace std;

// prototypes
void addVillager(map<string, tuple<int, string, string>> &);
int printMenu();
void printVillagers(map<string, tuple<int, string, string>>);
void increaseFriendship(map<string, tuple<int, string, string>> &);
void decreaseFriendship(map<string, tuple<int, string, string>> &);

int main()
{
    // map declaration
    map<string, tuple<int, string, string>> vInfo; // each pair is comprised of a string name(key), struct containing tuple of int/string/string

    vInfo["Test"] = make_tuple(1, "a", "a"); // test

    do
    {
        switch (printMenu())
        {
        case(1):
            printVillagers(vInfo);
            break;

        case(2):
            printVillagers(vInfo);
            break;

        case(3):
            break;

        case(4):
            break;

        case(5):
            break;
        
        default:
            break;
        }
    }
    while(printMenu() != 6);

    return 0;
}

void addVillager(map<string, tuple<int, string, string>> &villagers)
{
    string n, s, c;
    int f;

    cout << "Villager Name: ";
    getline(cin, n); 

    cout << "Friendship Level: ";
    cin >> f;
    while (f < 1 || f > 10) //simple validation loop
    {
        cout << "ERROR: Friendship must be a number 1-10, try again: ";
        cin >> f;
    }

    cout << "Species: ";
    cin >> s;

    cin.ignore(); //clear for next getline
    cout << "Catchphrase: ";
    getline(cin,c);

    villagers[n] = {f,s,c}; //assign to tuple 
}

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
    cout << '\n'; //formatting
    return (c);
}

void printVillagers(map<string, tuple<int, string, string>> villagers)
{
    if (villagers.size() > 0)
    {
        cout << "Villager Details: \n";
        for (const auto &a : villagers) // for each villager
            cout << a.first << " [" << "Friendship Level: " << get<0>(a.second) << ", Species: " << get<1>(a.second) << ", Catchphrase: " << get<2>(a.second) << "]\n"; //access specific tuple elements
    }
    else
    {
        cout << "No Villagers yet, try adding some first!\n"; 
    }
    cout << '\n'; //formatting
}

void increaseFriendship(map<string, tuple<int, string, string>> &villagers)
{
    string buf;

    cin.ignore(); //clear for getline
    cout << "Enter name of villager to incrase friendship: ";   
    getline(cin,buf);

    auto search = villagers.find(buf); 
    if(search != villagers.end()) //if villager found in map
    {
        search->second
    }
}