// Problem#: 2252
// Submission#: 3371351
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
template<typename T>
class List {
public:
    struct Node {
        T data;
        Node * next;
        Node(const T & x, Node * p = NULL):data(x),next(p){};
    };
    typedef Node * Ptr;
    Node * head;
    int theSize;
    List() {
        head = NULL;
        theSize = 0;
    }
    ~List() {
        clear();
        theSize = 0;
    }
    List(const List &l) {
        head = NULL;
        theSize = 0;
        Node * temp = l.head;
        while (temp) {
            this->push_back(temp->data);
            temp = temp->next;
        }
    }
    const List & operator=(const List &l) {
        clear();
        Node * temp = l.head;
        while (temp) {
            this->push_back(temp->data);
            temp = temp->next;
        }
    }
    int size() const {
        return theSize;
    }
    bool empty() const {
        return theSize == 0;
    }
    void clear() {
        while (head) {
            Node * del = head;
            head = head->next;
        }
        theSize = 0;
        head = NULL;
    }
    Ptr find( T &x) const {
        Node * temp = head;
        while (temp) {
            if (temp->data) return temp;
        }
        return NULL;
    }
    Ptr insert(Ptr position, const T &x) {
        Node * temp = head;
        Node * beforeTemp;
        bool positionRight = false;
        while (temp) {
            if (temp == position) {
                positionRight = true;
                break;
            }
            beforeTemp = temp;
            temp = temp->next;
        }
        if (!positionRight) return NULL;
        else {
            theSize++;
            if (temp == head) {
                Node * newHead = new Node(x, head);
                head = newHead;
                return newHead;
            } else {
                Node * newNode = new Node(x, temp);
                beforeTemp->next = newNode;
                return newNode;
            }
        }
    }
    void push_front(const T &x) {
        if (theSize) insert(head, x);
        else {
            theSize = 1;
            head = new Node(x);
        }
    }
    void push_back(const T &x) {
        if (theSize == 0) {
            theSize = 1;
            head = new Node(x);
            return;
        }
        Node * temp = head;
        while (temp->next) temp = temp->next;
        Node * newEnd = new Node(x);
        temp->next = newEnd;
        theSize++;
    }
    T & front() {
        if (head) return head->data;
    }
    T & back() {
        if (theSize) {
           Node * temp = head;
           while (temp->next) temp = temp->next;
           return temp->data;
        }
    }
    Ptr begin(){
        return head;
    }
    Ptr end(){
        return NULL;
    }
    void traverse(void (*visit)(T &)) {
        Node * temp = head;
        while (temp) {
            visit(temp->data);
            temp = temp->next;
        }
    }
    Ptr advance(Ptr p) {
        if (p) return p->next;
    }
    Ptr erase(Ptr position) {
       Node * temp = head;
       Node * beforeTemp;
       bool positionRight = false;
       while (temp) {
           if (temp == position) {
               positionRight = true;
               break;
           }
           beforeTemp = temp;
           temp = temp->next;
       }
       if (!positionRight) return NULL;
       else {
           theSize--;
           if (temp == head) {
               head = temp->next;
               delete temp;
               return head;
           } else {
               beforeTemp->next = temp->next;
               delete temp;
               return beforeTemp->next;
           }
       }
   }
};                                 