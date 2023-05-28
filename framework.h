// header.h : include file for standard system include files,
// or project specific include files
//
#define CURL_STATICLIB
#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>
// C RunTime Header Files
#include <stdio.h>
#include <malloc.h>
#include <thread>
#include <memory.h>
#include <tchar.h>
#include <C:\src\vcpkg\installed\x64-windows\include\curl\curl.h>
#pragma comment(lib, "libcurl.lib")