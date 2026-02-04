/*-----------------------------------------------------------------------------
	mf.cpp
-------------------------------------------------------------------------------
	Main source file for the make file, empty file generator application.
	Generates as many files as the parameters can take.
	
	./mf.exe <file_name_1> <file_name_2> <...>
-------------------------------------------------------------------------------
	Authored by Anthoni Caldwell
	Authored on 2026.02.04
	Updated on 2026.02.04
-------------------------------------------------------------------------------
	License - BSD License
-------------------------------------------------------------------------------	
	Copyright (c) 2026, Anthoni Caldwell

	Redistribution and use in source and binary forms, with or without 
	modification, are permitted provided that the following condition is met:

	Redistributions of source code must retain the above copyright notice, 
	this list of conditions and the following disclaimer.

	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
	AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
	THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
	PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
	CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
	EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
	(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
	LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND 
	ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
	(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF 
	THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.)
-----------------------------------------------------------------------------*/

#include <cstdio>

#define MAX_FILES 1024

static_assert(MAX_FILES > 0, "MAX_FILES must be at least 1");
static_assert(MAX_FILES <= 2048, "MAX_FILES might be too big for Windows!");

void make_file( const char * file_name ) { // Does the actual file making.
	if (file_name == NULL) { 
		printf( "Error: No file name provided.\n" );
		return; 
	}
	
	FILE * pf = fopen(file_name, "wb");
	
	if (pf != NULL) {
		int result = fclose(pf);
		if (result != 0) {
			printf( "Error: Can not create file(s).\n" );
		}
	}
}

int main ( int argc, char * argv[] ) {
	int limit = (argc > MAX_FILES) ? MAX_FILES : argc;
	
	if (argc > 1) { // Check for file names.
		
		for (int i=1; i<limit; i++ ) { // Loop through file names and make files.
			make_file( argv[i] );
		}
		
	} else { // If no files are provided, show an error.
		printf( "Error: need at least one file name to make.\n" );
	}

	return 0;
}