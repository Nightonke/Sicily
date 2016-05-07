// Problem#: 1151
// Submission#: 3960514
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
using namespace std;

const int BIG_PRIME = 40343;
#define MAX_SIZE 40320

// 状态结构体
struct step {
    step * preStep;
    char c;
    int n;
    step() {
        preStep = NULL;
    }
};

struct step * record[BIG_PRIME + 1];
struct step number[MAX_SIZE];

int A(int num)
{

    int first = num / 10000;
    int second = num % 10000;
    return second * 10000 + first;
}

int B(int num)
{

    int first = num / 10000;
    int second = num % 10000;
    first = first / 10 + first % 10 * 1000;
    second = second / 10 + second % 10 * 1000;
    return first * 10000 + second;
}

int C(int num) {

    int digit[8];
    for (int i = 7; i >= 0; i--)
    {
        digit[i] = num % 10;
        num /= 10;
    }

    int tmp = digit[1];
    digit[1] = digit[5];
    digit[5] = digit[6];
    digit[6] = digit[2];
    digit[2] = tmp;

    num = digit[0];
    for (int i = 1; i < 8; i++)
        num = num * 10 + digit[i];
    return num;
}

// 广度优先搜索，找到所有答案
void BFS() {

    for (int i = 0; i < BIG_PRIME; i++) record[i] = NULL;

    number[0].n = 12348765;
    number[0].c = ' ';

    record[number[0].n % BIG_PRIME] = &number[0];

    int pos = 0, next = 1;
    int result;

    while (next < MAX_SIZE && pos < next) {
        // A
        result = A(number[pos].n);
        int p = result % BIG_PRIME;
        if (record[p] == NULL) {
            number[next].n = result;
            number[next].preStep = &number[pos];
            number[next].c = 'A';
            record[p] = &number[next];
            next++;
        }
        // B
        result = B(number[pos].n);
        p = result % BIG_PRIME;
        if (record[p] == NULL) {
            number[next].n = result;
            number[next].preStep = &number[pos];
            number[next].c = 'B';
            record[p] = &number[next];
            next++;
        }
        // C
        result = C(number[pos].n);
        p = result % BIG_PRIME;
        if (record[p] == NULL) {
            number[next].n = result;
            number[next].preStep = &number[pos];
            number[next].c = 'C';
            record[p] = &number[next];
            next++;
        }
        pos++;
    }
}

int main() {

    BFS();

    // 取消cin、cout和scanf、printf的同步，提高读入写出效率
    std::ios::sync_with_stdio(false);

    while (1) {
        int n;

        cin >> n;
        if (n == -1) break;
        char move[30];
        int p = 0, temp;

        for (int i = 0; i < 8; i++) {
            cin >> temp;
            p = p * 10 + temp;
        }

        step * last = record[p % BIG_PRIME];
        p = 0;
        if (!last) cout << -1 << endl;
        else {
            while (last->preStep) {
                move[p++] = last->c;
                last = last->preStep;
            }
            if (p > n) cout << -1 << endl;
            else {
                cout << p << " ";
                for (int i = p - 1; i >= 0; i--) cout << move[i];
                cout << endl;
            }
        }
    }

    return 0;
}                                 