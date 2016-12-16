//============================================================================
// Name        : XinTest.cpp
// Author      : Xin Liu
// Version     : v2
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

/// Matrix class that enables flip value functionality
class Mat
{
public:

	/// construct the Matrix with M rows and N columns
	Mat(unsigned int M, unsigned int N)
	: mCols(N)
	, mRows(M)
	, mValue(M, std::vector<unsigned int>(N, 0))
	{}

	/// set value at i-th row, j-th column with value k
	void setValue(unsigned int i, unsigned int j, unsigned int k)
	{
		assert(k == 0 || k==1);
		mValue[i][j] = k;
	}

	/// get value at i-th row, j-th column
	unsigned int getValue(unsigned int i, unsigned int j)
	{
		return mValue[i][j];
	}

	/// flip the values according to the given rule
	void flip()
	{
		for (unsigned int i=0; i<mRows; ++i)
			for (unsigned int j = 0; j < mCols; ++j)
			{
				flipValue(i,j);
			}
	}

	/// print out the matrix
	void print(std::ostream &out)
	{
		for (unsigned i = 0; i < mRows; ++i)
		{
			for (unsigned j = 0; j<mCols; ++j)
				out <<mValue[i][j] <<" ";
			out <<std::endl;
		}
		out <<std::endl;
	}

private:
	/// flip value at index [i,j]
	void flipValue(unsigned int i, unsigned int j)
	{
		// flip value based on label
		switch (mValue[i][j])
		{
		case 0:
			// zero bit
			flipZero(i,j);
			break;
		case 1:
			// 1 bit
			break;
		case 2:
			// original zero values are labeled to 2 during flipZero
			flipTwo(i,j);
			break;
		case 3:
			// original one values are labeled to 3 during flipZero
			mValue[i][j] = 0;
			break;
		}
	}

	/// flip values to labels
	void flipValueToLabels(unsigned int i, unsigned int j)
	{
		if (mValue[i][j] == 0 || mValue[i][j]==2)
		{
			// original 0 or 2 values are labeled to 2
			mValue[i][j] = 2;
		}
		else
		{
			// otherwise values are labeld to 3
			mValue[i][j] = 3;
		}
	}

	/// flip a zero value at [i,j]
	void flipZero(unsigned int i, unsigned int j)
	{
		for (unsigned int rowIdx = 0; rowIdx < j; ++rowIdx)
		{
			mValue[i][rowIdx] = 0;
		}
		for (unsigned int rowIdx = j+1; rowIdx < mCols; ++rowIdx)
		{
			flipValueToLabels(i, rowIdx);
		}

		for (unsigned int colIdx = 0; colIdx < i; ++colIdx)
		{
			mValue[colIdx][j] = 0;
		}
		for (unsigned int colIdx = i+1; colIdx < mRows; ++colIdx)
		{
			flipValueToLabels(colIdx, j);
		}
	}

	/// flip a two value at [i,j]
	void flipTwo(unsigned int i, unsigned int j)
	{
		flipZero(i,j);
		mValue[i][j] = 0;
	}


private:
	/// number of columns
	unsigned int mCols;
	/// number of rows
	unsigned int mRows;
	/// matrix value
	std::vector<std::vector<unsigned int> > mValue;
};

/// small test case
void testMyMat()
{
	unsigned int M = 4;
	unsigned int N = 3;

	std::vector<std::vector<unsigned int> > testValues =
	{{0,1,0}, {1,1,0}, {1,1,1}, {1,1,1}};

	std::vector<std::vector<unsigned int> > expectedValues =
	{{0,0,0}, {0,0,0}, {0,1,0}, {0,1,0}};

	Mat test(4,3);

	for (unsigned int i=0; i<M; ++i)
		for (unsigned int j = 0; j < N; ++j)
		{
			test.setValue(i,j,testValues[i][j]);
		}

	test.flip();

	for (unsigned int i=0; i<M; ++i)
		for (unsigned int j = 0; j < N; ++j)
		{
			assert(test.getValue(i,j)==expectedValues[i][j]);
		}
}

/// manual test case
void runManualTest(std::istream const & in)
{
	unsigned int M, N;
        
	std::cin >>M >>N;
  	
	Mat test(M,N);

	for (unsigned int i = 0; i < M; ++i)
	{
		for (unsigned int j = 0; j <N; ++j)
		{
			unsigned int k;
			std::cin >>k;
			test.setValue(i,j,k);
		}
	}

	test.print(std::cout);

	test.flip();

	test.print(std::cout);
}

int main()
{
	testMyMat();
	runManualTest(std::cin);
	return 0;
}
