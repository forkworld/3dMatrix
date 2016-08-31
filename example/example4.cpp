//**************************************************************************//
//                         Welcom to use 3dMatrix                           //
//        this is the example shows how to create an identity matrix        //
//**************************************************************************//


// INCLUDE Files

#include "core.hpp"
using namespace MyMatrix;

int main()
{


	int rawArray1[25] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25 };
	Matrix<int, 5, 5> matri5x5(rawArray1);
	matri5x5._print();
	matri5x5._loadIdentity();
	matri5x5._print();
	return 1;

}