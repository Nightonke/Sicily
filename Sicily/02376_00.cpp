// Problem#: 2376
// Submission#: 3593630
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
/*
 * I - Cutting The Cake
 * ACM International Collegiate Programming Contest
 * Greater New York Region
 * October 24, 2010
 */

#include <stdio.h>
#include <math.h>

#define EPS (.00001)
/*
 * (below <XY> = vector from point X to point Y and |V| = magnitude of vector V)
 * we have a triangle with vertices A, B, C with the length of
 * the side opposite A, B or C being a, b or c, respectively
 * a line intersects the triangle on side AB at a fraction x (0<= x<= 1)
 * of the distance from A to B and intersects the side AC at a fraction
 * y of the distance from A to C
 *               A
 *              / \
 *          x*c/    \  y*b
 *            /       \
 *         -----------------------
 *          /            \
 *         B______________C
 *
 * the area of the triangle: Area = 1/2 |<AB> X <AC>| (cross product)
 * the area of the triangle cut off by the line is
 * 1/2 | (x *<AB>) X (y * <AC>)| = 1/2*x*y * Area (of entire triangle)
 * perimeter of entire triangle = a+b+c
 * part of perimeter cut off by the line is x*c + y*b
 *
 * If the line is an equalizer for the triangle:
 * cutoff area = 1/2 triangel area => x*y = 1/2
 * cutoff perimeter = 1/2 trinagle perimeter =>
 * x*c + y*b = 1/2(a+b+c)
 * Solving:
 *  y = ((1/2)(a+b+c) - x*c)/b
 *  x * (((1/2)(a+b+c) - x*c)/b = 1/2
 * clear denominators:
 *  x*(a+b+c) - 2*c*x*x = b OR
 *  2*c*x^2 - (a+b+c)*x + b = 0;
 *  x = [(a+b+c) +- sqrt((a+b+c)^2 - 8*b*c)]/4*c
 *  y = [(a+b+c) -+ sqrt((a+b+c)^2 - 8*b*c)]/4*b
 *
 * we need to try this for each choice of cut off vertex A, B or C
 * to find a case where ((a+b+c)^2 - 8*b*c) >= 0 AND
 * x and y are between 0 and 1 (including 1)
 *
 * when found we have two points on the equalizer line
 * (x0,y0) = A + x * <AB>
 * (x1,y1) + A + y * <AC>
 * the equation of the line is
 * (y1 - y0)*X + (x1- x0)*Y = (y1 - y0)*x0 + (x1- x0)*y0
 */

/*
 * check solns of
 *  x = [(a+b+c) +- sqrt((a+b+c)^2 - 8*b*c)]/4*c
 *  y = [(a+b+c) -+ sqrt((a+b+c)^2 - 8*b*c)]/4*b
 * return number of real solns with 0 < x,y <= 1
 * pSoln should have 4 slots
 * pSoln[0] = first soln x   pSoln[1] = first soln y 
 * pSoln[2] = second soln x   pSoln[3] = second soln y 
 */
int CheckEqSolns(double a, double b, double c, double *pSoln)
{
    double perim, discr, x, y;
    int ret = 0;
    perim = a+b+c;
    discr = perim*perim - 8*b*c;
    if(discr < 0) {
        return 0;
    }
    discr = sqrt(discr);
    x = (perim + discr)/(4.0*c);
    y = (perim - discr)/(4.0*b);
    if((x > 0.0) && (x <= (1.0 + EPS)) && (y > 0.0) && (y <= (1.0 + EPS))) {
        ret++;
        pSoln[0] = x;
        pSoln[1] = y;
    }
    x = (perim - discr)/(4.0*c);
    y = (perim + discr)/(4.0*b);
    if((x > 0.0) && (x <= (1.0 + EPS)) && (y > 0.0) && (y <= (1.0 + EPS))) {
        pSoln[2*ret] = x;
        pSoln[2*ret+1] = y;
        ret++;
    }
    return ret;
}

int FindEqualizer(double *pVerts, double *pResult)
{
    double vAB[2], vAC[2], vBC[2], soln[4];
    double a, b, c, x0, y0, x1, y1, denom;
    vAB[0] = pVerts[2] - pVerts[0];
    vAB[1] = pVerts[3] - pVerts[1];
    vAC[0] = pVerts[4] - pVerts[0];
    vAC[1] = pVerts[5] - pVerts[1];
    vBC[0] = pVerts[4] - pVerts[2];
    vBC[1] = pVerts[5] - pVerts[3];
    a = sqrt(vBC[0]*vBC[0] + vBC[1]*vBC[1]);
    b = sqrt(vAC[0]*vAC[0] + vAC[1]*vAC[1]);
    c = sqrt(vAB[0]*vAB[0] + vAB[1]*vAB[1]);
    if(fabs(a-b) < EPS) {   // isoceles vertes at c
        x0 = pVerts[4];
        y0 = pVerts[5];
        x1 = 0.5*(pVerts[0] + pVerts[2]);
        y1 = 0.5*(pVerts[1] + pVerts[3]);
    }
    else if(fabs(a-c) < EPS) {  // isoceles vertes at b
        x0 = pVerts[2];
        y0 = pVerts[3];
        x1 = 0.5*(pVerts[0] + pVerts[4]);
        y1 = 0.5*(pVerts[1] + pVerts[5]);
    }
    else if(fabs(b-c) < EPS) {  // isoceles vertes at b
        x0 = pVerts[0];
        y0 = pVerts[1];
        x1 = 0.5*(pVerts[2] + pVerts[4]);
        y1 = 0.5*(pVerts[3] + pVerts[5]);
    }
    else if(CheckEqSolns(a, b, c, &(soln[0])) > 0) { // soln crossin AB and AC
        x0 = pVerts[0] + vAB[0]*soln[0];
        y0 = pVerts[1] + vAB[1]*soln[0];
        x1 = pVerts[0] + vAC[0]*soln[1];
        y1 = pVerts[1] + vAC[1]*soln[1];
    }
    else if(CheckEqSolns(b, c, a, &(soln[0])) > 0) { // soln crossing BC and BA
        x0 = pVerts[2] + vBC[0]*soln[0];
        y0 = pVerts[3] + vBC[1]*soln[0];
        x1 = pVerts[2] - vAB[0]*soln[1];
        y1 = pVerts[3] - vAB[1]*soln[1];
    }
    else if(CheckEqSolns(c, a, b, &(soln[0])) > 0) { // soln crossing CA and CB
        x0 = pVerts[4] - vAC[0]*soln[0];
        y0 = pVerts[5] - vAC[1]*soln[0];
        x1 = pVerts[4] - vBC[0]*soln[1];
        y1 = pVerts[5] - vBC[1]*soln[1];
    }
    else {
        return -1;
    }
    a = y1 - y0;
    b = -(x1-x0);
    if(a < 0.0) {
        a = -a;
        b = -b;
    }
    denom = sqrt(a*a + b*b);
    pResult[0] = a/denom;
    pResult[1] = b/denom;
    pResult[2] = (a*x0 + b*y0)/denom;
    return 0;
}

char inbuf[256];
int main()
{
    int nprob, curprob, index;
    double invals[6], result[3];

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
        if(sscanf(&(inbuf[0]), "%d %lf %lf %lf %lf %lf %lf", &index,
            &(invals[0]), &(invals[1]), &(invals[2]),
            &(invals[3]), &(invals[4]), &(invals[5])) != 7)
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
        if(FindEqualizer(&(invals[0]), &(result[0])) == 0) {
            printf("%d %.5f %.5f %.5f\n", curprob,
                result[0], result[1], result[2]);
        } else {
            printf("no soln found\n");
        }
    }
    return 0;
}                                 