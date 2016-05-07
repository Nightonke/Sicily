// Problem#: 2250
// Submission#: 3370988
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
typedef int T;
class Vector {
public:
   Vector() {
       counter = 0;
       arraySize = 0;
       elems = NULL;
   }
   Vector(int n) {
       counter = n;
       arraySize = n;
       if (n) elems = new int[arraySize];
       else elems = NULL;
       for (int i = 0; i < n; i++) elems[i] = T();
   }
   ~Vector() {
       if (elems) delete[] elems;
       elems = NULL;
   }
   Vector(const Vector & c) {
       counter = c.size();
       arraySize = c.capacity();
       elems = NULL;
       if (arraySize) elems = new int[arraySize];
       for (int i = 0; i < counter; i++) elems[i] = c.elems[i];
   }
   const Vector& operator = (Vector & c) {
       if (elems) delete[] elems;
       elems = NULL;
       counter = c.size();
       arraySize = c.capacity();
       if (arraySize) elems = new int[arraySize];
       for (int i = 0; i < counter; i++) elems[i] = c.elems[i];
       return *this;
   }
   int size() const {
       return counter;
   }
   int capacity() const {
       return arraySize;
   }
   bool empty() const {
       return counter == 0;
   }
   void clear() {
       counter = 0;
   }
   T & operator [] (int position) {
       if (0 <= position && position < counter)
            return elems[position];
   }
   int find( T &x) const {
       for (int i = 0; i < counter; i++) {
           if (elems[i] == x) return i;
       }
       return -1;
   }
   int insert(int position, const T &x) {
       if (position < 0 || position > counter) return -1;
       if (counter + 1 > arraySize) {
           int * newElems = new int[(arraySize ? 2 * arraySize : 1)];
           for (int i = 0; i < position; i++) newElems[i] = elems[i];
           newElems[position] = x;
           for (int i = position; i < counter; i++) newElems[i + 1] = elems[i];
           counter++;
           arraySize = arraySize ? 2 * arraySize : 1;
           delete[] elems;
           elems = newElems;
       } else {
           counter++;
           for (int i = counter - 1; i > position; i--) elems[i] = elems[i - 1];
           elems[position] = x;
       }
       return position;
   }
   int push_back(const T &x) {
       return insert(counter, x);
   }
   int erase(int position) {
       if (position < 0 || position >= counter) return -1;
       for (int i = position; i < counter - 1; i++) elems[i] = elems[i + 1];
       counter--;
       return position + 1;
   }
   void traverse(void (*visit)(T &)) {
       for (int i = 0; i < counter; i++) visit(elems[i]);
   }
 private:
    T *elems;
    int counter; //number of items in the list
    int arraySize; // the size of the array 
};
typedef Vector MyVector;                                 