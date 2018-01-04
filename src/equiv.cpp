// CSCI 3300
// Assignment: 3
// Author:     Joshua Bowen
// File:       equiv.cpp
// Tab stops:  8

// **Say what this program does here.  (replace this comment)**


#include <cstdio>
//#include "equiv.h"
ER newER(int);
int leader(ER &e, int x);
bool together(ER &e, int n, int x);
void combine(ER &e, int n, int x);
void destroyER(ER &e);
void showER(ER &e, int n);
using namespace std;


/*int main(int argc, char** argv)
{
  return 0;
} */

// newER(n) returns an array of n+1 integers.

ER newER (int n)
{
	int* newArray = new int[n+1];
	for (int i = 1; i < (n+1); i++)
	{
		newArray[i] = i;
	}
	return newArray;
}

// leader(ER &e, n) returns the leader of x in equivalence relation e.

int leader(ER &e, int x)
{
	if (e[x] == x)
	{
		return x;
	}
	else
	{
		int m = e[x]
		return leader(e, m);
	}
}

// together(ER &e, x, y) determines if x and y are in the same equivalence class
// in equivalence relation e.

bool together(ER &e, int x, int y)
{
	if (leader(e, x) == leader(e, y))
	{
		return true;
	}
	else
	{
		return false;
	}
}

// combine(ER &e, x, y) combines the equivalence classes of x and y in e.

void combine(ER &e, int x, int y)
{
	if (leader(e, x) == leader(e, y))
	{
		leader(e, x) = leader(e, y);
	}
	else
	{
	}
}

// destroy(ER &e) deallocates e from the memory.

void destroyER(ER &e)
{
	delete e;
}

// showER(ER &e, n) prints the contents of array e of size n.

void showER(ER &e, int n)
{
	for (int i = 1; i <= n; i++)
	{
		printf("%d\n", e[i];
	}
}

