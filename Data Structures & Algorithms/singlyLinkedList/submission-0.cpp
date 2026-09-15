struct Node { 
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

class LinkedList {
    Node* head;
    Node* tail;
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    int get(int index) {
        Node* ptr = head;
        for (int i = 0; i < index && ptr != nullptr; ++i) {
            ptr = ptr->next;
        }
        return ptr != nullptr ? ptr->val : -1;
    }

    void insertHead(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }
    
    void insertTail(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    bool remove(int index) {
        Node* ptr = head;
        Node* prevPtr = nullptr;
        for (int i = 0; i < index && ptr != nullptr; ++i) {
            prevPtr = ptr;
            ptr = ptr->next;
        }
        if (ptr == nullptr) return false;
        
        if (ptr == head) {
            head = head->next;
            if (!head) {
                tail = nullptr;
            }
            delete ptr;
            return true;
        }

        prevPtr->next = ptr->next;
        if (ptr == tail) {
            tail = prevPtr; 
        }

        delete ptr;
        return true;
    }

    vector<int> getValues() {
        vector<int> values;
        Node* ptr = head;
        while (ptr != nullptr) {
            values.push_back(ptr->val);
            ptr = ptr->next;
        }
        return values;
    }
};
