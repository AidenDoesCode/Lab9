//-----------------------------------------------------------
//  Purpose:    Test the Queue class.
//  Author:     John Gauch
//-----------------------------------------------------------
#include "timer.h"
#include "queue.h"
#include <cstdlib>
#include <ctime>

int main()
{
   Queue q;
   Timer T;
   int underflowCount = 0;
   int maxLength = 0;
   srand(static_cast<unsigned int>(time(0)));

   T.start_timer();

   for (int i = 0; i < 1000000; i++)
   {
      int value = rand() % 10;
      q.Insert(value);

      int currentLength = q.GetLength();
      if (currentLength > maxLength)
         maxLength = currentLength;

      if (q.IsEmpty())
      {
         underflowCount++;
      }
      else
      {
         int removed;
         q.Remove(removed);
      }
   }

   T.end_timer();

   cout << "Underflow count = " << underflowCount << endl;
   cout << "Maximum queue length = " << maxLength << endl;
   cout << "CPU time = " << T.elapsed_time() << " sec\n";
   return 0;
}

