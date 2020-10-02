#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
using namespace std;

const int heapSize=11; // HEAP SIZE 11 BECAUSE INDEX 0 IS NOT USED FOR EASY CALCULATION

string fileName;
int tempArr[heapSize] = {0};
int heapArr[heapSize]={0}; // INITIALIZE ALL ARRAY VALUES WITH ZERO
int index=0;

void maxHeap(int num);

int main()
{
	int choice;
	int number;
	int number2;
	int count;
	string line;
	ifstream ifs;

	do
	{
		// SHOW THE MENU
		cout << "MENU" << endl;
		cout << "1) Max Heap" << endl;
		cout << "2) Exit the program" << endl;
		cin >> choice;

		switch(choice)
		{
			case 1: // MAX HEAP
			{
				do {
                        cout << "Enter the name of the File with .txt extension." << endl;
                        cin >> fileName;

                        if(fileName != "data.txt") {
                            cout << "File name is Invalid! " << endl;
                        } else {
                            ifs.open("data.txt");

                             if (ifs.is_open()) {
                                cout<<"The File have been successfully opened." << endl;
                             } else {
                                cout << "File failed to Open " << endl;
                             }
                        }

                } while (fileName != "data.txt");

                for(int i=0; i<10; i++) {
                    ifs >> number;

                    maxHeap(number);
                }

				cout << endl;
				cout << "HEAP ARRAY USING MAX HEAP" << endl;
				for(int i=1; i<heapSize; i++)
				{
					cout << heapArr[i] << "  ";
				}
				cout << endl << endl;
				cout << "HEAP ARRAY USING MAX HEAP DISPLAY THE FIRST FIVE ELEMENTS" << endl;
				for(int i=1; i<6; i++)
				{
					cout << heapArr[i] << "  ";
				}
				cout << endl << endl;
				break;
				ifs.close();
			}

			case 2: // EXIT THE PROGRAM
			{
				cout << "Thank you for using the program, end the program." << endl;
				break;
			}

			default: // VALIDATE THE USER INPUT
			{
				cout << "Your input is wrong!" << endl;
			}
			cout << endl;
		}
	}
	while(choice!=3);
}


void maxHeap(int num) // MAX HEAP
{
	heapArr[++index]=num;
	for(int i=index; i>1; i/=2)
	{
		if(heapArr[i/2]<heapArr[i]) // IF THE CHILD VALUE IS BIGGER THAN THE PARENT VALUE, SWAP.
		{
			int temp=heapArr[i/2];
			heapArr[i/2]=heapArr[i];
			heapArr[i]=temp;
		}
		else
			break;
	}
}



