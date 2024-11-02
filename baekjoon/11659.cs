using System;

class Program
{
    static void Main(string[] args)
    {
        string[] firstLine = Console.ReadLine().Split();
        int N = int.Parse(firstLine[0]);
        int M = int.Parse(firstLine[1]);

        int[] numbers = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        long[] prefixSum = new long[N + 1];
        prefixSum[0] = numbers[0];
        
        for (int i = 1; i <= N; i++)
        {
            prefixSum[i] = numbers[i - 1] + prefixSum[i - 1];
        }

        for (int k = 0; k < M; k++)
        {
            string[] s = Console.ReadLine().Split();
            int i = int.Parse(s[0]);
            int j = int.Parse(s[1]);
            
            Console.WriteLine(prefixSum[j] - prefixSum[i - 1]);
        }
    }
}
