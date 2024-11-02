using System;

class Program
{
    static void Main(string[] args)
    {
        string[] firstLine = Console.ReadLine().Split();
        int N = int.Parse(firstLine[0]);
        int M = int.Parse(firstLine[1]);
        
        int[,] A = new int[N + 1, N + 1];
        int[,] D = new int[N + 1, N + 1];
        
        for (int i = 1; i <= N; i++)
        {
            string[] row = Console.ReadLine().Split();
            for (int j = 1; j <= N; j++)
            {
                A[i, j] = int.Parse(row[j - 1]);
                D[i, j] = D[i - 1, j] + D[i, j - 1] - D[i - 1, j - 1] + A[i, j];
            }
        }
        
        for (int k = 0; k < M; k++)
        {
            string[] query = Console.ReadLine().Split();
            int X1 = int.Parse(query[0]);
            int Y1 = int.Parse(query[1]);
            int X2 = int.Parse(query[2]);
            int Y2 = int.Parse(query[3]);
            
            int ans = D[X2, Y2] - D[X2, Y1 - 1] - D[X1 - 1, Y2] + D[X1 - 1, Y1 - 1];
            Console.WriteLine(ans);
        }
    }
}
