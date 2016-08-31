//**************************************************************************//
//                         Welcom to use 3dMatrix                           //
//           this is the example shows how two matrix subtraction           //
//**************************************************************************//


// INCLUDE Files



#include "core.hpp"
using namespace MyMatrix;

int main()
{


	int rawArray1[25] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25 };
	Matrix<int, 5, 5> mati5x5(rawArray1);
	mati5x5._print();
	Matrix<int, 5, 5> smati5x5;
	smati5x5._loadIdentity();
	Matrix<int, 5, 5> rmati5x5;
	typedef Matrix<int, 5, 5> MatrixType;
	MatrixSubtraction<MatrixType, MatrixType, MatrixType, 5, 5>(mati5x5, smati5x5, rmati5x5);
	rmati5x5._print();
	return 1;

}