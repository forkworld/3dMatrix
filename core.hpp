/* ========================================================================= *
*                                                                           *
*                               3dMatrix                                    *
*                          Copyright (c) 2016-8-31                          *
*                            Author: Sicheng Ren                            *
*                          Email: forkworld@163.com                         *
*                           All rights reserved.                            *
*                                                                           *
*                                                                           *
*---------------------------------------------------------------------------*
* This file is part of 3dMatrix.                                            *
*---------------------------------------------------------------------------*
*                                                                           *
* Redistribution and use in source and binary forms, with or without        *
* modification, are permitted provided that the following conditions        *
* are met:                                                                  *
*                                                                           *
* 1. Redistributions of source code must retain the above copyright notice, *
*    this list of conditions and the following disclaimer.                  *
*                                                                           *
* 2. Redistributions in binary form must reproduce the above copyright      *
*    notice, this list of conditions and the following disclaimer in the    *
*    documentation and/or other materials provided with the distribution.   *
*                                                                           *
* 3. Neither the name of the copyright holder nor the names of its          *
*    contributors may be used to endorse or promote products derived from   *
*    this software without specific prior written permission.               *
*                                                                           *
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS       *
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED *
* TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A           *
* PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER *
* OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  *
* EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,       *
* PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR        *
* PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF    *
* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING      *
* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS        *
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.              *
*                                                                           *
* ========================================================================= */

/*===========================================================================*\
*                                                                           *
*   $Revision$                                                         *
*   $Date$                   *
*                                                                           *
\*===========================================================================*/


//== INCLUDES =================================================================
#include <iostream>

// the class of one row and column dot product

