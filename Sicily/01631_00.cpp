// Problem#: 1631
// Submission#: 3593591
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
/*
 * Triangular garden solution
 * by Fred Pickel
 * October 2008
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;

#define MAX_PROBS   100
#define EPS .001
#define ERR .001

char inbuf[512];
double inx[3], iny[3];
double outfx[2], outfy[2];
double outdfx[2], outdfy[2];

int matsolve(double coefs[6][4], double soln[])
{
    int i, j, k, maxloc, currow;
    double maxval, tmp;
    int solrow[6], freecol;

    currow = 0;
    freecol = -1;
    for(j = 0; j < 4; j++)
    {
        /* find pivot */
        maxloc = currow; maxval = fabs(coefs[currow][currow]);
        for(i = currow+1; i < 6; i++)
        {
            tmp = fabs(coefs[i][j]);
            if(tmp > maxval)
            {
                maxval = tmp;
                maxloc = i;
            }
        }
        if(maxval < EPS)
        {   /* zero pivot */
            freecol = j;
            solrow[j] = -1;
            continue;
        }
        solrow[j] = currow;
        /* if maxloc != currow. swap rows */
        if(maxloc != currow)
        {
            for(i = j ; i < 4; i++)
            {
                tmp = coefs[currow][i];
                coefs[currow][i] = coefs[maxloc][i];
                coefs[maxloc][i] =tmp;
            }
        }
        /* div pivot row by leading coeff */
        tmp = 1.0/coefs[currow][j];
        for(i = j; i < 4; i++)
        {
            coefs[currow][i] *= tmp;
        }
        /* for each row other than currow, subtract mult of currow to kill coef in j col */
        for(k = 0; k < 6 ; k++)
        {
            if(k == currow)
            {
                continue;
            }
            tmp = coefs[k][j];
            for(i = j; i < 4; i++)
            {
                coefs[k][i] -= tmp * coefs[currow][i];
            }
        }
        currow++;
    }
    /* now extract soln */
    if(freecol == -1)
    {   /* no (non-zero) soln */
        return -1;
    }
    soln[freecol] = -1.0;
    for(j = 0; j < 4; j++)
    {
        if(solrow[j] == -1)
        {
            continue;
        }
        soln[j] = coefs[solrow[j]][freecol];
    }
    return 0;
}
/*
 * direct method:
 * center of ellipse = centroid of triangle (true for circle in equilateral triangle, unchanged by skewing/stretching)
 * subtract out center point from vertices so
 * ellipse eqn A*x*x +B*x*y + G*y*y + F = 0 mustbe satisfied at side midpoits 
 * ((x0 + x1)/2, (y0 + y1)/2), ((x0 + x2)/2, (y0 + y2)/2), ((x2 + x1)/2, (y2 + y1)/2)
 * and normal to ellipe <2*A*x + B*y, B*x + 2*G*y> must be perpendicular to
 * edge at each midpoint
 * six eqns, four unknowns three eqns redundant solve for A, B, G, in terms of F
 * rotate ellipe to align with axis to get
 * a*x*x + c*y*y = -F
 * rotate x = xp*cos(t) - yp*sin(t) = xp*C - yp*S  y = xp*S + yp*C
 * substitute:
 * A*(xp*xp*C*C - 2*xp*yp*S*C +yp*yp*S*S) + B*(xp*xp*C*S + xp*yp*(C*C - S*S) - yp*yp*C*S)
 * + G*(xp*xp*S*S + 2*xp*yp*C*S + yp*yp*C*C) + F =
 * xp*xp*(A*C*C + B*C*S + G*S*S) + xp*yp*(-2*A*S*C + B*(C*C - S*S) + 2*G*C*S) +
 * yp*yp*(A*S*S - B*C*S + G*C*C) + F
 * to make coeff of xp*yp go away:
 * 2*S*C*(A-G) =B*(C*C - S*S) => 2*S*C/(C*C-S*S) = B/(A-G) = sin(2t)/cos(2t) = tan(2t)
 * t = 1/2arctan(B/(G-A))
 * a = (A*C*C + B*C*S + G*S*S) g = (A*S*S - B*C*S + G*C*C)
 * get foci for this ellipse, translate and rotateback to original position
 * xp vertices (yp = 0) = +-sqrt(-F/a)
 * yp vertices (xp = 0) = +-sqrt(-F/g)
 * if(g > a) major axis along xp dist center to focus = sqrt(xvert^2 - yvert^2)
 * = sqrt(-F/a + F/g) else sqrt(-F/g + F/a)
 * get rope length as sum of dist (f0, edge midpoint) +  dist (f1, edge midpoint)
 */
int EllipseDirect(double*x, double *y, double *fx, double *fy, double *pLength)
{
    double midx[3], midy[3], vx[3], vy[3], cen[2];
    double coef[6][4], coef2[6][4], v[6];
    double soln[4], theta, s, c, a, g, flen;
    int i, j;
    /* computer center andsubtrat from vertices */
    cen[0] = (x[0] + x[1] + x[2])/3.0;
    cen[1] = (y[0] + y[1] + y[2])/3.0;
    x[0] -= cen[0]; x[1] -= cen[0]; x[2] -= cen[0]; 
    y[0] -= cen[1]; y[1] -= cen[1]; y[2] -= cen[1]; 
    /* compute midpts and vectors for side opposite index vertex */
    midx[0] = (x[1] + x[2]) * 0.5; midy[0] = (y[1] + y[2]) * 0.5; vx[0] = x[2] - x[1]; vy[0] = y[2] -y[1];
    midx[1] = (x[0] + x[2]) * 0.5; midy[1] = (y[0] + y[2]) * 0.5; vx[1] = x[2] - x[0]; vy[1] = y[2] -y[0];
    midx[2] = (x[1] + x[0]) * 0.5; midy[2] = (y[1] + y[0]) * 0.5; vx[2] = x[0] - x[1]; vy[2] = y[0] -y[1];
    /* build coeff matrix */
    for(i = 0; i < 3; i++)
    {
        coef[i][0] = midx[i] * midx[i]; coef[i][1] = midx[i] * midy[i] ; coef[i][2] = midy[i]*midy[i];
        coef[i][3] = 1.0;
        coef[i+3][0] = 2.0 * midx[i] * vx[i];
        coef[i+3][1] = midy[i] * vx[i] + midx[i] * vy[i];
        coef[i+3][2] = 2.0 * midy[i] * vy[i];
        coef[i+3][3] = 0.0;
    }
    for(i = 0; i < 6; i++)
    {
        for(j = 0; j < 4; j++)
            coef2[i][j] = coef[i][j];
    }
    if(matsolve(coef, soln) != 0)
    {
        return -1;
    }
    for(i = 0; i < 6; i++)
    {
        v[i] = 0.0;
        for(j = 0; j < 4; j++)
            v[i] += coef2[i][j] * soln[j];
    }
    if((-soln[3]) < EPS)
    {
        return -2;
    }
    theta =0.5*atan2(soln[1], soln[0] - soln[2]);
    s = sin(theta); c = cos(theta);
    a = soln[0]*c*c + soln[1]*c*s + soln[2]*s*s;
    g = soln[2]*c*c - soln[1]*c*s + soln[0]*s*s;
    /* eqn: a*xp*xp + g*yp*yp = -F => xp*xp/g + yp*yp/a = -F/(a*g) */ 
    /* if yp= 0, xp = +- sqrt(-F/a), if xp = 0, yp = +- sqrt(-F/g) (veritces ofrotated ellipse) */
    if(g > a)
    {   /* major axis along xp */
        *pLength = 2.0 * sqrt(-soln[3]/a);
        flen = sqrt(-soln[3]/a + soln[3]/g); /* sqrt(major axis^2 - minor axis ^ 2) */
        if(flen < EPS)
        {   /* circle */
            fx[0] = fx[1] = cen[0];
            fy[0] = fy[1] = cen[1];
        }
        else if((c > 0.0) || ((c == 0.0) && (s > 0.0)))
        {   /* get dx and dy from xp, c and s */
            fx[0] = cen[0] - flen*c;
            fy[0] = cen[1] - flen*s;
            fx[1] = cen[0] + flen*c;
            fy[1] = cen[1] + flen*s;
        }
        else
        {
            fx[1] = cen[0] - flen*c;
            fy[1] = cen[1] - flen*s;
            fx[0] = cen[0] + flen*c;
            fy[0] = cen[1] + flen*s;
        }
    }
    else
    {   /* major axis along yp */
        *pLength = 2.0 * sqrt(-soln[3]/g);
        flen = sqrt(-soln[3]/g + soln[3]/a); /* sqrt(major axis^2 - minor axis ^ 2) */
        if(flen < EPS)
        {   /* circle */
            fx[0] = fx[1] = cen[0];
            fy[0] = fy[1] = cen[1];
        }
        else if((s < 0.0) || ((s == 0.0) && (c > 0.0)))
        {   /* get dx and dy from yp, c and s */
            fx[0] = cen[0] + flen*s;
            fy[0] = cen[1] - flen*c;
            fx[1] = cen[0] - flen*s;
            fy[1] = cen[1] + flen*c;
        }
        else
        {
            fx[1] = cen[0] + flen*s;
            fy[1] = cen[1] - flen*c;
            fx[0] = cen[0] - flen*s;
            fy[0] = cen[1] + flen*c;
        }
    }
    return 0;
}

/*
 * sneaky method:
 * Marden's Theorem:
 * Let p(z) be a third degree polynomial with complex coefficents,
 * and whose roots z0, z1,z2 are non-collinear points in the complex plane.
 * LetT be the triangle with verticesat z0, z1 and z2. There is a unique ellipse
 * inscribed in T and tangent to the sides at their midpoints. The foci  of this ellipse
 * are the roots of p'(z)
 * p(Z) = Z^3 - (z0 + z1 + z2)*Z^2 + (z0*z1 + z0*z2 + z1*z2) * Z + z0*z1*z2
 *      = Z^3 + B*Z^2 +C*Z +D
 * p'(Z) = 3*Z^2 -2*(z0 + z1 + z2)*Z + (z0*z1 + z0*z2 + z1*z2)
 * the roots ofp'(Z) are
 * Z = (-b +-sqrt(b*b - 4*a*c))/2a
 *   = (2*(z0 + z1 + z2) +-sqrt(4*(z0 + z1 + z2)*(z0 + z1 + z2) - 4*3*(z0*z1 + z0*z2 + z1*z2)))/6
 *   = (z0 + z1 + z2)/3 +- sqrt(z0*z0 + z1*z1 + z2*z2 - z0*z1 - z0*z2 - z1*z2)/3
 */
int EllipseMarden(double*x, double *y, double *fx, double *fy, double *pLength)
{
    double B[2], C[2], disc[2], ang, mag, mid[2];
    B[0] = x[0] + x[1] + x[2];
    B[1] = y[0] + y[1] + y[2];
    C[0] = (x[0]*x[1] - y[0]*y[1] + x[2]*x[1] - y[2]*y[1] + x[0]*x[2] - y[0]*y[2]);
    C[1] = (x[0]*y[1] + y[0]*x[1] + x[2]*y[1] + y[2]*x[1] + x[0]*y[2] + y[0]*x[2]);
    disc[0] = B[0]*B[0] - B[1]*B[1] - 3*C[0];
    disc[1] = 2.0*B[0]*B[1] - 3*C[1];
    mag = sqrt(disc[0]*disc[0] + disc[1]*disc[1]);
    mag = sqrt(mag);
    if(mag < EPS)
    {   /* circle */
        fx[0] = fx[1] = B[0]/3.0;
        fy[0] = fy[1] = B[1]/3.0;
        ang = 0.0;
    }
    else
    {
        ang= atan2(disc[1], disc[0]);
        if((cos(ang/2) > 0) || ((cos(ang/2) == 0) && (sin(ang/2) > 0)))
        {
            fx[0] = (B[0] - mag*cos(ang/2))/3.0;
            fx[1] = (B[0] + mag*cos(ang/2))/3.0;
            fy[0] = (B[1] - mag*sin(ang/2))/3.0;
            fy[1] = (B[1] + mag*sin(ang/2))/3.0;
        }
        else
        {
            fx[0] = (B[0] + mag*cos(ang/2))/3.0;
            fx[1] = (B[0] - mag*cos(ang/2))/3.0;
            fy[0] = (B[1] + mag*sin(ang/2))/3.0;
            fy[1] = (B[1] - mag*sin(ang/2))/3.0;
        }
    }
    mid[0] = (x[0] + x[1])/2.0;
    mid[1] = (y[0] + y[1])/2.0;
    mag = sqrt((fx[0] - mid[0]) * (fx[0] - mid[0]) + (fy[0] - mid[1]) * (fy[0] - mid[1]));
    mag += sqrt((fx[1] - mid[0]) * (fx[1] - mid[0]) + (fy[1] - mid[1]) * (fy[1] - mid[1]));
    *pLength = mag;
    return 0;
}

