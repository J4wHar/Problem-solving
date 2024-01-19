public class Solution {
    int[] memo = new int[101];
    private int Solve(int i, ref string s)
    {
        if(i == s.Length)
        {
            return 1;
        }
        if(i > s.Length)
        {
            return 0;
        }
        if(s[i] == '0')
        {
            return 0;
        }
        if(memo[i] != -1)
        {
            return memo[i];
        }
        if(s[i] == '1')
        {
            return memo[i] = Solve(i+1, ref s) + Solve(i+2, ref s);
        }
        if(s[i] == '2')
        {
            if(i+1<s.Length && s[i+1]<'7')
            {
                return memo[i] = Solve(i+1, ref s) + Solve(i+2, ref s);
            }
        }
        return memo[i] = Solve(i+1, ref s);
    }
    public int NumDecodings(string s) {
        for(int i=0;i<s.Length;i++)
        {
            memo[i] = -1;
        }
        return Solve(0, ref s);
    }
}