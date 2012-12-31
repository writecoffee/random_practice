
///////////////////////////////////////////////////////////////////
// compress string "hellooo" to format like "h1e1l2o3" 
// O(n) time and space complexity
///////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

int count_size(const char *str) {
    size_t len = strlen(str);
    if (len == 1) return 1;
    int last = 0;
    int size = 2;
    for (int i = 1; i < len; ++i) {
        if (str[i] == str[last]) {
            continue;
        }
        last = i;
        size += 2;
    }
    return size;
}

const char *compress(const char *str) {
    size_t len = strlen(str);
    int size = count_size(str);
    if (size >= len) {
        return str;
    }

    char *newstr = new char[size + 1];
    int cnt = 1;
    int last = 0;
    int j = 0;
    newstr[j++] = str[0];
    for (int i = 1; i < len; ++i) {
        if (str[i] == str[last]) {
            cnt++;
            continue;
        }
        newstr[j++] = '0' + cnt;
        newstr[j++] = str[i];
        last = i;
        cnt = 1;
    }
    newstr[j++] = '0' + cnt;
    newstr[j] = 0;
    return newstr;
}

void test(const char *str = "hellooooooooo") {
    cout << compress(str);
}

int main() {
    test();

    return 0;
}
