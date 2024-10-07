class Solution {
public:
    int AgnosticBS(arr, start, end, tg) {
        int n = arr.size();
        if(n == 1 && arr[0] == tg) {
            return 0;
        }
        if(n == 1 && arr[0] != tg) {
            return -1;
        }
        int start = 0, end = n-1;
        bool isAscending = arr[end] > arr[start];
        int mid;
        if(isAscending == true) {
            while(start <= end) {
                mid = start + (end - start) / 2;
                if(arr[mid] == tg) return mid;
                else if(arr[mid] > tg) end = mid - 1;
                else start = mid + 1;
            }
        } else if(isAscending == false) {
            while(start <= end) {
                mid = start + (end - start) / 2;
                if(arr[mid] == tg) return mid;
                else if(tg > arr[mid]) end = mid - 1;
                else start = mid + 1;
            }
        }
        return -1;
    }
};
