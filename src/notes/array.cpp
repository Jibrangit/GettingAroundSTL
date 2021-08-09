#include <iostream>
#include <array>


int main(int argc, char const *argv[])
{
    /** EXAMPLE# 1
    * @brief : Array initialization
    * */
   std::array<std::string, 3> stooges {
       std::string("Larry"),
       "Moe",
       std::string("Curly")
   };




    /** EXAMPLE# 2
    * @brief : Array methods
    * */
    std::cout << stooges.size() << std::endl;
    std::cout << stooges[1] << std::endl;
    std::cout << stooges.front() << std::endl;
    std::cout << stooges.back() << std::endl;
    std::cout << stooges.empty() << std::endl;
    std::cout << stooges.max_size() << std::endl;

    std::string *data = stooges.data();
    std::cout << data << std::endl;
    return 0;
}

