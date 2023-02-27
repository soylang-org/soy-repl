#pragma once
/*
==================================================================
Copyright (c) 2023 Jesse Stojan.

Redistribution and use in source and binary forms,
with or without modification, are permitted provided
that the following conditions are met:

1.	Redistributions of source code must retain the above copyright
	notice, this list of conditions and the following disclaimer.

2.	Redistributions in binary form must reproduce the above
	copyright notice, this list of conditions and the following
	disclaimer in the documentation and/or other materials
	provided with the distribution.

3.	Neither the name of the copyright holder nor the names of its
	contributors may be used to endorse or promote products derived
	from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
CONTRIBUTORS “AS IS” AND ANY EXPRESS OR IMPLIED WARRANTIES,
INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
==================================================================
Please visit https://soylang.org for change logs, documentation,
news, updates, and resources related to Soy programming language.

Change Log: https://soylang.org/changelog/soy-repl/inc/common/platform.hh
==================================================================
*/

//////////////////////////////////////////////////////////////////
#ifndef __SOY_REPL_COMMON_HH__
#define __SOY_REPL_COMMON_HH__
//////////////////////////////////////////////////////////////////

//================================================================
#if defined(_MSC_VER) && defined(_WIN32)
//----------------------------------------------------------------
// win32
//----------------------------------------------------------------
#ifndef WIN32_LEAN_AND_MEAN
// Define to exclude some breaking windows headers (originally was meant to just reduce compile times on older windows platforms)
#define WIN32_LEAN_AND_MEAN				1
#endif//WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <windowsx.h>

// For debug builds, include these MSVC specific headers
#ifdef _DEBUG
#include <crtdbg.h>
#endif//_DEBUG

#if defined(SOY_REPL_AS_SHARED_LIBRARY)
#	ifndef SOY_REPL_EXPORT_DLL
#		ifndef SOYREPL_API
#			define SOYREPL_API __declspec(dllexport)
#		endif//SOYREPL_API
#	else
#		ifndef SOYREPL_API
#			define SOYREPL_API __declspec(dllimport)
#		endif//SOYREPL_API
#	endif//SOY_REPL_EXPORT_DLL
#endif//SOY_REPL_AS_SHARED_LIBRARY

#elif defined(__APPLE__)
//----------------------------------------------------------------
// macOS
//----------------------------------------------------------------
//TODO: Add macOS system headers
#elif defined(__linux__)
//----------------------------------------------------------------
// Linux
//----------------------------------------------------------------
//TODO: Add linux system headers

#else
//----------------------------------------------------------------
// ERROR
//----------------------------------------------------------------
#error "ERROR: Unsupported Platform for Soy REPL."
#endif//win32|macos|linux|unsupported
//================================================================

// C/C++ Language specializations

//================================================================
#ifndef __cplusplus
//----------------------------------------------------------------
// C
//----------------------------------------------------------------
#include <stdint.h>
#include <stdlib.h>

#else
//----------------------------------------------------------------
// C++
//----------------------------------------------------------------
#include <cstdint>
#include <cstdlib>

#endif//C|C++
//================================================================

//================================================================
// Not Building as a shared library, or not using MSVC
#ifndef SOYREPL_API
#define SOYREPL_API
#endif//SOYREPL_API
//================================================================

//////////////////////////////////////////////////////////////////
#endif//__SOY_REPL_COMMON_HH__
//////////////////////////////////////////////////////////////////
