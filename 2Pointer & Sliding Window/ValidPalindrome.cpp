// input -> string given
// remove all the non-alphanumeric characters from string, convert to lowercase and check its palindrome or not
// input -> string str = "race : car"
// remove even whitespaces
// after removing -> str = "racecar" --> palindrome
// ouput --> true

bool isPalindrome(string& str) {
  int i = 0;
  int j = str.size()-1;
  while(i<j) {
    while(!isalnum(s[i]) && i<j ) i++;
    while(!isalnum(s[j]) && i<j) j--;

    if(tolower(s[i]) != tolower(s[j])) return false;
    i++;
    j--;
  }
  return true;
}
// TC O(n), Sc O(1)
// isalnum() is C++ function in <cctype> header file.
// isalnum(x) --> returns true if x is a character which is alpha-numeric.
// !isalnum(x) --> returns true if x is a non alpha-numeric character and increments the pointer away from it.
// !isalnum(s[i]) --> i++, increments i pointer is s[i] is a non alphanumeric character.
