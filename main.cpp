#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

double V(double t, int initial_victims, int initial_killers, double alpha1, double alpha2, double beta1, double beta2)
{
    return initial_victims * cos(sqrt(alpha1 * alpha2) * t) - (initial_killers * sqrt(alpha2) * beta1 * sin(sqrt(alpha1 * alpha2) * t)) / (beta2 * sqrt(alpha1)) + alpha2 / beta2;
}

double K(double t, int initial_victims, int initial_killers, double alpha1, double alpha2, double beta1, double beta2)
{
    return (initial_victims * sqrt(alpha1) * beta2 * sin(sqrt(alpha1 * alpha2) * t)) / (beta1 * sqrt(alpha2)) + initial_killers * cos(sqrt(alpha1 * alpha2) * t) + alpha1 / beta1;
}

int main()
{

    double initial_victims, initial_killers;
    double alpha1, alpha2, beta1, beta2;
    double T, N;

    cin >> initial_victims >> initial_killers >> alpha1 >> beta1 >> alpha2 >> beta2 >> T >> N;

    vector<double> t = vector<double>();
    vector<double> v = vector<double>();
    vector<double> k = vector<double>();

    initial_victims -= alpha2 / beta2;
    initial_killers -= alpha1 / beta1;

    cout.precision(2);
    cout << fixed;

    std::ofstream outfile1("v.dat");
    std::ofstream outfile2("k.dat");
    std::ofstream outfile3("kv.dat");

    cout << "t:\n";
    for (double i = 0.00; i <= T; i += T / N)
    {
        t.push_back(i);
        v.push_back(V(i, initial_victims, initial_killers, alpha1, alpha2, beta1, beta2));
        k.push_back(K(i, initial_victims, initial_killers, alpha1, alpha2, beta1, beta2));
        cout << i << " ";

        outfile1 << V(i, initial_victims, initial_killers, alpha1, alpha2, beta1, beta2) << " " << i << std::endl;
        outfile2 << K(i, initial_victims, initial_killers, alpha1, alpha2, beta1, beta2) << " " << i << std::endl;
        outfile3 << K(i, initial_victims, initial_killers, alpha1, alpha2, beta1, beta2) << " " << V(i, initial_victims, initial_killers, alpha1, alpha2, beta1, beta2) << std::endl;
    }
    cout << "\n";

    cout << "v:\n";
    for (double i : v)
    {
        cout << i << " ";
    }
    cout << "\n";

    cout << "k:\n";
    for (double i : k)
    {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}
