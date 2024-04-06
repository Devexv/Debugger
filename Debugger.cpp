#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> checkSyntaxErrors(const string& code) {
    vector<string> errors;

    size_t pos = 0;
    while ((pos = code.find(";", pos)) != string::npos) {
        pos++;
        if (pos < code.size() && code[pos] != '\n' && code[pos] != ' ')
            errors.push_back("Missing semicolon at position " + to_string(pos) + ".");
    }


    return errors;
}

int main() {
    string code = R"(
#include <iostream>

int main() {
    std::cout << "Hello, world!" << std::endl
    return 0;
}
)";

    vector<string> syntaxErrors = checkSyntaxErrors(code);

    if (!syntaxErrors.empty()) {
        cout << "Syntax errors found:" << endl;
        for (const auto& error : syntaxErrors) {
            cout << error << endl;
        }
    } else {
        cout << "No syntax errors found." << endl;
    }

    return 0;
}
