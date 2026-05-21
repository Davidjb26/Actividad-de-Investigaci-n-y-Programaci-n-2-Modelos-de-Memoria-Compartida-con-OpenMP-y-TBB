#include <iostream>
#include <vector>
#include <oneapi/tbb.h>

int main() {
    const int N = 1000000;
    std::vector<int> A(N, 1);
    std::vector<int> B(N, 2);
    std::vector<int> C(N, 0);

    // Paralelización usando el parallel_for y rangos genéricos de TBB
    tbb::parallel_for(tbb::blocked_range<size_t>(0, N), [&](const tbb::blocked_range<size_t>& r) {
        for (size_t i = r.begin(); i != r.end(); ++i) {
            C[i] = A[i] + B[i];
        }
    });

    std::cout << "Resultado en C[0]: " << C[0] << " (Esperado: 3)" << std::endl;
    return 0;
}
