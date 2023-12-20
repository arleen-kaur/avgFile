#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
   string inputFile;
   string outputFile;
   if (argc != 3) {
      cout << "Usage: " << argv[1] << inputFile;
      return EXIT_FAILURE;
   }

   inputFile = argv[1];
   outputFile = argv[2];
   // Assign to inputFile value of 2nd command line argument
   // Assign to outputFile value of 3rd command line argument
   
   // Create input stream and open input csv file.
   ifstream inSS(inputFile);
   // Verify file opened correctly.
   if (!inSS.is_open()) {
      cout << "Error opening " << inputFile << endl;
      return 1;
   }
      // Output error message and return 1 if file stream did not open correctly.
         int val = 0;
         vector <int> allVals;
         char comma;
         while(inSS >> val) {
            inSS >> comma;
            allVals.push_back(val);
         }
      // Read in integers from input file to vector.
      inSS.close();
   
   // Close input stream.
   int total = 0;
   int avg = 0;
   for (unsigned int i = 0; i < allVals.size(); i++) {
      total = allVals.at(i) + total;
   }
   avg = total / allVals.size();

   // Get integer average of all values read in.
   
   // Convert each value within vector to be the difference between the original value and the average.
   for (unsigned int i = 0; i < allVals.size(); i++)  {
      allVals.at(i) = allVals.at(i) - avg;
   }
   // Create output stream and open/create output csv file.
   ofstream outFS(outputFile);

   // Verify file opened or was created correctly.
   if (!outFS.is_open()) {
      cout << "Error opening " << inputFile << endl;
      return 1;
   // Output error message and return 1 if file stream did not open correctly.
   } 
      for (unsigned int i = 0; i <allVals.size(); i++)  {
      outFS << allVals.at(i);
      if (i + 1 < allVals.size())  {
         outFS << ",";
      }
      }
   // Write converted values into ouptut csv file, each integer separated by a comma.
   outFS.close();
   // Close output stream.
   return 0;
   }