#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<string> split(string input);

int main() {
    
}

vector<string> split(string input) {
    vector<string> returnValue;
    stringstream stream(input);
    string element;
    while (stream >> element) {
        returnValue.push_back(element);
    }
    stream.clear();
    return returnValue;
}