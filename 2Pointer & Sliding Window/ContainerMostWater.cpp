// GGOGLE, Meta, Amazon ****
// input --> [1,8,6,2,5,4,8,3,7]
// bar graph drawn with input.
// output -> 49
// find 2 lines which together form a container with x-axis, such that container contains max water(max area)

int maxArea(vector<int>& height) {
  int n = height.size();
  int i = 0, j = n - 1;
  int maxWater = 0;
        
  while(i < j) {
    int width = j - i;
    int ht = min(height[i], height[j]);
    int area = width * ht;
    maxWater = max(maxWater, area);
    if(height[i] > height[j]) j--;
    else i++;
  }
  return maxWater;
}

/*
    Given array of heights, find max water container can store
    Ex. height = [1,8,6,2,5,4,8,3,7] -> 49, (8 - 1) x min(8, 7)

    2 pointers outside in, greedily iterate pointer w/ lower height

    Time: O(n)
    Space: O(1)
*/
// https://leetcode.com/problems/container-with-most-water/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        
        int curr = 0;
        int result = 0;
        
        while (i < j) {
            curr = (j - i) * min(height[i], height[j]);
            result = max(result, curr);
            
            if (height[i] <= height[j]) {
                i++;
            } else {
                j--;
            }
        }
        
        return result;
    }
};


// Refer to problem for diagram
