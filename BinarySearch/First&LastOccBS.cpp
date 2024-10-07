class Solution {
public:
    int firstOcc(arr, ele) {
        low = 0, high = size - 1, res = -1;
        while(low <= high) {
            mid = low + (high - low) / 2;
            if(arr[mid] == ele) {
                res = mid;
                high = mid - 1;
            } else if(arr[mid] < ele) low = mid + 1;
            else if(arr[mid] > ele) high = mid - 1;
        }
        return res;
    }
    int lastOcc(arr, ele) {
        low = 0, high = size - 1, res = -1;
        while(low <= high) {
            mid = low + (high - low) / 2;
            if(arr[mid] == ele) {
                res = mid;
                start = mid + 1;
            } else if(arr[mid] < ele) low = mid + 1;
            else if(arr[mid] > ele) high = mid - 1;
        }
        return res;
    }
};
