#include <iostream> 
#include <string>
#include <map>
#include "algo.h"

using namespace std;

int main(){
    string symbols;
    cin >> symbols; 
    for(int i = 0; i < symbols.length(); i++){
        cout << convert(symbols[i]);
    }
    cout << endl;
    return 0;
}