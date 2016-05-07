// Problem#: 1276
// Submission#: 3295608
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Queen {
public:
    char QChar, BChar;  // 代表皇后和空白的字符
    int * q_in_row;  // q_in_row[i] = j表示在第i行第j列有个皇后
    bool * col_free;  // col_free[i] = true表示第i列没有皇后
    bool * up_free;  // 从右上到左下的对角线是否可以放置皇后
    bool * down_free;  // 从左上到右下的对角线是否可以放置皇后
    int N;  // 皇后个数、正方形棋盘的边长
    bool ONE, NUM, ALL;  // 由于只有一个递归函数，三个变量用于区分是哪一个问题
    bool ONE_FINISH;  // 判断只返回一个解的问题是否已经解决
    int num;  // 所有解的个数
    vector<vector<char> > oneAns;  // 一个解
    vector<vector<vector<char> > > allAns;  // 所有解

    Queen() {
        QChar = 'Q';
        BChar = '.';
        ONE = NUM = ALL = ONE_FINISH = false;
    }

    void changeChar(char q, char b) {  // 可以改变代表皇后和空白的字符
        QChar = q;
        BChar = b;
    }

    void makeBoard(int n) {  // 为接下来的操作开辟空间
        N = n;
        q_in_row = new int[N];
        col_free = new bool[N];
        up_free = new bool[2 * N - 1];
        down_free = new bool[2 * N - 1];
        for (int i = 0; i < N; i++) q_in_row[i] = col_free[i] = true;
        for (int i = 0; i < 2 * N - 1; i++) up_free[i] = down_free[i] = true;
    }

    void deleteBoard() {  // 删除已经开辟的空间
        delete []q_in_row;
        delete []col_free;
        delete []up_free;
        delete []down_free;
    }

    void construct_solution() {  // 构造法，通过N皇后问题的规律总结而来，出自http://poj.org/problem?id=3239
        int row = 0;
        if (N % 6 != 2 && N % 6 != 3) {
            if (N % 2 == 0) {
                for (int i = 2; i <= N; i += 2) q_in_row[row++] = i - 1;
                for (int i = 1; i <= N - 1; i += 2) q_in_row[row++] = i - 1;
            } else {
                for (int i = 2; i <= N - 1; i += 2) q_in_row[row++] = i - 1;
                for (int i = 1; i <= N; i += 2) q_in_row[row++] = i - 1;
            }
        } else {
            if (N % 2 == 0) {
                if ((N / 2) % 2 == 0) {
                    for (int i = N / 2; i <= N; i += 2) q_in_row[row++] = i - 1;
                    for (int i = 2; i <= N / 2 - 2; i += 2) q_in_row[row++] = i - 1;
                    for (int i = N / 2 + 3; i <= N - 1; i += 2) q_in_row[row++] = i - 1;
                    for (int i = 1; i <= N / 2 + 1; i += 2) q_in_row[row++] = i - 1;
                } else {
                    for (int i = N / 2; i <= N - 1; i += 2) q_in_row[row++] = i - 1;
                    for (int i = 1; i <= N / 2 - 2; i += 2) q_in_row[row++] = i - 1;
                    for (int i = N / 2 + 3; i <= N; i += 2) q_in_row[row++] = i - 1;
                    for (int i = 2; i <= N / 2 + 1; i += 2) q_in_row[row++] = i - 1;
                }
            } else {
                if ((N / 2) % 2 == 0) {
                    for (int i = N / 2; i <= N - 1; i += 2) q_in_row[row++] = i - 1;
                    for (int i = 2; i <= N / 2 - 2; i += 2) q_in_row[row++] = i - 1;
                    for (int i = N / 2 + 3; i <= N - 2; i += 2) q_in_row[row++] = i - 1;
                    for (int i = 1; i <= N / 2 + 1; i += 2) q_in_row[row++] = i - 1;
                    q_in_row[row++] = N - 1;
                } else {
                    for (int i = N / 2; i <= N - 2; i += 2) q_in_row[row++] = i - 1;
                    for (int i = 1; i <= N / 2 - 2; i += 2) q_in_row[row++] = i - 1;
                    for (int i = N / 2 + 3; i <= N - 1; i += 2) q_in_row[row++] = i - 1;
                    for (int i = 2; i <= N / 2 + 1; i += 2) q_in_row[row++] = i - 1;
                    q_in_row[row++] = N - 1;
                }
            }
        }
        write_in(oneAns);
    }

    vector<vector<char> > Return_an_ans(int n) {  // 返回一个解
        makeBoard(n);
        if (n > 3) {
            construct_solution();
        } else {
            ONE = true;
            dfs(0);
        }
        deleteBoard();
        return oneAns;
    }

    int Return_all_ans_num(int n) {  // 返回所有解的个数
        makeBoard(n);
        NUM = true;
        num = 0;
        dfs(0);
        deleteBoard();
        return num;
    }

    vector<vector<vector<char> > > Return_all_ans(int n) {  // 返回所有解
        makeBoard(n);
        ALL = true;
        dfs(0);
        deleteBoard();
        return allAns;
    }

    void write_in(vector<vector<char> > & a) {  // 写入一个解
        a.resize(N);
        for (int i = 0; i < N; i++) {
            a[i].resize(N);
            for (int j = 0; j < N; j++) {
                if (q_in_row[i] == j) a[i][j] = QChar;
                else a[i][j] = BChar;
            }
        }
    }

    void dfs(int now) {  // 深搜到每一个解

        if (now == N) {  // 如果能到这步说明找到了一个合适解
            if (ONE) {  // 如果只要求一个
                ONE_FINISH = true;
                write_in(oneAns);
                return;
            }
            if (NUM) {  // 如果求的是数目
                num++;
                return;
            }
            if (ALL) {  // 如果要求所有解
                vector<vector<char> > a;
                write_in(a);
                allAns.push_back(a);
                return;
            }
        }

        for (int col = 0; col < N; col++) {  // 对于每一列遍历
            if (col_free[col] && up_free[now + col] && down_free[now - col + N - 1]) {  // 如果找到合适位置
                q_in_row[now] = col;  // 写入列号
                col_free[col] = up_free[now + col] = down_free[now - col + N - 1] = false;  // 为下一步划定限制
                dfs(now + 1);
                if (ONE && ONE_FINISH) return;
                col_free[col] = up_free[now + col] = down_free[now - col + N - 1] = true;  // 重置以免影响其他深搜
            }
        }
    }
};

int main() {

    std::cout.sync_with_stdio(false);

    Queen q;
    int caseNum;
    cin >> caseNum;

    while (caseNum--) {
        int temp;
        cin >> temp;
        cout << temp;
        vector<vector<char> > ans = q.Return_an_ans(temp);
        for (int i = 0; i < temp; i++) {
            for (int j = 0; j < ans[i].size(); j++) {
                if (ans[i][j] == 'Q') {
                    cout << " " << j;
                    break;
                }
            }
        }
        cout << endl;
    }

    return 0;
}                                 