namespace MyMatrix
{ 

template <class T1, class T2, int M, int col, class TR>
class _RowColDotProduct
{
public:
	static TR calc(T1 matrix1, T2 matrix2);
};

template <class T1, class T2, int M, int col, class TR>
TR _RowColDotProduct<T1, T2, M, col, TR>::calc(T1 matrix1, T2 matrix2)
{
	return matrix1[0] * matrix2[0] + _RowColDotProduct<T1, T2, M - 1, col, TR>::calc(&matrix1[col], &matrix2[1]);
}

template <class T1, class T2, int col, class TR>
class _RowColDotProduct < T1, T2, 1, col, TR >
{
public:
	static TR calc(T1 matrix1, T2 matrix2);
};

template <class T1, class T2, int col, class TR>
TR _RowColDotProduct<T1, T2, 1, col, TR>::calc(T1 matrix1, T2 matrix2)
{
	return matrix1[0] * matrix2[0];
}


// one row and column dot product, the help function
template <class T1, class T2, int M, int col, class TR>
TR RowColDotProduct(T1 matrix1, T2 matrix2)
{
	return _RowColDotProduct<T1, T2, M, col, TR>::calc(matrix1, matrix2);

}


// the class of OneRowCalc
template <class T1, class T2, class T3, int M, int L, int col, class TR>
class _OneRowCalc
{
public:
	static void calc(T1 matrix1, T2 matrix2, T3 matrix3);
};

template <class T1, class T2, class T3, int M, int L, int col, class TR>
void _OneRowCalc<T1, T2, T3, M, L, col, TR>::calc(T1 matrix1, T2 matrix2, T3 matrix3)
{
	matrix3[0] = RowColDotProduct<T1, T2, M, col, TR>(matrix1, matrix2);
	_OneRowCalc<T1, T2, T3, M, L - 1, col, TR>::calc(matrix1, &matrix2[M], &matrix3[M]);
}

template <class T1, class T2, class T3, int M, int col, class TR>
class _OneRowCalc < T1, T2, T3, M, 1, col, TR >
{
public:
	static void calc(T1 matrix1, T2 matrix2, T3 matrix3);
};

template <class T1, class T2, class T3, int M, int col, class TR>
void _OneRowCalc<T1, T2, T3, M, 1, col, TR>::calc(T1 matrix1, T2 matrix2, T3 matrix3)
{
	matrix3[0] = RowColDotProduct<T1, T2, M, col, TR>(matrix1, matrix2);
}

// one Row in matrix calculation, the help function
template <class T1, class T2, class T3, int M, int L, int col, class TR>
void OneRowCalc(T1 matrix1, T2 matrix2, T3 matrix3)
{
	_OneRowCalc<T1, T2, T3, M, L, col, TR>::calc(matrix1, matrix2, matrix3);
}

// the class of Matrix multiply
template <class T1, class T2, class T3, int N, int M, int L, int col, class TR = double>
class _MatrixMultiply
{
public:
	static void calc(T1 matrix1, T2 matrix2, T3 matrix3);
};

template <class T1, class T2, class T3, int N, int M, int L, int col, class TR>
void _MatrixMultiply<T1, T2, T3, N, M, L, col, TR>::calc(T1 matrix1, T2 matrix2, T3 matrix3)
{
	OneRowCalc<T1, T2, T3, M, L, col, TR>(matrix1, matrix2, matrix3);
	_MatrixMultiply<T1, T2, T3, N - 1, M, L, col, TR>::calc(&matrix1[1], matrix2, &matrix3[1]);
}



template <class T1, class T2, class T3, int M, int L, int col, class TR>
class _MatrixMultiply < T1, T2, T3, 1, M, L, col, TR >
{
public:
	static void calc(T1 matrix1, T2 matrix2, T3 matrix3);
};


template <class T1, class T2, class T3, int M, int L, int col, class TR>
void _MatrixMultiply<T1, T2, T3, 1, M, L, col, TR>::calc(T1 matrix1, T2 matrix2, T3 matrix3)
{
	OneRowCalc<T1, T2, T3, M, L, col, TR>(matrix1, matrix2, matrix3);
}


//  for calculation Matrix multiply, the help function

template <class T1, class T2, class T3, int N, int M, int L, int Pointerflag>
void MatrixMultiply(T1 matrix1, T2 matrix2, T3 matrix3)
{
	_MatrixMultiply<T1, T2, T3, N, M, L, N>::calc(matrix1, matrix2, matrix3);
}


// added the code
template <class T1, class T2, class T3, int N, int M, int L>
void MatrixMultiply(T1 * matrix1, T2 * matrix2, T3 * matrix3)
{
	typedef T1 * T1p;
	typedef T2 * T2p;
	typedef T3 * T3p;
	_MatrixMultiply<T1p, T2p, T3p, N, M, L, N, T3>::calc(matrix1, matrix2, matrix3);
}

template <class T1, class T2, class T3, int N, int M, int L>
void MatrixMultiply(T1 & matrix1, T2 & matrix2, T3 & matrix3)
{
	typedef typename T1::value_type * T1p;
	typedef typename T2::value_type * T2p;
	typedef typename T3::value_type * T3p;
	typedef typename T3::value_type T3R;
	_MatrixMultiply<T1p, T2p, T3p, N, M, L, N, T3R>::calc(matrix1.array, matrix2.array, matrix3.array);
}

template <class T1, class T2, class T3, int N, int M, int L>
void MatrixMultiply(T1 * matrix1, T2 & matrix2, T3 & matrix3)
{
	typedef T1 * T1p;
	typedef typename T2::value_type * T2p;
	typedef typename T3::value_type * T3p;
	typedef typename T3::value_type T3R;
	_MatrixMultiply<T1p, T2p, T3p, N, M, L, N, T3R>::calc(matrix1, matrix2.array, matrix3.array);

}

template <class T1, class T2, class T3, int N, int M, int L>
void MatrixMultiply(T1 & matrix1, T2 * matrix2, T3 & matrix3)
{
	typedef typename T1::value_type * T1p;
	typedef T2 * T2p;
	typedef typename T3::value_type * T3p;
	typedef typename T3::value_type T3R;
	_MatrixMultiply<T1p, T2p, T3p, N, M, L, N, T3R>::calc(matrix1.array, matrix2, matrix3.array);
}

template <class T1, class T2, class T3, int N, int M, int L>
void MatrixMultiply(T1 & matrix1, T2 * matrix2, T3 * matrix3)
{
	typedef typename T1::value_type * T1p;
	typedef T2 * T2p;
	typedef T3 * T3p;
	_MatrixMultiply<T1p, T2p, T3p, N, M, L, N, T3>::calc(matrix1.array, matrix2, matrix3);
}

template <class T1, class T2, class T3, int N, int M, int L>
void MatrixMultiply(T1 * matrix1, T2 & matrix2, T3 * matrix3)
{
	typedef T1 * T1p;
	typedef typename T2::value_type * T2p;
	typedef T3 * T3p;
	_MatrixMultiply<T1p, T2p, T3p, N, M, L, N, T3>::calc(matrix1, matrix2.array, matrix3);
}

template <class T1, class T2, class T3, int N, int M, int L>
void MatrixMultiply(T1 * matrix1, T2 * matrix2, T3 & matrix3)
{
	typedef T1 * T1p;
	typedef T2 * T2p;
	typedef typename T2::value_type * T3p;
	typedef typename T3::value_type T3R;
	_MatrixMultiply<T1p, T2p, T3p, N, M, L, N, T3R>::calc(matrix1, matrix2, matrix3.array);
}

template <class T1, class T2, class T3, int N, int M, int L>
void MatrixMultiply(T1 & matrix1, T2 & matrix2, T3 * matrix3)
{
	typedef typename T1::value_type T1p;
	typedef typename T2::value_type T2p;
	typedef T3 * T3p;
	_MatrixMultiply<T1p, T2p, T3p, N, M, L, N, T3>::calc(matrix1.array, matrix2.array, matrix3);
}


// the code for the matrix addition
template <class T1, class T2, class T3, int M, int col>
class _OneRowAddition
{
public:
	static void _calc(T1 matrix1, T2 matrix2, T3 matrix3);

};

template <class T1, class T2, class T3, int M, int col>
void _OneRowAddition<T1, T2, T3, M, col>::_calc(T1 matrix1, T2 matrix2, T3 matrix3)
{
	matrix3[0] = matrix1[0] + matrix2[0];
	_OneRowAddition<T1, T2, T3, M - 1, col>::_calc(&matrix1[col], &matrix2[col], &matrix3[col]);
}

template <class T1, class T2, class T3, int col>
class _OneRowAddition<T1, T2, T3, 1, col>
{
public:
	static void _calc(T1 matrix1, T2 matrix2, T3 matrix3);

};

template <class T1, class T2, class T3, int col>
void _OneRowAddition<T1, T2, T3, 1, col>::_calc(T1 matrix1, T2 matrix2, T3 matrix3)
{
	matrix3[0] = matrix1[0] + matrix2[0];
}

template <class T1, class T2, class T3, int M, int col>
void OneRowAddition(T1 matrix1, T2 matrix2, T3 matrix3)
{
	_OneRowAddition<T1, T2, T3, M, col>::_calc(matrix1, matrix2, matrix3);
}

template <class T1, class T2, class T3, int N, int M, int col>
class _MatrixAddition
{
public:
	static void _calc(T1 matrix1, T2 matrix2, T3 matrix3);
};

template <class T1, class T2, class T3, int N, int M, int col>
void _MatrixAddition<T1, T2, T3, N, M, col>::_calc(T1 matrix1, T2 matrix2, T3 matrix3)
{
	OneRowAddition<T1, T2, T3, M, col>(matrix1, matrix2, matrix3);
	_MatrixAddition<T1, T2, T3, N - 1, M, col>::_calc(&matrix1[1], &matrix2[1], &matrix3[1]);
}

template <class T1, class T2, class T3, int M, int col>
class _MatrixAddition<T1, T2, T3, 1, M, col>
{
public:
	static void _calc(T1 matrix, T2 matrix2, T3 matrix3);
};

template <class T1, class T2, class T3, int M, int col>
void _MatrixAddition<T1, T2, T3, 1, M, col>::_calc(T1 matrix1, T2 matrix2, T3 matrix3)
{
	OneRowAddition<T1, T2, T3, M, col>(matrix1, matrix2, matrix3);
}


template <class T1, class T2, class T3, int N, int M, int Pointerflag>
void MatrixAddition(T1 matrix1, T2 matrix2, T3 matrix3)
{
	_MatrixAddition<T1, T2, T3, N, M, N>::_calc(matrix1, matrix2, matrix3);
}


template <class T1, class T2, class T3, int N, int M>
void MatrixAddition(T1 * matrix1, T2 * matrix2, T3 * matrix3)
{
	typedef T1 * T1p;
	typedef T2 * T2p;
	typedef T3 * T3p;
	_MatrixAddition<T1p, T2p, T3p, N, M, N>::_calc(matrix1, matrix2, matrix3);
}

template <class T1, class T2, class T3, int N, int M>
void MatrixAddition(T1 & matrix1, T2 & matrix2, T3 & matrix3)
{
	typedef typename T1::value_type * T1p;
	typedef typename T2::value_type * T2p;
	typedef typename T3::value_type * T3p;
	typedef typename T3::value_type T3R;
	_MatrixAddition<T1p, T2p, T3p, N, M, N>::_calc(matrix1.array, matrix2.array, matrix3.array);
}

template <class T1, class T2, class T3, int N, int M>
void MatrixAddition(T1 * matrix1, T2 & matrix2, T3 & matrix3)
{
	typedef T1 * T1p;
	typedef typename T2::value_type * T2p;
	typedef typename T3::value_type * T3p;
	typedef typename T3::value_type T3R;
	_MatrixAddition<T1p, T2p, T3p, N, M, N>::_calc(matrix1, matrix2.array, matrix3.array);

}

template <class T1, class T2, class T3, int N, int M>
void MatrixAddition(T1 & matrix1, T2 * matrix2, T3 & matrix3)
{
	typedef typename T1::value_type * T1p;
	typedef T2 * T2p;
	typedef typename T3::value_type * T3p;
	typedef typename T3::value_type T3R;
	_MatrixAddition<T1p, T2p, T3p, N, M, N>::_calc(matrix1.array, matrix2, matrix3.array);
}

template <class T1, class T2, class T3, int N, int M>
void MatrixAddition(T1 & matrix1, T2 * matrix2, T3 * matrix3)
{
	typedef typename T1::value_type * T1p;
	typedef T2 * T2p;
	typedef T3 * T3p;
	_MatrixAddition<T1p, T2p, T3p, N, M, N>::_calc(matrix1.array, matrix2, matrix3);
}

template <class T1, class T2, class T3, int N, int M>
void MatrixAddition(T1 * matrix1, T2 & matrix2, T3 * matrix3)
{
	typedef T1 * T1p;
	typedef typename T2::value_type * T2p;
	typedef T3 * T3p;
	_MatrixAddition<T1p, T2p, T3p, N, M, N>::_calc(matrix1, matrix2.array, matrix3);
}

template <class T1, class T2, class T3, int N, int M>
void MatrixAddition(T1 * matrix1, T2 * matrix2, T3 & matrix3)
{
	typedef T1 * T1p;
	typedef T2 * T2p;
	typedef typename T2::value_type * T3p;
	typedef typename T3::value_type T3R;
	_MatrixAddition<T1p, T2p, T3p, N, M, N>::_calc(matrix1, matrix2, matrix3.array);
}

template <class T1, class T2, class T3, int N, int M>
void MatrixAddition(T1 & matrix1, T2 & matrix2, T3 * matrix3)
{
	typedef typename T1::value_type T1p;
	typedef typename T2::value_type T2p;
	typedef T3 * T3p;
	_MatrixAddition<T1p, T2p, T3p, N, M, N>::_calc(matrix1.array, matrix2.array, matrix3);
}


// matrix subStraction
template <class T1, class T2, class T3, int M, int col>
class _OneRowSubtraction
{
public:
	static void _calc(T1 matrix1, T2 matrix2, T3 matrix3);

};

template <class T1, class T2, class T3, int M, int col>
void _OneRowSubtraction<T1, T2, T3, M, col>::_calc(T1 matrix1, T2 matrix2, T3 matrix3)
{
	matrix3[0] = matrix1[0] - matrix2[0];
	_OneRowSubtraction<T1, T2, T3, M - 1, col>::_calc(&matrix1[col], &matrix2[col], &matrix3[col]);
}

template <class T1, class T2, class T3, int col>
class _OneRowSubtraction<T1, T2, T3, 1, col>
{
public:
	static void _calc(T1 matrix1, T2 matrix2, T3 matrix3);

};

template <class T1, class T2, class T3, int col>
void _OneRowSubtraction<T1, T2, T3, 1, col>::_calc(T1 matrix1, T2 matrix2, T3 matrix3)
{
	matrix3[0] = matrix1[0] - matrix2[0];
}

template <class T1, class T2, class T3, int M, int col>
void OneRowSubtraction(T1 matrix1, T2 matrix2, T3 matrix3)
{
	_OneRowSubtraction<T1, T2, T3, M, col>::_calc(matrix1, matrix2, matrix3);
}

template <class T1, class T2, class T3, int N, int M, int col>
class _MatrixSubtraction
{
public:
	static void _calc(T1 matrix1, T2 matrix2, T3 matrix3);
};

template <class T1, class T2, class T3, int N, int M, int col>
void _MatrixSubtraction<T1, T2, T3, N, M, col>::_calc(T1 matrix1, T2 matrix2, T3 matrix3)
{
	OneRowSubtraction<T1, T2, T3, M, col>(matrix1, matrix2, matrix3);
	_MatrixSubtraction<T1, T2, T3, N - 1, M, col>::_calc(&matrix1[1], &matrix2[1], &matrix3[1]);
}

template <class T1, class T2, class T3, int M, int col>
class _MatrixSubtraction<T1, T2, T3, 1, M, col>
{
public:
	static void _calc(T1 matrix, T2 matrix2, T3 matrix3);
};

template <class T1, class T2, class T3, int M, int col>
void _MatrixSubtraction<T1, T2, T3, 1, M, col>::_calc(T1 matrix1, T2 matrix2, T3 matrix3)
{
	OneRowSubtraction<T1, T2, T3, M, col>(matrix1, matrix2, matrix3);
}


template <class T1, class T2, class T3, int N, int M, int Pointerflag>
void MatrixSubtraction(T1 matrix1, T2 matrix2, T3 matrix3)
{
	_MatrixSubtraction<T1, T2, T3, N, M, N>::_calc(matrix1, matrix2, matrix3);
}


template <class T1, class T2, class T3, int N, int M>
void MatrixSubtraction(T1 * matrix1, T2 * matrix2, T3 * matrix3)
{
	typedef T1 * T1p;
	typedef T2 * T2p;
	typedef T3 * T3p;
	_MatrixSubtraction<T1p, T2p, T3p, N, M, N>::_calc(matrix1, matrix2, matrix3);
}

template <class T1, class T2, class T3, int N, int M>
void MatrixSubtraction(T1 & matrix1, T2 & matrix2, T3 & matrix3)
{
	typedef typename T1::value_type * T1p;
	typedef typename T2::value_type * T2p;
	typedef typename T3::value_type * T3p;
	typedef typename T3::value_type T3R;
	_MatrixSubtraction<T1p, T2p, T3p, N, M, N>::_calc(matrix1.array, matrix2.array, matrix3.array);
}

template <class T1, class T2, class T3, int N, int M>
void MatrixSubtraction(T1 * matrix1, T2 & matrix2, T3 & matrix3)
{
	typedef T1 * T1p;
	typedef typename T2::value_type * T2p;
	typedef typename T3::value_type * T3p;
	typedef typename T3::value_type T3R;
	_MatrixSubtraction<T1p, T2p, T3p, N, M, N>::_calc(matrix1, matrix2.array, matrix3.array);

}

template <class T1, class T2, class T3, int N, int M>
void MatrixSubtraction(T1 & matrix1, T2 * matrix2, T3 & matrix3)
{
	typedef typename T1::value_type * T1p;
	typedef T2 * T2p;
	typedef typename T3::value_type * T3p;
	typedef typename T3::value_type T3R;
	_MatrixSubtraction<T1p, T2p, T3p, N, M, N>::_calc(matrix1.array, matrix2, matrix3.array);
}

template <class T1, class T2, class T3, int N, int M>
void MatrixSubtraction(T1 & matrix1, T2 * matrix2, T3 * matrix3)
{
	typedef typename T1::value_type * T1p;
	typedef T2 * T2p;
	typedef T3 * T3p;
	_MatrixSubtraction<T1p, T2p, T3p, N, M, N>::_calc(matrix1.array, matrix2, matrix3);
}

template <class T1, class T2, class T3, int N, int M>
void MatrixSubtraction(T1 * matrix1, T2 & matrix2, T3 * matrix3)
{
	typedef T1 * T1p;
	typedef typename T2::value_type * T2p;
	typedef T3 * T3p;
	_MatrixSubtraction<T1p, T2p, T3p, N, M, N>::_calc(matrix1, matrix2.array, matrix3);
}

template <class T1, class T2, class T3, int N, int M>
void MatrixSubtraction(T1 * matrix1, T2 * matrix2, T3 & matrix3)
{
	typedef T1 * T1p;
	typedef T2 * T2p;
	typedef typename T2::value_type * T3p;
	typedef typename T3::value_type T3R;
	_MatrixSubtraction<T1p, T2p, T3p, N, M, N>::_calc(matrix1, matrix2, matrix3.array);
}

template <class T1, class T2, class T3, int N, int M>
void MatrixSubtraction(T1 & matrix1, T2 & matrix2, T3 * matrix3)
{
	typedef typename T1::value_type T1p;
	typedef typename T2::value_type T2p;
	typedef T3 * T3p;
	_MatrixSubtraction<T1p, T2p, T3p, N, M, N>::_calc(matrix1.array, matrix2.array, matrix3);
}

// the matrix scale code

template <class T1, class T2, int M, int col>
class _OneRowScale
{
public:
	static void _calc(T1 matrix, const T2 & factor);
};

template <class T1, class T2, int M, int col>
void _OneRowScale<T1, T2, M, col>::_calc(T1 matrix, const T2 & factor)
{
	matrix[0] = factor*matrix[0];
	_OneRowScale<T1, T2, M - 1, col>::_calc(&matrix[col], factor);
}

template <class T1, class T2, int col>
class _OneRowScale<T1, T2, 1, col>
{
public:
	static void _calc(T1 matrix, const T2 & factor);

};

template <class T1, class T2, int col>
void _OneRowScale<T1, T2, 1, col>::_calc(T1 matrix, const T2 & factor)
{
	matrix[0] = factor*matrix[0];
}

template <class T1, class T2, int M, int col>
void OneRowScale(T1 matrix, const T2 & factor)
{
	_OneRowScale<T1, T2, M, col>::_calc(matrix, factor);
}

template <class T1, class T2, int N, int M, int col>
class _MatrixScale
{
public:
	static void _calc(T1 matrix, const T2 & factor);
};

template <class T1, class T2, int N, int M, int col>
void _MatrixScale<T1, T2, N, M, col>::_calc(T1 matrix, const T2 & factor)
{
	OneRowScale<T1, T2, M, col>(matrix, factor);
	_MatrixScale<T1, T2, N - 1, M, col>::_calc(&matrix[1], factor);
}

template <class T1, class T2, int M, int col>
class _MatrixScale<T1, T2, 1, M, col>
{
public:
	static void _calc(T1 matrix, const T2 & factor);
};

template <class T1, class T2, int M, int col>
void _MatrixScale<T1, T2, 1, M, col>::_calc(T1 matrix, const T2 & factor)
{
	OneRowScale<T1, T2, M, col>(matrix, factor);
}

template <class T1, class T2, int N, int M, int Pointerflag>
void MatrixScale(T1 matrix, const T2 & factor)
{
	_MatrixScale<T1, T2, N, M, N>::_calc(matrix, factor);
}

template <class T1, class T2, int N, int M>
void MatrixScale(T1 * matrix, const T2 & factor)
{
	typedef T1 * T1p;
	_MatrixScale<T1p, T2, N, M, N>::_calc(matrix, factor);
}

template <class T1, class T2, int N, int M>
void MatrixScale(T1 & matrix, const T2 & factor)
{
	typedef typename T1::value_type * T1p;
	_MatrixScale<T1p, T2, N, M, N>::_calc(matrix.array, factor);
}

// the code for vector dot product
template <class T1, class T2, class T3, int N>
class _dotProduct
{
public:
	static T3 _calc(T1 vec1, T2 vec2);
};

template <class T1, class T2, class T3, int N>
T3 _dotProduct<T1, T2, T3, N>::_calc(T1 vec1, T2 vec2)
{
	return vec1[0] * vec2[0] + _dotProduct<T1, T2, T3, N - 1>::_calc(&vec1[1], &vec2[1]);
}

template <class T1, class T2, class T3>
class _dotProduct<T1, T2, T3, 1>
{
public:
	static T3 _calc(T1 vec1, T2 vec2);
};

template <class T1, class T2, class T3>
T3 _dotProduct<T1, T2, T3, 1>::_calc(T1 vec1, T2 vec2)
{

	return vec1[0] * vec2[0];
}

template <class T1, class T2, class T3, int N, int Pointerflag>
T3 dotProduct(T1 vec1, T2 vec2)
{
	return _dotProduct<T1, T2, T3, N>::_calc(vec1, vec2);
}

template <class T1, class T2, class T3, int N>
T3 dotProduct(T1 * vec1, T2 * vec2)
{
	typedef T1 * T1p;
	typedef T2 * T2p;
	return _dotProduct<T1p, T2p, T3, N>::_calc(vec1, vec2);
}

template <class T1, class T2, class T3, int N>
T3 dotProduct(T1 & vec1, T2 & vec2)
{
	typedef typename T1::value_type * T1p;
	typedef typename T2::value_type * T2p;
	return _dotProduct<T1p, T2p, T3, N>::_calc(vec1.array, vec2.array);
}

template <class T1, class T2, class T3, int N>
T3 dotProduct(T1 & vec1, T2 * vec2)
{
	typedef typename T1::value_type * T1p;
	typedef T2 * T2p;
	return _dotProduct<T1p, T2p, T3, N>::_calc(vec1.array, vec2);
}

template <class T1, class T2, class T3, int N>
T3 dotProduct(T1 * vec1, T2 & vec2)
{
	typedef T1 * T1p;
	typedef typename T2::value_type * T2p;
	return _dotProduct<T1p, T2p, T3, N>::_calc(vec1, vec2.array);
}

//the code for Vector Plus
template <class T1, class T2, class T3, int N>
class _VecAddition
{
public:
	static void _calc(T1 vec1, T2 vec2, T3 vec3);
};

template <class T1, class T2, class T3, int N>
void _VecAddition<T1, T2, T3, N>::_calc(T1 vec1, T2 vec2, T3 vec3)
{
	vec3[0] = vec1[0] + vec2[0];
	_VecAddition<T1, T2, T3, N - 1>::_calc(&vec1[1], &vec2[1], &vec3[1]);
}

template <class T1, class T2, class T3>
class _VecAddition<T1, T2, T3, 1>
{
public:
	static void _calc(T1 vec1, T2 vec2, T3 vec3);
};

template <class T1, class T2, class T3>
void _VecAddition<T1, T2, T3, 1>::_calc(T1 vec1, T2 vec2, T3 vec3)
{
	vec3[0] = vec1[0] + vec2[0];
}

template <class T1, class T2, class T3, int N, int Pointerflag>
void VecAddition(T1 vec1, T2 vec2, T3 vec3)
{
	_VecAddition<T1, T2, T3, N>::_calc(vec1, vec2, vec3);
}

template <class T1, class T2, class T3, int N>
void VecAdditon(T1 vec1, T2 vec2, T3 vec3)
{
	typedef typename T1::value_type * T1p;
	typedef typename T2::value_type * T2p;
	typedef typename T3::value_type * T3p;
	_VecAddition<T1p, T2p, T3p, N>::_calc(vec1.array, vec2.array, vec3.array);
}

template <class T1, class T2, class T3, int N>
void VecAddition(T1 * vec1, T2 vec2, T3 vec3)
{
	typedef T1 * T1p;
	typedef typename T2::value_type * T2p;
	typedef typename T3::value_type * T3p;
	_VecAddition<T1p, T2p, T3p, N>::_calc(vec1, vec2.array, vec3.array);
}

template <class T1, class T2, class T3, int N>
void VecAddition(T1 vec1, T2 *vec2, T3 vec3)
{
	typedef typename T1::value_type * T1p;
	typedef T2 * T2p;
	typedef typename T3::value_type * T3p;
	_VecAddition<T1p, T2p, T3p, N>::_calc(vec1.array, vec2, vec3.array);
}

template <class T1, class T2, class T3, int N>
void VecAddition(T1 * vec1, T2 * vec2, T3 vec3)
{
	typedef T1 * T1p;
	typedef T2 * T2p;
	typedef typename T3::value_type * T3p;
	_VecAddition<T1p, T2p, T3p, N>::_calc(vec1, vec2, vec3.array);
}

template<class T1, class T2, class T3, int N>
void VecAddition(T1 vec1, T2 vec2, T3 * vec3)
{
	typedef typename T1::value_type * T1p;
	typedef typename T2::value_type * T2p;
	typedef T3 * T3p;
	_VecAddition<T1p, T2p, T3p, N>::_calc(vec1.array, vec2.array, vec3);
}

template <class T1, class T2, class T3, int N>
void VecAddition(T1 vec1, T2 * vec2, T3 * vec3)
{
	typedef typename T1::value_type * T1p;
	typedef T2 * T2p;
	typedef T3 * T3p;
	_VecAddition<T1p, T2p, T3p, N>::_calc(vec1.array, vec2, vec3);
}

template <class T1, class T2, class T3, int N>
void VecAddition(T1 * vec1, T2 * vec2, T3 * vec3)
{
	typedef T1 * T1p;
	typedef T2 * T2p;
	typedef T3 * T3p;
	_VecAddition<T1p, T2p, T3p, N>::_calc(vec1, vec2, vec3);
}

template <class T1, class T2, class T3, int N>
void VecAddition(T1 * vec1, T2 vec2, T3 * vec3)
{
	typedef T1 * T1p;
	typedef typename T2::value_type * T2p;
	typedef T3 * T3p;
	_VecAddition<T1p, T2p, T3p, N>::_calc(vec1, vec2.array, vec3);
}


// the code for vector subtraction

template <class T1, class T2, class T3, int N>
class _VecSubtration
{
public:
	static void _calc(T1 vec1, T2 vec2, T3 vec3);
};

template <class T1, class T2, class T3, int N>
void _VecSubtration<T1, T2, T3, N>::_calc(T1 vec1, T2 vec2, T3 vec3)
{
	vec3[0] = vec1[0] - vec2[0];
	_VecSubtration<T1, T2, T3, N - 1>::_calc(&vec1[1], &vec2[1], &vec3[1]);
}

template <class T1, class T2, class T3>
class _VecSubtration<T1, T2, T3, 1>
{
public:
	static void _calc(T1 vec1, T2 vec2, T3 vec3);
};

template <class T1, class T2, class T3>
void _VecSubtration<T1, T2, T3, 1>::_calc(T1 vec1, T2 vec2, T3 vec3)
{
	vec3[0] = vec1[0] - vec2[0];
}

template <class T1, class T2, class T3, int N, int Pointerflag>
void VecSubtration(T1 vec1, T2 vec2, T3 vec3)
{
	_VecSubtration<T1, T2, T3, N>::_calc(vec1, vec2, vec3);
}

template <class T1, class T2, class T3, int N>
void VecSubtration(T1 vec1, T2 vec2, T3 vec3)
{
	typedef typename T1::value_type * T1p;
	typedef typename T2::value_type * T2p;
	typedef typename T3::value_type * T3p;
	_VecSubtration<T1p, T2p, T3p, N>::_calc(vec1.array, vec2.array, vec3.array);
}

template <class T1, class T2, class T3, int N>
void VecSubtration(T1 * vec1, T2 vec2, T3 vec3)
{
	typedef T1 * T1p;
	typedef typename T2::value_type * T2p;
	typedef typename T3::value_type * T3p;
	_VecSubtration<T1p, T2p, T3p, N>::_calc(vec1, vec2.array, vec3.array);
}

template <class T1, class T2, class T3, int N>
void VecSubtration(T1 vec1, T2 *vec2, T3 vec3)
{
	typedef typename T1::value_type * T1p;
	typedef T2 * T2p;
	typedef typename T3::value_type * T3p;
	_VecSubtration<T1p, T2p, T3p, N>::_calc(vec1.array, vec2, vec3.array);
}

template <class T1, class T2, class T3, int N>
void VecSubtration(T1 * vec1, T2 * vec2, T3 vec3)
{
	typedef T1 * T1p;
	typedef T2 * T2p;
	typedef typename T3::value_type * T3p;
	_VecSubtration<T1p, T2p, T3p, N>::_calc(vec1, vec2, vec3.array);
}

template<class T1, class T2, class T3, int N>
void VecSubtration(T1 vec1, T2 vec2, T3 * vec3)
{
	typedef typename T1::value_type * T1p;
	typedef typename T2::value_type * T2p;
	typedef T3 * T3p;
	_VecSubtration<T1p, T2p, T3p, N>::_calc(vec1.array, vec2.array, vec3);
}

template <class T1, class T2, class T3, int N>
void VecSubtration(T1 vec1, T2 * vec2, T3 * vec3)
{
	typedef typename T1::value_type * T1p;
	typedef T2 * T2p;
	typedef T3 * T3p;
	_VecSubtration<T1p, T2p, T3p, N>::_calc(vec1.array, vec2, vec3);
}

template <class T1, class T2, class T3, int N>
void VecSubtration(T1 * vec1, T2 * vec2, T3 * vec3)
{
	typedef T1 * T1p;
	typedef T2 * T2p;
	typedef T3 * T3p;
	_VecSubtration<T1p, T2p, T3p, N>::_calc(vec1, vec2, vec3);
}

template <class T1, class T2, class T3, int N>
void VecSubtration(T1 * vec1, T2 vec2, T3 * vec3)
{
	typedef T1 * T1p;
	typedef typename T2::value_type * T2p;
	typedef T3 * T3p;
	_VecSubtration<T1p, T2p, T3p, N>::_calc(vec1, vec2.array, vec3);
}

template <class T1, class T2, int N>
class _VecScale
{
public:
	static void _calc(T1 vec, const T2 & factor);
};

template <class T1, class T2, int N>
void _VecScale<T1, T2, N>::_calc(T1 vec, const T2 & factor)
{
	vec[0] = factor * vec[0];
	_VecScale<T1, T2, N - 1>::_calc(&vec[1], factor);
}

template <class T1, class T2>
class _VecScale<T1, T2, 1>
{
public:
	static void _calc(T1 vec, const T2 & factor);
};

template <class T1, class T2>
void _VecScale<T1, T2, 1>::_calc(T1 vec, const T2 & factor)
{
	vec[0] = factor * vec[0];
}

template <class T1, class T2, int N>
void VecScale(T1 vec, const T2 & factor)
{
	_VecScale<T1, T2, N>::_calc(vec, factor);
}
// define vector
template <class T, int N>
class Vector
{
public:
	typedef T value_type;
	value_type array[N];

public:
	Vector();
	Vector(const Vector & vec);
	Vector(const value_type *rawArray);
	void _print();
	void _setValue(const value_type * rawArray);
	void _setValue(const Vector & vec);
	void _setValue(const value_type & value);
private:
	template <class T1, int N1>
	class initialValue
	{
	public:
		static void _initialValue(value_type * rawArray)
		{
			rawArray[0] = 0;
			initialValue<T1, N1 - 1>::_initialValue(&rawArray[1]);
		}
	};

