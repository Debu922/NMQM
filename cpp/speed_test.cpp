#include <iostream>
#include <chrono>
#include <random>
#include <functional>
#include <cmath>
#include <complex>

class Rand_double
{
public:
    Rand_double(double low, double high)
        : r(std::bind(std::uniform_real_distribution<>(low, high), std::default_random_engine())) {}

    double operator()() { return r(); }

private:
    std::function<double()> r;
};

int main()
{
    long N;
    long logN_max = 18;
    long iter = 10;
    auto start = std::chrono::steady_clock::now();
    auto finish = std::chrono::steady_clock::now();
    Rand_double rd{-1e2, 1e2};
    std::complex<double> img(0.0, 1.0);

    // Integer Addition
    std::cout << "Integer Addition" << std::endl;
    N = 1;
    for (long logN = 0; logN < logN_max; logN++)
    {
std::cout<<logN<<"\t";
        for (long iter_no = 0; iter_no < iter; iter_no++)
        {
            long A[N], B[N], S[N];
            for (long i = 0; i < N; i++)
            {
                A[i] = rand();
                B[i] = rand();
            }
            start = std::chrono::steady_clock::now();
            for (long i = 0; i < N; i++)
            {
                S[i] = A[i] + B[i];
            }
            finish = std::chrono::steady_clock::now();
            std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "\t";
        }
        std::cout << std::endl;
        N = N * 2;
    }

    // Integer Multiplication
    std::cout << "Integer Multiplication" << std::endl;
    N = 1;
    for (long logN = 0; logN < logN_max; logN++)
    {
std::cout<<logN<<"\t";
        for (long iter_no = 0; iter_no < iter; iter_no++)
        {
            long A[N], B[N], S[N];
            for (long i = 0; i < N; i++)
            {
                A[i] = rand();
                B[i] = rand();
            }
            start = std::chrono::steady_clock::now();
            for (long i = 0; i < N; i++)
            {
                S[i] = A[i] * B[i];
            }
            finish = std::chrono::steady_clock::now();
            std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "\t";
        }
        std::cout << std::endl;
        N = N * 2;
    }

    // Integer Division
    std::cout << "Integer Division" << std::endl;
    N = 1;
    for (long logN = 0; logN < logN_max; logN++)
    {
std::cout<<logN<<"\t";
        for (long iter_no = 0; iter_no < iter; iter_no++)
        {
            long A[N], B[N], S[N];
            for (long i = 0; i < N; i++)
            {
                A[i] = rand();
                B[i] = rand();
                if (B[i] == 0)
                    B[i] = 1;
            }
            start = std::chrono::steady_clock::now();
            for (long i = 0; i < N; i++)
            {
                S[i] = A[i] / B[i];
            }
            finish = std::chrono::steady_clock::now();
            std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "\t";
        }
        std::cout << std::endl;
        N = N * 2;
    }

    // Integer Accumulation
    std::cout << "Integer Accumulation" << std::endl;
    N = 1;
    for (long logN = 0; logN < logN_max; logN++)
    {
std::cout<<logN<<"\t";
        for (long iter_no = 0; iter_no < iter; iter_no++)
        {
            long A[N];
            long S = 0;
            for (long i = 0; i < N; i++)
            {
                A[i] = rand();
            }
            start = std::chrono::steady_clock::now();
            for (long i = 0; i < N; i++)
            {
                S += A[i];
            }
            finish = std::chrono::steady_clock::now();
            std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "\t";
        }
        std::cout << std::endl;
        N = N * 2;
    }

    // Real Addition
    std::cout << "Real Addition" << std::endl;
    N = 1;
    for (long logN = 0; logN < logN_max; logN++)
    {
std::cout<<logN<<"\t";
        for (long iter_no = 0; iter_no < iter; iter_no++)
        {
            double A[N], B[N], S[N];
            for (long i = 0; i < N; i++)
            {
                A[i] = rd();
                B[i] = rd();
            }
            start = std::chrono::steady_clock::now();
            for (long i = 0; i < N; i++)
            {
                S[i] = A[i] + B[i];
            }
            finish = std::chrono::steady_clock::now();
            std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "\t";
        }
        std::cout << std::endl;
        N = N * 2;
    }

    // Real Multiplication
    std::cout << "Real Multiplication" << std::endl;
    N = 1;
    for (long logN = 0; logN < logN_max; logN++)
    {
std::cout<<logN<<"\t";
        for (long iter_no = 0; iter_no < iter; iter_no++)
        {
            double A[N], B[N], S[N];
            for (long i = 0; i < N; i++)
            {
                A[i] = rd();
                B[i] = rd();
            }
            start = std::chrono::steady_clock::now();
            for (long i = 0; i < N; i++)
            {
                S[i] = A[i] * B[i];
            }
            finish = std::chrono::steady_clock::now();
            std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "\t";
        }
        std::cout << std::endl;
        N = N * 2;
    }

    // Real Division
    std::cout << "Real Division" << std::endl;
    N = 1;
    for (long logN = 0; logN < logN_max; logN++)
    {
std::cout<<logN<<"\t";
        for (long iter_no = 0; iter_no < iter; iter_no++)
        {
            double A[N], B[N], S[N];
            for (long i = 0; i < N; i++)
            {
                A[i] = rd();
                B[i] = rd();
                if (B[i] == 0)
                    B[i] = 1;
            }
            start = std::chrono::steady_clock::now();
            for (long i = 0; i < N; i++)
            {
                S[i] = A[i] / B[i];
            }
            finish = std::chrono::steady_clock::now();
            std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "\t";
        }
        std::cout << std::endl;
        N = N * 2;
    }

    // Real Accumulation
    std::cout << "Real Accumulation" << std::endl;
    N = 1;
    for (long logN = 0; logN < logN_max; logN++)
    {
std::cout<<logN<<"\t";
        for (long iter_no = 0; iter_no < iter; iter_no++)
        {
            double A[N];
            double S = 0;
            for (long i = 0; i < N; i++)
            {
                A[i] = rd();
            }
            start = std::chrono::steady_clock::now();
            for (long i = 0; i < N; i++)
            {
                S += A[i];
            }
            finish = std::chrono::steady_clock::now();
            std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "\t";
        }
        std::cout << std::endl;
        N = N * 2;
    }

    // Real Sin
    std::cout << "Real Sin" << std::endl;
    N = 1;
    for (long logN = 0; logN < logN_max; logN++)
    {
std::cout<<logN<<"\t";
        for (long iter_no = 0; iter_no < iter; iter_no++)
        {
            double A[N], S[N];
            for (long i = 0; i < N; i++)
            {
                A[i] = rd();
            }
            start = std::chrono::steady_clock::now();
            for (long i = 0; i < N; i++)
            {
                S[i] = sin(A[i]);
            }
            finish = std::chrono::steady_clock::now();
            std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "\t";
        }
        std::cout << std::endl;
        N = N * 2;
    }

    // Real Exp
    std::cout << "Real Exp" << std::endl;
    N = 1;
    for (long logN = 0; logN < logN_max; logN++)
    {
std::cout<<logN<<"\t";
        for (long iter_no = 0; iter_no < iter; iter_no++)
        {
            double A[N], S[N];
            for (long i = 0; i < N; i++)
            {
                A[i] = rd();
            }
            start = std::chrono::steady_clock::now();
            for (long i = 0; i < N; i++)
            {
                S[i] = sin(A[i]);
            }
            finish = std::chrono::steady_clock::now();
            std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "\t";
        }
        std::cout << std::endl;
        N = N * 2;
    }

    // Real log
    std::cout << "Real log" << std::endl;
    N = 1;
    for (long logN = 0; logN < logN_max; logN++)
    {
std::cout<<logN<<"\t";
        for (long iter_no = 0; iter_no < iter; iter_no++)
        {
            double A[N], S[N];
            for (long i = 0; i < N; i++)
            {
                A[i] = rd();
            }
            start = std::chrono::steady_clock::now();
            for (long i = 0; i < N; i++)
            {
                S[i] = log(A[i]);
            }
            finish = std::chrono::steady_clock::now();
            std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "\t";
        }
        std::cout << std::endl;
        N = N * 2;
    }

    // Complex Additon
    std::cout << "Complex Addition" << std::endl;
    N = 1;
    for (long logN = 0; logN < logN_max; logN++)
    {
std::cout<<logN<<"\t";
        for (long iter_no = 0; iter_no < iter; iter_no++)
        {
            std::complex<double> A[N], B[N], S[N];
            for (long i = 0; i < N; i++)
            {
                A[i] = rd() + rd() * img;
                B[i] = rd() + rd() * img;
            }
            start = std::chrono::steady_clock::now();
            for (long i = 0; i < N; i++)
            {
                S[i] = A[i] + B[i];
            }
            finish = std::chrono::steady_clock::now();
            std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "\t";
        }
        std::cout << std::endl;
        N = N * 2;
    }

    // Complex Multiplcation
    std::cout << "Complex Multiplicaition" << std::endl;
    N = 1;
    for (long logN = 0; logN < logN_max; logN++)
    {
std::cout<<logN<<"\t";
        for (long iter_no = 0; iter_no < iter; iter_no++)
        {
            std::complex<double> A[N], B[N], S[N];
            for (long i = 0; i < N; i++)
            {
                A[i] = rd() + rd() * img;
                B[i] = rd() + rd() * img;
            }
            start = std::chrono::steady_clock::now();
            for (long i = 0; i < N; i++)
            {
                S[i] = A[i] * B[i];
            }
            finish = std::chrono::steady_clock::now();
            std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "\t";
        }
        std::cout << std::endl;
        N = N * 2;
    }

    // Complex Divison
    std::cout << "Complex Division" << std::endl;
    N = 1;
    for (long logN = 0; logN < logN_max; logN++)
    {
std::cout<<logN<<"\t";
        for (long iter_no = 0; iter_no < iter; iter_no++)
        {
            std::complex<double> A[N], B[N], S[N];
            for (long i = 0; i < N; i++)
            {
                A[i] = rd() + rd() * img;
                B[i] = rd() + rd() * img;
            }
            start = std::chrono::steady_clock::now();
            for (long i = 0; i < N; i++)
            {
                S[i] = A[i] / B[i];
            }
            finish = std::chrono::steady_clock::now();
            std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "\t";
        }
        std::cout << std::endl;
        N = N * 2;
    }

    // Complex Accumulation
    std::cout << "Complex Accumulation" << std::endl;
    N = 1;
    for (long logN = 0; logN < logN_max; logN++)
    {
std::cout<<logN<<"\t";
        for (long iter_no = 0; iter_no < iter; iter_no++)
        {
            std::complex<double> A[N];
            std::complex<double> S = 0.0;
            for (long i = 0; i < N; i++)
            {
                A[i] = rd() + rd() * img;
            }
            start = std::chrono::steady_clock::now();
            for (long i = 0; i < N; i++)
            {
                S += A[i];
            }
            finish = std::chrono::steady_clock::now();
            std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "\t";
        }
        std::cout << std::endl;
        N = N * 2;
    }

    // Complex Sin
    std::cout << "Complex Sin" << std::endl;
    N = 1;
    for (long logN = 0; logN < logN_max; logN++)
    {
std::cout<<logN<<"\t";
        for (long iter_no = 0; iter_no < iter; iter_no++)
        {
            std::complex<double> A[N];
            std::complex<double> S[N];
            for (long i = 0; i < N; i++)
            {
                A[i] = rd() + rd() * img;
            }
            start = std::chrono::steady_clock::now();
            for (long i = 0; i < N; i++)
            {
                S[i] = sin(A[i]);
            }
            finish = std::chrono::steady_clock::now();
            std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "\t";
        }
        std::cout << std::endl;
        N = N * 2;
    }

    // Complex Sin
    std::cout << "Complex Exp" << std::endl;
    N = 1;
    for (long logN = 0; logN < logN_max; logN++)
    {
std::cout<<logN<<"\t";
        for (long iter_no = 0; iter_no < iter; iter_no++)
        {
            std::complex<double> A[N];
            std::complex<double> S[N];
            for (long i = 0; i < N; i++)
            {
                A[i] = rd() + rd() * img;
            }
            start = std::chrono::steady_clock::now();
            for (long i = 0; i < N; i++)
            {
                S[i] = exp(A[i]);
            }
            finish = std::chrono::steady_clock::now();
            std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "\t";
        }
        std::cout << std::endl;
        N = N * 2;
    }

    // Complex log
    std::cout << "Complex log" << std::endl;
    N = 1;
    for (long logN = 0; logN < logN_max; logN++)
    {
std::cout<<logN<<"\t";
        for (long iter_no = 0; iter_no < iter; iter_no++)
        {
            std::complex<double> A[N];
            std::complex<double> S[N];
            for (long i = 0; i < N; i++)
            {
                A[i] = rd() + rd() * img;
            }
            start = std::chrono::steady_clock::now();
            for (long i = 0; i < N; i++)
            {
                S[i] = log(A[i]);
            }
            finish = std::chrono::steady_clock::now();
            std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "\t";
        }
        std::cout << std::endl;
        N = N * 2;
    }

    return 0;
}