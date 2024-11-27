
// A Binary Tree 

// USE A MAP to store string and JSON pairing
struct JSON { 
	int isprimitive; // i can store if we are 
	map<string, JSON*> mp;
	int val;
}

map<string, int> dfs(struct* JSON, map<string, int>& ans, string& curr_key)
	if(JSON->isprimitive){
		ans[curr_key] = JSON->val;
		return;
	}
	for(auto [key, obj] : mp){
		string new_key = curr_key + key;
		dfs(obj, ans, new_key);
	}
}

