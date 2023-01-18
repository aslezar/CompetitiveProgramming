#include <fstream>
#include <iostream>
// #include <string>
using namespace std;

#define el cout << '\n';

class Solution;
int main()
{
    // Solution solution;
    fstream f("input");
    if (!f)
        cout << "File not Found\n";
    else
        cout << "File opened\n";

    f << "Files can be tricky, but it is fun enough!\n";
    string myText;
    // Output the text from the file
    f.seekg(0, ios::beg);
    getline(f,myText);
    cout << myText;
    f.close();
    return 0;
}