using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AlgorithmConsoleApp
{
    public static class Algorithms
    {
        public static int returnGreatest(int[] arrayToSearch)
        {
            int maximalNumber = arrayToSearch[0];
            foreach(int number in arrayToSearch)//O(1)
            {
                if (number > maximalNumber)
                    maximalNumber = number;//O(N)
            }
            return maximalNumber;//O(1)
        }//total O(1+N+1)=O(2+N)=O(N) if N~infinity 
        //the complexity of algorithm is in direct ratio with input values volume

        public static bool isContainsDublicated_simple(int[] arrayToScan)
        {
            foreach(int numberCompared in arrayToScan)
            {
                foreach(int numberComparer in arrayToScan)
                {
                    if (numberCompared == numberComparer)
                        return true;//O(N^2) - because of nested array
                }
            }
            return false;//O(1)
        }//total O(1+N^2)=O(N^2)
        //the complexity of algorithm is in quadratic ration with input values volume

        public static int chooseDividingPoint(int[] unsortedArray)
        {
            int numberOfElementInArray = unsortedArray.Length;
            int lastElementId = numberOfElementInArray - 1;

            int firstElement = unsortedArray[0];
            int midleElement = unsortedArray[numberOfElementInArray / 2];
            int lastElement = unsortedArray[lastElementId];

            if ((firstElement > midleElement) == (midleElement > lastElement))
            {//let assume that we retern true in both cases a>b>c and c>b>a
                return midleElement;//O(1)
            }
            else if ((midleElement > lastElement) == (lastElement > firstElement))
            {
                return lastElement;//O(1)
            }
            else
            {
                return firstElement;//O(1)
            }
        }//total O(3)=O(1)
        //the complexity of algorithm is independent of input values volume
    }
}
