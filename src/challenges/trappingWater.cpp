#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height);
    void calculateArea(int heights []);

private:
    vector<int> heights;
    int area{};
};

int Solution::trap(vector<int>& height) 
{
    auto temp = max_element(height.begin(), height.end());
    auto maxIndex = temp;
    stack <vector<int>::iterator> left, right;

    left.push(temp);
    right.push(temp);
    // cout << *(left.top()) << " "; 
    while(temp != height.begin())
    {
        temp = max_element(height.begin(), temp);
        left.push(temp);
        // cout << *(left.top()) << " "; 
    }
    // cout << endl;
    // cout << *(right.top()) << " "; 

    temp = max_element(height.begin(), height.end());
    
    while((temp+1) != height.end())
    {
        temp = max_element(temp+1, height.end());
        right.push(temp);
        // cout << *(right.top()) << " "; 
    }

    int sum{};
    
    /** @ TODO: Now that I have the stacks, just have to add up areas. 
     * To do this, I must get all elements that come in between the elements that are pointed to by the iterators temp and top()
     * */

    temp = left.top();
    left.pop();
    while(!left.empty())
    {
        
        for(auto i=temp+1; i < left.top(); i++)
        {
            sum += (*i);
        }

        int height = *temp;
        int width = left.top() - temp - 1;

        area += (width * height) - sum;
        sum = 0;

        temp = left.top();
        left.pop(); 
    }

    temp = right.top();
    right.pop();
    while(!right.empty())
    {
        for(auto i=right.top()+1; i < temp; i++)
            sum += (*i);

        int height = *temp;

        int width = temp - right.top() - 1;

        area += (width * height) - sum;
        sum = 0;

        temp = right.top();
        right.pop();
    }
    return area;
}

int main(int argc, char const *argv[])
{
    vector<int> input {4,2,0,3,2,5};
    Solution sol;
    int area = sol.trap(input);
    cout << area << endl;

    return 0;
}
