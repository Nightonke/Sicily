// Problem#: 1301
// Submission#: 3453650
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum TResult {
    WHITEWIN = 1,
    BLACKWIN,
    STALEMATE,
    DRAW,
    DEAD,
    PUZZLE,
    ILLEGAL
};

const char RESULT[8][20] = {
    "",
    "White Win",
    "Black Win",
    "Stalemate",
    "Draw",
    "Dead Moves",
    "Puzzle Move",
    "Illegal Move"
};

enum TPieceType {
    SPACE = 0,
    PAWN,
    KING,
    QUEEN,
    ROOK,
    BISHOP,
    KNIGHT
};

enum TSide {
    NONE = 0,
    WHITE,
    BLACK
};

typedef struct {
    TSide side;
    TPieceType pt;
}TPiece;

typedef TPiece TBoard[8][8];

int n;
TResult result;
bool wc, bc, w0rm, w7rm, b0rm, b7rm, wkm, bkm;

TPieceType ChessType(char * mv) {
    switch(mv[0]) {
    case 'K': return KING;
    case 'Q': return QUEEN;
    case 'R': return ROOK;
    case 'B': return BISHOP;
    case 'N': return KNIGHT;
    }
    return PAWN;
}

void clear(TBoard b, int x, int y) {
    b[x][y].side = NONE;
    b[x][y].pt = SPACE;
}

void init(TBoard b) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            clear(b, i, j);
        }
    }
    for (int i = 0; i < 8; i++) {
        b[0][i].side = b[1][i].side = WHITE;
        b[1][i].pt = PAWN;
        b[7][i].side = b[6][i].side = BLACK;
        b[6][i].pt = PAWN;
    }
    b[0][0].pt = b[0][7].pt = b[7][7].pt = b[7][0].pt = ROOK;
    b[0][1].pt = b[0][6].pt = b[7][6].pt = b[7][1].pt = KNIGHT;
    b[0][2].pt = b[0][5].pt = b[7][2].pt = b[7][5].pt = BISHOP;
    b[0][3].pt = b[7][3].pt = QUEEN;
    b[0][4].pt = b[7][4].pt = KING;
}

void skipInput(int k) {
    char temp[20];
    for (int i = k; i < n; i++) 
        scanf("%s", temp);
}

bool outOfBoard(int x, int y) {
    if (x < 0 || y < 0) return true;
    if (x >= 8 || y >= 8) return true;
    return false;
}

bool canMoveP(TBoard b, int x, int y, int x2, int y2, int flag) {
    if (flag == 1) {
        if (y != y2 || b[x2][y2].side != NONE) return false;
        if (b[x][y].side == WHITE) {
            if (x == 1) {
                return (x2 == 2 || (x2 == 3 && b[2][y].side == NONE));
            } else {
                return x2 == x + 1;
            }
        } else {
            if (x == 6) return (x2 == 5 || (x2 == 4 && b[5][y].side == NONE));
            else return x2 == x - 1;
        }
    } else {
        if (b[x][y].side == WHITE) {
            return (x2 == x + 1 && abs(y2 - y) == 1);
        } else {
            return (x2 == x - 1 && abs(y2 - y) == 1);
        }
    }
    return false;
}

bool canMoveK(TBoard b, int x, int y, int x2, int y2) {
    return (abs(x - x2) <= 1 && abs(y - y2) <= 1);
}

bool canMoveR(TBoard b, int x, int y, int x2, int y2) {
    int dx, dy, xx, yy;
    if (x != x2 && y != y2) return false;
    if (x2 < x) dx = -1;
    else dx = 1;
    if (y2 < y) dy = -1;
    else dy = 1;
    if (x == x2) {
        for (int i = 1; i < abs(y - y2); i++) {
            yy = y + i * dy;
            if (b[x][yy].side != NONE) return false;
        }
        return true;
    }
    for (int i = 1; i < abs(x - x2); i++) {
        xx = x + i * dx;
        if (b[xx][y].side != NONE) return false;
    }
    return true;
}

bool canMoveB(TBoard b, int x, int y, int x2, int y2) {
    int dx, dy, xx, yy;
    if (abs(x - x2) != abs(y - y2)) return false;
    if (x2 < x) dx = -1;
    else dx = 1;
    if (y2 < y) dy = -1;
    else dy = 1;
    for (int i = 1; i < abs(x - x2); i++) {
        xx = x + i * dx;
        yy = y + i * dy;
        if (b[xx][yy].side != NONE) return false;
    }
    return true;
}

