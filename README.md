# TestTarget
A test program for use as a memory reading target.

## Usage

	USAGE:    testtarget.exe money gold isgentoo ispriv speed name

	OPTIONS:

	money:    Integer value of the Money variable
	gold:     Integer value of the Gold variable
	isgentoo: Boolean (1=true,0=false) value for the GentooInstalled variable
	ispriv:   Boolean (1=true,0=false) value for the PrivilegeChecked variable
	speed:    Short value for the SpeedOfSeriousShit variable
	name:     String value for the Name variable, max 1024 chars

	Backing variable types:
		Integer=int32_t, Short=int16_t, Boolean=int8_t, String=char *

	The provided variables are set into static variables, for easy access.
	After setting the variables, the address of the state struct is printed
	with the PRIXPTR format specifier. Then, a call is made to getchar()
	to pause execution.

## Compiling

TestTarget has no dependencies outside the C standard library.

### Windows:
 1. Install Visual Studio, latest Community Edition will do fine
 2. Launch `Developer Command Prompt for VS2015` (or whichever
	VS version you have), or run (replace 14.0 with your version):
	`C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat`
	in order to set up the environmental variables.
 3. Run `build.bat` or `nmake all /F NMakeFile`

### Linux:
 1. Run `make all`
	
## License
TestTarget is licensed under the MIT License (Expat).
See LICENSE.
