////////////////////////////////////////////////////////////
/*
tcharall.c : 测试各种编译器使用tchar（GBK编码）.
Author: zyl910
Blog: http://www.cnblogs.com/zyl910
URL: http://www.cnblogs.com/zyl910/archive/2013/01/17/tcharall.html
Version: V1.00
Updata: 2013-01-17


Update
~~~~~~

[2013-01-17] V1.00
* V1.0发布.

[2012-11-08] V0.01
* 初步完成.

*/
////////////////////////////////////////////////////////////

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


char* psa = "A汉字ABC_Welcome_歡迎_ようこそ.";
wchar_t* psw = L"W汉字ABC_Welcome_歡迎_ようこそ_\uD658\uC601.";	// \uD658\uC601是韩文欢迎.
TCHAR* pst = _T("T汉字ABC_Welcome_歡迎_ようこそ.");


int _tmain(int argc, TCHAR* argv[])
{
	// init.
	setlocale(LC_ALL, "");	// 使用客户环境的缺省locale.

	_tprintf(_T("tcharall_gbk v1.00 (%dbit)\n"), (int)(8*sizeof(int*)));
	_tprintf(_T("Compiler: %")_T(PRIsA)_T("\n"), COMPILER_NAME);
	_tprintf(_T("\n"));

	// show
	_tprintf(_T("%")_T(PRIsA)_T("\n"), psa);	// 输出窄字符串.
	_tprintf(_T("%")_T(PRIsW)_T("\n"), psw);	// 输出宽字符串.
	_tprintf(_T("%")_T(PRIsT)_T("\n"), pst);	// 输出TCHAR字符串.
	

	return 0;
}

