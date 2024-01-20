class Solution {
public:

   bool static cmp(pair<char,vector<int>>&A,pair<char,vector<int>>&B)
   {
       return (A.second > B.second) || (A.second == B.second && A.first < B.first);
   }




    string rankTeams(vector<string>& votes) {
        int numTeams = votes[0].size();

        map<char,vector<int>>positions;
        for(auto &vote:votes)
        {
            for(int i = 0;i<numTeams;i++)
            {
                char team = vote[i];
                positions[team].resize(numTeams,0);
                positions[team][i]++;
            }
        }

        vector<pair<char,vector<int>>>teams(positions.begin(),positions.end());
        sort(teams.begin(),teams.end(),cmp);

        string res = "";
        for(auto &team:teams)
        {
            res += team.first;
        }
        return res;
    }
};