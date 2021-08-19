
class Node {
    public:
    Node *next , *prev;
    string url;
    Node(string s){
        next = NULL;
        prev = NULL;
        url = s;
    }
    
};


class BrowserHistory {
public:
    Node *front , *rear, * curr;
    
    BrowserHistory(string homepage) {
        curr = front = rear = new Node(homepage); 
    }
    
    void visit(string url) {
        curr = new Node(url);
        curr->next = front;
        front->prev = curr;
        front = curr;
    }
    
    string back(int steps) {
        string s;
        for(int i=0;i<steps;i++){
            if(front->next==NULL)
                return front->url;
            front = front->next;
        }
        return front->url;
    }
    
    string forward(int steps) {
        string s;
        for(int i=0;i<steps;i++){
            if(front->prev==NULL)
                return front->url;
            front = front->prev;
        }
        return front->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */