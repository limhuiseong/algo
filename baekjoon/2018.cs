using System;

class Program
{
    static void Main(string[] args)
    {
        int N = int.Parse(Console.ReadLine());
        
        int start = 1;
        int end = 1;
        int sum = 1;
        int ans = 1;
        
        while (end != N)
        {
            if (sum == N)
            {
                ans += 1;
                end += 1;
                sum += end;
            }
            else if (sum > N)
            {
                sum -= start;
                start += 1;
            }
            else
            {
                end += 1;
                sum += end;
            }
        }
        
        Console.WriteLine(ans);
    }
}
