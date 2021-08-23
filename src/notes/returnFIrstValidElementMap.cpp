#include <iostream>
#include <map>
#include <algorithm>

/** @brief: Checking out how to retrieve a random element, in this case the first elemnent as it is an ordered map, that satisfies a given condition)
 * */

int main(int argc, char const *argv[])
{
    std::map<char, bool> visited;
    visited.insert(std::make_pair('A', true));
    visited.insert(std::make_pair('B', true));
    visited.insert(std::make_pair('C', false));
    visited.insert(std::make_pair('D', true));
    visited.insert(std::make_pair('E', true));

    auto it = visited.begin();
    std::cout << it->first << std::endl;
    while(it->second)
    {
        std::advance(it, 1);
        std::cout << it->first << std::endl;

    }

    return 0;
}

