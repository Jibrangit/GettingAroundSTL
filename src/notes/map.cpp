#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <set>

int main(int argc, char const *argv[])
{
    std::map<std::string, std::string> m {  // Map consist of std::pair objects (key-value)
        {"Bob", "Butcher"},
        {"Anne", "Baker"},
        {"George", "Candlestick Maker"}
    };
    std::cout << m.size() << std::endl;




    std::pair<std::string, std::string> p1 {"James", "Mechanic"};
    m.insert(p1);
    m.insert(std::make_pair("Roger", "Ranger"));

    m["Frank"] = "Teacher";
    m.at("Frank") = "Professor"; 




    m.erase("Anne");        // Erase with key



    if(m.find("Bob") != m.end())
        std::cout << "Found Bob!" << std::endl;



    auto it = m.find("George");
    if(it != m.end())
        m.erase(it);



    int num = m.count("Bob"); // Same as set, this method is used to check if element is present or not



    m["Frank"] += 10;


    auto it2 = m.find("Frank");
    if(it2 != m.end())
        std::cout << "Found: " << it2->first << " : " << it2->second << std::endl;
    
    
    
    
    std::map<std::string, std::set<int>> grades {
        {"Larry", {100, 90}},
        {"Moe", {94}},
        {"Curly", {80, 90, 100}}
    }; 

    grades["Larry"].insert(95);
    
    // Just like sets, multi-maps allow storage of duplicates


    return 0;
}
