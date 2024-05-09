#include <iostream>
#include "Tokenizer.hpp"
using namespace std;
//from parsing_input_files video on learn
int main(){
Tokenizer *tokenizer = nullptr;
string input_cmd;
bool initialized = false;

while(cin >> input_cmd){
    if (input_cmd == "M" && (!initialized)){
        int size;
        cin >> size;
        tokenizer = new Tokenizer(size);
        //create dictionary here
        cout << "success" << endl;
        initialized = true;
    }

    else if(input_cmd == "INSERT"){
        string word;
        cin >> word;
        if(tokenizer -> insert(word)){
            cout << "success" << endl;
        }    
        else{
            cout << "failure" <<endl;
        }
            

    }
    else if(input_cmd == "READ"){
        string filename;
        cin>>filename;
        fstream fin(filename.c_str());
        if(tokenizer->tokenizeFile(fin)){
            cout << "success" << endl;
        }
        else {
            cout << "failure" << endl;
        }
    }
    else if (input_cmd == "TOKENIZE"){
        string word;
        cin >> word;
        int t = tokenizer->tokenize(word);
        cout << t << endl;
    }
    else if (input_cmd == "RETRIEVE"){
        int t;
        cin >> t;
        string word = tokenizer->retrieve(t);
        cout << word<< endl;

    }
    else if (input_cmd == "TOKS"){
        int t;

        while (cin >> t && (t != -1)){
            cout << tokenizer->retrieve(t)<< " ";
        }
        if (t == -1){
            cout << "\n";
        }
    }
    else if (input_cmd == "STOK"){
        string word;

        while (cin >> word && (word != "_DONE_")){
           cout << tokenizer->tokenize(word) << " ";
        }
        if (word == "_DONE_"){
            cout <<"\n";
        }
    }

    else if (input_cmd == "PRINT"){
        int key;
        cin >> key;

        cout <<tokenizer->print(key)<<"\n";
    }
    
    else if (input_cmd == "EXIT"){
        delete tokenizer;
        return 0;
    }


}
delete tokenizer;
return 0;
}