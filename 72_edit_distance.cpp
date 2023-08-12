class Solution {
public:
    int minDistance(string word1, string word2) {
        
        string s1="@"+word1;
        string s2="#"+word2;
        int n1=s1.size();
        int n2=s2.size();
        vector<vector<int>> dp(n1,vector<int>(n2,0));
        for(int i=0;i<n1;i++) dp[i][0]=i;
        for(int i=0;i<n2;i++) dp[0][i]=i;

        for(int i=1;i<n1;i++){
            for(int j=1;j<n2;j++){
                dp[i][j]=1e5;
                if(s1[i]==s2[j]){
                    dp[i][j]=min({dp[i-1][j-1],dp[i][j]});
                }
                else{
                   
                    dp[i][j]=min({dp[i][j],1+dp[i-1][j-1],1+dp[i-1][j],1+dp[i][j-1]});

                }
            }
        }
        // for(int i=0;i<n1;i++){
        //     for(int j=0;j<n2;j++){
        //          cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[n1-1][n2-1];
    }
};
