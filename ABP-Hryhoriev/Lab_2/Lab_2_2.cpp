#include <iostream>
#include <cmath>

using namespace std;


double calculate_an(int n) {
    return pow(-1.0, n) * (1.0 - (2.0 * n - 1.0) / (2.0 * (n + 1.0)));
}


double sum_with_precision(double epsilon) {
    double sum = 0.0, sum_ten = 0.0;
    int n = 1;
    double term = calculate_an(n);


    while (fabs(term) > epsilon) {
        sum += term;
        n++;
        term = calculate_an(n);
        // if (n == 9)
        // {
        //     sum_ten = sum;
        // }
    }

    return sum;
}


double sum_first_10_terms() {
    double sum = 0.0;
    for (int n = 1; n <= 10; ++n) {
        sum += calculate_an(n);
    }
    return sum;
}


int Lab_2_2() {

    double epsilon = 0.000001;


    double sum_precise = sum_with_precision(epsilon);
    cout << "Suma riadu z tochniistiu do " << epsilon << ": " << sum_precise << endl;


    double sum_10_terms = sum_first_10_terms();
    cout << "Suma pershykh 10 chleniv riadu: " << sum_10_terms << endl;

    return 0;
}


