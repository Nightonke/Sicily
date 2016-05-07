// Problem#: 1217
// Submission#: 3586328
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <algorithm>
//#include <stdlib.h>
using namespace std;

#define maxwarriors 2000
#define maxstrlen 13

long day;

class WARRIOR {
public:
    char name[maxstrlen];
    long maxlife, attack, defense, resume;
    long skill, life, life_time, ok_time;
    long id;
    bool operator < (const WARRIOR & that) const {
        return strcmp(name, that.name) < 0;
    }
    void cal_life() {
        if (life == maxlife) {
            life_time = day;
            return;
        }
        life += resume * (day - life_time - 1);
        if (life > maxlife) life = maxlife;
        life_time = day;
    }
    void damage(long d) {
        life -= d;
        if (life < 0) life = 0;
        ok_time = life_time + (maxlife - life + resume - 1) / resume + 1;
    }
};

bool skillcmp(WARRIOR * w1, WARRIOR * w2) {
    if (w1->skill != w2->skill) return w1->skill > w2->skill;
    else return strcmp(w1->name, w2->name) < 0;
}

/*
int sort_skill(const void * a, const void * b) {
    long i;
    i = (*(WARRIOR**)b)->skill - (*(WARRIOR**)a)->skill;
    if (i > 0) i = 1;
    if (i < 0) i = -1;
    if (i == 0) {
        if (strcmp((*(WARRIOR**)a)->name, (*(WARRIOR**)b)->name) > 0) i = 1;
        else i = -1;
    }
    return i;
}
*/

class KING {
public:
    char kingname[maxstrlen];
    long n;
    WARRIOR w[maxwarriors];
    long win_times;
    long chosed;
    WARRIOR * id_skill[maxwarriors];
    void init_warriors() {
        scanf("%ld", &n);
        for (int i = 0; i < n; i++) {
            scanf("%s%ld%ld%ld%ld", w[i].name, &w[i].maxlife, &w[i].attack, &w[i].defense, &w[i].resume);
            w[i].skill = w[i].maxlife * 2 + w[i].attack * 8 + w[i].defense * 6;
            w[i].life = w[i].maxlife;
            w[i].life_time = w[i].ok_time = 0;
        }
        sort(w, w + n);
        for (int i = 0; i < n; i++) {
            id_skill[i] = &w[i];
            w[i].id = i;
        }
        sort(id_skill, id_skill + n, skillcmp);
        //qsort(&(id_skill[0]), n, sizeof(id_skill[0]), sort_skill);
    }
    void init() {
        long i;
        init_warriors();
        win_times = 0;
    }
    void chose() {
        char s[100];
        long i;
        WARRIOR tmp;
        scanf("%s", s);
        if (strcmp(s, "choose") == 0) {
            scanf("%*s");
            for (i = 0; i < n; i++) if (id_skill[i]->ok_time <= day) break;
            chosed = id_skill[i]->id;
        } else {
            strcpy(tmp.name, s);
            chosed = lower_bound(w, w + n, tmp) - w;
        }
    }
};

void battle(KING * pa, KING * pb) {
    WARRIOR * wa, * wb, * tmp;
    KING * mid;
    long damage1, damage2, times1, times2, times1_r, times2_r;
    wa = &pa->w[pa->chosed];
    wa->cal_life();
    wb = &pb->w[pb->chosed];
    wb->cal_life();
    if (!((*wa) < (*wb))) {
        mid = pa;
        pa = pb;
        pb = mid;
        tmp = wa;
        wa = wb;
        wb = tmp;
    }
    damage1 = wa->attack - wb->defense;
    if (damage1 < 10) damage1 = 10;
    damage2 = wb->attack - wa->defense;
    if (damage2 < 10) damage2 = 10;
    times1 = (wb->life + damage1 - 1) / damage1;
    times2 = (wa->life + damage2 - 1) / damage2;
    if (times1 <= times2) {
        pa->win_times++;
        times1_r = times1;
        times2_r = times1 - 1;
        printf("Winner:%s %s\nLoser:%s %s\n", pa->kingname, wa->name, pb->kingname, wb->name);
    } else {
        pb->win_times++;
        times1_r = times2;
        times2_r = times2;
        printf("Winner:%s %s\nLoser:%s %s\n", pb->kingname, wb->name, pa->kingname, wa->name);
    }
    wa->damage(times2_r * damage2);
    wb->damage(times1_r * damage1);
}

KING a, b;
KING * pa, * pb;
long m;
long years_days[1001];
long month_days[2][12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool leap(long year) {
    return (year % 100 != 0 && year % 4 == 0) || year % 400 == 0;
}

long get_day(char date[]) {
    long i, j, k, y, m, d, re;
    for (i = 0; date[i]; i++) if (date[i] == '/') date[i] = ' ';
    sscanf(date, "%ld%ld%ld", &y, &m, &d);
    if (y == 0) re = 0;
    else re = years_days[y - 1];
    k = leap(y);
    for (i = 1; i < m; i++) re += month_days[k][i - 1];
    return re + d;
}

int main() {
    char date[100], s[100];
    years_days[0] = 365 + leap(0);
    for (int i = 1; i <= 1000; i++) years_days[i] = years_days[i - 1] + 365 + leap(i);
    scanf("%s%s", &a.kingname, &b.kingname);
    a.init();
    b.init();
    scanf("%ld", &m);
    while (m--) {
        scanf("%s", date);
        day = get_day(date);
        scanf("%s", s);
        if (strcmp(s, a.kingname) == 0) {
            pa = &a;
            pb = &b;
        } else {
            pa = &b;
            pb = &a;
        }
        pa->chose();
        scanf("%*s");
        pb->chose();
        battle(pa, pb);
    }
    if (a.win_times > b.win_times) printf("Winner:%s\nLoser:%s\n", a.kingname, b.kingname);
    else printf("Winner:%s\nLoser:%s\n", b.kingname, a.kingname);

    int qwe;
    scanf("%d", &qwe);

    return 0;
}                                 