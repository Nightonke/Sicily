// Problem#: 2302
// Submission#: 3371367
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
template <typename T> class Queue {
public:
    Queue() {
        counter = 0;
    }
    ~Queue() {
        counter = 0;
    }
    Queue(const Queue &rhs) {
        counter = rhs.size();
        for (int i = 0; i < counter; i++) a[i] = rhs.a[i];
    }
    const Queue & operator=(const Queue &rhs) {
        counter = rhs.size();
        for (int i = 0; i < counter; i++) a[i] = rhs.a[i];
    }
    bool empty() const {
        return counter == 0;
    }
    bool full() const {
        return counter == 100;
    }
    int size() const {
        return counter;
    }
    bool push(const T &x) {
        if (counter < 100) {
            a[counter++] = x;
            return true;
        } else return false;
    }
    bool pop() {
        if (counter) {
            for (int i = 0; i < counter - 1; i++) a[i] = a[i + 1];
            counter--;
            return true;
        } else return false;
    }
    const T & front() const {
        if (counter) return a[0];
    }
private:
    T a[105];
    int counter;
};                                 