	template <class T1>
	class initialValue<T1, 1>
	{
	public:
		static void _initialValue(value_type * rawArray)
		{
			rawArray[0] = 0;
		}
	};
	template <class T1, int N1>
	class VecSet
	{
	public:
		static void _initialValue(const value_type * rawArray, value_type * rawArray1)
		{
			rawArray1[0] = rawArray[0];
			VecSet<T1, N1 - 1>::_initialValue(&rawArray[1], &rawArray1[1]);
		}
	};
	template <class T1>
	class VecSet<T1, 1>
	{

	public:
		static void _initialValue(const value_type * rawArray, value_type * rawArray1)
		{
			rawArray1[0] = rawArray[0];
		}
	};
	template <class T1, int N1>
	class setIdentity
	{
	public:
		static void _setIdentity(const value_type & value, value_type * rawArray)
		{
			rawArray[0] = value;
			setIdentity<T1, N1 - 1>::_setIdentity(value, &rawArray[1]);
		}
	};
	template <class T1>
	class setIdentity<T1, 1>
	{

	public:
		static void _setIdentity(const value_type & value, value_type * rawArray)
		{
			rawArray[0] = value;
		}
	};
	template <class T1, int N1>
	class printVec
	{
	public:
		static void _printVec(const value_type * rawArray)
		{
			std::cout << rawArray[0] << "     ";
			printVec<T1, N1 - 1>::_printVec(&rawArray[1]);
		}
	};
	template <class T1>
	class printVec<T1, 1>
	{
	public:
		static void _printVec(const value_type * rawArray)
		{
			std::cout << rawArray[0] << "     " << std::endl;
		}
	};
};

template <class T, int N>
Vector<T, N>::Vector()
{
	initialValue<T, N>::_initialValue(this->array);
}

template <class T, int N>
Vector<T, N>::Vector(const value_type *rawArray)
{
	VecSet<T, N>::_initialValue(rawArray, this->array);
}

template <class T, int N>
Vector<T, N>::Vector(const Vector & vec)
{
	VecSet<T, N>::_initialValue(vec.array, this->array);
}

template <class T, int N>
void Vector<T, N>::_setValue(const value_type * rawArray)
{
	VecSet<T, N>::_initialValue(rawArray, this->array);
}

template <class T, int N>
void Vector<T, N>::_setValue(const Vector & vec)
{
	VecSet<T, N>::_initialValue(vec.array, this->array);
}

template <class T, int N>
void Vector<T, N>::_setValue(const T & value)
{
	setIdentity<T, N>::_setIdentity(value, this->array);
}

template <class T, int N>
void Vector<T, N>::_print()
{
	printVec<T, N>::_printVec(this->array);
}

// define matrix
template <class T, int N, int M>
class Matrix
{
public:
	typedef T value_type;
	value_type array[N*M];

public:
	// the constructor and copy constructor
	Matrix();
	Matrix(const Matrix & mat);
	Matrix(const value_type * rawArray);
	Matrix & operator =(const Matrix & mat);

	//format output the result
	void _print();
	void _loadIdentity();
	void _setValue(const value_type * rawArray);
	void _setValue(const Matrix & mat);

private:
	// the help class

	template <class T1, int NM>
	class setValue
	{
	public:
		static void _setValue(value_type * rawArray)
		{
			rawArray[0] = 0;
			setValue<T1, NM - 1>::_setValue(&rawArray[1]);

		}
	};


	template <class T1>
	class setValue < T1, 1 >
	{
	public:
		static void _setValue(value_type * rawArray)
		{
			rawArray[0] = 0;
		}
	};


	template <class T1, int NM>
	class setIdentity
	{
	public:
		static void _setIdentity(value_type * rawArray)
		{
			rawArray[0] = 1;
			setIdentity<T1, NM - 1>::_setIdentity(&rawArray[N + 1]);
		}
	};


	template <class T1>
	class setIdentity < T1, 1 >
	{
	public:
		static void _setIdentity(value_type *rawArray)
		{
			rawArray[0] = 1;
		}
	};


	template <class T1, int NM>
	class matrixSet
	{
	public:
		static void setValue(value_type * rawArray1, const value_type * rawArray2)
		{
			rawArray1[0] = rawArray2[0];
			matrixSet<T1, NM - 1>::setValue(&rawArray1[1], &rawArray2[1]);
		}
	};


