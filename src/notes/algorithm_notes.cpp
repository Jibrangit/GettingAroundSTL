#include <iostream>
#include <algorithm>
#include <vector>

// Functor
struct Square_Functor {  // Can be implemented as a class as well
    void operator() (int x) {
        std::cout << x*x << " ";
    }
};

// Function pointer
void square_fn(int x) {
    std::cout << x*x << " ";
}

int main(int argc, char const *argv[])
{

    /** EXAMPLE#1 
    * @brief : FInding the first occurence of an element 
    * */
    std::vector<int> vec {1, 2, 3, 4};
    auto loc = std::find(vec.begin(), vec.end(), 3);

    if(loc != vec.end())    //found it!
        std::cout << *loc << std::endl;





    /** EXAMPLE# 2 
    * @brief : Example of a functor, specifically, for_each
    * */
    Square_Functor square;

    std::for_each(vec.begin(), vec.end(), square);





    /** EXAMPLE# 3
    * @brief : Example of a function pointer to do the same thing as #2
    * */
    std::for_each(vec.begin(), vec.end(), square_fn);






    /** EXAMPLE# 4
    * @brief : Example of a lambda expression to do the same thing as #2
    * */
    std::for_each(vec.begin(), vec.end(),
    [](int x) { std::cout << x*x << " "; });






    /** EXAMPLE#5
    * @brief : FInding the number of occurences of an element 
    * */
   int num = std::count(vec.begin(), vec.end(), 1);
   std::cout << std::endl << num << " occurences found!" << std::endl;
    


    
    
    
    /** EXAMPLE#6
    * @brief : Count the number of occurences of an element in a container 
    *          based on a predicate using a lambda expression. 
    * */
   int num_if = std::count_if(vec.begin(), vec.end(), [](int x) {return x%2 == 0; });
   std::cout << std::endl << num_if << " even numbers found!" << std::endl; 





    /** EXAMPLE#7
    * @brief : Replace occurences of an element in a container 
    * */
   std::replace(vec.begin(), vec.end(), 1, 100);
   for(auto i:vec) {
       std::cout << i << " ";
   }
   std::cout << std::endl;







    /** EXAMPLE# 8
    * @brief : Check if all elements in the container meet a certain condition
    * */
    if(std::all_of(vec.begin(), vec.end(), [](int x) { return x < 200; }))
        std::cout << "All the elements are < 200" << std::endl;
    








    /** EXAMPLE# 9
    * @brief : Transform elements in a container
    * */
    std::string str1 {"This is a test"};
    std::cout << "Before transform : " << str1 << std::endl;
    std::transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    std::cout << "After transform: " << str1 << std::endl;








    return 0;
}

