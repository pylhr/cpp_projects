#include<iostream>
#include<sstream>
#include<stdexcept>
#include<cmath>

using namespace std;

//Funtion prototypes for two operands arithmetic calculations.

double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double power(double a, double b);
double squareRoot(double num);

int main(){
    std::cout<<"Two Operands Calculator\n";
    std::cout<<"-----------------------\n";
    std::cout<<"Add operands and operator in single lines with whitespace separating them.Operations available : + - / * ^ sqrt\n";
    std::cout<<"Memory functionos : M, MR, MC \n";

    string input;
    double num1, num2, memory = 0;
    char op;

    while (true){
        std::cout<<"Enter an expression: ";
        getline(cin, input);

        stringstream ss(input);
        ss >> num1 >> op >> num2;

        try{
            if(ss.fail()){
                throw invalid_argument("Invalid input format.");
                
                
            }
            else {
                    if(op != '+' && op != '-' && op != '*' && op != '/' && op != 's'&& op != '^' && op != 'M' && op != 'MR' && op != 'MC'){
                    throw invalid_argument("Invalid operator.");
                    }

                }

            //invalid operator check
            

            //Division by zero check
            if(op == '/' && num2 ==0){
                throw runtime_error("Division by zero.");
            }

            //Memory function
            if(op =='M'){
                memory = num1;
                std::cout<<"Memory Stored";
                continue; 
            }
            else if ( op == 'MR'){
                num1 = memory;

            }
            else if(op ==  'MC'){
                memory = 0;
                std::cout<<"Memory cleared. \n";
                continue;
            }

            double result;

            switch(op) {
                case '+':
                result = add(num1, num2);
                break;
                case '-':
                result = subtract(num1, num2);
                break;
                case '/':
                result = divide(num1, num2);
                break;
                case '*':
                result = multiply(num1, num2);
                break;
                case '^':
                result = power(num1, num2);
                break;
                case 's':
                result = squareRoot(num1);
                break;
                default:
                throw invalid_argument("Invalid operator.");
            }
            std::cout<< "Result: "<<result <<endl;

            }
            catch (const exception& e) {
                cerr << "Error: "<<e.what() << endl;
        }
        std::cout<<"Do you want to continue(y/n)?";
        char choice;
        cin>> choice;
        if(choice != 'y' && choice != 'Y'){
            break;
        }
        cin.ignore();
    }
    std::cout<< "Thank you for using the calculator. Goodbye! \n";
    return 0;

}

//Function definition

double add(double a, double b){
    return a + b;
}

double subtract(double a, double b){
    return a - b;
}

double divide(double a, double b){
    return a / b;
}

double multiply(double a, double b){
    return a * b;
}

double power(double base, double exponent){
    return pow(base, exponent);
}

double squareRoot(double num){
    if (num < 0){
        throw domain_error("Cannot calculate square root of a negative number.");
    }
    return sqrt(num);

}