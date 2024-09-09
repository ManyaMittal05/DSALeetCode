class LRUCache {
public:
    class Node{
        public:
        int key, val;
        Node* next;
        Node* prev;

        Node(int key, int val){
            this->key = key;
            this->val = val;
            next = NULL;
            prev = NULL;
        }
    };

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    unordered_map<int, Node*> mp;
    int capacity, size;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;

        Node* node = mp[key];

        Node* prevNode = node->prev;
        prevNode->next = node->next;
        node->next->prev = prevNode;
        node->next = head->next;
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
            node->prev = head;
            head->next = node;
        }
        else{
            if(size == capacity){
                Node* lru = tail->prev;
                tail->prev = lru->prev;
                tail->prev->next = tail;
                delete lru;
                mp.erase()
                size--;
            }
            
            Node* newNode = new Node(key, value);
            newNode->next = head->next;
            head->next = newNode;
            newNode->prev = head;
            newNode->next->prev = newNode;
            size++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */