#include <iostream>
#include <vector>

using namespace std;

struct CharIntPair {
    char character;
    int number;

    CharIntPair(char c, int n) : character(c), number(n) {}
};
 // searches for the pair of key c in the vector and returns it s value
int getValueByChar(const std::vector<CharIntPair>& pairs, char c) {
    for (const CharIntPair& pair : pairs) {
        if (pair.character == c) {
            return pair.number;
        }
    }
    // Throws an error if we forgot to declare the variable ;)
    throw std::runtime_error("Character not found in pairs"); 
}