// Problem#: 2373
// Submission#: 3593621
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
/*
 * F - I2C
 * ACM International Collegiate Programming Contest
 * Greater New York Region
 * October 24, 2010
 */     

#include <stdio.h>
#include <stdlib.h>

char buf[128];
char *p = NULL;

void GetSample(int &scl, int &sda)
{
    scl = sda = 0;
    for(;;){
        if(p == NULL || *p == '\0'){
            p = ::fgets(&(buf[0]), sizeof(buf), stdin);
            if(p == NULL){
                break;
            }
        }
        if(*p == '0' || *p == '1'){
            scl = *p - '0';
            p++;
            sda = *p - '0';
            p++;
            break;
        } else {
            p++;
        }
    }
}

int main(int argc, char **argv)
{
    int i, nByteCount, nProb, np, nb, scl, sda, nState, nAddr, nFlag, nBit, nByte, nLastDa;

    ::fgets(&(buf[0]), sizeof(buf), stdin);
    nProb = ::atoi(&(buf[0]));

    for(i = 1; i <= nProb; i++){
        if(::fgets(&(buf[0]), sizeof(buf), stdin) == NULL){
            break;
        }
        if(::sscanf(&(buf[0]), "%d %d", &(np), &(nb)) != 2){
            break;
        }
        nState = 0;
        nByteCount = 0;
        p = NULL;
        while(nState >= 0 && nb > 0){
            nb--;
            GetSample(scl, sda);
            switch(nState){
            case 0:  // waiting for clock high and data high
                if(scl == 1 && sda == 1){
                    nState++;
                }
                break;

            case 1: // waiting for data to go low with clock high
                if(scl == 0){
                    nState = 0;
                } else {
                    if(sda == 0){
                        // got start
                        nState++;
                        // Flag indicates we are doing the first byte (addr)
                        nFlag = 0;
                        nBit = 0;
                        nByte = 0;
                        nLastDa = 0;
                    }
                }
                break;

            case 2: // getting a byte - wait for clock low
                if(scl == 0){
                    nState++;
                } else {
                    if(nLastDa == 0 && sda == 1){
                        // SDA was brought high while clock was high, this is a stop
                        nState = -1;
                    }
                }
                break;

            case 3: // wait for clock high, then save bit
                if(scl == 1){
                    nLastDa = sda;
                    nByte = (nByte << 1) | sda;
                    nBit++;
                    if(nBit == 8){
                        if(nFlag == 0){
                            nAddr = nByte;
                        }
                        nState++;
                    } else {
                        // wait for clock to go low for next bit
                        nState = 2;
                    }
                }
                break;

            case 4: // got last bit of byte. wait for clock high and data low for ack
                if(scl == 1){
                    if(sda == 0){
                        nState++;
                        if(nFlag == 0){
                            nFlag = 1;
                        } else {
                            nByteCount++;
                        }
                        nByte = 0;
                        nBit = 0;
                        nState = 2;
                    }
                    nLastDa = sda;
                }
                break;
            }
        }
        // Gotta suck up rest of data even though we dont care about it since we saw a stop
        while(nb-- > 0){
            GetSample(scl, sda);
        }
        switch(nState){
        case 0:
        case 1:
            printf("%d ERROR NO START BIT\n", i);
            break;
        case 2:
        case 3:
            printf("%d ERROR NO STOP BIT\n", i);
            break;
        case 4:
            if(nByteCount == 0){
                printf("%d ERROR NO ACK FROM SLAVE %02X\n", i, nAddr >> 1);
            } else {
                printf("%d ERROR NO ACK FOR DATA\n", i);
            }
            break;
        case -1:
            printf("%d %s OF %d BYTES %s SLAVE %02x\n",
                i, (nAddr & 1) ? "READ" : "WRITE",
                nByteCount,
                (nAddr & 1) ? "FROM" : "TO",
                nAddr >> 1);
            break;

        default:
            printf("%d GENERAL ERROR %d SHOULDNT HAPPEN\n", i, nState);
            break;
        }
    }
    return(0);
}                                 