#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>

/** EXAMPLE#1 
 * @brief : Examples of iterator declarations 
 * */
std::vector<int>::iterator it1;
std::list<std::string>::iterator it2;
std::map<std::string, std::string>::iterator it3;
std::set<char>::iterator it4;


/** EXAMPLE#2 
 * @brief : Example of iterator definition 
 * */

std::vector<int> vec {1, 2, 3};

std::vector<int>::iterator it = vec.begin();
// OR
// auto it = vec.begin();


/** EXAMPLE#3 
 * @brief : Example of iterator usage 
 * */

while (it != vec.end()) {
    std::cout << *it << " ";
    ++ it;
}

/** EXAMPLE#4 
 * @brief : Reverse iterator
 * */

std::vector<int>::reverse_iterator itr = vec.begin();
//OR
// auto itr = vec.rbegin();


/** EXAMPLE#5 
 * @brief : Constant iterator
 * The elements they point to cant be changed. 
 * */

std::vector<int>::const_iterator cit = vec.begin();
//OR
// auto cit = vec.cbegin();

/** EXAMPLE#6 
 * @brief : Iterating over a map
 * The elements they point to cant be changed. 
 * */
std::map<std::string, std::string> favorites {
    {"Frank", "C++"},
    {"Bill", "Java"},
    {"James", "Haskell"}
};

auto itm = favorites.begin();
while(itm! = favorites.end()) {
    std::cout << itm.first() << ":" << itm.second() << std::endl;
    itm++;
}