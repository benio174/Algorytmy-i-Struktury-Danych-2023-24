#include <iostream>
#include <cmath>
using namespace std;

template<typename T>
class Polynomial{
    private:
    static const int MAX = 10;
    int degree;
    T coefficients[MAX + 1];

    public:
    int getDegree(){

        cout << "What degree does your polynomial have?" << endl;
        cin >> degree;
        if(degree > MAX || degree <= 0){
            cerr << "Incorrect polynomial degree" << endl;
            exit(EXIT_FAILURE);
        }
        return degree;
    }
    
    void getCoefficients(){
        cout << "Please input coefficients" << endl;
        for (int i = degree; i >= 0; --i){
            if(i == 1){
                cout << "Coefficient for x:" << endl;
                cin >> coefficients[i];
            } else if(i == 0){
                cout << "Absolute term:" << endl;
                cin >> coefficients[i];
            } else {
            cout << "Coefficient for x^" << i << ": " << endl;
            cin >> coefficients[i];
            }
        }
            
        cout << "Polynomial: ";
        for(int i = degree; i >= 0; --i){
            if(coefficients[i] != 0){
                if(coefficients[i] > 0 && i < degree){
                cout << " + ";
            } else if(coefficients[i] < 0) {
                cout << " - ";
            }
            cout << abs(coefficients[i]);
            if (i > 0){
                cout << "x";
            }
            if (i > 1){
                cout << "^" << i;
            }
        }
    }
    cout << endl;
}

    void getSum(const Polynomial<T>& other) {
            int finalDegree = max(degree, other.degree);
            cout << "Sum of polymonials: ";
            for(int i = finalDegree; i >= 0; --i){
                T result = (i <= degree) ? coefficients[i] : 0;
                result += (i <= other.degree) ? other.coefficients[i] : 0;
                
                if(result != 0){
                    if(result > 0 && i == finalDegree){
                        cout << result;
                    } else if(result < 0){
                        cout << " - " << abs(result);
                    } else {
                         cout << " + " << abs(result);
                    }
                    if (i > 0){
                        cout << "x";
                    }
                    if (i > 1){
                        cout << "^" << i;
                    }
                }
            }
            cout << endl;
         }
    
    void getDifference(const Polynomial<T>& other) {
    int finalDegree = max(degree, other.degree);
    cout << "Difference of polynomials: ";
    for(int i = finalDegree; i >= 0; --i){
        T result = (i <= degree) ? coefficients[i] : 0;
        result -= (i <= other.degree) ? other.coefficients[i] : 0;

        if(result != 0){
            if(result > 0 && i == finalDegree){
                cout << result;
            }
            else if (result < 0) {
                cout << " - " << abs(result);
            } else {
                cout << " + " << abs(result);
            }

            if (i > 0) {
                cout << "x";
            }

            if (i > 1) {
                cout << "^" << i;
            }
        }
    }
    cout << endl;
    }

    void getMultiplication(const Polynomial<T>& other) {
    int resultDegree = degree + other.degree;
    T* resultCoefficients = new T[resultDegree + 1]();

    for (int i = 0; i <= degree; ++i) {
        for (int j = 0; j <= other.degree; ++j) {
            resultCoefficients[i + j] += coefficients[i] * other.coefficients[j];
        }
    }

    cout << "Multiplication of polynomials: ";
    for (int i = resultDegree; i >= 0; --i) {
        if (resultCoefficients[i] != 0) {

            if(resultCoefficients[i] > 0 && i == resultDegree){
                cout << resultCoefficients[i];
            }
            else if (resultCoefficients[i] < 0) {
                cout << " - " << abs(resultCoefficients[i]);
            } else {
                cout << " + " << abs(resultCoefficients[i]);
            }

            if (i > 0) {
                cout << "x";
            }

            if (i > 1) {
                cout << "^" << i;
            }
        }
    }
    cout << endl;

    delete[] resultCoefficients;
}

   T evaluateHorner(T x) const {
        T result = coefficients[degree];
        
        for (int i = degree - 1 ; i >= 0; --i) { 
            result = (result * x) + coefficients[i];
        }

        return result;
    }
        
 };

int main(){

    Polynomial<int> polynomial1, polynomial2;

    int choice;
    int n;

    polynomial1.getDegree();
    polynomial1.getCoefficients();

    cout << "What would you want to do? (type suitable number)" << endl;
    cout << "1. Add two polymonials, 2. Substract two polymonials, 3. Multiply two polymonials, 4. Calculate ponymonial values" << endl;
    cin >> choice;

    switch(choice){
        case 1:
        cout << "Please input your second polymonial:" << endl;
        polynomial2.getDegree();
        polynomial2.getCoefficients();
        polynomial1.getSum(polynomial2);
        break;

        case 2:
        cout << "Please input your second polymonial:" << endl;
        polynomial2.getDegree();
        polynomial2.getCoefficients();
        polynomial1.getDifference(polynomial2);
        break;

        case 3:
        cout << "Please input your second polymonial:" << endl;
        polynomial2.getDegree();
        polynomial2.getCoefficients();
        polynomial1.getMultiplication(polynomial2);
        break;

        case 4:
        cout << "Please enter a number to calculate value of polynomial for this value:" << endl;
        cin >> n;
        cout << polynomial1.evaluateHorner(n) << endl;
        break;

        default:
        cerr << "Wrong number given" << endl;
        exit(EXIT_FAILURE);
        

    }

    return 0;
}
