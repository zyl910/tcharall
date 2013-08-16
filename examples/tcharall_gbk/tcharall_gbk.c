//Copyright (c) 2000-2013 zyl910 <zyl910hero@gmail.com>
//
//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this software and associated documentation files (the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions:
//
//The above copyright notice and this permission notice shall be included in
//all copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//THE SOFTWARE.

/** @addtogroup GROUP_ZYLLIBC	zyllibc
 * @{
 */

/** @addtogroup GROUP_TCHARALL	tcharall
 * @{
 */

/** @addtogroup GROUP_TCHARALL_TCHARALLGBK	tcharall_gbk_example
 * Test @ref GROUP_TCHARALL using GBK encoding source file (测试各种编译器使用tchar，源文件使用GBK编码).
 *
 * @author	[zyl910](mailto:zyl910hero@gmail.com)
 * @since	@ref GROUP_TCHARALL 1.0
 * @version	1.1
 * @date	2013-08-16
 *
 * Links:
 *
 * * Git: https://github.com/zyl910/tcharall
 * * Blog: http://www.cnblogs.com/zyl910/tag/tcharall/
 *
 *
 * ## Tested compiler (测试过的编译器)
 * 
 * * Virtual C++: 6, 7.1(2003), 8(2005).
 * * Borland C++ Builder: 6.
 * * GCC(MinGW): 4.6.2(MinGW(20120426)), 4.7.1(TDM-GCC(MinGW-w64)).
 *
 *
 * ## Change history (变更日志)
 *
 * [2013-08-16] v1.1
 *
 * * Using @ref GROUP_TCHARALL v1.1 .
 * * Using Doxygen style comments (使用doxygen规范注释).
 *
 * [2013-01-17] V1.0
 *
 * * Release v1.0 (发布1.0版).
 *
 * @{
 */

/**
 * @file	tcharall_gbk.c
 * @brief	Test @ref GROUP_TCHARALL using GBK encoding source file (测试各种编译器使用tchar，源文件使用GBK编码).
 * @since	@ref GROUP_TCHARALL 1.0
 */


#include <stdio.h>
#include <locale.h>
#include <wchar.h>

#include "auto_tchar.h"
#include "prichar.h"
#include "auto_tmain.h"



// Compiler name
#define MACTOSTR(x)	#x
#define MACROVALUESTR(x)	MACTOSTR(x)
#if defined(__ICL)	// Intel C++
#  if defined(__VERSION__)
#    define COMPILER_NAME	"Intel C++ " __VERSION__
#  elif defined(__INTEL_COMPILER_BUILD_DATE)
#    define COMPILER_NAME	"Intel C++ (" MACROVALUESTR(__INTEL_COMPILER_BUILD_DATE) ")"
#  else
#    define COMPILER_NAME	"Intel C++"
#  endif	// #  if defined(__VERSION__)
#elif defined(_MSC_VER)	// Microsoft VC++
#  if defined(_MSC_FULL_VER)
#    define COMPILER_NAME	"Microsoft VC++ (" MACROVALUESTR(_MSC_FULL_VER) ")"
#  elif defined(_MSC_VER)
#    define COMPILER_NAME	"Microsoft VC++ (" MACROVALUESTR(_MSC_VER) ")"
#  else
#    define COMPILER_NAME	"Microsoft VC++"
#  endif	// #  if defined(_MSC_FULL_VER)
#elif defined(__GNUC__)	// GCC
#  if defined(__CYGWIN__)
#    define COMPILER_NAME	"GCC(Cygmin) " __VERSION__
#  elif defined(__MINGW32__)
#    define COMPILER_NAME	"GCC(MinGW) " __VERSION__
#  else
#    define COMPILER_NAME	"GCC " __VERSION__
#  endif	// #  if defined(__CYGWIN__)
#elif defined(__TURBOC__)	// Borland C++
#  if defined(__BCPLUSPLUS__)
#    define COMPILER_NAME	"Borland C++ (" MACROVALUESTR(__BCPLUSPLUS__) ")"
#  elif defined(__BORLANDC__)
#    define COMPILER_NAME	"Borland C (" MACROVALUESTR(__BORLANDC__) ")"
#  else
#    define COMPILER_NAME	"Turbo C (" MACROVALUESTR(__TURBOC__) ")"
#  endif	// #  if defined(_MSC_FULL_VER)
#else
#  define COMPILER_NAME	"Unknown Compiler"
#endif	// #if defined(__ICL)	// Intel C++


const char* psa = "A_Welcome_歡迎_ようこそ.";	//!< Narrow char string. "Welcome": English, Traditional Chinese, Japanese.
const wchar_t* psw = L"W_Welcome_歡迎_ようこそ_\uD658\uC601.";	//!< Wide char string. "\uD658\uC601" is Korean Welcome.
const TCHAR* pst = _T("T_Welcome_歡迎_ようこそ.");	//!< TCHAR string.

/// tchar main .
int _tmain(int argc, TCHAR* argv[])
{
	// init.
	setlocale(LC_ALL, "");	// 使用客户环境的缺省locale.

	// title.
	_tprintf(_T("tcharall_gbk v1.1 (%dbit)\n"), (int)(8*sizeof(int*)));
	_tprintf(_T("Compiler: %")_T(PRIsA)_T("\n"), COMPILER_NAME);
	_tprintf(_T("\n"));

	// show.
	_tprintf(_T("%")_T(PRIsA)_T("\n"), psa);	// Print narrow char string.
	_tprintf(_T("%")_T(PRIsW)_T("\n"), psw);	// Print wide char string.
	_tprintf(_T("%")_T(PRIsT)_T("\n"), pst);	// Print TCHAR string.
	

	return 0;
}


/** @} */	// @addtogroup GROUP_TCHARALL_TCHARALLGBK
/** @} */	// @addtogroup GROUP_TCHARALL
/** @} */	// @addtogroup GROUP_ZYLLIBC

