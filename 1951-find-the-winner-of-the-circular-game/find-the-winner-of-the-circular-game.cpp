class Solution {
public:
    int findTheWinner(int n, int k) {
        set<int> friends;
        for (int i = 1; i <= n; i++)
            friends.insert(i);
        set<int>::iterator it = friends.begin(), forDelete;
        while (friends.size() > 1){
            for (int i = 1; i < k; i++){
                it++;
                if (it == friends.end())
                    it = friends.begin();
            }
            forDelete = it;
            it++;
            if (it == friends.end())
                it = friends.begin();
            friends.erase(forDelete);
        }
        return *it;
    }
};