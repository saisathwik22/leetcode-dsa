
// sort the array and point to the element which is not equal to largest from last.

int findSecondLargest(int n, vector<int> &arr)
{
    // Write your code here.
    sort(arr.begin(), arr.end());

    for(int i = n-1; i>0; i--) {
        if(arr[i] != arr[i-1]) {
            return arr[i-1];
        }
    }
    return -1;
    
}
