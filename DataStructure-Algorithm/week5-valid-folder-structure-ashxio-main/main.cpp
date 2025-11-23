#include <iostream>
#include <filesystem>
#include <fstream>
#include "Solution.hpp"  

using namespace std;
namespace fs = std::filesystem;

int main() {
    fs::create_directories("nirkkonke");
    cout << "nirkkonke/ created!" << endl;

    fs::create_directories("nirkkonke/sub1");
    cout << "nirkkonke/sub1 created!" << endl;
    fs::create_directories("nirkkonke/sub2");
    cout << "nirkkonke/sub2 created!" << endl;

    fs::create_directories("nirkkonke/sub2/subsub1");
    cout << "nirkkonke/sub2/subsub1 created!" << endl;

    ofstream("nirkkonke/sub1/text1.txt") << "nirkklangwoowwwjgtvdateamazing";
    ofstream("nirkkonke/sub2/text1.txt") << "imsolazyionwannadomywork";
    ofstream("nirkkonke/sub2/subsub1/text1.txt") << "killmeplease";

    cout << "files created." << endl;

    // Test the function
    fs::path testPath = "nirkkonke";

    cout << "Testing folder validity: " << testPath << endl;

    bool valid = isFolderValid(testPath);

    if (valid) {
        cout << "The folder structure is [VALID]." << endl;
    } else {
        cout << "The folder structure is [INVALID]." << endl;
    }

    return 0;
}
