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

// Refer to problem for diagram
