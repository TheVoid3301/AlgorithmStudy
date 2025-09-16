class NumberContainers {
public:
    NumberContainers() {

    }
    
    void change(int index, int number) {
        if (!m.contains(index)) {
            m[index] = number;
            mp[number].insert(index);
        } else {
            mp[m[index]].erase(index);
            m[index] = number;
            mp[number].insert(index);
        }
    }
    
    int find(int number) {
        if (mp[number].size() != 0) {
            return *mp[number].begin();
        }
        return -1;
    }

private:
    map<int, int> m;
    map<int, set<int>> mp;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */