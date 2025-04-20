#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    bool all_upper = true;
    bool except_first_upper = true;

    for (char c : s) {
        if (!isupper(c)) {
            all_upper = false;
            break;
        }
    }

    for (int i = 1; i < (int)s.size(); i++) {
        if (!isupper(s[i])) {
            except_first_upper = false;
            break;
        }
    }
    if (!s.empty() && !islower(s[0])) {
        except_first_upper = false;
    }

    if (all_upper || except_first_upper) {
        for (char &c : s) {
            if (islower(c)) c = toupper(c);
            else c = tolower(c);
        }
    }

    cout << s << "\n";
    return 0;
}