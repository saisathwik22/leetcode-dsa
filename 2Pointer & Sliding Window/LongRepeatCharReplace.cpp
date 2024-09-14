// Longest Repeating character substring after replacement of K characters in string with uppercase letters.
// input -> AABABBA, k = 1
// replace A between two B's with B
// resultant string -> AABBBBA -> longest substring BBBB -> ouput = 4(len)

// Better Approach
// optimising O(n*n) to O(n)
// Sc - O(26)
// 2 pointer & sliding window

int charReplacement(string s, int k) {
  int l=0, r=0, maxLen=0, maxFreq=0;
  unordered_map<char, int> hash;
  while(r < s.size()) {
    hash[s[r] - 'A']++;
    maxFreq = max(maxFreq, hash[s[j]-'A']);
    while((r-l+1) - maxFreq > k) {
      hash[s[l] - 'A']--;
      maxFreq = 0;
      for(int i=0; i<25; i++) {
        maxFreq = max(maxFreq, hash[i]);
      }
      l++;
    }
    if((r-l+1)-maxFreq <= k) maxLen = max(maxLen, r-l+1);
    r++;
  }
  return maxLen;
}


// Brute Force
// TC = O(n*n) SC = O(26)
// changes = len of substring - maxFreq --> no. of chars to be changed.

int charReplacement(string s, int k) {
  int maxLen = 0;
  int n = s.length();
  for(int i=0; i<n; i++ ){
    int maxFreq = 0;
    unordered_map<char, int> hash;
    for(int j=i; j<n; j++) {
      hash[s[j]]++;
      maxFreq = max(maxFreq, hash[s[j]]);
      int changes = (j-i+1)-maxFreq;
      if(changes <= k) {
        maxLen = max(maxLen, j-i+1);
      }
      else break;
    }
  }
  return maxLen;
}
