// Problem#: 2016
// Submission#: 3728282
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 2016
// Submission#: 3552081
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<stdio.h>
#include<math.h>
#include<string.h>

const int maxn = 1000 + 10; //最大陨石数
const double eps = 1e-8; //控制精度
const double pi = acos(-1.0);//圆周率

double d1, d2, R; //起点和终点弧度，太空船半径
double xd1, yd1, xd2, yd2; //起点和终点坐标。
int n; //陨石数目
double x[maxn], y[maxn], r[maxn]; //陨石圆心坐标和半径
int a[maxn][maxn]; //无向图
int b[maxn]; //陨石与太空船相交标记
int cas;

inline double dis(double x, double y){
    //计算向量长度
    return sqrt(x * x + y * y);
}

inline double helen(double a, double b, double c){
    double p = (a + b + c) / 2.0;
    //海伦公式计算长度为a、b、c的三角形面积
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int intersect(int i, int j){
    //利用面积判断第i个圆和第j个圆的交点是否在太空船内
    //计算边长
    double di = dis(x[i], y[i]);
    double dj = dis(x[j], y[j]);
    double ij = dis(x[i] - x[j], y[i] - y[j]);
    //计算4个三角形的面积
double S = helen(di, dj, ij);
    double Si = helen(di, r[i], R);
    double Sj = helen(dj, r[j], R);
    double Sij = helen(ij, r[i], r[j]);
    //利用这4个三角形的面积来判断
    return Si + Sj + Sij > S;
}

int dfs(int root){
    //深度优先遍历
    if (b[root] == 2) return 0; //找到一个标记为2的结点则返回
    b[root] = 0; //标记
    int i;
    for (i = 0; i < n; i++) if(b[i] && a[root][i] == cas) {
        if (dfs(i) == 0) return 0; //如果没访问过则进行访问
    }
    return 1;
}       


int main(){
    //读入数据组数
    int T;
    scanf("%d", &T);
    double tmp, d, di; //临时变量
    int ok; //可行标记
    int i,j; //循环变量
    memset(a, 0, sizeof(a)); //对a清零
    cas = 0; //数据序号
    while (T--) {
        cas++;
        scanf("%lf%lf%lf", &R, &d1, &d2); //读入半径
        //交换以保证d1 <= d2
        if (d1 > d2) {
            tmp = d1;
            d1 = d2;
            d2 = tmp;
        }
        //角度化成弧度
        d1 = pi / 180.0 * d1;
        d2 = pi / 180.0 * d2;
        //起点和终点坐标
        xd1 = R * cos(d1);
        yd1 = R * sin(d1);
        xd2 = R * cos(d2);
        yd2 = R * sin(d2);
        //读入陨石坐标
scanf("%d", &n);
        for (i = 0; i < n; i++) scanf("%lf%lf%lf", &x[i], &y[i], &r[i]);
        ok = 1;
        memset(b, 0, sizeof(b)); //清空b数组
        for (i = 0; i < n; i++) {//遍历陨石
            d = dis(x[i], y[i]); //计算距离
            if (d > R + r[i] + eps) { //相离，标记为0
                b[i] = 0;
                continue;
            }
            if (r[i] + d + eps < R) { //相含，标记为3
                b[i] = 3;
                continue;
            }
            //陨石直接撞到起点或者终点
            if (dis(x[i] - xd1, y[i] - yd1) <= eps + r[i] ||
                dis(x[i] - xd2, y[i] - yd2) <= eps + r[i]){     
                ok = 0; //无解
                continue;
            }
            //计算圆心弧度
            di = acos(x[i] / d);
            if (y[i] < 0.0) di = pi + pi - di;
            //判断相交于哪个区间
            if(di > d1 && di < d2) b[i] = 1; 
            else b[i] = 2;
        }
        if (!ok) { 
            //如果陨石直接撞到起点或终点
            printf("Die hard!\n");
            continue;
        }
        //否则进行遍历
        for (i = 0; i < n; i++) if (b[i])
            for (j = i + 1; j < n; j++) if (b[j])   
if (dis(x[i] - x[j], y[i] - y[j]) <= r[i] + r[j]) {
                    if(b[i] + b[j] != 3 || intersect(i, j))
                        //如果两个陨石相交则连边
                        a[i][j] = a[j][i] = cas;
                }       
        //对每一个标记为1的点开始遍历，看能否到达标记为2的点
        for (i = 0; i < n; i++) {
            if (b[i] == 1) ok = dfs(i);
            if (!ok) break;
        }
        //输出判定结果
        if (ok) printf("Escape!\n");
        else printf("Die hard!\n");
    }
    return 0;
}                                 