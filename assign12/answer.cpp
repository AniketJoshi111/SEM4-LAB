#include <iostream>
#include <fstream>
using namespace std;

class Direct {
public:
    void writefile() {
        ofstream fout;
        fout.open("One.txt", ios::out);  // out mode madhye 
        cout << "\n Location: " << fout.tellp();  // position :0
        fout << "1011 Akshay BE-Comp Nashik";   // length 26 
        cout << "\n Location: " << fout.tellp();  // position : 26
        fout << "1012 Akanksha BE-Comp Pune ";
        cout << "\n Location: " << fout.tellp();
        fout << "1013 Tejal BE-Comp Mumbai";
        cout << "\n Location: " << fout.tellp() << endl;
        fout.close();
    }

    void readfile() {
        ifstream fin;
        fin.open("One.txt", ios::in);  // read open in (in) mode
        cout << "\n Location: " << fin.tellg();
        fin.seekg(0, ios::beg);   // seekg -> get pointer in the input mode in the specified position 
        cout << "\n Location: " << fin.tellg();
        char c;
        while (fin.get(c)) {
            cout << c;
        }
        fin.close();
    }

    void deleteFile() {
        if (remove("One.txt") != 0) {
            cout << "Error deleting file";
        } else {
            cout << "File successfully deleted";
        }
    }
};

int main() {
    Direct d;
    d.writefile();
    d.readfile();
   // d.deleteFile();
    return 0;
}
