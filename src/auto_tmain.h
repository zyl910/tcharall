////////////////////////////////////////////////////////////
/*
auto_tmain.h : 使各种编译器兼容_tmain .
Author: zyl910
Blog: http://www.cnblogs.com/zyl910
URL: http://www.cnblogs.com/zyl910/archive/2013/01/17/tcharall.html
Version: V1.00
Updata: 2013-01-17


Update
~~~~~~

[2013-01-17] V1.00
* V1.0发布.


Manual
~~~~~~

智能地使_tmain可用.
只需在主源文件中加上一行——
#include "auto_tmain.h"


兼容 VC、GCC、BCB。

参考了 https://github.com/coderforlife/mingw-unicode-main/blob/master/mingw-unicode.c

*/
////////////////////////////////////////////////////////////

/** @addtogroup GROUP_ZYLLIBC	zyllibc
 * @{
 */

/** @addtogroup GROUP_TCHARALL	tcharall
 * @{
 */

/**
 * @file	auto_tmain.h
 * @brief	Auto support `_tmain` (使各种编译器兼容 `_tmain` 入口函数).
 * @since	@ref GROUP_TCHARALL 1.0
 *
 * Just add one line (只需在主源文件中加上一行):
 *
 * 	#include "auto_tmain.h"
 *
 *
 * References (参考了) :
 *
 * * https://github.com/coderforlife/mingw-unicode-main/blob/master/mingw-unicode.c
 *
 */

#ifndef __AUTO_TMAIN_H_INCLUDED
#define __AUTO_TMAIN_H_INCLUDED

#if defined(__GNUC__) && defined(_UNICODE)

#ifndef __MSVCRT__
#error Unicode main function requires linking to MSVCRT
#endif

#include <wchar.h>
#include <stdlib.h>
#include "tchar.h"

#undef _tmain
#ifdef _UNICODE
#define _tmain wmain
#else
#define _tmain main
#endif


extern int _CRT_glob;
extern 
#ifdef __cplusplus
"C" 
#endif
void __wgetmainargs(int*,wchar_t***,wchar_t***,int,int*);

#ifdef MAIN_USE_ENVP
int wmain(int argc, wchar_t *argv[], wchar_t *envp[]);
#else
int wmain(int argc, wchar_t *argv[]);
#endif

int main(void)
{
	wchar_t **enpv, **argv;
	int argc=0, si = 0;
	__wgetmainargs(&argc, &argv, &enpv, _CRT_glob, &si); // this also creates the global variable __wargv
#ifdef MAIN_USE_ENVP
	return wmain(argc, argv, enpv);
#else
	return wmain(argc, argv);
#endif	// #ifdef MAIN_USE_ENVP
}

#endif	// #if defined(__GNUC__) && defined(_UNICODE)

#endif	// #ifndef __AUTO_TMAIN_H_INCLUDED

/** @} */	// @addtogroup GROUP_TCHARALL
/** @} */	// @addtogroup GROUP_ZYLLIBC
