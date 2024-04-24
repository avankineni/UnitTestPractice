#include "Password.h"
#include <string>
#include <algorithm>
#include <cctype>

using std::string;

Password::Password() {
    // Default password initialization
    pass_history.push_back("ChicoCA-95929");
}

int Password::count_leading_characters(string phrase) {
    if (phrase.empty()) return 0; // Handling empty strings

    int repetition = 1;
    int index = 0;

    while (index < phrase.length() - 1 && phrase[index] == phrase[index + 1]) {
        repetition++;
        index++;
    }
    return repetition;
}

bool Password::has_mixed_case(string phrase) {
    bool has_upper = false;
    bool has_lower = false;
    for (char c : phrase) {
        if (isupper(c)) has_upper = true;
        if (islower(c)) has_lower = true;
        if (has_upper && has_lower) return true;
    }
    return false;
}

void Password::set(string new_password) {
    if (new_password.length() < 8 || new_password.length() > 20) return;
    if (count_leading_characters(new_password) > 3) return;
    if (!has_mixed_case(new_password)) return;
    if (std::find(pass_history.begin(), pass_history.end(), new_password) != pass_history.end()) return;

    // Set the new password
    pass_history.push_back(new_password);
}

bool Password::authenticate(string test_password) {
    if (pass_history.empty()) return false;
    return pass_history.back() == test_password;
}
