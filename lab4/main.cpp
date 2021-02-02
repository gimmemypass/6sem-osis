#include <iostream> 
#include <string>
#include <map>

using namespace std;

const map<char, string> morze {
        {'a', ".- "},
        {'b', "-... "},
        {'c', "-.-. "},
        {'d', "-.. "},
        {'e', ". "},
        {'f', "..-. "},
        {'g', "--. "},
        {'h', ".... "},
        {'i', ".. "},
        {'j', ".--- "},
        {'k', "-.- "},
        {'l', ".-.. "},
        {'m', "-- "},
        {'n', "-. "},
        {'o', "--- "},
        {'p', ".--. "},
        {'q', "--.- "},
        {'r', ".-. "},
        {'s', "... "},
        {'t', "- "},
        {'u', "..- "},
        {'v', "...- "},
        {'w', ".-- "},
        {'x', "-..- "},
        {'y', "-.-- "},
        {'z', "--.. "},
        {'\n', "\n"},
        {' ', "  "}
};

string convert(char sym){
    string result = " ";
    if(morze.find(sym) != morze.end()){
        result = morze.at(sym);
    }
    return result;
}
int main(){
    string symbols;
    cin >> symbols; 
    for(int i = 0; i < symbols.length(); i++){
        cout << convert(symbols[i]);
    }
    cout << endl;
    return 0;
}