class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        string x1="@"+s1;
        string x2="#"+s2;
        int y1=x1.size();
        int y2=x2.size();
        vector<vector<int>> dp(y1,vector<int>(y2,0));
        vector<vector<char>> dp2(y1,vector<char>(y2,'N'));
        string x3="";
        for(int i=1;i<y1;i++){
            for(int j=1;j<y2;j++){
                if(x1[i]==x2[j]){
                    char z=x1[i];
                    dp[i][j]=1+dp[i-1][j-1];
                    dp2[i][j]='D';
                
                }
                else{
                    // dp[i][j]=max({dp[i-1][j],dp[i][j-1]});

                    if(dp[i-1][j] >= dp[i][j-1]){
                          dp[i][j]=dp[i-1][j];
                          dp2[i][j]='U';
                    }
                    else{
                         dp[i][j]=dp[i][j-1];
                          dp2[i][j]='L';
                    }


                }
            }
        }
        //  for(int i=0;i<y1;i++){
        //     for(int j=0;j<y2;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int i=0;i<y1;i++){
            for(int j=0;j<y2;j++){
                cout<<dp2[i][j]<<" ";
            }
            cout<<endl;
        }

        int i=y1-1 ;
        int j=y2-1;
        while(i!=0 || j!=0){
            if(x1[i]==x2[j]){
                x3+=x1[i];
                if(dp2[i][j]=='U'){
                    i--;
                      
                }
                 else if(dp2[i][j]=='D'){
                    i--;
                    j--;
                }
                 else if(dp2[i][j]=='L'){
                    j--;
                }
                 else if(dp2[i][j]=='N'){
                    break;
                }

            }
            else{
                 if(dp2[i][j]=='U'){
                   i--;
                }
                 else if(dp2[i][j]=='D'){
                    i--;
                    j--;
                }
                 else if(dp2[i][j]=='L'){
                    j--;
                }
                else if(dp2[i][j]=='N'){
                    break;
                }

            }

        }
        reverse(x3.begin(),x3.end());
        cout<<x3<<endl;

        
        return 456;
    }
};
