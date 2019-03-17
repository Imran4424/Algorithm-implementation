#include <bits/stdc++.h>
using namespace std; 
#define N 8

void printBoard(int chessboard[][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<chessboard[i][j]<<" ";
        }
        cout<<endl;
    }
}

// Checks if a queen can be placed at chessboard[row][col]
bool isValidMove(int chessboard[][N], int col, int row){
    
    // If there is a queen in the same row, we can't place our queen at CB[row][col]
    for(int i=0;i<col;i++){
        if(chessboard[row][i] == 1){
            return false;
        }
    }
    
    // No need to check for the same column since we have ensure that 
    // only one queen will be placed in one column. So, no column can contain two queens.
    // for(int i=0;i<row;++i){
    //     if(chessboard[i][col] == 1){
    //         cout<<"Case 2: False"<<endl;
    //         return false;
    //     }
    // }
    
    // If there is a queen in the upper diagonal, we can't place our queen at CB[row][col]
    for(int j=col-1,i=row-1;i>=0,j>=0;i--,j--){
        if(chessboard[i][j] == 1){
            return false;
        }
    }
    
    // If there is a queen in the lower diagonal, we can't place our queen at CB[row][col]
    for(int j=col-1,i=row+1;j>=0,i<N;j--,i++){
        if(chessboard[i][j] == 1){
            return false;
        }
    }

    // If it passed all the conditions, we can place a queen here.
    return true;
}

bool solveNQueen(int chessboard[][N], int col){
    
    // If we reached col=N, then we have placed N queens on the board. Cheers!
    if(col==N){
        return true;
    }
    
    // Consider this column(col) and try placing this queen in all rows one by one 
    for(int i=0;i<N;i++){
        
        //Check if a queen can be placed at chessboard[i][col]
        if(chessboard[i][col]==0 && isValidMove(chessboard,col,i)){
            
            // Yes, we can place
            chessboard[i][col] = 1;
            
            // recur to place rest of the queens.
            if (solveNQueen(chessboard, col+1)){
                return true;
            }
            
            // If placing queen in board[i][col] doesn't lead to a solution, 
            // then remove queen from board[i][col]
            chessboard[i][col] = 0;
        }
    }
    
    // If the queen cannot be placed in any row in this colum col then return false 
    return false;
}

int main() 
{
    int chessboard[N][N];
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            chessboard[i][j] = 0;
        }
    }
    
    if(solveNQueen(chessboard, 0)){
        printBoard(chessboard);
    }
    else{
        cout<<"Can't be solved!"<<endl;
    }

    return 0; 
} 