// Problem#: 9992
// Submission#: 2746184
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
void bubbleSort(double list[], int size) {
    int i, j;
    double temp;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (list[j] > list[j + 1]) {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}                                 