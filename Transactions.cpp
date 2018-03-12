#include "Transactions.h"
#include "strtools.h"
#include <fstream>

Transactions::Transactions()
{
}

Transactions::Transactions(string file)
{
	loadFile(file);
}

bool Transactions::loadFile(string fileName)
{
	_filename = fileName;
	ifstream fs(fileName);
	string line;
	vector<string> data;
	getline(fs, line); //Read headers and do nothing with them
	while (getline(fs, line))
	{
		data = str::explode(line, ',', true);
		Transaction tran;
		if (data.size() < 3) return false;
		try { tran.amount = stod(data[data.size() - 1]); }
		catch (...) { tran.amount = 0.0; }
		tran.state = tran.getState(data[data.size() - 2]);
		try { tran.transactionId = stoi(data[0]); }
		catch (...) { tran.transactionId = 0; }
		if (data.size() < 4)
		{
			tran.merchantTransactionId = tran.transactionId;
		}
		else
		{
			try { tran.merchantTransactionId = stoi(data[1]); }
			catch (...) { tran.merchantTransactionId = 0; }
		}
		_trans.push_back(tran);
	}
	return false;
}


Transactions::~Transactions()
{
}
