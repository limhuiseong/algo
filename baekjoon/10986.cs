using System;

class Program
{
    static void Main(string[] args)
    {
        string[] firstLine = Console.ReadLine().Split();
        int N = int.Parse(firstLine[0]);
        int M = int.Parse(firstLine[1]);
        
        long[] numbers = new long[N + 1];
        long[] prefixSum = new long[N + 1];
        
        string[] s = Console.ReadLine().Split();
        
        for (int i = 1; i <= N; i++)
        {
            numbers[i] = long.Parse(s[i - 1]);
            prefixSum[i] = prefixSum[i - 1] + numbers[i];
        }
        
        long ans = 0;
        long[] C = new long[M];
        
        for (int i = 0; i < N; i++)
        {
            long remainder = prefixSum[i] % M;
            if (remainder == 0) ans += 1;
            C[remainder] += 1;
        }
        
        for (int i = 0; i < M; i++)
        {
            if (C[i] > 1)
            {
                ans += C[i] * (C[i] -1) / 2;
            }
        }
        
        Console.WriteLine(ans);
    }
}
