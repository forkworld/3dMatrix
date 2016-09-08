/* =========================================================================*
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
	/// 2 columns of vector of  floating-point precision numbers.
	/// There is no guarantee on the actual precision.
	///
	typedef Vector<float, 2> vec2;

	/// 3 columns of vector of  floating-point precision numbers.
	/// There is no guarantee on the actual precision.
	///
	typedef Vector<float, 3> vec3;

	/// 4 columns of vector of  floating-point precision numbers.
	/// There is no guarantee on the actual precision.
	///
	typedef Vector<float, 4> vec4;

	/// 5 columns of vector of  floating-point precision numbers.
	/// There is no guarantee on the actual precision.
	///
	typedef Vector<float, 5> vec5;

	/// 2 columns of vector of  double precision numbers.
	/// There is no guarantee on the actual precision.
	///
	typedef Vector<double, 2> vecd2;

	/// 3 columns of vector of  double precision numbers.
	/// There is no guarantee on the actual precision.
	///
	typedef Vector<double, 3> vecd3;

	/// 4 columns of vector of  double precision numbers.
	/// There is no guarantee on the actual precision.
	///
	typedef Vector<double, 4> vecd4;

	/// 5 columns of vector of  double precision numbers.
	/// There is no guarantee on the actual precision.
	///
	typedef Vector<double, 5> vecd5;

	/// 2 columns of vector of  int precision numbers.
	/// There is no guarantee on the actual precision.
	///
	typedef Vector<int, 2> veci2;

	/// 3 columns of vector of  int precision numbers.
	/// There is no guarantee on the actual precision.
	///
	typedef Vector<int, 3> veci3;

	/// 4 columns of vector of  int precision numbers.
	/// There is no guarantee on the actual precision.
	///
	typedef Vector<int, 4> veci4;

	/// 5 columns of vector of  int precision numbers.
	/// There is no guarantee on the actual precision.
	///
	typedef Vector<int, 5> veci5;
}