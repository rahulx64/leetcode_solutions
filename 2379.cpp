class Solution {
public:
    int minimumRecolors(string blocks, int k) {

        int mini = 1e8;
        int cnt = 0;
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'B')
                cnt++;
        }
        mini = min(mini, k - cnt);
        int l = 0;
        int r = k;

        for (int r = k; r < blocks.size(); r++) {
            if (blocks[r] == 'B')
                cnt++;
            if (blocks[l] == 'B')
                cnt--;
            l++;
            mini = min(mini, k - cnt);
        }
        return mini;
    }
};
