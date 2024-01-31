public class Solution {
    public int[] DailyTemperatures(int[] temperatures) {
        int n = temperatures.Length;
        Dictionary<int, Queue<int>> d = new Dictionary<int, Queue<int>>();
        int[] ans = new int[n];
        for(int i=0;i<n;i++)
        {
            ans[i] = 1000000;
            int x = temperatures[i];
            if(!d.ContainsKey(x))
            {
                d.Add(x, new Queue<int>());
            }
            d[x].Enqueue(i);
        }
        for(int i=0;i<n;i++)
        {
            int x = temperatures[i];
            d[x].Dequeue();
            for(int temp=x+1;temp<=100;temp++)
            {
                if(d.ContainsKey(temp) && d[temp].Count()!=0)
                {
                    ans[i] = Math.Min(ans[i], d[temp].Peek() - i);
                }
            }
            if(ans[i] == 1000000)
            {
                ans[i] = 0;
            }
        }
        return ans;
    }
}