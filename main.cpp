// COMSC-210 | lab 27 | Kent Kawashima
// IDE used: Visual Studio Code
#include <iostream>
#include <map>
#include <vector>
#include <tuple> //for tuple
using namespace std;

struct myTuple
{
    tuple<int, string, string>data;
}; 

main()
{
    // map declaration
    map<string, myTuple> villagerColors; //each pair is comprised of a string name(key), struct containing tuple of int/string/string

    villagerColors["test"].data.insert({1,"a","a"}); 



/*
    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerColors["Audie"] = {"Orange", "Yellow", "Red"};
    villagerColors["Raymond"] = {"Black", "Gray", "White"};
    villagerColors.insert({"Marshal", {"Blue", "White", "Black"}});

    // access the map using a range-based for loop
    cout << "Villagers and their favorite colors (range-based for loop):" << endl;
    for (auto pair : villagerColors)
    {
        cout << pair.first << ": ";
        for (auto color : pair.second)
            cout << color << " ";
        cout << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, vector<string>>::iterator it = villagerColors.begin();
         it != villagerColors.end(); ++it)
    {
        cout << it->first << ": ";
        for (auto color : it->second)
        {
            cout << color << " ";
        }
        cout << endl;
    }

    // delete an element
    villagerColors.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerColors.find(searchKey);
    if (it != villagerColors.end())
    { // the iterator points to beyond the end of the map
      // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto color : it->second) // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    }
    else
        cout << endl
             << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerColors.size() << endl;
    villagerColors.clear();
    cout << "Size after clear: " << villagerColors.size() << endl;
*/

    return 0;
}