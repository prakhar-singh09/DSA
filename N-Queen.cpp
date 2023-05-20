class Solution {
public:
     bool isSafe(int n,int row,int col,vector<string>&mat){
        for(int i=0;i<n;i++){

          //checking if in same columns
          if(mat[i][col]=='Q')
              return false;         
          
          //checking only in upper diagonals
          if(row>=i && col>=i && mat[row-i][col-i]=='Q')
          return false;
          if(row>=i && col+i>=0 && mat[row-i][col+i]=='Q')
          return false;
   }
   return true;
}
    void solve(int row,int n,vector<string>&mat, vector<vector<string>>&ans)
    {
        //base case
    if(row == n){
    ans.push_back(mat);
    return;
    }

      for(int col = 0;col<n;col++){
           if(isSafe(n,row,col,mat))
           {
               mat[row][col] = 'Q';
               solve(row+1,n,mat,ans);    
               mat[row][col] = '.';             //backtracking
           }
      }
    }
    vector<vector<string>> solveNQueens(int n) {
     vector<vector<string>>ans;
    vector<string>mat(n,string(n,'.'));
    solve(0,n,mat,ans);
    return ans;
    }
};
