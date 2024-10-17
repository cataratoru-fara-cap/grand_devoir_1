#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm> // for std::all_of
#include <cctype> // for std::isdigit
#include "getValueByChar.h"
#include "infixToPostfix.h"
#include "eval.h"
using namespace std;

class Calculator
{
public:
    //I used the expressionStack in the headers but with anothe
    vector<CharIntPair> pairs;
    std::string polish_line;
    std::string line;
    static std::string letters;
    static std::string operators;

    void readInput(const std::string& filePath){
        ifstream file(filePath);

        if (!file) {
            std::cerr << "Unable to open file " << filePath << std::endl;
            return;
        }

        while (getline(file, line)){
            bool allDigits = all_of(line.begin() + 2, line.end(), [](char c){ return isdigit(c); }); //check if everything after = is a digit
            bool A_Z = (letters.find(line[0]) != std::string::npos); // check if the variable declaration meets the imposed rules
            
            if((line[0] != '(') && (line[1] == '=') && (A_Z) && (allDigits)){
                //code that writes CharIntPair's to pairs and checks for assignment errors 
                size_t equalPos = line.find('=');
                char c = line[0]; //we get the var name
                int n = stoi(line.substr(equalPos + 1)); //we get the var value
                
                // Create a CharIntPair and add it to pairs
                CharIntPair my_tuple = CharIntPair(c, n);
                pairs.push_back(my_tuple);
                
            } else if (line[0] == '(') {
                /* code that checks expression validity and writes to stack*/
                // needed implementation to check if arithmetic expression is valid !!!
                polish_line = infixToPostfix(line);
                
                //to make this code work with more than one expression per file we would 
                //need to have a queue or a list where we would add a different instance 
                //of this stack everytime
                
            } else {
                cout << line << ": Improper input format" << endl;
                polish_line = ""; //We empty the memory just to be safe
                pairs = vector<CharIntPair>();
                break;
            }
        }
    }

    int execute(){
        int result = evaluatePostfix(polish_line, pairs);
        return result;
    }

    void writeOutput(){
                ofstream outputFile("output.txt");

                if (!outputFile)
                {
                    cerr << "Unable to open output file." << endl;
                    return;
                }

                int result = execute();
                outputFile << "Result: " << result << endl;

                outputFile.close();
    }

    Calculator(/* args */) = default;
};
std::string Calculator::letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
std::string Calculator::operators = "+-*/%";


int main(int argc, char const *argv[])
{
    /* if (argc < 2) {if (argc < 2) {
        std::cerr << "Please provide a file path as a command line argument." << std::endl; //Error Handling if there is no arg provided
        return 1;
    }
        std::cerr << "Please provide a file path as a command line argument." << std::endl; //Error Handling if there is no arg provided
        return 1;
    } */

    Calculator calculator;
    calculator.readInput("/home/lupulcelbun/Programing/ccc/grand-devoir/3/my_input.txt");
    calculator.execute();
    calculator.writeOutput();
    // Other code...

    return 0;
}