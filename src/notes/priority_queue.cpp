#include <iostream>
#include <queue>

int main(int argc, char const *argv[])
{
    /** @brief : Priority queue stores the elements in a sorted order with the largest at the top.
     * To use them with your own custom objects, overload the < operator
     * */
    std::priority_queue<int> pq;

    pq.push(10);
    pq.push(20);
    pq.push(3);
    pq.push(4);

    std::cout << pq.top() << std::endl;

    pq.pop();
    pq.top();

    std::cout << pq.top() << std::endl;

    return 0;
}
