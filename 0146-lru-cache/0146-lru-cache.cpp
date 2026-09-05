class LL {
public:
    int key;
    int val;
    LL* prev;
    LL* next;
    LL(int x, int y) : key(x), val(y), prev(nullptr), next(nullptr) {}
    LL(int x, int y, LL* p, LL* n) : key(x), val(y), prev(p), next(n) {}
};

class LRUCache {
public:
    int s = 0;
    LL* lr;
    LL* mr;
    unordered_map<int, LL*> map;
    LRUCache(int capacity) {
        s = capacity;
        lr = new LL(0, 0);
        mr = new LL(0, 0);
        lr->next = mr;
        mr->prev = lr;
    }

    void remove(LL* node) {
        LL* nodeprev = node->prev;
        LL* nodenext = node->next;
        nodeprev->next = nodenext;
        nodenext->prev = nodeprev;
        node->prev = nullptr;
        node->next = nullptr;
    }
    void insert(LL* node) {
        LL* mrprev = mr->prev;
        
        mrprev->next = node;
        node->prev = mrprev;
        node->next = mr;
        mr->prev = node;
    }

    int get(int key) {
        if (map.contains(key)) {
            LL* node = map[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (map.contains(key)) {
            LL* node = map[key];
            node->val = value;
            remove(node);
            insert(node);
            return;
        }
        if (map.size() == s) {
            LL* lru = lr->next;
            remove(lru);
            map.erase(lru->key);
            delete lru;
        }
        LL* node = new LL(key,value);
        map[key] = node;
        insert(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */