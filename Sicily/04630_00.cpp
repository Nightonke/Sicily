// Problem#: 4630
// Submission#: 2701522
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
double area(double T[3][2]) {
    return T[0][0] * T[1][1] - T[1][0] * T[0][1] + T[1][0] * T[2][1] - T[2][0] * T[1][1] + T[2][0] * T[0][1] - T[0][0] * T[2][1] < 0 ? -(T[0][0] * T[1][1] - T[1][0] * T[0][1] + T[1][0] * T[2][1] - T[2][0] * T[1][1] + T[2][0] * T[0][1] - T[0][0] * T[2][1]) / 2 : (T[0][0] * T[1][1] - T[1][0] * T[0][1] + T[1][0] * T[2][1] - T[2][0] * T[1][1] + T[2][0] * T[0][1] - T[0][0] * T[2][1]) / 2;
}                                 