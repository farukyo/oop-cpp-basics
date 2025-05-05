#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;



int main(){
    string data = "data.txt";

    cout << "DEBUG: Program Started!" << endl;
    ofstream outputFile (data, ios::out);
    if (!outputFile){
        cout << "DEBUG: output.txt write error" << endl;
        return 1;
    }
    outputFile << "this is the first line" << endl;
    outputFile << "I am inside the file on the 2nd line";
    outputFile.close();



    ifstream inputFile (data, ios::in);
    if(!inputFile){
        cout << "DEBUG: input.txt read error" << endl;
        return 1;
    }

    string temp;
    while (inputFile >> temp){
        cout << temp << " ";
    }
    inputFile.close(); 



    cout << endl << "DEBUG: Program Finished!" << endl; 
}