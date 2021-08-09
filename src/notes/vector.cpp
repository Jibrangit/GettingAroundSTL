#include <iostream>
#include <vector>
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

    /** Example# 1 
     * @brief: Using emplace_back to create an object simultaneously as it is about to be inserted into a vector
     * */
    std::vector<Person> persons;
    persons.emplace_back("Jibran", 24);
    std::cout << persons.at(0).get_name() << std::endl;





    /** Example# 2
     * @brief: Inserting an element in the middle
     * */
    std::vector<int> vec1 {1, 2, 3, 4, 5};
    std::vector<int> vec2 {10, 20, 30, 40, 50};

    auto it = std::find(vec1.begin(), vec1.end(), 3);
    vec1.insert(it, 10);
    std::cout << vec1.at(2) << std::endl;






    /** Example# 3
     * @brief: Inserting a bunch of elements in the middle
     * */

    it = std::find(vec1.begin(), vec1.end(), 4);
    vec1.insert(it, vec2.begin(), vec2.end());
    std::cout << vec1.at(6) << std::endl;







    return 0;
}
