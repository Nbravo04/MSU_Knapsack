/*
Nicholas Bravata
Project 10 Knapsack
Section 003
11/29/2017
*/
#include<iostream>
using std::ostream;
#include<sstream>
using std::ostringstream;
#include <string>
using std::string;
#include "proj10_package.h"

//The function takes an already open ostream and sends out the package in the
//following format: weight_:priority_.
ostream& operator<<(ostream& out, Package& p)
{
  ostringstream oss;

  oss<< p.weight_<< ":"<<p.priority_;

  string s = oss.str();
  oss.clear();
  out << s;

  return out;
}

//This function compares two packages priority_/weight_ ratio and returns
// true is P1 is larger. False otherwise.
bool package_compare(const Package &p1, const Package &p2)
{
  long p1_ratio = p1.priority_ / p1.weight_;
  long p2_ratio = p2.priority_ / p2.weight_;

  if (p1_ratio < p2_ratio)
    return false;
  else
    return true;
}
