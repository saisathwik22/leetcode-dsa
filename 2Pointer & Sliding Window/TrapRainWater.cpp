// array given --> apt heights;
// apt standing --> how much water trapped between them?
// arr=[4,0,6]
// three apts of ht 4, 0, 6 standing, rain water stores till 4 that is min of both 4,6
// output --> 4;

vector<int> getLeftMax(vector<int>& ht, int& n){
  vector<int> leftMax(n);
  leftMax[0] = ht[0];
  for(int i=0; i<n; i++) {
    leftMax[i] = max(leftMax[i-1], ht[i]);
  }
  return leftMax;
}
vector<int> getRightMax(vector<int>& ht, int& n) {
  vector<int> rightMax(n);
  rightMax[n-1] = ht[n-1];
  for(int i=n-2; i>=0; i--) {
    rightMax[i] = max(rightMax[i+1], ht[i]);
  }
  return rightMax;
}
int trap(vector<int>& ht){
  int n=ht.size();
  vector<int> leftMax = getLeftMax(ht, n);
  vector<int> rightMax = getRightMax(ht, n);
  int sum = 0;
  for(int i=0; i<n; i++ ){
    int h = min(leftMax[i], rightMax[i]) - ht[i];
    sum += h;
  }
  return sum;
}
