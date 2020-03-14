// final 2 assignment.cpp : Defines the entry point for the console application.
//



#include "stdafx.h"
#include<iostream>
#include<math.h>
using namespace std;

int *convertDecimalToTwoscomplement(int a, int bitLength)
{
	int *A=new int[bitLength];
	int input=a;

	for(int i=bitLength-1; i>=0; i--)
	{
		A[i]=a%2;
		a = a/2;
	}

	if(input < 0) // Negative integer.
	{
		for(int i=bitLength-1; i>=0 ;i--)
		{
			if (A[i]==0)
			{
				A[i]=1;
			}
			else 
			{
				A[i]=0;
			}
		}

		for(int i=bitLength-1; i>=0 ;i--) // Adding one.
		{
			if(A[i]==0)
			{
				A[i]=1;
				break;
			}

			else 
			{
				A[i]=0;
			}
		}

		return A;
	}

	else if(input  >=0 ) // positive number.
	{
		return A;
	}
}


int *twosComplementAddition( int *A, int *B, int bitLength)
{
	int* addResult = new int[bitLength];
	bool carryover = false;
	{
		for(int i = bitLength-1; i>=0; i--)
		{
			if( A[i]==1 && B[i]==1 && carryover==false)
			{
				addResult[i]=0;
				carryover=true;
			}

			else if( A[i]==1 && B[i]==1 && carryover==true)
			{
				addResult[i]=1;
				carryover=true;
			}

			else if( A[i]==0 && B[i]==0 && carryover==false)
			{
				addResult[i]=0;
				carryover=false;
			}

			else if( A[i]==0 && B[i]==0 && carryover==true)
			{
				addResult[i]=1;
				carryover=false;
			}
			
			else if( A[i]==0 && B[i]==1  && carryover==false || A[i]==1 && B[i]==0 && carryover==false )
			{
				addResult[i]=1;
				carryover=false;
			}

			else if( A[i]==0 && B[i]==1  && carryover==true || A[i]==1 && B[i]==0 && carryover==true)
			{
				addResult[i]=0;
				carryover=true;
			}
		}
		return addResult;
	}

}



int twosComplementToDecimal (int* C, const int bitLength )
{
	int decimal=0;

	if(C[0]==1) // Negative number
	{
		for(int i=bitLength-1; i>=0; i--)
		{
			if (C[i]==0)
			{
				C[i]=1;
			}
			else
			{
				C[i]=0;
			}
		}

		for(int i=bitLength-1; i>=0 ;i--) // Adding one.
		{
			if(C[i]==0)
			{
				C[i]=1;
				break;
			}

			else 
			{
				C[i]=0;
			}
		}

		for (int i=bitLength-1, j=0; i>=0 ; i--, j++)
		{
			decimal=decimal + C[i] * pow(2.0 , j);
		}

		return decimal*(-1);
	}

	else if(C[0]==0) //Positive number
	{
		for (int i=bitLength-1, j=0; i>=0 ; i--, j++)
		{
			decimal=decimal + C[i] * pow(2.0 , j);
		}

		return decimal;
	}
}

			






void printBinaryArray(const int *binaryArray, const int bitLength)
{
	for(int i=0; i<bitLength; i++)
	{
		cout<<binaryArray[i];
		if((i+1)%4 == 0)
		{
			cout <<" ";
		}
	}
}



int main()
{
	// declare two integer variable a and b and read their values from the user
	int a, b;
	cout << "Enter first operand integer number : ";
	cin >> a;
	cout << "Emter second operand integer number : ";
	cin >> b;

	// Add the integers a and b in decimal
	int decimalArithmeticResultc = a+b;

	//Declare array size and reads is value from the user
	int bitLength;
	cout << "Enter the size of the array : ";
	cin >> bitLength;

	// compute the two's complement of a.
	// The bitlength of the two's complement must be equal to bitLength
	int *A = convertDecimalToTwoscomplement(a, bitLength);
	cout << a << " in two's complement binary is " ;
	printBinaryArray(A, bitLength);
	cout << endl;

	// compute the two's complement of b.
	// The bitlength of the two's complement must be equal to bitLength
	int *B = convertDecimalToTwoscomplement(b, bitLength);
	cout << b << " in two's complement binary is " ;
	printBinaryArray(B, bitLength);
	cout << endl;

	// Add the two arrays A and B in two's complement binary arithmetic.
	// The result must have the same bitlength equal to bitLength
	int *C = twosComplementAddition(A, B, bitLength);
	cout << "The two's complement binary sum is ";
	printBinaryArray(C, bitLength);
	cout << endl;

	// Convert yhe two's complement binary result to decimal
	int binaryArithmenticResult = twosComplementToDecimal(C, bitLength);


	cout<<endl<<endl;
	cout << "The sum in decimal arithmetic is " << decimalArithmeticResultc << endl;
	cout << "The same sum in two's complement arithmetic is " << binaryArithmenticResult << endl;

	// Now, if the values of binaryArithmenticResult and  decimalArithmeticResultc are equal
	// Then you have done a good job
	// If they are not equal the either the result must be out of range for the given bitlength
	// or something must  have gone wrong; and you need to check your work.

	if( binaryArithmenticResult == decimalArithmeticResultc)
	{
		cout << "Great job ! Congratulation, You are now a binary guru." << endl;
	}
	else
	{
		cout << "Either the result is out of range or something is wrong in your work. " << endl;
	}
	delete [] A;
	delete [] B;
	delete [] C;
	system("pause");





	
	return 0;
}



