using System;

class Program
{
    static void Main(string[] args)
    {
        int N = int.Parse(Console.ReadLine());
        int[] numbers = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        int ans = 0;
        
        Array.Sort(numbers);
        
        for (int i = 0; i < N; i++)
        {
            long target = numbers[i];
            int first = 0;
            int second = N - 1;
            
            while (first < second)
            {
                int sum = numbers[first] + numbers[second];
                
                if (i == first) first += 1;
                else if (i == second) second -= 1;
                else
                {
                    if (sum == target)
                    {
                        ans += 1;
                        break;
                    }
                    else if (sum > target)
                    {
                        second -= 1;
                    }
                    else 
                    {
                        first += 1;
                    }
                }
            }
        }
        
        Console.WriteLine(ans);
    }
}
