#pragma once

#include <string>
#include <vector>
#include <sstream>

using namespace std;

enum State{
	SUCCESS,
	PENDING,
	FAILED,
	UNKNOWN
};

struct Transaction
{
	int transactionId;
	int merchantTransactionId;
	State state;
	double amount;

	State getState(string st)
	{
		if (st == "SUCCESS") return SUCCESS;
		if (st == "PENDING") return PENDING;
		if (st == "FAILED")  return FAILED;
		return UNKNOWN;
	}
};

class Transactions
{
private:
	string _filename;
	vector<Transaction> _trans;
public:
	Transactions();
	Transactions(string file);
	bool loadFile(string fileName);
  string getFileName() { return _filename; }
  const vector<Transaction>& getTransactions() { return _trans; }
	~Transactions();
};

