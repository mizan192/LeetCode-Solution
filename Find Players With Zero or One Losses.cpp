#define ff frist
#define ss second
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();

        int win[100003], loss[100003];
        for (int i = 0; i <= 100000; i++) {
            win[i] = loss[i] = 0;
        }

        for (auto x : matches) {
            int w = x[0], l = x[1];
            win[w]++;
            loss[l]++;
        }

        vector<int>winner, losser;
        for (int i = 1; i <= 100000; i++) {
            if (win[i] >= 1 && loss[i] == 0)  winner.push_back(i);
        }
        for (int i = 1; i <= 100000; i++) {
            if (loss[i] == 1 )  losser.push_back(i);
        }



        vector<vector<int>>ans;
        ans.push_back(winner);
        ans.push_back(losser);

        return ans;


    }
};