// ------------------------------------------------------------------------------ //
// Function name:   findNumClosestTo.
// Input data type: int array list, int array quantity
// Data types used: int's and vector<int>'s.
// What does it do: This function finds the number closest to the number 0.
//                  If a minus number and positive have the same difference, 
//                  the positive number will be selected.
//                  E.g. if -8 and 8 were left over, 8 would be selected.
//                  This function also sorts the positive and negative 
//                  numbers into positive and negative vector lists. 
//                  It counts the quantity of both positive and negative
//                  numbers and uses this information for finding 1 chosen
//                  number of each type. Once each type has been distinguished,
//                  the difference between that number and 0 will be counted.
//                  Finally, the differences of each positive and negative number
//                  will be compared and a suitable number will be chosen as the 
//                  closest one to 0.

#include <iostream>
#include <vector>

using namespace std;

void findNumClosestTo(int numArray[], int quantity)
{
	cout << "********** Find the number closest to 0 function **********"
		<< endl;
	cout << "Array quantity = " << quantity << "." << endl;
	cout << "Values = ";
	for (int i = 0; i < quantity; i++)
	{
		cout << numArray[i] << " ";
	}
	cout << endl;

	int loc = 0;
	vector<int> posNums;
	vector<int> negNums;
	int chosenPos = 0; 
	int chosenNeg = 0;
	int posQuantity = 0;
	int negQuantity = 0;
	int differencePos = 0; 
	int differenceNeg = 0;
	int chosenNum;

	cout << endl;

	cout << "Step 1: Sort numbers into positive and negative orders:" << endl;
	// Sort numbers into positive and negative lists
	while (loc < quantity)
	{
		cout << "Current number = " << numArray[loc] << ". ";
		if (numArray[loc] > 0)
		{
			posNums.push_back(numArray[loc]);
			chosenPos = numArray[loc];
			posQuantity++;
			cout << "This is a positive number." << endl;
		}
		else if (numArray[loc] < 0)
		{
			negNums.push_back(numArray[loc]);
			chosenNeg = numArray[loc];
			negQuantity++;
			cout << "This is a negative number." << endl;
		}
		else
		{
			chosenNum = numArray[loc];
			cout << "The obvious number closest to 0 = " << chosenNum << ".\n";
		}
		loc++;
	}
	cout << "Positive number quantity = " << posQuantity << "." << endl;
	for (int i = 0; i < posQuantity; i++)
	{
		cout << "posNums[" << i << "] = " 
			<< posNums[i] << "." << endl;
	}
	cout << "Negative number quantity = " << negQuantity << "." << endl;
	for (int i = 0; i < negQuantity; i++)
	{
		cout << "negNums[" << i << "] = "
			<< negNums[i] << "." << endl;
	}

	cout << endl;

	// Choosing one positive and one negative number*****
	cout << "Step 2: Find the positive and negative number closest to 0." << endl;
	cout << "Current positive number = " << chosenPos << "." << endl;
	for (int i = 0; i < posQuantity; i++)
	{
		if (posNums[i] < chosenPos)
		{
			chosenPos = posNums[i];
		}
	}
	cout << "Chosen positive number = " << chosenPos << "." << endl;

	cout << "Current negative number = " << chosenNeg << "." << endl;
	for (int i = 0; i < negQuantity; i++)
	{
		if (negNums[i] > chosenNeg)
		{
			chosenNeg = negNums[i];
		}
	}
	cout << "Chosen negative number = " << chosenNeg << "." << endl;

	cout << endl;

	// Calculating the difference between pos and neg numbers
	cout << "Step 3: Calculate the difference between the chosen positive and negative numbers."
		<< endl;
	cout << "Number " << chosenPos << "." << endl;
	for (int count = chosenPos; count > 0; count--)
	{
		differencePos++;
	}
	cout << "Difference between " << chosenPos << " and 0 = " << differencePos << ".\n";

	cout << "Number " << chosenNeg << "." << endl;
	for (int count = chosenNeg; count < 0; count++)
	{
		differenceNeg++;
	}
	cout << "Difference between " << chosenNeg << " and 0 = " << differenceNeg << ".\n";

	cout << endl;

	cout << "Therefore... ";

	// Final decision
	if (differencePos <= differenceNeg)
	{
		cout << "The number closest to 0 is "
			<< chosenPos << "." << endl;
	}
	else if (differenceNeg > differencePos)
	{
		cout << "The number closest to 0 is "
			<< chosenNeg << "." << endl;
	}
	else
	{
		cout << "The number closest to 0 is "
			<< chosenNum << "." << endl;
	}

	cout << "********** End of function *************" << endl;
}
