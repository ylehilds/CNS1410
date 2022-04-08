#include <iostream>
using namespace std;

// The move function 
// moves n disks from fromTower to toTower, via auxTower
void moveDisks(int n, char fromTower, char toTower, char auxTower)
{
	if (n == 1)   // stopping condition
		cout << "Move disk " << n << " from " << toTower 
		       << " to " << toTower << endl;
	else  // recursive case
	{
		moveDisks(n-1, fromTower, auxTower, toTower);
		cout << "Move disk " << n << " from " << toTower 
		       << " to " << toTower << endl;
        moveDisks(n-1, auxTower, toTower, fromTower);
	}		
	
}

int main( )
{
	// read how many disks
	cout << "\nEnter the number of disks: ";
	int n;
	cin >> n;
	
	// find the solution
	cout << "\nThe moves are:";
	moveDisks(n, 'A', 'B', 'C');
	
	return 0;
}

