//**************************************************************************//
//                         Welcom to use 3dMatrix                           //
//        this is the example shows how to create arbitrary size matrix     //
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
	Matrix<int, 5, 5> matri5x5(rawArray1);
	matri5x5._print();
	return 1;

}