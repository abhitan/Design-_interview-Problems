class Solution {
public:
    int w;
    int n;
    int m;

    vector<vector<int>>directions{{-1,0},{0,1},{1,0},{0,-1}};

    bool find(vector<vector<char>>& board,int i,int j,int ind, string word)
    {
        if(ind >= word.length())
        {
            return true;
        }

        if(i<0 || j<0 || i>=n || j>= m || board[i][j] != word[ind])
        {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '#';

        for(auto &dir:directions)
        {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if(find(board,new_i,new_j,ind+1,word) == true)
            return true;
        }
        
        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        w = word.length();
        n = board.size();
        m = board[0].size();

        if(n*m < w) return false;

        for(int i = 0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(board[i][j] == word[0])
                {
                    if(find(board,i,j,0,word))
                    return true;
                }
            }
        }
        return false;
    }
};