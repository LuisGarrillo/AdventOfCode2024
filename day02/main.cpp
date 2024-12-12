#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<string> split(string input);

int main() {
    vector<vector<int>> reports;
    int safeReports = 0;

    ifstream input("input.in");
    string line;
    int counter = 0;
    while(getline(input, line)) {
        vector<string> splittedLine = split(line);
        vector<int> reportData;
        for (int i = 0, length = splittedLine.size(); i < length; i++) {
            reportData.push_back(stoi(splittedLine[i]));
        }
        reports.push_back(reportData);
        
    }
    input.close();

    for (int i = 0, length = reports.size(); i < length; i++) {
        bool increasing = false;
        bool valid = true;
        

        vector<int> iterationSample = reports[i];
        int iteractionMax = reports[i].size();
        int skipIndex = 0;
        while (skipIndex <= iteractionMax) {
            int lengthj = iterationSample.size();

            for (int j = 0; j < lengthj -1; j++) {
                bool unsafe = false;
                valid = true;
                if (j == 0) {
                    int counter = 0;
                    while(counter >= 0) {
                        if (iterationSample[counter] < iterationSample[counter+1]) {
                            increasing = true;
                            counter = -2;
                        }
                        else if (iterationSample[counter] > iterationSample[counter+1]) {
                            increasing = false;
                            counter = -2;
                        }
                        counter++;
                    }
                }
                
                if (increasing) {
                    if (iterationSample[j] > iterationSample[j+1]) {
                        unsafe = true;
                        cout << "should increase" << endl;
                    }
                }
                else {
                    if (iterationSample[j] < iterationSample[j+1]) {
                        unsafe = true;
                        cout << "should decrease" << endl;
                    }
                }
                int difference = abs(iterationSample[j] - iterationSample[j + 1]);
                if (difference < 1 || difference > 3) {
                    unsafe = true;
                    cout << "bad range " << difference << " between " << iterationSample[j] << " " << iterationSample[j + 1] << endl;
                }

                if (unsafe) {
                    valid = false;
                    break;
                }
            }

            if (valid){
                break;
            }

            iterationSample = reports[i];
            cout << iterationSample[skipIndex] << endl;
            iterationSample.erase(iterationSample.begin() + skipIndex);
            skipIndex++;
            
            if (skipIndex > iteractionMax) {
                valid = false;
            }
        }
        
        if (valid) {
            cout << "index " << i << " is valid" << endl;
            safeReports++;
        } 
        else {
            cout << "index " << i << " is invalid" << endl;
        }
    }

    cout << "The number of safe reports is: " << safeReports << endl;
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