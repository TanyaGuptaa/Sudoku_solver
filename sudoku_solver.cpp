#include<bits\stdc++.h>
using namespace std;

//print sudoku board
//void board[][]{



//}


bool isSafe(int row,int col,vector<vector<int>> & board,int val){
    for(int i=0;i<board.size();i++){
        //horizontal row check
        if(board[row][i]==val)
        return false;
        // vertical column check
        if(board[i][col]==val)
        return false;
        //sub box check
        int s=sqrt(board.size());
        //starting value of subbox
        int startrow=i-i%s;
        int startcol=row-row%s;

         for(int r=startrow;r<startrow+s;r++){
             for(int c=startcol;c<startcol+s;c++){
                 if(board[r][c]==val)
                 return false;
             }
         }
        
    }return true;
}




bool solve(vector<vector<int>> & board){
     int n=board.size();
     
     int row;int col;
     for(row=0;row<n;row++){
         for( col=0;col<n;col++){
             //cell empty
             if(board[row][col]==0){
                 //fill values
                 return true;
                 }else return false;
                 if(row==n && col==n)return true;
                 for(int val=1;val<=n;val++){
                 //check if clashing or not
                 if(isSafe(row,col,board,val)){
                     board[row][col]==val;
                     //recursive call for next cells
                     if(solve(board))
                     return true;
                 
                     //backtrack
                     board[row][col]==0;
                 }
             }
            
         return false;}
    
  /*  for(int row=0;row<board.size();row++){
        for(int col=0;col<board.size();col++){
            if(col==3||col==6)cout<<" | ";
            cout<<board[row][col]<<" ";

        }if (row==2||row==5)cout<<endl;
        for(int i=0;i<board.size();i++)cout<<"- - -";
    }cout<<endl;

     return true;*/


//print sudoku grid after solving
void print(vector<vector<int>>&board)
{
    for(int row=0;row<board.size();row++){
        for(int col=0;col<board.size();col++){
            if(col==3 || col==6)
            cout<<" | ";
            cout<<board[row][col]<<" ";

        }if (row==2 || row==5){
        cout<<endl;
        for(int i=0;i<board.size();i++)
        cout<<"---";
    }cout<<endl;
    }cout<<endl;}

int main(){
    
    vector<vector<int>> sudoku{
    {3,0,6,5,0,8,4,0,0},
    {5,2,0,0,0,0,0,0,0},
    {0,8,7,0,0,0,0,3,1},
    {0,0,3,0,1,0,0,8,0},
    {9,0,0,8,6,3,0,0,5},
    {0,5,0,0,9,0,6,0,0},
    {1,3,0,0,0,0,2,5,0},
    {0,0,0,0,0,0,0,7,4},
    {0,0,5,2,0,6,3,0,0}  };
    print(sudoku);
    solve(sudoku);
    cout<<" SOLVING "<<endl;
    print(sudoku);
    cout<<" SOLVED "<<endl;
    return 0;
}