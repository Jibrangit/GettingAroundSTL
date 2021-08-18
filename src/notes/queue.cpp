#include <iostream>
#include <queue>
#include <list>
#include <deque>

int main(int argc, char const *argv[])
{
    // Initialization methods 
    // FIFO
    std::queue<int> q;
    std::queue<int, std::list<int>> q2;
    std::queue<int, std::deque<int>> q3;


    q.push(10);
    q.push(20);
    q.push(30);


    std::cout << q.front() << std::endl;
    std::cout << q.back() << std::endl;

    q.pop();

    std::cout << q.front() << std::endl;
    std::cout << q.back() << std::endl;

    std::cout << q.size() << std::endl;
    return 0;
}
