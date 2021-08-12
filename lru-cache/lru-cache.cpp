
class Node {
    public:
    Node *prev, *next;
    int key, value;
    Node(int k,int v) {
        key = k;
        value = v;
        prev = NULL;
        next = NULL;
    }
    
};


class LinkedList {
    public:
    Node *front, *rear;
    
    LinkedList() {
        front = NULL;
        rear = NULL;
    }
    
    Node* addfront(int k, int v) {
        Node *n = new Node(k,v);
        if((front==NULL) && (rear ==NULL)){
            front = n;
            rear = n;
        }
        else {
            front->prev = n;
            n->next = front;
            front = n;
        }
        return n;
    }
    void move_page_to_head(Node *n) {
        if(n==front) {
          return;
        }
        if(n == rear) {
          rear = rear->prev;
          rear->next = NULL;
        }
        else {
          n->prev->next = n->next;
          n->next->prev = n->prev;
        }

        n->next = front;
        n->prev = NULL;
        front->prev = n;
        front = n;
    }
    
    void removerear() {
        if(rear==NULL)
            return;
        else if(front==rear) {
            delete rear;
            front = rear = NULL;
        }
        else {
            Node *temp = rear;
            rear = rear->prev;
            rear->next = NULL;
            delete temp;
        }
    }
    
    
    
};





class LRUCache {
public:
    int size = 0,n;
    unordered_map < int , Node * > m;
    LinkedList * l = new LinkedList();
    LRUCache(int capacity) {
        n = capacity;
        size = 0;
    }
    
    int get(int key) {
        if(m[key]==NULL)
            return -1;
        int value = m[key]->value;
        l->move_page_to_head(m[key]);
        return value;
    }
    
    void put(int key, int value) {
        if(m[key]==NULL){
            m[key] = l->addfront(key,value);
            size++;
        }
        else {
            m[key]->value = value;
            l->move_page_to_head(m[key]);
        }
        if(size>n){
            Node *temp = l->rear;
            int k = temp->key;
            m.erase(k);
            l->removerear();
            size--;
        }
        
            
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */