////////////////////////////////////////////////////////////
/*
prichar.h : 字符串的格式控制字符.
Author: zyl910
Blog: http://www.cnblogs.com/zyl910
URL: http://www.cnblogs.com/zyl910/archive/2013/01/17/tcharall.html
Version: V1.00
Updata: 2013-01-17


测试过的编译器--
VC: 6, 2003, 2005, 2008, 2010, 2012.
BCB: 6.
GCC: 4.7.1(MinGW-w64), 4.7.0(Fedora 17), 4.6.2(MinGW), llvm-gcc-4.2(Mac OS X Lion 10.7.4, Xcode 4.4.1).


Update
~~~~~~

[2013-01-17] V1.00
* V1.0发布.


Manual
~~~~~~

参考了C99的“inttypes.h”，为字符类型设计的格式字符串。

前缀--
PRI: print, 输出.
SCN: scan, 输入.

中缀--
c: char, 字符.
s: string, 字符串.

后缀--
A: char, 窄字符版.
W: wchar_t, 宽字符版.
T: TCHAR, TCHAR版.


*/
////////////////////////////////////////////////////////////

/** @addtogroup GROUP_ZYLLIBC	zyllibc
 * @{
 */

/** @addtogroup GROUP_TCHARALL	tcharall
 * @{
 */

/**
 * @file	prichar.h
 * @brief	Macros for char types format specifiers (字符类型的格式控制宏).
 * @since	@ref GROUP_TCHARALL 1.0
 *
 * 为字符类型提供格式控制宏，宏名参考了C99的 `inttypes.h`.
 *
 * Prefix (前缀)--
 * * PRI: print (输出).
 * * SCN: scan (输入).
 * 
 * Infix (中缀)--
 * * c: char (字符).
 * * s: string (字符串).
 * 
 * Suffix (后缀)--
 * * A: char (窄字符版).
 * * W: wchar_t (宽字符版).
 * * T: TCHAR (TCHAR版).
 *
 */

#ifndef __PRICHAR_H_INCLUDED
#define __PRICHAR_H_INCLUDED


//#include "tchar.h"

#if defined __cplusplus
extern "C" {
#endif

////////////////////////////////////////
// char
////////////////////////////////////////

#if defined(_MSC_VER)||defined(__BORLANDC__)
	// VC、BCB 均支持hc/hs总是代表窄字符.
	#define PRIcA	"hc"
	#define PRIsA	"hs"
#elif defined(__GNUC__)||defined(_WIN32)||defined(_WIN64)
	// GCC的窄版函数有时无法识别hc/hs, 而宽版函数总是支持hc/hs. 假设其他Windows平台的编译器也是这样.
	#if defined(_UNICODE)
		#define PRIcA	"hc"
		#define PRIsA	"hs"
	#else
		#define PRIcA	"c"
		#define PRIsA	"s"
	#endif
#else
	// 假定其他平台只支持c/s.
	#define PRIcA	"c"
	#define PRIsA	"s"
#endif

/** @def PRIcA
 * [print format] char .
 */

/** @def PRIsA
 * [print format] char string .
 */


////////////////////////////////////////
// wchar_t
////////////////////////////////////////

// C99标准规定lc/ls总是代表宽字符.
#define PRIcW	"lc"	//!< [print format] wchat_t .
#define PRIsW	"ls"	//!< [print format] wchat_t string .


////////////////////////////////////////
// TCHAR
////////////////////////////////////////

#if defined(_WIN32)||defined(_WIN64)||defined(_MSC_VER)
	// VC、BCB、MinGW等Windows平台上的编译器支持c为自适应, 对于窄字符函数是char, 对于宽字符函数是wchar_t.
	#define PRIcT	"c"
	#define PRIsT	"s"
#else
	// 其他平台.
	#if defined(_UNICODE)
		#define PRIcT	PRIcW
		#define PRIsT	PRIsW
	#else
		#define PRIcT	PRIcA
		#define PRIsT	PRIsA
	#endif
#endif

/** @def PRIcT
 * [print format] TCHAR .
 */

/** @def PRIsT
 * [print format] TCHAR string .
 */


////////////////////////////////////////
// SCN
////////////////////////////////////////

#define SCNcA	PRIcA	//!< [scan format] char .
#define SCNsA	PRIsA	//!< [scan format] char string .
#define SCNcW	PRIcW	//!< [scan format] wchat_t .
#define SCNsW	PRIsW	//!< [scan format] wchat_t string .
#define SCNcT	PRIcT	//!< [scan format] TCHAR .
#define SCNsT	PRIsT	//!< [scan format] TCHAR string .


#if defined __cplusplus
};
#endif

#endif	// #ifndef __PRICHAR_H_INCLUDED

/** @} */	// @addtogroup GROUP_TCHARALL
/** @} */	// @addtogroup GROUP_ZYLLIBC
