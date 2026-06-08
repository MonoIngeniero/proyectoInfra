#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>

using namespace std;
using namespace std::chrono;

double promedio(const vector<long long>& datos) {
    double suma = 0;

    for (long long x : datos)
        suma += x;

    return suma / datos.size();
}

double desviacionEstandar(const vector<long long>& datos, double media) {

    double suma = 0;

    for (long long x : datos)
        suma += pow(x - media, 2);

    return sqrt(suma / (datos.size() - 1));
}

// ==========================
// VERSION A
// float + acceso [k][i]
// ==========================

float versionA(const vector<vector<float>>& A,
               const vector<float>& v,
               int n) {

    float result = 0.0f;

    for (int i = 0; i < n; i++)
        for (int k = 0; k < n; k++)
            result += A[k][i] * v[i] * v[k];

    return result;
}

// ==========================
// VERSION B
// float + acceso [i][k]
// ==========================

float versionB(const vector<vector<float>>& B,
               const vector<float>& v,
               int n) {

    float result = 0.0f;

    for (int i = 0; i < n; i++)
        for (int k = 0; k < n; k++)
            result += B[i][k] * v[i] * v[k];

    return result;
}

// ==========================
// VERSION C
// double + acceso [k][i]
// ==========================

double versionC(const vector<vector<double>>& C,
                const vector<double>& v,
                int n) {

    double result = 0.0;

    for (int i = 0; i < n; i++)
        for (int k = 0; k < n; k++)
            result += C[k][i] * v[i] * v[k];

    return result;
}

int main() {

    const int muestras = 30;

    for (int n : {64,128,256,512,1024,2048}) {

        cout << "\n========================================\n";
        cout << "N = " << n << endl;

        // --------------------
        // Datos float
        // --------------------

        vector<vector<float>> A(n, vector<float>(n));
        vector<float> vf(n);

        // --------------------
        // Datos double
        // --------------------

        vector<vector<double>> C(n, vector<double>(n));
        vector<double> vd(n);

        // Inicialización

        for (int i = 0; i < n; i++) {

            vf[i] = (i % 100) + 1;
            vd[i] = (i % 100) + 1;

            for (int j = 0; j < n; j++) {

                A[i][j] = (i + j) % 100;

                C[i][j] = (i + j) % 100;
            }
        }

        vector<long long> tiemposA;
        vector<long long> tiemposB;
        vector<long long> tiemposC;

        float resultadoA = 0;
        float resultadoB = 0;
        double resultadoC = 0;

        for (int rep = 0; rep < muestras; rep++) {

            // ==========
            // VERSION A
            // ==========

            auto inicioA = high_resolution_clock::now();

            resultadoA = versionA(A, vf, n);

            auto finA = high_resolution_clock::now();

            tiemposA.push_back(
                duration_cast<microseconds>(finA - inicioA).count()
            );

            // ==========
            // VERSION B
            // ==========

            auto inicioB = high_resolution_clock::now();

            resultadoB = versionB(A, vf, n);

            auto finB = high_resolution_clock::now();

            tiemposB.push_back(
                duration_cast<microseconds>(finB - inicioB).count()
            );

            // ==========
            // VERSION C
            // ==========

            auto inicioC = high_resolution_clock::now();

            resultadoC = versionC(C, vd, n);

            auto finC = high_resolution_clock::now();

            tiemposC.push_back(
                duration_cast<microseconds>(finC - inicioC).count()
            );
        }

        double mediaA = promedio(tiemposA);
        double mediaB = promedio(tiemposB);
        double mediaC = promedio(tiemposC);

        double desvA = desviacionEstandar(tiemposA, mediaA);
        double desvB = desviacionEstandar(tiemposB, mediaB);
        double desvC = desviacionEstandar(tiemposC, mediaC);

        cout << "\nVERSION A (float, [k][i])\n";
        cout << "Resultado: " << resultadoA << endl;
        cout << "Media: " << mediaA << " us\n";
        cout << "Desviacion: " << desvA << " us\n";

        cout << "\nVERSION B (float, [i][k])\n";
        cout << "Resultado: " << resultadoB << endl;
        cout << "Media: " << mediaB << " us\n";
        cout << "Desviacion: " << desvB << " us\n";

        cout << "\nVERSION C (double, [k][i])\n";
        cout << "Resultado: " << resultadoC << endl;
        cout << "Media: " << mediaC << " us\n";
        cout << "Desviacion: " << desvC << " us\n";
    }

    return 0;
}