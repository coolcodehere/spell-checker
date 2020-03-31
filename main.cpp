#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Dictionary.h"

using namespace std;


void split(vector<string> &words, vector<int> &lines, int line, string str) {
    string temp = "";

    for (int i = 0; i < str.length(); i++) {
        if (!isalpha(str[i]) && temp != "") {
            
            words.push_back(temp);
            lines.push_back(line);
            temp = "";
        } else if (isalpha(str[i])) {
            temp += tolower(str.at(i));
        }
    }
}

void split(Dictionary &d, string str) {

}


// Gets a vector of words from a provided file.
void getWordVector(vector<string> &words, vector<int> &lines, string filename) {
    fstream in;
    in.open(filename);
    string buf;
    int line = 1;
    while(getline(in, buf)) {
        split(words, lines, line, buf);
        line++;
    }

    in.close();
}


// Adds words from provided file to a dictionary
void buildDict(Dictionary &d, string filename) {

    fstream in;
    in.open(filename);
    string buf;

    while(getline(in, buf)) {
        if (!d.contains(buf)) {
            d.insert(buf);   
        }
    }

    in.close();
}


void addLetters(vector<string> &v, string &word) {
    //for every position in word
    for (int pos = 0; pos <= word.size(); pos++) {
    //  add a-z
        for (int let = 97; let <= 122; let++) {
            string temp = word;
            string curr = "";
            curr += (char)let;
            temp.insert(pos, curr);
            v.push_back(temp);
        }
    }
}


void delLetters(vector<string> &v, string &word) {
    for (int i = 0; i < word.size(); i++) {
        string temp = word; 
        temp.erase(i, 1);
        v.push_back(temp);
    }
}


void swapLetters(vector<string> &v, string &word) {
    for (int i = 0; i < word.size() - 1; i++) {
        for (int j = 0; j < word.size(); j++) {
            string temp = word;
            swap(temp[i], temp[j]);
            v.push_back(temp);
        }
    }
}


void generateSuggestions(Dictionary &dict, vector<string> &v, string &word) {
    vector<string> gen;

    addLetters(gen, word);
    delLetters(gen, word);
    swapLetters(gen, word);

    for (int i = 0; i < gen.size(); i++) {
        if (dict.contains(gen.at(i))) {
            v.push_back(gen.at(i));
        }
    }
}


void loadNewFile(vector<string> &words, vector<int> &lines, Dictionary &dict, const string &filename) {
    vector<string> tempw;
    vector<int> templ;
    getWordVector(tempw, templ, "test1.txt");

    for (int i = 0; i < tempw.size(); i++) {
        if (!dict.contains(tempw.at(i))) {
            words.push_back(tempw.at(i));
            lines.push_back(templ.at(i));
        }
    }
}

void displayTitle() {
    if (system("CLS")) {
        system("clear");
    }

    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << "/  ___|| ___ \\|  ___|| |    | |     /  __ \\| | | ||  ___|/  __ \\| | / /|  ___|| ___ \\ " << endl;
    cout << "\\ `--. | |_/ /| |__  | |    | |     | /  \\/| |_| || |__  | /  \\/| |/ / | |__  | |_/ /" << endl;
    cout << "`--. \\ |  __/ |  __| | |    | |     | |    |  _  ||  __| | |    |    \\ |  __| |    /" << endl;
    cout << "/\\__/ /| |    | |___ | |____| |____ | \\__/\\| | | || |___ | \\__/\\| |\\  \\| |___ | |\\ \\" << endl;
    cout << "\\____/ \\_|    \\____/ \\_____/\\_____/  \\____/\\_| |_/\\____/  \\____/\\_| \\_/\\____/ \\_| \\_|" << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << endl;
}


int menu(bool dictLoaded, bool filesLoaded) {
    displayTitle();

    if (dictLoaded) {
        cout << "1) Load Another Dictionary File" << endl;
    } else {
        cout << "1) Load Dictionary File" << endl;
    }
    
    cout << "2) Load Text File to Check" << endl;

    if (filesLoaded) {
        cout << "3) Show Spelling Mistakes" << endl;
    } else {
        cout << "3) --- LOCKED (Please Load Text File) ---" << endl;
    }
    
    cout << "4) Exit" << endl;
    cout << endl;

    cout << "Enter Option: ";
    int select;
    cin >> select;

    return select;
}


string getFileName(int n) {
    displayTitle();
    string filename;

    while (true) {
        if (n == 1) {
            cout << "Enter dictionary filename: ";
        } else {
            cout << "Enter text filename: ";
        }
        
        cin >> filename;
        ifstream f(filename.c_str());

        if (f.good()) {
            cout << "Loading " << filename << endl;
            break;
        } else {
            cout << "Filename Doesn't Exist!" << endl;
            cout << endl;
        }
    }

    
    return filename;
}


void spellingMistakesMenu(vector<string> &misspelled, vector<int> lines, Dictionary d) {
    int selection = -1;
    vector<string> temp;

    while (selection != 0) {
        displayTitle();

        cout << "Words not found in dictionary: " << endl;
        cout << endl << "Line#) Word\n\tSuggestions" << endl << endl;
        
        for (int i = 0; i < misspelled.size(); i++) {
                cout << lines.at(i) << ") " << misspelled.at(i) << endl;
                
                generateSuggestions(d, temp, misspelled.at(i));
                cout << "\t";
                
                if (temp.size() > 0) {
                    for (int j = 0; j < temp.size(); j++) {
                        cout << temp.at(j) << " ";
                    }
                    cout << endl << endl;
                } else {
                    cout << "\"No Suggestions\"" << endl << endl;
                }
                
                temp.clear();
        }
        
        cout << "Enter '0' to Exit..." << endl;
        cin >> selection;
    }
}


int main() {
    Dictionary dict(113);
    vector<string> words;
    vector<int> lines;
    bool shouldExit = false;
    bool fileLoaded = false;
    bool dictLoaded = false;

    while (!shouldExit) {
        int select = menu(dictLoaded, fileLoaded);
        vector<string> tempw;
        vector<int> templ;
        
        switch (select) {
            case 1:
                buildDict(dict, getFileName(1));
                dictLoaded = true;
                break;

            case 2:
                words.clear();
                lines.clear();
                getWordVector(words, lines, getFileName(2));
                fileLoaded = true;
                break;

            case 3:
                if (fileLoaded) {
                    for (int i = 0; i < words.size(); i++) {
                        if (!dict.contains(words.at(i))) {
                            tempw.push_back(words.at(i));
                            templ.push_back(lines.at(i));
                        }
                    }
                    spellingMistakesMenu(tempw, templ, dict);
                    break;
                }


            case 4:
                shouldExit = true;

                if (system("CLS")) {
                    system("clear");
                }

                break;
            default:
                break;
        }
    }
}
