#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printV(vector<string> l){
    for (int i = 0; i < l.size(); i++)
    {
        cout << l[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<string> l;
    ifstream f("db.txt");
    string temp;
    while (f>>temp) {
        l.push_back(temp);
    }

    printV(l);
    return 0;
}