#include <iostream>
using namespace std;

int Lab_4() {
    const short S = 9;
    short Ar[S][S];
    short l = 0, r = 0;
    short r1 = 0, r2 = S - 1;
    short dd = 1;
    short k = 1;


    short top = 0, bottom = S - 1;
    short left = 0, right = S - 1;


    while (k <= S * S) {

        for (r = left; r <= right; ++r) {
            Ar[top][r] = k++;
        }
        top++;


        for (l = top; l <= bottom; ++l) {
            Ar[l][right] = k++;
        }
        right--;


        for (r = right; r >= left; --r) {
            Ar[bottom][r] = k++;
        }
        bottom--;


        for (l = bottom; l >= top; --l) {
            Ar[l][left] = k++;
        }
        left++;
    }


    for (l = 0; l < S; ++l) {
        for (r = 0; r < S; ++r) {
            cout << Ar[l][r] << "\t";
        }
        cout << endl;
    }

    return 0;
}
