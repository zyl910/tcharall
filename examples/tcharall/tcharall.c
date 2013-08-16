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

/** @addtogroup GROUP_TCHARALL_TCHARALL	tcharall_example
 * Test @ref GROUP_TCHARALL using UTF-8 encoding source file (测试各种编译器使用tchar，源文件使用UTF-8编码).
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
 * ## make command
 * 
 * ### On Linux/Mac platforms
 * 
 * Make narrow char version executable file (生成窄字符版可执行文件):
 * 
 * 	make
 * 
 * Remark (备注):
 * 
 * * Linux/Mac platforms only support narrow char API (Linux/Mac平台仅支持窄字符版API) .
 * * On Linux/Mac platforms, "terminal character set" is usually UTF-8 (在Linux/Mac平台上, "终端字符集"一般为UTF-8). And gcc's "default execution character set" is UTF-8 (且gcc的默认"执行字符集"是UTF-8). So no need to modify character set configuration (所以不需修改字符集配置). 
 * 
 * 
 * ### On Windows platform
 * 
 * Make narrow char version executable file (生成窄字符版可执行文件):
 * 
 * 	make EXFLAGS="-fexec-charset=GB18030"
 * 
 * Make wide char version executable file (生成宽字符版可执行文件):
 * 
 * 	make EXFLAGS="-fexec-charset=GB18030" UNICODE=1
 * 
 * Remark (备注):
 * 
 * * Windows platform support narrow char API & wide char API (Windows平台支持窄字符版API与宽字符版API) . You can use UNICODE variable (您可以使用UNICODE变量).
 * * On Simplified Chinese Windows platform, "terminal character set" is usually GBK (在简体中文Windows平台上, "终端字符集"一般为GBK). So need to use "-fexec-charset" to modify character set configuration (所以需要使用"-fexec-charset"去修改字符集配置). GB18030 is a superset of GBK (GB18030 是 GBK 的超集).
 *
 *
 * ## Tested compiler (测试过的编译器)
 * 
 * * Virtual C++: 7.1(2003), 8(2005), 9(2008), 10(2010), 11(2012).
 * * GCC(Linux): 4.7.0(Fedora 17),  4.7.2(Fedora 18),  4.8.1(Fedora 19).
 * * GCC(MinGW): 4.6.2(MinGW(20120426)), 4.7.1(TDM-GCC(MinGW-w64)).
 * * LLVM GCC: 4.2(Mac OS X Lion 10.7.4), 4.2.1(Mac OS X Mountain Lion 10.8.3).
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
 * @file	tcharall.c
 * @brief	Test @ref GROUP_TCHARALL using UTF-8 encoding source file (测试各种编译器使用tchar，源文件使用UTF-8编码).
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


const char* psa = "A_Welcome_歡迎_ようこそ_환영.";	//!< Narrow char string. "Welcome": English, Traditional Chinese, Japanese, Korean.
const wchar_t* psw = L"W_Welcome_歡迎_ようこそ_환영.";	//!< Wide char string.
const TCHAR* pst = _T("T_Welcome_歡迎_ようこそ_환영.");	//!< TCHAR string.

/// tchar main .
int _tmain(int argc, TCHAR* argv[])
{
	// init.
	setlocale(LC_ALL, "");	// 使用客户环境的缺省locale.

	// title.
	_tprintf(_T("tcharall v1.1 (%dbit)\n"), (int)(8*sizeof(int*)));
	_tprintf(_T("Compiler: %")_T(PRIsA)_T("\n"), COMPILER_NAME);
	_tprintf(_T("\n"));

	// show.
	_tprintf(_T("%")_T(PRIsA)_T("\n"), psa);	// Print narrow char string.
	_tprintf(_T("%")_T(PRIsW)_T("\n"), psw);	// Print wide char string.
	_tprintf(_T("%")_T(PRIsT)_T("\n"), pst);	// Print TCHAR string.
	

	return 0;
}


/** @} */	// @addtogroup GROUP_TCHARALL_TCHARALL
/** @} */	// @addtogroup GROUP_TCHARALL
/** @} */	// @addtogroup GROUP_ZYLLIBC

