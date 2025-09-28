class LRUCache {
public:

    class Node{
    public:
        int key, val;
        Node* prev;
        Node* next;

        Node(int k, int v){
            key=k;
            val=v;
            prev=next=nullptr;
        }
    };

    Node* head= new Node(-1,-1);
    Node* tail= new Node(-1,-1);

    unordered_map<int, Node*> m;
    int limit;

    void addNode(Node* newnode){
        Node* oldnext= head->next;
        head->next=newnode;
        oldnext->prev= newnode;

        newnode->next= oldnext;
        newnode->prev= head;
    }

    void delNode(Node* oldnode){
        Node* oldprev= oldnode->prev;
        Node* oldnext= oldnode->next;

        oldprev->next=oldnext;
        oldnext->prev= oldprev;
    }

    LRUCache(int capacity) {
        limit= capacity;
        head->next= tail;
        tail->prev= head;
        
    }
    
    int get(int key) {
        if(m.find(key)==m.end()){
            return -1;
        }
        Node* ansNode= m[key];
        int ans=ansNode->val;

        m.erase(key);
        delNode(ansNode);

        addNode(ansNode);
        m[key]=ansNode;

        return ans;
    }
    
    void put(int key, int value) {
    if(m.count(key)){
        Node* oldnode= m[key];
        delNode(oldnode);
        m.erase(key);
    }

    //capacity reach check
    if(m.size()==limit){
        m.erase(tail->prev->key);
        delNode(tail->prev);
    }

    Node* newnode= new Node(key, value);
    addNode(newnode);
    m[key]= newnode;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */