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

#include "core.hpp"

namespace MyMatrix
{
	/// 2 columns of 2 components matrix of  floating-point precision numbers.
	/// There is no guarantee on the actual precision.
	///
	typedef Matrix<float, 2, 2> mat2x2;

	/// 3 columns of 3 components matrix of  floating-point precision numbers.
	/// There is no guarantee on the actual precision.
	///
	typedef Matrix<float, 3, 3> mat3x3;

	/// 4 columns of 4 components matrix of  floating-point precision numbers.
	/// There is no guarantee on the actual precision.
	///
	typedef Matrix<float, 4, 4> mat4x4;

	/// 5 columns of 5 components matrix of  floating-point precision numbers.
	/// There is no guarantee on the actual precision.
	///
	typedef Matrix<float, 5, 5> mat5x5;

	/// 2 columns of 2 components matrix of  double precision numbers.
	/// There is no guarantee on the actual precision.
	///
	typedef Matrix<double, 2, 2> matd2x2;

	/// 3 columns of 3 components matrix of  double precision numbers.
	/// There is no guarantee on the actual precision.
	///
	typedef Matrix<double, 3, 3> matd3x3;

	/// 4 columns of 4 components matrix of  double precision numbers.
	/// There is no guarantee on the actual precision.
	///
	typedef Matrix<double, 4, 4> matd4x4;

	/// 5 columns of 5 components matrix of  double precision numbers.
	/// There is no guarantee on the actual precision.
	///
	typedef Matrix<double, 5, 5> matd5x5;

	/// 2 columns of 2 components matrix of  integer precision numbers.
	/// There is no guarantee on the actual precision.
	///
	typedef Matrix<int, 2, 2> mati2x2;

	/// 3 columns of 3 components matrix of  integer precision numbers.
	/// There is no guarantee on the actual precision.
	///
	typedef Matrix<int, 3, 3> mati3x3;

	/// 4 columns of 4 components matrix of  integer precision numbers.
	/// There is no guarantee on the actual precision.
	///
	typedef Matrix<int, 4, 4> mati4x4;

	/// 5 columns of 5 components matrix of  integer precision numbers.
	/// There is no guarantee on the actual precision.
	///
	typedef Matrix<int, 5, 5> mati5x5;

}