bool canMoveQ(TBoard b, int x, int y, int x2, int y2) {
    return canMoveR(b, x, y, x2, y2) || canMoveB(b, x, y, x2, y2);
}

bool canMoveN(int x, int y, int x2, int y2) {
    int xx = abs(x - x2), yy = abs(y - y2);
    return (xx + yy == 3 && (xx == 1 || yy == 1));
}

bool canMove(TBoard b, int x, int y, int x2, int y2, int flag) {
    if (outOfBoard(x, y) || outOfBoard(x2, y2)) return false;
    if (b[x][y].side == NONE) return false;
    switch (b[x][y].pt) {
    case PAWN: return canMoveP(b, x, y, x2, y2, flag);
    case KING: return canMoveK(b, x, y, x2, y2);
    case QUEEN: return canMoveQ(b, x, y, x2, y2);
    case ROOK: return canMoveR(b, x, y, x2, y2);
    case BISHOP: return canMoveB(b, x, y, x2, y2);
    case KNIGHT: return canMoveN(x, y, x2, y2);
    }
    return false;
}

void chessMove(TBoard b, int x, int y, int x2, int y2) {
    b[x2][y2].side = b[x][y].side;
    b[x2][y2].pt = b[x][y].pt;
    clear(b, x, y);
}

void getP(char * s, int & x2, int & y2) {
    int k = 0;
    if (s[0] < 'a') k = 1;
    x2 = s[k + 1] - '1';
    y2 = s[k] - 'a';
}

void getSourceP(TBoard b, int x2, int y2, int & x, int & y, TPieceType ct, TSide side) {
    int flag = 1;
    if (b[x2][y2].side != NONE) flag = 2;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (b[i][j].side == side && b[i][j].pt == ct) {
                if (canMove(b, i, j, x2, y2, flag)) {
                    if (x == -1) {
                        x = i;
                        y = j;
                    } else {
                        x = -2;
                        return;
                    }
                }
            }
        }
    }
}

void markRM(TSide s, int x, int y) {
    if (s == WHITE) {
        if (x == 0) {
            if (y == 0) w0rm = true;
            if (y == 7) w7rm = true;
        }
        return;
    }
    if (x == 7) {
        if (y == 0) b0rm = true;
        if (y == 7) b7rm = true;
    }
}

void move(TBoard b, char * s, TSide side) {
    int x, y, x2, y2;
    getP(s, x2, y2);
    if (b[x2][y2].side == side) {
        result = ILLEGAL;
        return;
    }
    x = -1;
    getSourceP(b, x2, y2, x, y, ChessType(s), side);
    if (x == -1) {
        result = ILLEGAL;
        return;
    }
    if (x == -2) {
        result = PUZZLE;
        return;
    }
    if (b[x][y].pt == ROOK) markRM(side, x, y);
    if (b[x][y].pt == KING) {
        if (side == WHITE) wkm = true;
        else bkm = true;
    }
    chessMove(b, x, y, x2, y2);
}

TSide opp(TSide side) {
    if (side == BLACK) return WHITE;
    return BLACK;
}

bool beAttack(TBoard b, int x, int y, TSide byWho) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (b[i][j].side == byWho && canMove(b, i, j, x, y, 2)) return true;
        }
    }
    return false;
}

bool canCastle(TBoard b, TSide side, int flag) {
    int row;
    if (side == WHITE) {
        if (wkm) return false;
        if (flag == 3 && w7rm) return false;
        if (flag == 5 && w0rm) return false;
    } else {
        if (bkm) return false;
        if (flag == 3 && b7rm) return false;
        if (flag == 5 && b0rm) return false;
    }
    if (side == WHITE) row = 0;
    else row = 7;
    if (flag == 5) {
        for (int i = 1; i < 4; i++) {
            if (b[row][i].side != NONE) return false;
        }
        for (int i = 0; i < 5; i++) {
            if (beAttack(b, row, i, opp(side))) return false;
        }
    } else {
        for (int i = 5; i < 7; i++) {
            if (b[row][i].side != NONE) return false;
        }
        for (int i = 4; i < 8; i++) {
            if (beAttack(b, row, i, opp(side))) return false;
        }
    }
    return true;
}

void getKP(TBoard b, TSide side, int & x, int & y) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (b[i][j].pt == KING && b[i][j].side == side) {
                x = i;
                y = j;
                return;
            }
        }
    }
}

bool beCheck(TBoard b, TSide side) {
    int x, y;
    TSide op;
    getKP(b, side, x, y);
    op = opp(side);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (b[i][j].side == op && canMove(b, i, j, x, y, 2)) return true;
        }
    }
    return false;
}

void copyB(TBoard b2, TBoard b) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            b2[i][j].pt = b[i][j].pt;
            b2[i][j].side = b[i][j].side;
        }
    }
}

bool noMove(TBoard b, TSide side) {
    int x, y, x2, y2;
    TBoard b2;
    for (x = 0; x < 8; x++) {
        for (y = 0; y < 8; y++) {
            if (b[x][y].side == side) {
                for (x2 = 0; x2 < 8; x2++) {
                    for (y2 = 0; y2 < 8; y2++) {
                        if ((x2 != x || y2 != y) && b[x][y].side != b[x2][y2].side && canMove(b, x, y, x2, y2, 1)) {
                            if (b[x][y].pt == KING) {
                                copyB(b2, b);
                                chessMove(b2, x, y, x2, y2);
                                if (!beCheck(b2, side)) {
                                    return false;
                                }
                            } else {
                                return false;
                            }
                        }
                    }
                }
            }
        }
    }
    return true;
}

void castle(TBoard b, TSide side, int flag) {
    int row;
    if (side == WHITE) {
        if (wc) {
            result = ILLEGAL;
            return;
        } else {
            wc = true;
        }
    } else {
        if (bc) {
            result = ILLEGAL;
            return;
        } else {
            bc = true;
        }
    }
    if (canCastle(b, side, flag)) {
        if (side == WHITE) {
            row = 0;
        } else {
            row = 7;
        }
        if (flag == 3) {
            chessMove(b, row, 4, row, 6);
            chessMove(b, row, 7, row, 5);
        } else {
            chessMove(b, row, 4, row, 2);
            chessMove(b, row, 0, row, 3);
        }
    } else {
        result = ILLEGAL;
    }
}

bool checkEnd(TBoard b, TSide side) {
    int x, y, x2, y2;
    TBoard b2;
    if (!beCheck(b, side)) return false;
    for (x = 0; x < 8; x++) {
        for (y = 0; y < 8; y++) {
            if (b[x][y].side == side) {
                for (x2 = 0; x2 < 8; x2++) {
                    for (y2 = 0; y2 < 8; y2++) {
                        if ((x != x2 || y != y2) && b[x2][y2].side != side) {
                            if (canMove(b, x, y, x2, y2, 1)) {
                                copyB(b2, b);
                                chessMove(b2, x, y, x2, y2);
                                if (!beCheck(b2, side)) return false;
                            }
                            if (b[x][y].pt == PAWN && canMove(b, x, y, x2, y2, 2)) {
                                copyB(b2, b);
                                chessMove(b2, x, y, x2, y2);
                                if (!beCheck(b2, side)) return false;
                            }
                        }
                    }
                }
            }
        }
    }
    return true;
}

void run(TBoard b) {
    char s[20];
    TSide side;
    side = WHITE;
    for (int i = 0; i < n; i++) {
        if (result == WHITEWIN || result == BLACKWIN || result == STALEMATE) {
            result = DEAD;
            skipInput(i);
            return;
        }
        scanf("%s", s);
        if (s[0] != 'O') move(b, s, side);
        else castle(b, side, strlen(s));
        if (beCheck(b, side)) result = ILLEGAL;
        if (result == PUZZLE || result == ILLEGAL) {
            skipInput(i + 1);
            return;
        }
        if (checkEnd(b, opp(side))) {
            if (side == WHITE) {
                result = WHITEWIN;
            } else {
                result = BLACKWIN;
            }
        }
        side = opp(side);
    }
    if (result == DRAW && noMove(b, side)) result = STALEMATE;
}

int main() {

    //std::ios::sync_with_stdio(false);

    TBoard b;

    while (scanf("%d", &n), n > 0) {
        init(b);
        result = DRAW;
        wc = bc = w0rm = w7rm = b0rm = b7rm = wkm = bkm = false;
        run(b);
        printf("%s\n", RESULT[result]);
    }

    return 0;
}                                 