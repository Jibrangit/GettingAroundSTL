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
    std::string str = s;
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    std::deque<char> pal;
    std::deque<char> reverse_pal;
    // for(int i{}; i < str.size(); i++)
    // {
    //     if (str[i] < 'A' || str[i] > 'Z' &&
    //         str[i] < 'a' || str[i] > 'z')
    //     {  
    //         // erase function to erase
    //         // the character
    //         str.erase(i, 1);
    //         i--;
    //     }
    //     else {
    //         pal.emplace_back(str.at(i));
    //         reverse_pal.emplace_front(str.at(i));
            
    //     }
    // }

    for(char c : str)
        if(std::isalpha(c))
        {
            pal.emplace_back(c);
            reverse_pal.emplace_front(c);
             
        }
    // std::cout << pal << std::endl;
    // std::cout << reverse_pal;

    return (pal == reverse_pal);
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