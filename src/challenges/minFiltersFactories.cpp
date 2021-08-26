#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

int minFilters(std::vector<int> &v)
{
    std::sort(v.begin(), v.end());                              // Sort the array
    int current_sum = std::accumulate(v.begin(), v.end(), 0);   // Calculate sum of pollutions
    int initial_sum = current_sum;

    v.back() /= 2;                                              // Cut the last element(largest) by half
    int num_filters = 1;                                        // Since one 'halving' waas done, 1 filter was used.
    current_sum = std::accumulate(v.begin(), v.end(), 0);

    while(current_sum > (initial_sum/2)) {
        std::sort(v.begin(), v.end());                          
        v.back() /= 2;  
        ++num_filters;                                          // Increment number of filter
        current_sum = std::accumulate(v.begin(), v.end(), 0);
    }

    return num_filters;
}


int main(int argc, char const *argv[])
{
    // std::vector<int> factories {5, 19, 8, 1};
    // std::vector<int> factories {10, 10};
    std::vector<int> factories {3, 0, 5};
    int res = minFilters(factories);
    std::cout << "Num of filters = " << res << std::endl;
    return 0;
}