	template <class T1>
	class matrixSet < T1, 1 >
	{
	public:
		static void setValue(value_type * rawArray1, const value_type * rawArray2)
		{
			rawArray1[0] = rawArray2[0];
		}
	};


	template <int M1, int col>
	class oneRowPrint
	{
	public:
		static void _oneRowPrint(value_type *rawArray)
		{
			std::cout << rawArray[0] << "     ";
			oneRowPrint<M1 - 1, col>::_oneRowPrint(&rawArray[col]);
		}
	};


	template <int col>
	class oneRowPrint < 1, col >
	{
	public:
		static void _oneRowPrint(value_type *rawArray)
		{
			std::cout << rawArray[0] << std::endl;
		}
	};


	template <int N1, int M1, int col>
	class MatrixPrint
	{
	public:
		static void _MatrixPrint(value_type *rawArray)
		{
			oneRowPrint<M1, col>::_oneRowPrint(rawArray);
			MatrixPrint<N1 - 1, M1, col>::_MatrixPrint(&rawArray[1]);
		}
	};


	template <int M1, int col>
	class MatrixPrint < 1, M1, col >
	{
	public:
		static void _MatrixPrint(value_type *rawArray)
		{
			oneRowPrint<M1, col>::_oneRowPrint(rawArray);
		}

	};

};

template <class T, int N, int M>
Matrix<T, N, M>::Matrix()
{
	setValue<T, N*M>::_setValue(this->array);
}


template <class T, int N, int M>
Matrix<T, N, M>::Matrix(const Matrix & mat)
{
	matrixSet<T, N*M>::setValue(this->array, mat.array);
}

template <class T, int N, int M>
Matrix<T, N, M>::Matrix(const value_type * rawArray)
{
	matrixSet<T, N*M>::setValue(this->array, rawArray);
}


template <class T, int N, int M>
Matrix<T, N, M>& Matrix<T, N, M>::operator=(const Matrix & mat)
{

	matrixSet<T, N*M>::setValue(this->array, mat.array);
	return *this;
}

template <class T, int N, int M>
void Matrix<T, N, M>::_loadIdentity()
{
	setValue<T, N*M>::_setValue(this->array);
	setIdentity<T, N*M>::_setIdentity(this->array);

}

template <class T, int N, int M>
void Matrix<T, N, M>::_print()
{
	MatrixPrint<N, M, N>::_MatrixPrint(this->array);
}


template <class T, int N, int M>
void Matrix<T, N, M>::_setValue(const value_type * rawArray)
{
	matrixSet<T, N*M>::setValue(this->array, rawArray);
}

template <class T, int N, int M>
void Matrix<T, N, M>::_setValue(const Matrix & mat)
{
	matrixSet<T, N*M>::setValue(this->array, mat.array);
}

}
// the test code

