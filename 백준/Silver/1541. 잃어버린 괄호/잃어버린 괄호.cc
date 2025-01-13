#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    string formula; cin >> formula;
    
    vector<string>vec;

    int n {0};
    
    for(int i = 0; i < formula.size(); i++)
    {
        if(formula[i] == '-' || formula[i] == '+')
        {
            vec.push_back(formula.substr(n,i - n));
            vec.push_back(string(1,formula[i]));
            n = i+1;
        }
        if(i == formula.size()-1)
        {
            vec.push_back(formula.substr(n));
        }
    }
    vector<int>com;
    
    int result = 0;
    bool minusEncountered = false;
    int tempSum = 0;
    
    for(int i = 0; i < vec.size(); ++i) {
        if(vec[i] != "+" && vec[i] != "-") {
            int num = stoi(vec[i]);
            if(!minusEncountered) {
                result += num;
            } else {
                tempSum += num;
            }
        } else {
            if(vec[i] == "-") {
                if(!minusEncountered) {
                    minusEncountered = true;
                } else {
                    result -= tempSum;
                    tempSum = 0;
                }
            }
        }
    }
    if(minusEncountered) {
        result -= tempSum;
    }
    cout << result;
    return 0;
}

