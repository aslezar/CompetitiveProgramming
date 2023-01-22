#include <iostream>
using namespace std;

#define el << '\n'
#define ws << ' '

// Input function
int input(int a = 0)
{
    cin >> a;
    return a;
}

// For fast int read
void fastscan(int &number)
{
    // variable to indicate sign of input number
    bool negative = false;
    register int c;

    number = 0;

    // extract current character from buffer
    c = getchar();
    if (c == '-')
    {
        // number is negative
        negative = true;

        // extract the next character from the buffer
        c = getchar();
    }

    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c > 47 && c < 58); c = getchar())
        number = number * 10 + c - 48;

    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}

/************************************CODECHEF EDITORIAL*******************************************/
// CODECHEF EDITORIAL
#include <iostream>
#include <algorithm>
#include <assert.h>
#include <string>
using namespace std;

long long readInt(long long l, long long r, char endd)
{
    long long x = 0;
    int cnt = 0;
    int fi = -1;
    bool is_neg = false;
    while (true)
    {
        char g = getchar();
        if (g == '-')
        {
            assert(fi == -1);
            is_neg = true;
            continue;
        }
        if ('0' <= g && g <= '9')
        {
            x *= 10;
            x += g - '0';
            if (cnt == 0)
            {
                fi = g - '0';
            }
            cnt++;
            assert(fi != 0 || cnt == 1);
            assert(fi != 0 || is_neg == false);

            assert(!(cnt > 19 || (cnt == 19 && fi > 1)));
        }
        else if (g == endd)
        {
            assert(cnt > 0);
            if (is_neg)
            {
                x = -x;
            }
            assert(l <= x && x <= r);
            return x;
        }
        else
        {
            assert(false);
        }
    }
}
string readString(int l, int r, char endd)
{
    string ret = "";
    int cnt = 0;
    while (true)
    {
        char g = getchar();
        assert(g != -1);
        if (g == endd)
        {
            break;
        }
        cnt++;
        ret += g;
    }
    assert(l <= cnt && cnt <= r);
    return ret;
}
long long readIntSp(long long l, long long r)
{
    return readInt(l, r, ' ');
}
long long readIntLn(long long l, long long r)
{
    return readInt(l, r, '\n');
}
string readStringLn(int l, int r)
{
    return readString(l, r, '\n');
}
string readStringSp(int l, int r)
{
    return readString(l, r, ' ');
}

int T;
long long k;
long long a, b;
int main()
{
    T = readIntLn(1, 20);
    while (T--)
    {
        k = readIntSp(2, 1000000ll * 1000000ll);
        a = readIntSp(1, 9);
        b = readIntLn(0, 9);
        long long ans = a + b;
        if (k == 2)
        {
            if (ans % 3 == 0)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
            continue;
        }
        ans += (a + b) % 10;
        k -= 3;
        ans += (2 * (a + b) % 10) * (k / 4);
        ans += (4 * (a + b) % 10) * (k / 4);
        ans += (8 * (a + b) % 10) * (k / 4);
        ans += (6 * (a + b) % 10) * (k / 4);
        k %= 4;
        if (k > 0)
        {
            ans += 2 * (a + b) % 10;
            k--;
        }
        if (k > 0)
        {
            ans += 4 * (a + b) % 10;
            k--;
        }
        if (k > 0)
        {
            ans += 8 * (a + b) % 10;
            k--;
        }
        if (k > 0)
        {
            ans += 6 * (a + b) % 10;
            k--;
        }
        if (ans % 3 == 0)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    assert(getchar() == -1);
}

/************************************CODECHEF EDITORIAL END*******************************************/
