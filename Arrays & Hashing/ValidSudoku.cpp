// Rules:
//1-9 digits without repitition in a row, col, 3x3 subbox.

// Brute Force

bool validBox(vector<vector<char>> board, int rowStart, int rowEnd, int colStart, int colEnd){
  unordered_set<char> st;
  for(int i=rowStart; i<=rowEnd; i++) {
    for(int j=colStart; j<=colEnd; j++){
      if(board[i][j] == ".") continue;
      if(st.find(board[i][j]) != st.end()) return false;
      st.insert(board[i][j]);
    }
  }
  return true;
}
bool isValidSudoku(vector<vector<char>> board) {
  // row validation
  for(int row = 0; row<9; row++) {
    unordered_set<char> st;
    for(int col=0; col<9; col++) {
      if(board[row][col] == ".") continue;
      if(st.find(board[row][col]) != st.end()) return false;
      st.insert(board[row][col]);
    }
  }
  // col validation
  for(int col=0; col<9; col++) {
    unordered_set<char> st;
    for(int row=0; row<9; row++) {
      if(board[row][col] == ".") continue;
      if(st.find(board[row][col]) != st.end()) return false;
      st.insert(board[row][col]);
    }
  }
  // 3x3 subBox validation
  for(int rowStart=0; rowStart<9; rowStart+=3) {
    rowEnd = rowStart+2;
    for(int colStart=0; colStart<9; colStart+=3){
      colEnd = colStart+2;
      if(!validBox(board, rowStart, rowEnd, colStart, colEnd)) return false;
    }
  }
  return true;
}

//********* Better ***************************************************************//
// Among the 9 3x3 subBoxes, for any cell (i,j) when you do i/3 and j/3 --> (i/3, j/3) will be same for all the cells in that 3x3 subBox
// for example you visit cell cell[0][0] = 8, you cant have value 8 in any other cell where i=0 or j=0;
// for a cell (i,j) if you have value "x", then you cant have value "x" for any cell where either i is same  or j is same.

bool isValidSudoku(vector<vector<char>> board) {
  unordered_set<string> st;
  for(int i=0; i<9; i++){
    for(int j=0; j<9; j++){
      if(board[i][j] == ".") continue;
      string row = string(1, board[i][j]) + "_ROW_" + to_string(i);
      string col = string(1, board[i][j]) + "_COL_" + to_string(j);
      string box = string(1, board[i][j]) + "_BOX_" + to_string(i/3) + "_" + to_string(j/3);
      if(st.find(row) != st.end() || st.find(col) != st.end() || st.find(box)) return false;
      st.insert(row);
      st.insert(col);
      st.insert(box);
    }
  }
  return true;
}
