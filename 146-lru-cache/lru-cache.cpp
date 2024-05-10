class LRUCache {
public:
    class Node{
        public:
        int key, val;
        Node* prev;
        Node* next;

        Node(int key, int val){
            this->key = key;
            this->val = val;
        }
    };

    int cap;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> mp;

    void addNode(Node* node){
        Node* temp = head->next;

        node->next = temp;
        node->prev = head;

        head->next = node;
        temp->prev = node;
    }

    void delNode(Node* node){
        Node* prevv = node->prev;
        Node* nextt = node->next;

        prevv->next = nextt;
        nextt->prev = prevv;
    }

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (mp.find(key) != mp.end()){
            Node* temp = mp[key];
            int ans = temp->val;
            mp.erase(key);
            delNode(temp);
            addNode(temp);
            mp[key] = head->next;
            return ans;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()){
            Node* temp = mp[key];
            mp.erase(key);
            delNode(temp);
        } 
        if (mp.size() == cap){
            mp.erase(tail->prev->key);
            delNode(tail->prev);
        }
        addNode(new Node(key, value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */