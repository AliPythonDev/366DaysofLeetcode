/* 
Day: 16
Problem Number: 380 (https://leetcode.com/problems/insert-delete-getrandom-o1)
Date: 16-01-2024 
Description:
Implement the RandomizedSet class:
* RandomizedSet() Initializes the RandomizedSet object.
* bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
* bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
* int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.
You must implement the functions of the class such that each function works in average O(1) time complexity.
 
Code:  */
class RandomizedSet {
public:
    RandomizedSet() {
    }
    bool insert(int val) {
        if (d.count(val)) {
            return false;
        }
        d[val] = q.size();
        q.push_back(val);
        return true;
    }
    bool remove(int val) {
        if (!d.count(val)) {
            return false;
        }
        int i = d[val];
        d[q.back()] = i;
        q[i] = q.back();
        q.pop_back();
        d.erase(val);
        return true;
    }
    int getRandom() {
        return q[rand() % q.size()];
    }
private:
    unordered_map<int, int> d;
    vector<int> q;
};
/*
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
