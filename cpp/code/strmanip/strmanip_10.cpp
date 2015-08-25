
///////////////////////////////////////////////////////////////////
// collapse space in string like " collapse   the space please  "
// in-place!!
///////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
using namespace std;

char *collapse(char *str) {
    size_t len = strlen(str);
    int sp_cnt = 0;
    int j = 0;
    for (int i = 0; i < len; ++i) {
        if (str[i] == ' ') {
            sp_cnt++;
            if (sp_cnt == 1) {
                str[j++] = ' ';
            }
            continue;
        }

        str[j++] = str[i];
        sp_cnt = 0;
    }
    str[j] = 0;
    return str;
}

void test(const char *const_str) {
    size_t len = strlen(const_str);
    char *str = new char[len];
    strcpy(str, const_str);
    cout << collapse(str) << endl;
    delete []str;
}

int main() {
    test(" collapse   the space please  !   ");
    test("collapse");
    return 0;
}
