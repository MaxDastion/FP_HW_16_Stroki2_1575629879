#include <iostream>
#include <string>


using namespace std;

int main() {
    string text, find_str, replace_str;

    cout << "Enter text: ";
    getline(cin, text);

    cout << "Enter the word to be replaced: ";
    cin >> find_str;

    cout << "Enter a replacement word: ";
    cin >> replace_str;

    size_t pos = text.find(find_str);
    if (pos != string::npos) {
        text.replace(pos, find_str.length(), replace_str);
    }

    for (int i = 0; i < text.length(); i++) {
        if (i == 0 || (text[i - 1] == '.' || text[i - 1] == '?' || text[i - 1] == '!') && isspace(text[i - 2])) {
            text[i] = toupper(text[i]);
        }
    }

    int letter_counts[26] = { 0 };
    for (int i = 0; i < text.length(); i++) {
        if (isalpha(text[i])) {
            letter_counts[tolower(text[i]) - 'a']++;
        }
    }
    cout << "Number of occurring letters:" << endl;
    for (int i = 0; i < 26; i++) {
        if (letter_counts[i] > 0) {
            cout << (char)(i + 'a') << ": " << letter_counts[i] << endl;
        }
    }
    int digit_count = 0;
    for (int i = 0; i < text.length(); i++) {
        if (isdigit(text[i])) {
            digit_count++;
        }
    }
    cout << "Number of occurring digits: " << digit_count << endl;

    cout << "Changed text: " << endl;
    cout << text << endl;

}
