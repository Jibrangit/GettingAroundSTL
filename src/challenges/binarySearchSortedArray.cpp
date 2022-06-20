#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {

        // Creating a vector of indices
        int size = nums.size(); vector<int> indices(size, 0); int i=0; for_each(indices.begin(), indices.end(), [&i](int &ind) {ind=i; i++;});

        while(indices.size() > 1)
        {
            if(target == nums.at(indices.at((size-1))/2))
                return (nums.at(indices.at((size-1))/2));
            
            else 
            {
                
            }

        }
    
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    Solution sol;
    int index = sol.search(nums, target);

    // cout << "The index is : " << index << endl;
    return 0;
}
