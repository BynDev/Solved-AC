#include <iostream>
#include <string>
using namespace std;

int main(){
    int A, B, C;
    cin >> A >> B >> C;

    cout << A + B - C << "\n";
    
    string strA = to_string(A);
    string strB = to_string(B);
    string concat = strA + strB;
    
    cout << stoi(concat) - C;
    
    return 0;
}