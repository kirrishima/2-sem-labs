#include "Call.h"

namespace Call {

	int _cdecl  cdekl(int a, int b, int c) {
		return a + b + c;
	}

	int _stdcall cstd(const int& a, int b, int c) {
		return a * b * c;
	}

	int _fastcall cfst(int a, int b, int c, int d) {
		return a + b + c + d;
	}
}