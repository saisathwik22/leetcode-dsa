// LEETCODE Premium Problem:

// Design an algo to encode list of strings to a string.
// the encoded string then sent over network and decoded back to original list of strings
// implement encode and decode.
// input -> ["neet", "code"]
// output -> ["neet", "code"]

// encode the given string to unreadable sequence by adding some special chars, implement a function to be able to decode it back to its original form.

string encode(vector<string>& strs) {
  string result = "";

  for(int i=0; i<strs.size(); i++) {
    string str = strs[i];
    result += to_String(str.size()) + "#" + str;
  }
  return result;
}

vector<string> decode(string s){
  vector<string> result;
  int i = 0;
  while(i < s.size()) {
    int j = i;
    while(s[j] != '#') {
      j++;
    }
    int length = stoi(s.substr(i, j - i));
    string str = s.substr(j + 1, length);
    result.push_back(str);
    i = j + 1 + length;
  }
  return result;
}
