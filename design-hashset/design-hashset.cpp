class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        
    }
    
    vector<int> vis[1005];
    int F_vis[1005]={0};
    
    void add(int key) {
        int t1 = key%1000;
        int t2 = key/1000;

        if(F_vis[t1] == 0)
        {
            vis[t1].reserve( 1005 );/**std::vector class provides a useful function reserve which helps user specify the minimum size of the vector.It indicates that the vector is created such that it can store at least the number of the specified elements without having to reallocate memory.*/
        }
        vis[t1][t2] = 1;
        F_vis[t1] = 1;
    }
    
    void remove(int key) {
        int t1 = key%1000;
        int t2 = key/1000;
        if(F_vis[t1]==0)
            return;
        vis[t1][t2] = 0;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int t1 = key%1000;
        int t2 = key/1000;
        if(F_vis[t1]==0)
            return false;
        if(vis[t1][t2]==1)
            return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */