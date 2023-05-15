#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct word
{
    string text;
    int f=1;
    word* left;
    word* right;
};


void insert(word* &root, word* p){
    if (!root){
        root = p;
        return;
    }

    if (root->text == p->text)
    {
        root->f+=1;
    }
    

    if (p->text < root->text){
        insert(root->left, p);
        return ;
    }

    if (p->text > root->text){
        insert(root->right, p);
        return ;
    }

    return;
}

void insertByF(word* &root, string text, int f){
    if (!root){
        word* p = new word;
        p->text = text;
        p->f = f;
        return;
    }
    if (root->text == text){
        return ;
    }
    if (f < root->f){
        insertByF(root->left, text, f);
        return ;
    }
    if (f > root->f){
        insertByF(root->right, text, f);
        return ;
    }
    return;
}

// in-order tree traversal from right hand side first
void traverse(word* root, word* &newList){
    if (!root){
        return ;
    }
    word* p = new word;
    p->text = root->text;
    p->f = root->f;

    traverse(root->left, newList);
    // insertByF(newList, root);
    traverse(root->right, newList);
}

void printInDecending(word* root){
    if (!root){
        return;
    }
    printInDecending(root->left);
    cout << root->text << ": " << root->f << endl;
    printInDecending(root->right);
}

int main(){
    string db;
    cout << ".txt: ";
    cin >> db;

    ifstream f(db);
    if (!f.is_open())
    {
        cout << "file not found. \n";
        exit(0);
    }
    
    word* root;
    string temp;
    while (f >> temp){
        // cout << "Trying to add: " << temp <<endl;
        word* p = new word;
        p->text = temp;
        insert(root, p);
    }

    word* newList;
    traverse(root, newList);
    printInDecending(newList);
    return 0;
}