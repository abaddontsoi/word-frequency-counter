#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct word
{
    string text;
    int f=1;
    word(): text(" "), f(1) {};
    word(string t, int f):text(t), f(f) {};
};

void insert(vector<word> &l, string w){
    for ( word &i : l)
    {
        if (i.text == w)
        {
            i.f+=1;
            return;
        }
    }
    word p(w, 1);
    l.push_back(p);
}

void sort(vector<word> &l){
    int i, j;
    word key;
    for (i = 1; i < l.size(); i++)
    {
        key = l[i];
        j = i - 1;
 
        // Move elements of arr[0..i-1], 
        // that are greater than key, to one
        // position ahead of their
        // current position
        while (j >= 0 && l[j].f < key.f)
        {
            l[j + 1] = l[j];
            j = j - 1;
        }
        l[j + 1] = key;
    }
}

void printVec(vector<word> l){
    for (word i : l)
    {
        cout << i.text << ": " << i.f<< endl;
    }
}

int main(){
    string temp;
    ifstream f("db.txt");
    vector<word> l;

    while (f >> temp)
    {
        insert(l, temp);
    }
    sort(l);
    printVec(l);
    return 0;
}