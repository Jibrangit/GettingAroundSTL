// Section 20
// Challenge 1
// Identifying palindrome strings using a deque
#include <cctype>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

// Overloaded stream insertion operator << to print std::deque <char>
std::ostream & operator << (std::ostream &out, const std::deque<char> &deq) {
    for(int i{}; i < deq.size(); i++)
        out << deq.at(i);
    return out;
}

bool is_palindrome(const std::string& s)
{
    // You must implement this function.
    // Since we are learning the STL - use a deque to solve the problem.
    std::deque<char> pal;
    for(char c : s)
        if(std::isalpha(c))
        {
            pal.push_back(std::toupper(c));
             
        }
    
    char c1{}, c2{};
    while(pal.size() > 1) {
        c1 = pal.front();
        c2 = pal.back();
        pal.pop_front();
        pal.pop_back();
        if(c1 != c2)   
            return false;
    }
    return true;
}


int main()
{
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };

    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for(const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s)  << s << std::endl;
    }
    std::cout << std::endl;
    // is_palindrome(test_strings.at(0));
    return 0;
}