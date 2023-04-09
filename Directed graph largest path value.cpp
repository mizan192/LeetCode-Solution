//https://leetcode.com/problems/largest-color-value-in-a-directed-graph/
class Solution {
public:
	static const int lmt = 100003;
	vector<int>gr[lmt + 2];
	int inDeg[lmt+2];
	char ch;
	std::vector<bool>path;
	std::vector<int> vis;
	string color;

	int dfs(int node){
		if(path[node]) return -1;
		if(vis[node]!=-1) return vis[node];
		int len = (color[node]==ch);
		int cnt=0;

		path[node]=true;

		for(auto x : gr[node]){
			int next_len = dfs(x);
			if(next_len==-1) return -1;
			cnt=max(cnt,next_len);
		}
		path[node]=false;
		return vis[node]=len+cnt;

	}



	int largestPathValue(string c, vector<vector<int>>& e) {
		for (auto x : e) {
			gr[x[0]].push_back(x[1]);
			//gr[x[1]].push_back(x[0]);
		}
		int n = c.size();
		color=c;
		queue<int>q;
		for (int i = 0; i < n; i++) {    
			if (!inDeg[i]) q.push(i);
		}
		int nodeCunt = 0;
		while (!q.empty()) {
			int pr = q.front();
			q.pop();
			nodeCunt++;
			for (auto x : gr[pr]) {
				inDeg[x]--;
				if (!inDeg[x]) q.push(x);
			}
		}

		if (nodeCunt != n) return -1;


		int mx_len = 0;
		for (char c = 'a'; c <= 'z'; c++) {
			ch = c;
			path = std::vector<bool>(n, false);
			vis = std::vector<int>(n, -1);
			for(int i=0;i<n;i++){
				int len=dfs(i);
				if(len==-1) return -1;
				mx_len=max(mx_len,len);
			}
		}


		return mx_len;




	}
};