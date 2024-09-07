// Two strings s and t given
// check if they are anagrams or not
// Anagram - two strings are anagrams if the characters are same irrespective of the order they are placed.
// input - s = "car" t = "rat" output - false

// My solution - APPROACH 1
bool isAnagram(string s, string t) {
  int x = s.length(), y = t.length();
  if(x != y) return false;
  // two vectors to hash both strings characters.
  vector<int> hashS(26, 0);
  vector<int> hashT(26, 0);
  for(int i=0; i<x; i++) {
    hashS[s[i] - 'a']++;
    hashT[t[i] - 'a']++;
  }
  // comparing both hash vectors
  for(int i=0; i<26; i++) {
    if(hashS[i] != hashT[i]) return false;
  }
  return true;
}
// Usage of UNORDERED Maps - 
unordered_map<char, int> mapS;
unordered_map<char, int> mapT;

for(i=0 --> string length){
  mapS[s[i]]++, mapT[t[i]]++;
}
rest all same, compare both the hash maps upto mapS.size();
Time complexity && Space complexity --> O(mapS.size + mapT.size)

// Approach 2 - optimization for space complexity

sort the the two strings using sort();
compare the strings using for loop, if even a single mismatch --> false;
if iteration completed --> true;

TimeComplexity --> O(nLogn) + O(n);
Space Complexity --> O(1)
SC optimized....
