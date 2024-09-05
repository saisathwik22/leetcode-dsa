
// arr[] -> {1,2,3,4,5}  k=2
// k=1 -> rotate by 1 place -> 2,3,4,5,1
// k=2 -> rotate again -> 3,4,5,1,2

vector<int> rotateArray(vector<int>arr, int k) {
    
    int n = arr.size();

    while(k!=0) {
      // single rotation code snippet wrapped under 'k' loop for k times.
        int temp = arr[0];
        for(int i=1; i<n; i++) {
            arr[i-1] = arr[i];
        }
        arr[n-1] = temp;
        k--;
    }
    return arr;
}
