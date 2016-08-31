//**************************************************************************//
//                         Welcom to use 3dMatrix                           //
//           this is the example shows how two vector dotProduct            //
//**************************************************************************//


// INCLUDE Files



// INCLUDE Files

#include "core.hpp"
using namespace MyMatrix;

int main()
{

	Vector<int, 25> vec1;
	vec1._print();
	int rawArray[25] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25 };
	vec1._setValue(rawArray);
	vec1._print();
	int rawArray1[25] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25 };
	Vector<int, 25> vec2(rawArray1);
	vec2._print();
	int result = 0;
	result = dotProduct<Vector<int, 25>, Vector<int, 25>, int, 5>(vec1, vec2);
	return 1;

}