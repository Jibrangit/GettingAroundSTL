#include <iostream>
#include <set>
#include <algorithm>

class Person {
public:
    Person(std::string name, int age) : name_(name), age_(age) {}
    std::string get_name() { return name_; }
private:
    std::string name_;
    int age_;
};

int main(int argc, char const *argv[])
{
    std::set<int> s {4, 1, 1, 3, 3, 2, 5};
    std::cout << s.size() << std::endl;


    Person p1 {"Jibran", 24};
    Person p2 {"Amal", 22};
    std::set<Person> stooges;
    stooges.insert(p1);


    auto result = stooges.insert(p2); // Returns a std::pair<iterator, bool>
    return 0;
}
