// Problem#: 13475
// Submission#: 3516831
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
int digit(int n, int k) {
    int counter = 1;
    while (n) {
        if (counter == k) return n % 10;
        counter++;
        n /= 10;
    }
    return 0;
}                                 