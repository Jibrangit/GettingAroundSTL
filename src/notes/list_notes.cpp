#include <iostream>
#include <list>
#include <algorithm>
#include <forward_list>


int main(int argc, char const *argv[])
{
    // List initializations
    std::list<int> l {1, 2, 3, 4, 5};
    std::list<int> ll (10, 100); // ten 100s
    std::list<std::string> stooges {
        std::string{"Larry"},
        "Moe",
        std::string{"Curly"}
    };
    // NOTE : Lists do not allow direct element access
    // We will have to access the elements using iterators by finding the itertor to the element we are looking for

    //List method(s)
    l.resize(2);







    //Forward list
    /** @brief : Forward list (singly linked list)
     * Less overhead than list
     * No concept of back, only front
     * No reverse iterators either
     * Can only traverse in one direction
     * No size() available
     * */

    std::forward_list<int> fl {1, 2, 3, 4, 5};
    auto it = std::find(fl.begin(), fl.end(), 3);

    fl.insert_after(it, 10);
    fl.emplace_after(it, 100);
    fl.erase_after(it);

    std::advance(it, -4);  // Shifts the iterator










    return 0;
}
