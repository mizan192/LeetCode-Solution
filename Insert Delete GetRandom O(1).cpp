class RandomizedSet {
public:
	unordered_set<int>m;
	unordered_map<int, int>vis;
	queue<int>q;
	int totalElement = 0;
	RandomizedSet() {

	}

	bool insert(int val) {
		bool ans = false;
		if (vis[val] == 0) {
			ans = true;
			vis[val]++;
			m.insert(val);
		}
		return ans;
	}

	bool remove(int val) {
		if (vis[val]) {
			vis[val]--;
			m.erase(val);
			return true;
		}
		else return false;
	}

	int getRandom() {
		auto it = m.begin();
		advance(it, rand() % m.size());
		return *it;
	}


};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */