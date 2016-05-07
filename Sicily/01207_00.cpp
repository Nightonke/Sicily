// Problem#: 1207
// Submission#: 3593474
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
/*
 * 2005 ACM Greater New York Regional Collegiate Programming Contest
 * Problem G -- No Fold'em Hold'em
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//#define   WIN_DEBUG
//#define   DEBUG
//#define SHOWDEBUG

enum HandValue {
    HIGH_CARD = 0,
    PAIR,
    TWO_PAIR,
    THREE_KIND,
    STRAIGHT,
    FLUSH,
    FULL_HOUSE,
    FOUR_KIND,
    STRAIGHT_FLUSH
};

#if defined(DEBUG) || defined(SHOWDEBUG)
const char *szHandNames[] = {
    "High Card",
    "Pair",
    "Two Pair",
    "Three-of-a-kind",
    "Straight",
    "Flush",
    "Full house",
    "Four-of-a-kind",
    "Straight Flush"
};
#endif

struct Hand {
    int m_nValue[5];        /* 2-14 */
    int m_nSuit[5];         /* Bit for suit */
    enum HandValue m_nHandValue;
    int m_nInt1;            /* Cards of interest */
    int m_nInt2;
    int m_nInt3;
};

static const char *szValues = "2233445566778899tTjJqQkKaA";
static const char *szSuits = "sSdDhHcC";

/*
 * Evaluates a hand.
 * Fills in the Hand structure with data necessary for later
 * comparisons.  The nHandValue member is the best hand
 * possible for these cards.  The m_nInt members are "cards
 * of interest" to settle tie breakers on hands that have the
 * same nHandValue.  Usually, nInt1 is the "biggest" of something.
 * For full house, its the 3-of-a-kind.  For 4-of-akind, its the
 * extra cards.  Int2 and Int3 follow as well.
 */
void EvalHand(const char **szCards, Hand *pHand)
{
    int i, j, tmp, isFlush = 0;
    const char *szCard, *p;

#ifdef DEBUG
    ::fprintf(stderr, "New hand\n");
#endif
    /* Convert cards */
    for(i = 0; i < 5; i++){
        szCard = *szCards++;
#ifdef DEBUG
        ::fprintf(stderr, "Card %d: \"%c%c\" = ", i, szCard[0], szCard[1]);
#endif
        /* Find value */
        p = ::strchr(szValues, *szCard);
        if(p == NULL){
            ::fprintf(stderr, "Bad card (%d) = \"%s\"\n", i, szCard);
            return;
        }
        pHand->m_nValue[i] = ((p - szValues)/2) + 2;
        if(pHand->m_nValue[i] < 2 || pHand->m_nValue[i] > 14){
            ::fprintf(stderr, "Crazy card?\n");
        }
        p = ::strchr(szSuits, *++szCard);
        if(p == NULL){
            ::fprintf(stderr, "Bad suit (%d) = \"%s\"\n", i, szCard-1);
            return;
        }
        pHand->m_nSuit[i] = 1 << ((p - szSuits)/2);
        /* Compute if flush as we go along */
        if(i == 0){
            isFlush  = pHand->m_nSuit[i];
        } else {
            isFlush &= pHand->m_nSuit[i];
        }
#ifdef DEBUG
        ::fprintf(stderr, " %2d %x\n", pHand->m_nValue[i], pHand->m_nSuit[i]);
#endif
    }
#ifdef DEBUG
    ::fprintf(stderr, "Flush: %s\n", isFlush ? "YES" : "NO");
    ::fprintf(stderr, "Sorted:\n");
#endif

    /* sort */
    for(i = 0; i < 5; i++){
        for(j = i+1; j < 5; j++){
            /* Swap if smaller */
            if(pHand->m_nValue[j] < pHand->m_nValue[i]){
                tmp = pHand->m_nValue[i];
                pHand->m_nValue[i] = pHand->m_nValue[j];
                pHand->m_nValue[j] = tmp;
                /* Suits too */
                tmp = pHand->m_nSuit[i];
                pHand->m_nSuit[i] = pHand->m_nSuit[j];
                pHand->m_nSuit[j] = tmp;
            }
        }
#ifdef DEBUG
        ::fprintf(stdout, "%d: %2d %x\n", i, pHand->m_nValue[i], pHand->m_nSuit[i]);
#endif
    }
    /* Check straight */
    for(i = 0; i < 3; i++){
        if(pHand->m_nValue[i]+1 != pHand->m_nValue[i+1]){
            break;
        }
    }
    /* First 4 cards are consecutive */
    if(i == 3){
        if(pHand->m_nValue[3]+1 == pHand->m_nValue[4] || (pHand->m_nValue[3] == 5 && pHand->m_nValue[4] == 14)){
            /* Interest card is the largest */
            pHand->m_nInt1 = (pHand->m_nValue[3] == 5 && pHand->m_nValue[4] == 14) ? 5 : pHand->m_nValue[4];
            /* If straight, can't be anything else but flush */
            if(isFlush){
                pHand->m_nHandValue = STRAIGHT_FLUSH;
            } else {
                pHand->m_nHandValue = STRAIGHT;
            }
            return;
        }
    }
    /* If flush, can't be anything else at this point */
    if(isFlush){
        pHand->m_nInt1 = pHand->m_nValue[4];
        pHand->m_nHandValue = FLUSH;
        return;
    }
    /* 4-kind? if first and 4th cards are the same, or 2nd and 5th are the same */
    if(pHand->m_nValue[0] == pHand->m_nValue[3]){
        pHand->m_nInt1 = pHand->m_nValue[3];
        pHand->m_nInt2 = pHand->m_nValue[4];
        pHand->m_nHandValue = FOUR_KIND;
        return;
    }
    if(pHand->m_nValue[1] == pHand->m_nValue[4]){
        pHand->m_nInt1 = pHand->m_nValue[3];
        pHand->m_nInt2 = pHand->m_nValue[0];
        pHand->m_nHandValue = FOUR_KIND;
        return;
    }
    /* Full house? */
    if(pHand->m_nValue[0] == pHand->m_nValue[1]){
        /* Candidate since first two cards match. Check last 3 cards being the same */
        if(pHand->m_nValue[2] == pHand->m_nValue[4]){
            /* Last 3 match */
            pHand->m_nHandValue = FULL_HOUSE;
            /* Int1 is the 3 of a kind */
            pHand->m_nInt1 = pHand->m_nValue[2];
            pHand->m_nInt2 = pHand->m_nValue[1];
            return;
        }
        /* See if 1st 3 cards the same */
        if(pHand->m_nValue[1] == pHand->m_nValue[2]){
            pHand->m_nInt1 = pHand->m_nValue[1];
            pHand->m_nInt2 = pHand->m_nValue[4];
            /* If last 2 cards same, and first 3 cards same */
            if(pHand->m_nValue[3] == pHand->m_nValue[4]){
                pHand->m_nHandValue = FULL_HOUSE;
                return;
            }
            pHand->m_nHandValue = THREE_KIND;
            pHand->m_nInt3 = pHand->m_nValue[3];
            return;
        }
        if(pHand->m_nValue[2] == pHand->m_nValue[3] || pHand->m_nValue[3] == pHand->m_nValue[4]){
            pHand->m_nHandValue = TWO_PAIR;
            pHand->m_nInt1 = pHand->m_nValue[3];
            pHand->m_nInt2 = pHand->m_nValue[0];
            if(pHand->m_nValue[2] == pHand->m_nInt1){
                pHand->m_nInt3 = pHand->m_nValue[4];
            } else {
                pHand->m_nInt3 = pHand->m_nValue[2];
            }
            return;
        }
        pHand->m_nInt1 = pHand->m_nValue[0];
        pHand->m_nHandValue = PAIR;
        return;
    }
    /* Check for more pairs, 3kind */
    if(pHand->m_nValue[1] == pHand->m_nValue[2]){
        if(pHand->m_nValue[2] == pHand->m_nValue[3]){
            pHand->m_nHandValue = THREE_KIND;
            pHand->m_nInt1 = pHand->m_nValue[2];
            pHand->m_nInt2 = pHand->m_nValue[4];
            pHand->m_nInt3 = pHand->m_nValue[0];
            return;
        }
        if(pHand->m_nValue[3] == pHand->m_nValue[4]){
            pHand->m_nInt1 = pHand->m_nValue[3];
            pHand->m_nInt2 = pHand->m_nValue[1];
            pHand->m_nInt3 = pHand->m_nValue[0];
            pHand->m_nHandValue = TWO_PAIR;
            return;
        }
        pHand->m_nInt1 = pHand->m_nValue[1];
        pHand->m_nHandValue = PAIR;
        return;
    }
    /* Check last 3 cards same */
    if(pHand->m_nValue[2] == pHand->m_nValue[3]){
        pHand->m_nInt1 = pHand->m_nValue[3];
        if(pHand->m_nValue[3] == pHand->m_nValue[4]){
            pHand->m_nHandValue = THREE_KIND;
            pHand->m_nInt2 = pHand->m_nValue[1];
            pHand->m_nInt3 = pHand->m_nValue[0];
            return;
        }
        pHand->m_nHandValue = PAIR;
        return;
    }
    if(pHand->m_nValue[3] == pHand->m_nValue[4]){
        pHand->m_nInt1 = pHand->m_nValue[3];
        pHand->m_nHandValue = PAIR;
        return;
    }
    pHand->m_nHandValue = HIGH_CARD;
    return;
}

/*
 * Compare the two hands.  return <0, 0, >0 as to whether
 * p1 is < p2, = p2 or > p2 in hand value
 */
int HandCmp(Hand *p1, Hand *p2)
{
    int i, n;

    if(p1->m_nHandValue < p2->m_nHandValue){
        return(-1);
    }
    if(p1->m_nHandValue > p2->m_nHandValue){
        return(1);
    }
    /* First tie breaker */
    i = p1->m_nInt1 - p2->m_nInt1;
    /* Same hand, see which one is better */
    switch(p1->m_nHandValue){
    case STRAIGHT_FLUSH:
    case FULL_HOUSE:
    case STRAIGHT:
    case FOUR_KIND:
        /* These are all the 5 card hands */
        if(i != 0){
            return(i);
        }
        return(p1->m_nInt2 - p2->m_nInt2);
        break;
    case TWO_PAIR:
    case THREE_KIND:
        /* Two comparisons may be needed */
        if(i != 0){
            return(i);
        }
        i = p1->m_nInt2 - p2->m_nInt2;
        if(i != 0){
            return(i);
        }
        return(p1->m_nInt3 - p2->m_nInt3);
        break;
    case PAIR:
        if(i != 0){
            return(i);
        }
        /* Fall through */
    case FLUSH:
    case HIGH_CARD:
        /* Card-by-card comparison */
        for(i = 4; i >= 0; i--){
            n = p1->m_nValue[i] - p2->m_nValue[i];
            /* First difference is deciding factor */
            if(n != 0){
                return(n);
            }
        }
        break;
    default:
        ::fprintf(stderr, "Hand type %d is invalid\n", p1->m_nHandValue);
        break;
    }
    return(0);
}

char *ShowCards(Hand *ph)
{
    static char szBuf[64];
    char *p;
    int i, j;

    for(p = &(szBuf[0]), i = 0; i < 5; i++){
        *p++ = szValues[(ph->m_nValue[i]-2)*2];
        if(p[-1] == '\0'){
            ::fprintf(stderr, "bad card\n");
        }
        for(j = 0; j < 4; j++){
            if(ph->m_nSuit[i] == (1<<j)){
                *p++ = szSuits[j*2];
                break;
            }
        }
        *p++ = ' ';
    }
    *p = '\0';
    return(&(szBuf[0]));
}

int bCards[4][13];

void RemoveCard(const char *s)
{
    const char *p = ::strchr(szValues, *s);
    int nC, nS;

    if(p == NULL){
        return;
    }
    nC = (p - szValues)/2;
    p = ::strchr(szSuits, s[1]);
    if(p == NULL){
        return;
    }
    nS = (p - szSuits)/2;

    if(bCards[nS][nC]){
        ::fprintf(stderr, "Duplicate card %s\n", s);
    }
    bCards[nS][nC] = 1;
}

#define MAX_HANDS   11
/* One hand for each card for each player */
Hand allHands[MAX_HANDS][52];

int main(int argc, char* argv[])
{
    char *cards[5], *s;
    int i, j, k, l, m, n, o, t, ns, nc, nDS, nh;
    Hand hand1, hand2, *p1, *p2, *pTmp;
    char szCards[MAX_HANDS][2][3];
    char szBoard[5][3];
    char ibuf[128];

    if(::fgets(&(ibuf[0]), sizeof(ibuf), stdin) == NULL){
        return 2;
    }
    nDS = ::atoi(&(ibuf[0]));
    if(nDS <= 0){
        return 1;
    }
    for(nh = 1; nh <= nDS; nh++){
        n = 2;
        ::memset(&(bCards[0][0]), '\0', sizeof(bCards));
        ::memset(&(allHands[0][0]), '\0', sizeof(allHands));

        for(i = 0; i < n; i++){
            if(::fgets(&(ibuf[0]), sizeof(ibuf), stdin) == NULL){
                ::fprintf(stderr, "eof in cards\n");
                break;
            }
            szCards[i][0][0] = ibuf[0];
            szCards[i][0][1] = ibuf[1];
            szCards[i][0][2] = '\0';
            szCards[i][1][0] = ibuf[2];
            szCards[i][1][1] = ibuf[3];
            szCards[i][1][2] = '\0';
            RemoveCard(&(szCards[i][0][0]));
            RemoveCard(&(szCards[i][1][0]));
        }
        if(i < n){
            break;
        }
        /* Read board */
        if(::fgets(&(ibuf[0]), sizeof(ibuf), stdin) == NULL){
            ::fprintf(stderr, "eof during board read\n");
            break;
        }
        s = &(ibuf[0]);
        /* Read board */
        for(i = 0; i < 4; i++){
            szBoard[i][0] = *s++;
            szBoard[i][1] = *s++;
            szBoard[i][2] = '\0';
            RemoveCard(&(szBoard[i][0]));
        }
        /* For each unused card compute hand for each player */
        for(ns = 0; ns < 4; ns++){
            for(nc = 0; nc < 13; nc++){
                /* Card used */
                if(bCards[ns][nc]){
                    continue;
                }
                /* This is the hand index (card number 0-51) */
                m = ns*13 + nc;
                /* For each player, try this card */
                for(i = 0; i < n; i++){
                    szBoard[4][0] = szValues[nc*2];
                    szBoard[4][1] = szSuits[ns*2];
                    szBoard[4][2] = '\0';

                    p2 = &(hand1);
                    p1 = NULL;
                    /* Choose 5 things from 7 */
                    for(j = 0; j < 7; j++){
                        for(k = j+1; k < 7; k++){
                            if(k == j){
                                continue;
                            }
                            for(o = 0, l = 0; l < 7; l++){
                                if(l == k || l == j){
                                    continue;
                                }
                                if(l < 5){
                                    cards[o] = &(szBoard[l][0]);
                                } else {
                                    cards[o] = &(szCards[i][l-5][0]);
                                }
                                o++;
                            }
                            if(o != 5){
                                ::fprintf(stderr, "Not enough cards\n");
                            }
                            EvalHand((const char **)&(cards[0]), p2);
#ifdef TRYDEBUG
                            ::fprintf(stdout, "Try: %s = %s\n", ShowCards(p2), szHandNames[p2->m_nHandValue]);
#endif
                            if(p1 == NULL){
                                p1 = p2;
                                p2 = &(hand2);
                            } else if(HandCmp(p1, p2) < 0){
                                pTmp = p1;
                                p1 = p2;
                                p2 = pTmp;
                            }
                        }
                    }
                    /* p1 is the best hand */
                    allHands[i][m] = *p1;
                }
            }
        }
#ifdef SHOWDEBUG
        for(ns = 0; ns < 4; ns++){
            for(nc = 0; nc < 13; nc++){
                /* Dont show cards that are part of the original deal */
                if(bCards[ns][nc]){
                    continue;
                }
                m = ns*13+nc;
                for(i = 0; i < n; i++){
                    ::fprintf(stdout, "%c%c %d: %s = %s\n", szValues[nc*2], szSuits[ns*2],
                        i, ShowCards(&(allHands[i][m])), szHandNames[allHands[i][m].m_nHandValue]);
                }
            }
        }
#endif
        int nWin[52], nTie[52], nt, nw;
        /* For each player */
        for(i = 0; i < n; i++){
            nt = 0;
            nw = 0;
            /* For every card */
            for(ns = 0; ns < 4; ns++){
                for(nc = 0; nc < 13; nc++){
                    /* Make sure its not used by a player */
                    if(bCards[ns][nc]){
                        continue;
                    }
                    m = ns*13+nc;
                    if(ns == 3 && nc == 9){
                        t = 0;
                    }
                    t = 0;
                    /* For every other player */
                    for(j = 0; j < n; j++){
                        /* Except us... */
                        if(j == i){
                            continue;
                        }
                        /* Compare this player's hand with each other player */
                        l = HandCmp(&(allHands[i][m]), &(allHands[j][m]));
                        /* Does he beat us? */
                        if(l < 0){
                            /* Yes, so throw this card away */
                            break;
                        } else if(l == 0){
                            /* Remember any ties */
                            t++;
                        }
                    }
                    if(j >= n){
                        /* We can make money */
                        if(t > 0){
                            /* We tied at least one player */
                            nTie[nt++] = m;
                        } else {
                            nWin[nw++] = m;
                        }
                    }
                }
            }
#ifdef WIN_DEBUG
            /* Print results */
            ::fprintf(stdout, "Player #%d: Wins:%d Ties:%d\n", i+1, nw, nt);
            ::fprintf(stdout, " Wins:");
            for(j = 0; j < nw; j++){
                ns = nWin[j]/13;
                nc = nWin[j]%13;
                fprintf(stdout, " %c%c", szValues[nc*2+1], szSuits[ns*2+1]);
            }
            ::fprintf(stdout, "\n");
            ::fprintf(stdout, " Ties:");
            for(j = 0; j < nt; j++){
                ns = nTie[j]/13;
                nc = nTie[j]%13;
                fprintf(stdout, " %c%c", szValues[nc*2+1], szSuits[ns*2+1]);
            }
            ::fprintf(stdout, "\n");
#else
            ::fprintf(stdout, "%d:", nh);
            if(nw > 0){
                for(j = 0; j < nw; j++){
                    if(j == 15 || j == 30 || j == 45){
                        ::fprintf(stdout, "\n  ");
                    }
                    ns = nWin[j]/13;
                    nc = nWin[j]%13;
                    fprintf(stdout, " %c%c", szValues[nc*2+1], szSuits[ns*2+1]);
                }
            } else if(nt > 0){
                for(j = 0; j < nt; j++){
                    if(j == 15 || j == 30 || j == 45){
                        ::fprintf(stdout, "\n  ");
                    }
                    ns = nTie[j]/13;
                    nc = nTie[j]%13;
                    fprintf(stdout, " %c%c", szValues[nc*2+1], szSuits[ns*2+1]);
                }
            } else {
                ::fprintf(stdout, " LOSER");
            }
            ::fprintf(stdout, "\n");
            /* Only do player 1 (really, 0) */
            break;
#endif
        }
    }
    return 0;
}                                 