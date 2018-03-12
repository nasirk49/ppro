#pragma once
#include <vector>
#include "Transactions.h"

using namespace std;

struct ComputedTransactions
{
  string filename = "";
  int ok = 0, err = 0;
  double okvalue = 0.0, errvalue = 0.0;
};

class Computer
{
private:
  // first element must be for the transactions-ppro.csv file
  vector<Transactions> _filetrans;
  vector<ComputedTransactions> _computed;
public:
  Computer();
  ~Computer();
  void push_back(Transactions t) { _filetrans.push_back(t); }
  void Compute();
  void Show();
};

