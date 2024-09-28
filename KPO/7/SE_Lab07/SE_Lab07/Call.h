#pragma once

namespace Call {
	int _cdecl  cdekl(int a, int b, int c);
	int _stdcall cstd(const int& a, int b, int c);
	int _fastcall cfst(int a, int b, int c, int d);
}