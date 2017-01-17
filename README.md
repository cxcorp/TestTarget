# TestTarget
A test program for use as a memory reading target.
Part of a coursework project for [Javalabra-2017-3](https://github.com/javaLabra/Javalabra2017-3).

# Usage

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
	
# License
TestTarget is licensed under the MIT License (Expat). See LICENSE.
