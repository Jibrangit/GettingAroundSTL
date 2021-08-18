#include <iostream>
#include <stack>
#include <algorithm>
#include <deque>
#include <vector>
#include <list>


int main(int argc, char const *argv[])
{
    // Initialization methods for this container adaptor
    // LIFO
    std::stack<int> s;
    std::stack<int, std::vector<int>> s1;
    std::stack<int, std::list<int>> s2;
    std::stack<int, std::deque<int>> s3;



    // Push
    s.push(10);
    s.push(20);
    s.push(30);
    std::cout << s.top() << std::endl;

    s.pop();
    std::cout << s.top() << std::endl;

    s.top() = 100;
    std::cout << s.top() << std::endl;


    return 0;
}
