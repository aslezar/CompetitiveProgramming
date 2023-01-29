class Solution
{
public:
    int alternateDigitSum(int n)
    {
        int sum = 0;
        int s = 1;
        while (n)
        {
            int t = n % 10;
            sum += (t * (s));
            s *= -1;
            n /= 10;
        }
        return s < 0 ? sum : -sum;
    }
};