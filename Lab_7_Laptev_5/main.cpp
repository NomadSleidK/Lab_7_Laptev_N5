#include <iostream>
#include <math.h>
#include <exception>

using namespace std;

class ZeroDenominatorTestVar1{};
 
class ZeroDenominatorTestVar2
{
public:
    double valid;
    double imaginary;
};
 
class ZeroDenominatorTestVar3 : public exception
{
public:
    double valid;
    double imaginary;
};



double *Division(double valid1, double imaginary1, double valid2, double imaginary2)
{
    double* result = new double[2];
    
    result[0] = (valid1 * valid2 + imaginary1 * imaginary2) / (pow(valid2, 2) + pow(imaginary2, 2));
    
    result[1] = (imaginary1 * valid2 - valid1 * imaginary2) / (pow(valid2, 2) + pow(imaginary2, 2));
    
    return result;
}

bool IsPossible(double valid2, double imaginary2)
{
    if (pow(valid2, 2) + pow(imaginary2, 2) == 0)
    {
        return false;
    }
    return true;
}

double *Protocol(double valid1, double imaginary1, double valid2, double imaginary2)
{
    if (!IsPossible(valid2, imaginary2))
    {
        throw ZeroDenominatorTestVar1();
    }
    return Division(valid1, imaginary1, valid2, imaginary2);
}

double *Protocol2(double valid1, double imaginary1, double valid2, double imaginary2) throw ()
{
    if (!IsPossible(valid2, imaginary2))
    {
        throw ZeroDenominatorTestVar1();
    }
    return Division(valid1, imaginary1, valid2, imaginary2);
}

double *Protocol3(double valid1, double imaginary1, double valid2, double imaginary2) throw(exception)
{
    if (!IsPossible(valid2, imaginary2))
    {
        throw exception();
    }
    return Division(valid1, imaginary1, valid2, imaginary2);
}

double *Protocol4(double valid1, double imaginary1, double valid2, double imaginary2) throw(ZeroDenominatorTestVar1)
{
    if (!IsPossible(valid2, imaginary2))
    {
        throw ZeroDenominatorTestVar1();
    }
    return Division(valid1, imaginary1, valid2, imaginary2);
}


int main()
{
    int quantity = 0;
    double valid1, imaginary1;
    double valid2, imaginary2;
    double* result = NULL;
    
    cin >> quantity;
    
    for (int i = 0; i < quantity; i++)
    {
        cin >> valid1 >> imaginary1 >> valid2 >> imaginary2;
        try
        {
            result = Protocol(valid1, imaginary1, valid2, imaginary2);
            if (result[1] >= 0)
            {
                cout << result[0] << " + i*" << abs(result[1]) << endl;
            }
            else
            {
                cout << result[0] << " - i*" << abs(result[1]) << endl;
            }
        }
        catch(ZeroDenominatorTestVar1)
        {
            cout << "Error №1 - nulevoy znamenatel!!!!" << endl;
        }
    }
    return 0;
}

