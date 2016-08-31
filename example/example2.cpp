//**************************************************************************//
//                         Welcom to use 3dMatrix                           //
//           this is the example shows how two matrix multiply              //
//**************************************************************************//


// INCLUDE Files



#include "core.hpp"
using namespace MyMatrix;

int main()
{

	Matrix<int, 4, 5> mati4x5;
	mati4x5._print();
	int rawArray[20] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	mati4x5._setValue(rawArray);
	mati4x5._print();
	int rawArray1[25] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25 };
	Matrix<int, 5, 5> mati5x5(rawArray1);
	mati5x5._print();
	Matrix<int, 4, 5> rmati4x5;
	MatrixMultiply<Matrix<int, 4, 5>, Matrix<int, 5, 5>, Matrix<int, 4, 5>, 4, 5, 5>(mati4x5, mati5x5, rmati4x5);
	rmati4x5._print();
	return 1;

}