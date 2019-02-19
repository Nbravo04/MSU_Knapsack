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
#include<string>
using std::string;
#include<algorithm>
using std::copy;
#include<iterator>
#include<fstream>
using std::ifstream;
#include"proj10_knapsack.h"

/*
This is a cunstructor for Knapsack with only a single arg, Weight Limit.
*/
Knapsack::Knapsack(size_t wlimit)
{
  weight_limit_ = wlimit;
  capacity_ =10;
  size_ = 0;
  data_= new Package[capacity_];
}

/*
This is a cunstructor for Knapsack with two args, Weight Limit and capacity.
*/
Knapsack::Knapsack(size_t wlimit, size_t cap)
{
  weight_limit_ = wlimit;
  capacity_ =cap;
  size_ = 0;
  data_= new Package[capacity_];
}

/*
Returns the present capacity_ of the underlying array, the number of Packages the array could
hold before having to grow.
*/
long Knapsack::capacity() const
{
  return capacity_;
}

/*
Returns the present size_ , the number of Packages presently in the underlying array.
*/
long Knapsack::size() const
{
  return size_;
}

/*
Returns the present weight_limit that is set for this Knapsack instance
*/
long Knapsack::weight_limit() const
{
  return weight_limit_;
}

/*
Copy construstor for Knapsack
*/
Knapsack::Knapsack(const Knapsack& kpsac)
{
  data_ = new Package[kpsac.capacity_];
  copy(kpsac.data_, kpsac.data_+kpsac.size_, data_);
  capacity_ = kpsac.capacity_;
  weight_limit_ = kpsac.weight_limit_;
  size_ = kpsac.size_;
}

/*
The Destructor
*/
Knapsack::~Knapsack()
{
  delete[] data_;
}

/*
Assignment operator
*/
Knapsack& Knapsack::operator=(const Knapsack kpsac)
{
  delete []data_;
  data_ = new Package[kpsac.capacity_];
  copy(kpsac.data_, kpsac.data_+kpsac.size_, data_);
  size_ = kpsac.size_;
  capacity_ = kpsac.capacity_;
  weight_limit_= kpsac.weight_limit_;
  return *this;
}

/*
Checks the Knaps to see if adding the package will exceed Capacity or max weight.
adds package accordinly.
*/
bool Knapsack::add(const Package& pk)
{
  long pk_w = pk.weight_;
  long ks_weight = this->weight();
  if(ks_weight + pk_w > weight_limit_)
    return false;
  else
  {
    if(size_ +1>capacity_)
    {
      long n_size = capacity_ *2;
      capacity_ = n_size;
      Package *holder= new Package[n_size];
      copy(data_, data_+size_, holder);

      delete data_;
      data_ = new Package[n_size];
      copy(holder, holder+n_size, data_);
      delete []holder;

      data_[size_]=pk;
      size_++;

      return true;
    }
    else
    {
      data_[size_]=pk;
      size_++;
      return true;
    }
  }
}


/*
sum of the weight of the Packages the Knapsack currently holds
*/
long Knapsack::weight() const
{
  long sum=0;
  if (this->empty())
    return sum;
  else
  {
    for(auto iter=data_; iter != data_+size_;iter++)
      {
        long weight = iter->weight_;
        sum += weight;
      }
    return sum;
  }
}

/*
returns true if the Knapsack is empty, false otherwise
*/
bool Knapsack::empty() const
{
  if (size_ == 0)
    return true;
  else
    return false;
}

/*
sum of the priorities of Packages the Knapsack currently holds
*/
long Knapsack::priority() const
{
  long sum=0;
  if (this->empty())
    return sum;
  else
  {
    for(auto iter=data_; iter != data_+size_;iter++)
      {
        long prio = iter->priority_;
        sum += prio;
      }
    return sum;
  }
}

/*

*/
ostream& operator<<(ostream& out, Knapsack &kp1)
{
  ostringstream oss;
  //long size = kp1.size_;
  //Package data = kp1.data_;
  //long count = 1;
  for (unsigned int i=0; i<kp1.size_;i++)
  {
    if (i == kp1.size_-1)
      oss<< kp1.data_[i];
    else
      oss<< kp1.data_[i]<<", ";
  }

  string s = oss.str();
  oss.clear();
  out<<s;
  return out;
}
