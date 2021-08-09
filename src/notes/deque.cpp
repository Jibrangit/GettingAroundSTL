#include <iostream>
#include <deque>
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
    /** Example#1 
     * @brief : Some additional methods that deques offer compared to vectors
     * */
    std::deque<int> d {1, 2, 3, 4, 5};
    Person p1 ("Larry", 18);
    std::deque<Person> p;

    std::cout << d.front() << std::endl;
    d.pop_front();
    std::cout << d.front() << std::endl;

    p.push_back(p1);    // Not really a new method
    std::cout << p.at(0).get_name() << std::endl;

    p.emplace_front("Jibran", 24);
    std::cout << p.at(0).get_name() << std::endl;

    return 0;
}
