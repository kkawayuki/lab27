// COMSC-210 | lab 27 | Kent Kawashima
// IDE used: Visual Studio Code
#include <iostream>
#include <map> //for map
#include <vector>
#include <tuple> //for std::tuple
using namespace std;

// prototypes
void addVillager();
int printMenu();
void printVillager( map<string, tuple<int, string, string>>);

    int main()
{
    // map declaration
    map<string, tuple<int, string, string>> vInfo; // each pair is comprised of a string name(key), struct containing tuple of int/string/string

    vInfo["Test"] = make_tuple(1, "a", "a"); // test


    printMenu();


    return 0;
}

void addVillager()
{
}

int printMenu()
{
    int c;
    cout << "1. Add Villager\n2. Delete Villager\n3. Increase Friendship\n4. Decrease Friendship\n5. Search for Villager\n6. Exit\n\n"; 
    cout << "Choice: ";
    cin >> c;
    while(c < 1 || c > 6)
    {
        cout << "ERROR: Choice must be a number 1-6, try again: ";
        cin >> c;
    }
    return(c); 
}

void printVillager(map<string, tuple<int, string, string>>villagers)
{
    for(const auto &a : villagers) //for each villager
    {
        cout << villagers.
    }
}