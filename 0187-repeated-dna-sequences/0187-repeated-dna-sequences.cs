public class Solution {
    public IList<string> FindRepeatedDnaSequences(string s) {
        Dictionary<string, int> occ = new Dictionary<string, int>();
        IList<string> ans = new List<string>();
        int n = s.Length;
        for(int i=0;i<=n-10;i++)
        {
            string subString = s.Substring(i, 10);
            if(occ.ContainsKey(subString)){
                occ[subString]++;
            }
            else
            {
                occ.Add(subString, 1);
            }
        }
        foreach(var x in occ)
        {
            if(x.Value > 1)
            {
                ans.Add(x.Key);
            }
        }
        return ans;
    }
}