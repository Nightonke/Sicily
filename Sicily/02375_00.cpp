// Problem#: 2375
// Submission#: 3593627
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
/*
 * H - Scanning UPC Barcodes
 * ACM International Collegiate Programming Contest
 * Greater New York Region
 * October 24, 2010
 */

#include <stdio.h>
#include <math.h>

typedef unsigned char BYTE;
typedef unsigned short WORD;

#define FIRST_SCAN_COUNT    50
#define SECOND_SCAN_COUNT   45
#define MAX_UPCS        12

// bit pattern for left digit codes (LSB is rightmost band
BYTE lpattern[10] = 
{
    0x0d, 0x19, 0x13, 0x3d, 0x23, 0x31, 0x2f, 0x3b, 0x37, 0x0b
};
// bit pattern for righ digit codes (LSB is rightmost band
BYTE rpattern[10] = 
{
    0x72, 0x66, 0x6c, 0x42, 0x5c, 0x4e, 0x50, 0x44, 0x48, 0x74
};

// digits of found upcs for a given problem instance
char upcvals[MAX_UPCS][12];

// for a given problem instance
// bit 6-i of fwdvals[j] is 1 if the i band of digit code j is a '1' else 0
// bit 6-i of fwdmasks[j] is 1 if the i band of digit code j is not a '?'
// thus if (lpattern[k] & fwdmasks[j]) == fwdvals[j], lpattern[k] matches
// all non-? characters of digit code j so k is a valid digit at location j
BYTE fwdvals[12], fwdmasks[12];
// bit 6-i of backvals[j] is 1 if the i band of digit code j reading in reverse order is a '1' else 0
// bit 6-i of backmasks[j] is 1 if the i band of digit code j reading in reverse order is not a '?'
BYTE backvals[12], backmasks[12];

// bit i of fwddigits[j] is 1 if i is a valid digit for location j in the upc
// bit i of backdigits[j] is 1 if i is a valid digit for location j in the upc
// when read backwards
WORD fwddigits[12], backdigits[12];

// number of codes found for this problem instance so far
int numCodes;

char inbuf[256];

// read data for a single problem instance
// return < 0 for parse errors
// return > 0 if start middle or end code is not valid
// otherwise, fill in fwdvals, fwdmasks, backvals and backmasks
// and return 0
int ParseInData(int probnum)
{
    int i, j, k, ret;
    char c1, c2, c3, c4, c5;
    BYTE frmask, fval, brmask, bval, fmask, bmask;

    ret = 0;
    // get first row of data
    if(fgets(&(inbuf[0]), 255, stdin) == NULL) {
        fprintf(stderr, "Read failed on problem %d first row data\n", probnum);
        return -11;
    }
    // chack format
    for(i = 0; i < 50 ; i++) {
        c1 = inbuf[i];
        if((c1 != '0') && (c1 != '1') && (c1 != '?')) {
            fprintf(stderr, "bad %d char 0x%x on problem %d  first row data\n",
                i, c1, probnum);
            return -12;
        }
    }
    // check start
    c1 = inbuf[0]; c2 = inbuf[1]; c3 = inbuf[2];
    if(((c1 != '1') && (c1 != '?')) || 
        ((c2 != '0') && (c2 != '?')) ||
        ((c3 != '1') && (c3 != '?'))) {
        ret = 1;
    }
    // check middle
    c1 = inbuf[45]; c2 = inbuf[46]; c3 = inbuf[47]; c4 = inbuf[48]; c5 = inbuf[49];
    if(((c1 != '0') && (c1 != '?')) || 
        ((c2 != '1') && (c2 != '?')) ||
        ((c3 != '0') && (c3 != '?')) ||
        ((c4 != '1') && (c4 != '?')) ||
        ((c5 != '0') && (c5 != '?'))) {
        ret = 2;
    }
    // get first 6 digits of data
    for(i = 0, j = 3; i < 6 ; i++, j += 7) {
        frmask = fval = brmask = bval = 0;
        fmask = 0x40;
        bmask = 0x01;
        for(k = 0; k < 7 ; k++) {
            c1 = inbuf[j+k];
            if(c1 == '0') { // valid and blank
                frmask |= fmask;
                brmask |= bmask;
            } else if(c1 == '1') { // valid and bar
                frmask |= fmask;
                brmask |= bmask;
                fval |= fmask;
                bval |= bmask;
            }   // else unknown char
            fmask >>= 1;
            bmask <<= 1;
        }
        fwdvals[i] = fval;
        fwdmasks[i] = frmask;
        backvals[11 - i] = bval;
        backmasks[11 - i] = brmask;
    }
    // get second row of data
    if(fgets(&(inbuf[0]), 255, stdin) == NULL) {
        fprintf(stderr, "Read failed on problem %d second row data\n", probnum);
        return -15;
    }
    // check format
    for(i = 0; i < 45 ; i++) {
        c1 = inbuf[i];
        if((c1 != '0') && (c1 != '1') && (c1 != '?')) {
            fprintf(stderr, "bad %d char 0x%x on problem %d  second row data\n",
                i, c1, probnum);
            return -16;
        }
    }
    // check end
    c1 = inbuf[42]; c2 = inbuf[43]; c3 = inbuf[44];
    if(((c1 != '1') && (c1 != '?')) || 
        ((c2 != '0') && (c2 != '?')) ||
        ((c3 != '1') && (c3 != '?'))) {
        fprintf(stderr, "bad end code %c%c%c on problem %d  data\n",
            c1, c2, c3, probnum);
        ret = 3;
    }
    // get second 6 digits of data
    for(i = 0, j = 0; i < 6 ; i++, j += 7) {
        frmask = fval = brmask = bval = 0;
        fmask = 0x40;
        bmask = 0x01;
        for(k = 0; k < 7 ; k++) {
            c1 = inbuf[j+k];
            if(c1 == '0') { // valid and blank
                frmask |= fmask;
                brmask |= bmask;
            } else if(c1 == '1') { // valid and bar
                frmask |= fmask;
                brmask |= bmask;
                fval |= fmask;
                bval |= bmask;
            }   // else unknown
            fmask >>= 1;
            bmask <<= 1;
        }
        fwdvals[6+i] = fval;
        fwdmasks[6+i] = frmask;
        backvals[5 - i] = bval;
        backmasks[5 - i] = brmask;
    }
    return ret;
}

// for a single problem instance
// using fwdvals, fwdmasks, backvals and backmasks computed in ParseInData,
// compute fwddigits and back digits
void GetDigits()
{
    int i, j;
    WORD outmask;
    for(i = 0; i < 12; i++) {
        fwddigits[i] = backdigits[i] = 0;
    }
    // left digits
    for(i = 0; i < 6; i++) {
        outmask = 1;
        for(j = 0; j < 10 ; j++) {
            if((lpattern[j] & fwdmasks[i]) == fwdvals[i]) {
                // j is a valid digit for location i
                fwddigits[i] |= outmask;
            }
            if((lpattern[j] & backmasks[i]) == backvals[i]) {
                // j is a valid digit for location i (reversed)
                backdigits[i] |= outmask;
            }
            outmask <<= 1;
        }
    }
    // right digits
    for(i = 6; i < 12; i++) {
        outmask = 1;
        for(j = 0; j < 10 ; j++) {
            if((rpattern[j] & fwdmasks[i]) == fwdvals[i]) {
                // j is a valid digit for location i
                fwddigits[i] |= outmask;
            }
            if((rpattern[j] & backmasks[i]) == backvals[i]) {
                // j is a valid digit for location i (reversed)
                backdigits[i] |= outmask;
            }
            outmask <<= 1;
        }
    }
}

// compute check digit value for first 11 digits in upcDigits
char CompCheckDigit(char *upcDigits)
{
    int sum;
    sum = upcDigits[0] + upcDigits[2] + upcDigits[4] +
            upcDigits[6] + upcDigits[8] + upcDigits[10];
    sum = sum * 3 + upcDigits[1] + upcDigits[3] +
            upcDigits[5] + upcDigits[7] + upcDigits[9];
    sum = sum % 10;
    if(sum == 0) return 0;
    else return (char)(10 - sum);
}

// recursive check of valid upc codes
// index is which digit we are processing
// upc is the current upc code to this point
// fwdValid != 0 if we got here via fwdDigits
// backValid != 0 if we got here via backDigits
// NOTE that since we test upc codes in nnumerical order
// they will be added to the upcvals array in numeric order
void CheckValidCodes(int index, char *upc, char fwdValid, char backValid)
{
    char digit, newfwd, newback;
    int i;
    WORD mask;
    // check too many codes
    if(numCodes >= MAX_UPCS) {
        return;
    }
    // end case
    if(index == 11) {   // check digit
        digit = CompCheckDigit(upc);
        mask = (1 << digit);
        if((fwdValid && ((mask & fwddigits[11]) != 0)) ||
            (backValid && ((mask & backdigits[11]) != 0))) {
            // if the check digit is valid for the last location in either
            // direction and all previous digits are OK, it is a match, save it
            upc[11] = digit;
            for(i = 0; i < 12 ; i++) {
                upcvals[numCodes][i] = '0' + upc[i];
            }
            numCodes++;
        }
    }
    else { // scan through all digit possibilities
        for(digit = 0, mask = 1; digit < 10 ; digit ++, mask <<= 1) {
            newfwd = newback = 0;
            if(fwdValid && ((mask & fwddigits[index]) != 0)) newfwd = 1;
            if(backValid && ((mask & backdigits[index]) != 0)) newback = 1;
            // if this digit (and all previous digits match either forward or back
            // save the current digit and make a recursive call for the next digit
            if(newfwd || newback) {
                upc[index] = digit;
                CheckValidCodes(index+1, upc, newfwd, newback);
            }
        }
        // check too many codes
        if(numCodes >= MAX_UPCS) {
            return;
        }
    }
}

void PrintSoln(int probnum)
{
    int i;
    if(numCodes == 0) {
        printf("%d 0\n", probnum);  // no codes to print
        return;
    } else if(numCodes > 8) {
        printf("%d 9\n", probnum, numCodes);
        // only print the first 8
        numCodes = 8;
    } else {
        printf("%d %d\n", probnum, numCodes);
    }
    for(i = 0; i < numCodes ; i++) {
        printf("%c%c%c%c%c%c%c%c%c%c%c%c\n", 
            upcvals[i][0], upcvals[i][1], upcvals[i][2],
            upcvals[i][3], upcvals[i][4], upcvals[i][5],
            upcvals[i][6], upcvals[i][7], upcvals[i][8],
            upcvals[i][9], upcvals[i][10], upcvals[i][11]);
    }
}

// if start, middle and end match, find all upc codes that match
// fwdvals, fwdmasks, backvals and backmasks already computed in ParseInData
int FindUPCs(int probnum)
{
    char curUpc[12];
    GetDigits();    // get fwddigits and backdigits
    numCodes = 0;   // init count to 0
    CheckValidCodes(0, &(curUpc[0]), 1, 1); // recursively find (at most MAX_UPCS) matching upc codes
    PrintSoln(probnum); // print the ones we found
    return 0;
}

int main()
{
    int nprob, curprob, index, ret;

    if(fgets(&(inbuf[0]), 255, stdin) == NULL)
    {
        fprintf(stderr, "Read failed on problem count\n");
        return -1;
    }
    if(sscanf(&(inbuf[0]), "%d", &nprob) != 1)
    {
        fprintf(stderr, "Scan failed on problem count\n");
        return -2;
    }
    for(curprob = 1; curprob <= nprob ; curprob++)
    {
        if(fgets(&(inbuf[0]), 255, stdin) == NULL)
        {
            fprintf(stderr, "Read failed on problem %d data\n", curprob);
            return -3;
        }
        if(sscanf(&(inbuf[0]), "%d", &index) != 1)
        {
            fprintf(stderr, "Scan failed on problem %d data\n", curprob);
            return -4;
        }
        if(index != curprob)
        {
            fprintf(stderr, "problem index %d not = expected problem %d\n",
                index, curprob);
            return -7;
        }
        ret = ParseInData(curprob);
        if(ret > 0) {   // start middle or end did not match so no solutions
            printf("%d 0\n", curprob);
        } else if(ret == 0) {   // data to process
            FindUPCs(curprob);
        } else {    // bad input format (should not happen)
            return ret;
        }
    }
    return 0;
}                                 