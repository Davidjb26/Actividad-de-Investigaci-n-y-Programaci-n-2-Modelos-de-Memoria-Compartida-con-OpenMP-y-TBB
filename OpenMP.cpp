#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int N = 1000000;
    std::vector<int> A(N, 1); // Vector lleno de 1s
    std::vector<int> B(N, 2); // Vector lleno de 2s
    std::vector<int> C(N, 0); // Vector de resultados

    // Directiva OpenMP para paralelizar el ciclo constructivo
    #pragma omp parallel for
    for (int i = 0; i < N; ++i) {
        C[i] = A[i] + B[i];
    }

    std::cout << "Resultado en C[0]: " << C[0] << " (Esperado: 3)" << std::endl;
    return 0;
}
