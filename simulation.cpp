// //-----------------------------------------------------------
// //  Purpose:    This program demonstrates how multiple queues
// //              can be used to simulate customer arrivals.
// //  Author:     John Gauch
// //-----------------------------------------------------------
// #include "queue.h"
// #include <cstdlib>
// #include <ctime>

// // Generative AI review: the departure logic was duplicated inline in the main loop,
// // which made the simulation harder to reason about and easier to break.
// // I fixed this by moving the random customer-exit rule into a single helper function
// // so every queue is checked consistently before a new customer is assigned.
// void RemoveFinishedCustomers(Queue *Vendor, int NumLines)
// {
//    for (int Line = 0; Line < NumLines; Line++)
//    {
//       if (!Vendor[Line].IsEmpty() && (rand() % 5 == 0))
//       {
//          int FinishedCustomer;
//          Vendor[Line].Remove(FinishedCustomer);
//          cout << "Customer left queue " << Line << " with item count " << FinishedCustomer << endl;
//       }
//    }
// }

// //-----------------------------------------------------------
// // Main program uses the Queue class to simulate customers.
// //-----------------------------------------------------------
// int main()
// {
//    int NumLines = 4;
//    int NumCustomers = 20;
//    int CurrentTime = 0;
//    Queue *Vendor = new Queue[NumLines];
//    srand(static_cast<unsigned int>(time(0)));

//    // Add customers to different queues
//    for (int Customer = 0; Customer < NumCustomers; Customer++)
//    {
//       // Generate customer data
//       CurrentTime += 5 + rand() % 20;
//       int NumItems = 1 + rand() % 5;

//       // Check queues for customers who are done and ready to leave
//       RemoveFinishedCustomers(Vendor, NumLines);

//       // Search for shortest queue
//       int ShortLine = 0;
//       int ShortLength = Vendor[0].GetLength();
//       for (int Line = 1; Line < NumLines; Line++)
//       {
//          int Length = Vendor[Line].GetLength();
//          if (Length < ShortLength)
//          {
//             ShortLine = Line;
//             ShortLength = Length;
//          }
//       }

//       // Add customer to shortest line
//       Vendor[ShortLine].Insert(NumItems);

//       // Print all customer lines
//       for (int Line = 0; Line < NumLines; Line++)
//       {
//          cout << "Line: " << Line << " ";
//          Vendor[Line].Print();
//       }
//       cout << endl;
//    }

//    // Remove remaining customers after the last arrival
//    bool CustomersRemain = true;
//    while (CustomersRemain)
//    {
//       CustomersRemain = false;
//       for (int Line = 0; Line < NumLines; Line++)
//       {
//          if (!Vendor[Line].IsEmpty())
//          {
//             // CustomersRemain = true;
//             if (rand() % 5 == 0)
//             {
//                int FinishedCustomer;
//                Vendor[Line].Remove(FinishedCustomer);
//                cout << "Final cleanup: customer left queue " << Line << " with item count " << FinishedCustomer << endl;
//             }
//          }
//       }
//    }

//    cout << "All customers have left the queues." << endl;
//    delete[] Vendor;
//    return 0;
// }
