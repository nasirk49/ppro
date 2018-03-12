#include "Computer.h"
#include <iostream>

Computer::Computer()
{
}


Computer::~Computer()
{
}

void Computer::Compute()
{
  // Compute for ppro file
  ComputedTransactions ct;
  ct.filename = _filetrans[0].getFileName();
  for (auto tran : _filetrans[0].getTransactions())
  {
    bool good = false;
    for (size_t k = 1; k < _filetrans.size(); ++k)
    {
      for (auto t : _filetrans[k].getTransactions())
      {
        if ((tran.transactionId == t.transactionId
          || tran.merchantTransactionId == t.merchantTransactionId)
          && tran.state == t.state && tran.amount == t.amount)
        {
          good = true;
          ct.ok++;
          ct.okvalue += tran.amount;
          break;
        }
      }
      if (good) break;
    }
    if (!good)
    {
      ct.err++;
      ct.errvalue += tran.amount;
    }
  }
  _computed.push_back(ct);
  // Comptute for other files
  for (size_t k = 1; k < _filetrans.size(); ++k)
  {
    ComputedTransactions ctm;
    ctm.filename = _filetrans[k].getFileName();
    for (auto t : _filetrans[k].getTransactions())
    {
      bool goodm = false;
      for (auto tp : _filetrans[0].getTransactions())
      {
        if ((t.transactionId == tp.transactionId
          || t.merchantTransactionId == tp.merchantTransactionId)
          && t.state == tp.state && t.amount == tp.amount)
        {
          goodm = true;
          ctm.ok++;
          ctm.okvalue += t.amount;
          break;
        }
      }
      if (!goodm)
      {
        ctm.err++;
        ctm.errvalue += t.amount;
      }
    }
    _computed.push_back(ctm);
  }
}

void Computer::Show()
{
  for (auto t : _computed)
  {
    printf("File: %s:\n", t.filename.c_str());
    printf("Number of missing transactions: %d\n", t.err);
    printf("Value of missing transactions: %.2f\n", t.errvalue);
    printf("Number of good transactions: %d\n", t.ok);
    printf("Value of good transactions: %.2f\n", t.okvalue);
    printf("Total value: %.2f\n\n", t.okvalue + t.errvalue);
  }
}
