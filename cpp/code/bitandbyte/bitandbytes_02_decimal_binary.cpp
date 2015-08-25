//////////////////////////////////////////////////////////////////////////////////////////
// INTEGER PART
//	for every w(i) in Xw (also INT-X) where i is from 0 to w,
//		w(i) = ((INT-X >> 1 * i) % 2)
//
// DECIMAL PART
//	we have
//		Dw (also INT-DX) = d(0)*(1/2^0) + d(1)*(1/2^1) + ... + d(w-1)*(1/2^(w-1))
//	so for each i from 0 to w-1
//		d(i) = Dw - d(0)*2 - d(1)*2^1 - ... - d(i-1)*2^(i-1)
//////////////////////////////////////////////////////////////////////////////////////////

#include <cmath>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

string *get_binary(string *str) {
    string *result = new string();
    unsigned int pp = str->find('.');
    string str_int_part = str->substr(0, pp), str_dec_part = str->substr(pp + 1);
    string str_ip_bin, str_dp_bin;
    if (str_dec_part.length() > 32) {
        return NULL;
    }

    // generate integer part
    int int_part = 0;
    string::reverse_iterator i_rit;
    int i_step;
    for (i_rit = str_int_part.rbegin(), i_step = 0; i_rit != str_int_part.rend();
            ++i_rit, ++i_step) {
        int_part += (int)(*i_rit - '0') * pow(10, i_step);
    }

    while (int_part) {
        int r = int_part % 2;
        int_part >>= 1;
        str_ip_bin.push_back(r + '0');
    }
    reverse(str_ip_bin.begin(), str_ip_bin.end());

    // generate decimal part
    double dec_part = 0.0;
    string::iterator d_it;
    double d_step;
    for (d_it = str_dec_part.begin(), d_step = 0.1; d_it != str_dec_part.end();
            ++d_it, d_step *= 0.1) {
        dec_part += (double)(*d_it - '0') * d_step;
    }

    while (dec_part > 0.0) {
//        if (dec_part == 1) {
//            str_dp_bin.push_back('1');
//            break;
//        }
        double r = dec_part * 2;
        if (r >= 1) {
            str_dp_bin.push_back('1');
            dec_part = r - 1;
        }
        else {
            str_dp_bin.push_back('0');
            dec_part = r;
        }
    }

    // concatenate
    result->append(str_ip_bin);
    result->append(1, '.');
    result->append(str_dp_bin);
    return result;
}

int main() {
    srand(time(0));
    int i_len = 5, d_len = 5;
    string str, *result = NULL;

    for (int i = 0; i < i_len; ++i) {
        char val = '0' + rand() % 10;
        if (i == 0 && val == '0') { }
        else {
            str.push_back(val);
        }
    }
    str.push_back('.');
    for (int j = 0; j < d_len; ++j) {
        str.push_back('0' + rand() % 10);
    }

    cout << str << endl;
    cout << ((result = get_binary(&str)) ? *result : "invalid double") << endl;

    return 0;
}
