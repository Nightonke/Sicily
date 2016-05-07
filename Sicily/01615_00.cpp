// Problem#: 1615
// Submission#: 2699001
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

int main() {
    int output[110], input_counters[1010], t, max, n, i, temp, j;
    output[0] = -2;//输出序列是从第二项开始的，为保证第二项的正常输入，第一项设为-2
    scanf("%d", &t);
    while (t--) {
        memset(input_counters, 0, sizeof(input_counters));
        max = 0;
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            scanf("%d", &temp);
            max = temp > max ? temp : max;
            input_counters[temp]++;
        }
        j = 1;
        temp = -1;
        for (i = 0; i <= max; ) {//从最小的开始
            for (; input_counters[i] == 0 && i <= max; i++);//跳过空的数
            if (i > max)
                break;
            if (output[j - 1] == i - 1) {//如果不符合要求
                temp = i;//暂且存入temp中
                i++;//去检查下一个
            } else {
                if (temp != -1) {//temp中已经有了先前的数
                    input_counters[i]--;
                    output[j++] = i;//直接输出这个i
                    i = temp;//再把先前的temp拿出来进行下一轮检查
                    temp = -1;//temp变成空的
                } else {//temp先前为空
                    if (i + 1 == max && input_counters[i + 1] != 0) {//当i之后的值就是最大值要特殊处理，因为当达到最大值的时候，假如temp中存入了最大值，那就会因为没有进入下一轮而导致最大值在temp中拿不出来了
                        temp = i;//于是将没达到最大值的i先放进temp，先处理最大值
                    } else {
                        while (input_counters[i]--)
                            output[j++] = i;//假如下一个不是最大值就输出完i
                    }
                    i++;
                }
            }
        }
        printf("%d", output[1]);
        for (i = 2; i < n + 1; i++) {
            printf(" %d", output[i]);
        }
        printf("\n");
    }
    return 0;
}                                 