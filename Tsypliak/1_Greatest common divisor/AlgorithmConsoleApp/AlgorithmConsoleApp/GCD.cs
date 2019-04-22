using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AlgorithmConsoleApp
{
    public static class GCD
    {
        public static int divisionRemainder(int dividend, int divider)
        {
            return dividend % divider;
        }

        public static int findGreatestCommonDivisor(int a, int b)
        {
            //GCD(a;b)=GCD(b;a%b)
            while (b != 0)
            {
                int remainder = divisionRemainder(a, b);
                a = b;
                b = remainder;
            }
            return a;
        }
    }
}
