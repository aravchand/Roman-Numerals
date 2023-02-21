#include <bits/stdc++.h>
using namespace std;
// not great practice to use above lines... but makes writing simpler.

#define MAX_NUM 3999

int main() {

    while (1) {
        int num, original_num;
        // input
        cout << "Enter the number you wish to convert in range [0, 3999], or type -1 to quit: ";
        cin >> num;
        original_num = num;
        // cout << '\n';
        if(num == -1) {
            cout << "Good day!\n";
            break;
        } else if (num < 0 || num > MAX_NUM) {
            cout << "Currently cannot convert such number.\n";
            continue;
        }
        // conversion algorithm - digit-by-digit
        /*
            I   1     L   50    M  1000
            V   5     C  100
            X  10     D  500
        */
        string digit_conversion[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        // the "upgrade" array is used to shift the roman numerals to the respective power
        // to be used when converting digit in non-units place | note the 100 is to index for ascii 
        vector<vector<int>> upgrade(100, vector<int>(4));
        upgrade['I'] = {'I', 'X', 'C', 'M'};
        upgrade['V'] = {'V', 'L', 'D'};
        upgrade['X'] = {'X', 'C', 'M'};
        int magnitude = 0;
        string converted = "";
        while(num) {
            string digit_shif = digit_conversion[num % 10];
            num /= 10;
            for(char &c : digit_shif) {
                c = upgrade[c][magnitude];
            }
            converted = digit_shif + converted;
            magnitude++;
        }
        cout << original_num << " is " << converted << " in Roman Numerals.\n";
    }
    return 0;
}