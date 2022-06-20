// C++ program to illustrate
// unordered_set::insert()
 
#include <array>
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
 
int main()
{
    unordered_set<std::string> mySet = { "first",
                                "third", "second" };
    array<std::string, 2> myArray = { "tenth",
                                      "seventh" };
    string myString = "ninth";
 
    mySet.insert(myString);
 
    // array elements range insertion in set
    mySet.insert(myArray.begin(), myArray.end());
 
    // initializer list insertion
    mySet.insert({ "fourth", "sixth" });
    mySet.insert({ "fourth", "sixth" });
 
    cout << "myset contains:"
         << endl;
    for (const string& x : mySet) {
        cout << x
             << " ";
    }
    cout << endl;
 
    return 0;
}