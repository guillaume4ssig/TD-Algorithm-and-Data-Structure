bool dfs(char** board, int m,int n,char* word,int index,int rows,int cols){
    if (word[index]=='\0') return true;
    if (m < 0 || m >= rows || n < 0 || n >= cols) return false;
    if (board[m][n] != word[index]) return false;

    char temp=board[m][n];
    board[m][n]='-';

    bool found =
        dfs(board, m+1, n, word, index+1, rows, cols) ||
        dfs(board, m-1, n, word, index+1, rows, cols) ||
        dfs(board, m, n+1, word, index+1, rows, cols) ||
        dfs(board, m, n-1, word, index+1, rows, cols);


    board[m][n] = temp;

    return found;

}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int m = boardSize ;
    int n = boardColSize[0] ;

    for (int i=0; i<=m; i++){
        for (int j=0;j<=n; j++){
            if (dfs(board,i,j,word,0,m,n)){return true;}
        }
    }
    return false ;
}