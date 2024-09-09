class LRUCache {
public:
    class Node{
        public:
        int key, val;
        Node* next;
        Node* prev;

        Node(int keyy, int value){
            key = keyy;
            val = value;
            next = NULL;
            prev = NULL;
        }
    };

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    unordered_map<int, Node*> mp;
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;

        Node* node = mp[key];

        Node* prevNode = node->prev;
        prevNode->next = node->next;
        node->next->prev = prevNode;
        node->next = head->next;
        head->next->prev = node;
        node->prev = head;
        head->next = node;
        return mp[key]->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            node->val = value;
            Node* prevNode = node->prev;
            prevNode->next = node->next;
            node->next->prev = prevNode;
            node->next = head->next;
            head->next->prev = node;
            node->prev = head;
            head->next = node;
        }
        else{
            if(mp.size() == capacity){
                Node* lru = tail->prev;
                int removeValue = lru->key;
                tail->prev = lru->prev;
                tail->prev->next = tail;
                mp.erase(removeValue);
                delete lru;
            }
            
            Node* newNode = new Node(key, value);
            newNode->next = head->next;
            head->next = newNode;
            newNode->prev = head;
            newNode->next->prev = newNode;
            mp[key] = newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */