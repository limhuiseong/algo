using System;

class Program
{
    static void Main(string[] args)
    {
        int N = int.Parse(Console.ReadLine());
        int M = int.Parse(Console.ReadLine());
        
        int[] ingredients = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        Array.Sort(ingredients);
        
        int first = 0;
        int second = N - 1;
        int ans = 0;
        
        while (first < second)
        {
            int sum = ingredients[first] + ingredients[second];
            if (sum == M)
            {
                ans += 1;
                first += 1;
                second -= 1;
            }
            else if (sum > M)
            {
                second -= 1;
            }
            else 
            {
                first += 1;
            }
        }
        
        Console.WriteLine(ans);
    }
}
