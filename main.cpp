#include <iostream>
#include <fstream>
#include <string>
#include "Transactions.h"
#include "Computer.h"

#define PPRO "transactions-ppro.csv"

using namespace std;

// first argument must be transactions-ppro.csv
int main(int argc, char **argv)
{
  if (argc > 1 && string(argv[1]) != PPRO)
  {
    cout << "First file must be " + string(PPRO) << endl;
    return 1;
  }
  Computer comp;
	for (int i = 1; i < argc; ++i)
	{
		Transactions tran(argv[i]);
    comp.push_back(tran);
	}
  comp.Compute();
  comp.Show();
	return 0;	
}
