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
