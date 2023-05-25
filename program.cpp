#include <iostream>
#include <cmath>
using namespace std;

// program to implement the RSA algorithm

// Function for modular exponentiation
int modular_exponentiation(int base, int exponent, int modulus)
{
    int result = 1;
    base = base % modulus;

    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;

        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }

    return result;
}

int main()
{
    // Declare the variables
    int p, q, e, m;

    // Collect the inputs from the user
    cout << "Welcome to the RSA Algorithm Calculator" << endl;
    cout << "---------------------------------------" << endl;
    cout << "Enter a value for the p: ";
    cin >> p;
    cout << "Enter a value for the q: ";
    cin >> q;
    cout << "Enter a value for the e: ";
    cin >> e;
    cout << "Enter a value for the message m: ";
    cin >> m;

    // Declare the variables
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int d = 0;
    while ((d * e) % phi != 1)
    {
        d++;
    }
    // Run the program and observe the output
    cout << "------- Display the variables -------" << endl;
    cout << "The prime numbers are: " << p << ", " << q << endl;
    cout << "The modulus is: " << n << " and phi(n) is: " << phi << endl;
    cout << "The public key is: " << e << ", " << n << endl;
    cout << "The private key is: " << n << ", " << d << endl;
    cout << "------- Calculating the message -------" << endl;
    cout << "The original message is: " << m << endl;

    // Encrypting the message
    int c = modular_exponentiation(m, e, n);
    cout << "The encrypted message is: " << c << endl;
    cout << "The decrypted message is: " << modular_exponentiation(c, d, n) << endl;
    return 0;
}