bool isSame(double a, double b) {
    return fabs(a - b) < EPS;
}

int main()
{
    int probCnt, curProb, ret;
    double dlen, ddlen;

    if(fgets(&(inbuf[0]), 255, stdin) == NULL)
    {
        fprintf(stderr, "read failed on problem count\n");
        return -1;
    }
    inbuf[255] = 0;
    probCnt = atoi(&(inbuf[0]));
    if((probCnt < 1) || (probCnt > MAX_PROBS))
    {
        fprintf(stderr, "Problem count %d not in range 1...%d\n", probCnt, MAX_PROBS);
        return -2;
    }
    for(curProb = 1; curProb <= probCnt ; curProb++)
    {
        if(fgets(&(inbuf[0]), 255, stdin) == NULL)
        {
            fprintf(stderr, "read failed on problem %d\n", curProb);
            return -3;
        }
        if(sscanf(&(inbuf[0]), "%lf %lf %lf %lf %lf %lf",
            &(inx[0]), &(iny[0]), &(inx[1]), &(iny[1]), &(inx[2]), &(iny[2])) != 6)
        {
            fprintf(stderr, "scan failed on problem %d\n", curProb);
            return -4;
        }
            /*
        // eityher one of the two methods is sufficient
        if((ret = EllipseMarden(inx, iny, outfx, outfy, &dlen)) != 0)
        {
            fprintf(stderr, "EllipseMarden returned %d on problem %d\n", ret, curProb);
        }
        else if((ret = EllipseDirect(inx, iny, outdfx, outdfy, &ddlen)) != 0)
        {
            fprintf(stderr, "EllipseDirect returned %d on problem %d\n", ret, curProb);
        }
        else if((fabs(outfx[0] - outdfx[0]) > ERR) || (fabs(outfx[1] - outdfx[1]) > ERR) || 
            (fabs(outfy[0] - outdfy[0]) > ERR) || (fabs(outfy[1] - outdfy[1]) > ERR) ||
            (fabs(dlen - ddlen) > ERR))
        {   // testing that both methods give the same result
            fprintf(stderr, "Problem %d different answers\n", curProb);
            fprintf(stderr, "Marden %.4f %.4f %.4f %.4f %.4f\n",
                outfx[0], outfy[0], outfx[1], outfy[1], dlen);
            fprintf(stderr, "Direct %.4f %.4f %.4f %.4f %.4f\n",
                outdfx[0], outdfy[0], outdfx[1], outdfy[1], ddlen);
        }
        else
        {
            printf("%d %.2f %.2f %.2f %.2f %.2f\n",
                curProb, outfx[0], outfy[0], outfx[1], outfy[1], dlen);
        }
        */
        EllipseMarden(inx, iny, outfx, outfy, &dlen);
        if (outfx[0] > outfx[1]) swap(outfx[0], outfx[1]), swap(outfy[0], outfy[1]);
        else if (isSame(outfx[0], outfx[1]) && outfy[0] > outfy[1]) swap(outfy[0], outfy[1]);
        printf("%d %.2f %.2f %.2f %.2f %.2f\n",
                curProb, outfx[0], outfy[0], outfx[1], outfy[1], dlen);
    }
    return 0;
}                                 