int main()
{
	Matrix<int, 4, 3> mat4x3;
	mat4x3._print();
	mat4x3._loadIdentity();
	mat4x3._print();
	int p[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
	int k[12] = { 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4 };

	Matrix<int, 4, 4> mat4x4(p);
	mat4x4._print();
	Matrix<int, 4, 4> matc4x4 = mat4x4;
	std::cout << "---" << std::endl;
	mat4x4._print();
	matc4x4._print();
	matc4x4._loadIdentity();
	matc4x4._print();
	std::cout << "---" << std::endl;
	mat4x4._print();
	std::cout << "---" << std::endl;
	matc4x4 = mat4x4;
	std::cout << "---" << std::endl;
	mat4x4._print();

	matc4x4._print();
	mat4x4._print();

	std::cout << "---" << std::endl;
	std::cout << "---" << std::endl;

	int m[12];
	Matrix<int, 4, 4> matT4x4(p);
	Matrix<int, 4, 3> matT4x3(k);
	Matrix<int, 4, 3> matTr4x3;
	std::cout << "the new test-----------------" << std::endl;
	MatrixMultiply<Matrix<int, 4, 4>, Matrix<int, 4, 3>, Matrix<int, 4, 3>, 4, 4, 3>(matT4x4, matT4x3, matTr4x3);
	matTr4x3._print();
	matT4x4._print();
	std::cout << "the new test------------------" << std::endl;
	MatrixMultiply<int, int, int, 4, 4, 3>(p, k, m);
	for (int i = 0; i<12; ++i)
	{
		std::cout << m[i] << "    ";
	}
	//std::cin.get();
	Matrix<int, 4, 3> matt4x3(m);
	matt4x3._print();


	int k1[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	int k2[16] = { 1, 1, 1, 4, 5, 6, 1, 1, 1, 1, 1, 1 };
	int k3[16];
	MatrixSubtraction<int, int, int, 4, 3>(k1, k2, k3);
	Matrix<int, 4, 3> matK4x4(k3);
	matK4x4._print();

	//for the scale test code
	int kscale[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
	MatrixScale<int, int, 4, 4>(kscale, 2);
	Matrix<int, 4, 4> matrixS4x4(kscale);
	matrixS4x4._print();
	//matrix scale test
	MatrixScale<Matrix<int, 4, 4>, int, 4, 4>(matrixS4x4, 2);
	matrixS4x4._print();

	// the test code for vector dot product
	std::cout << "------- the test code for vector dot product ------" << std::endl;
	int vk1[16] = { 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	int vk2[16] = { 10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

	int result = dotProduct<int, int, int, 16>(vk1, vk2);
	std::cout << "the value of result is " << result << std::endl;

	// test the code for vec
	int vvv[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	Vector<int, 8> vec(vvv);
	Vector<int, 8> vec1(vec);
	vec._print();
	vec1._print();
	int mm[8] = { 2, 3, 4, 5, 6, 7, 8, 9 };
	vec1._setValue(mm);
	vec1._print();
	vec1._setValue(6);
	vec1._print();
	result = dotProduct<Vector<int, 8>, Vector<int, 8>, int, 8>(vec, vec);
	std::cout << "the result is " << result << std::endl;


	//test the code for vec addition
	int uu[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int hh[8] = { 2, 3, 4, 5, 6, 7, 8, 9 };
	int rr[8];
	VecAddition<int, int, int, 8>(uu, hh, rr);
	Vector<int, 8> rrr(rr);
	rrr._print();
	VecSubtration<int, int, int, 8>(uu, hh, rr);
	rrr._setValue(rr);
	//rrr._setValue(uu);
	rrr._print();

	//test the scale code
	VecScale<int *, int, 8>(uu, -1);
	rrr._setValue(uu);
	rrr._print();
	std::cin.get();
	return 1;
}
