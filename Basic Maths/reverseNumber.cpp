#include <bits/stdc++.h>
using namespace std;


int reverse(int x) {
        cout << "x = ";
        cin >> x;
        int revNum = 0;
        while (x != 0){
            int lastDigit = x%10;

            if (revNum > INT_MAX / 10 || (revNum == INT_MAX / 10 && lastDigit > 7)) return 0;
            if (revNum < INT_MIN / 10 || (revNum == INT_MIN / 10 && lastDigit < -8)) return 0;
            
            revNum = (revNum*10) + lastDigit;
            x /= 10;
        }

        return revNum;
    }

int main(){
    int n;
    int ans = reverse(n);
    cout << "Reversed Number is: " << ans << endl;

    return 0;
}