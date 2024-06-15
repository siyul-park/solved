class RandomizedSet {
public:
    RandomizedSet() : _map{}, _vector{} {}

    bool insert(int val) {
        if (auto it = _map.find(val); it == _map.end()) {
            _map[val] = _vector.size();
            _vector.push_back(val);
            return true;
        } else {
            return false;
        }
    }

    bool remove(int val) {
        if (auto it = _map.find(val); it != _map.end()) {
            _vector[it->second] = _vector.back();
            _vector.pop_back();
            _map[_vector[it->second]] = it->second;
            _map.erase(val);
            return true;
        } else {
            return false;
        }
    }

    int getRandom() { 
        return _vector[rand() % _vector.size()];
    }

private:
    unordered_map<int, int> _map;
    vector<int> _vector;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
 