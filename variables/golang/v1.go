
/*
1. declare local variables using the allowed syntaxes

2. find of behaviour of static variables in a function, in a file, etc. 

3. declaration together with initialization for native and user-defined

4. pass vars to a function. Pass address of variable (try swap program)

5. exercise every type of variable declaration

6. make is_palindrome in different possible ways
*/

package main

import (
  "fmt"
)

func main() {
  // VarDecl     = "var" ( VarSpec | "(" { VarSpec ";" } ")" ) .
  // VarSpec     = IdentifierList ( Type [ "=" ExpressionList ] | "=" ExpressionList ) .
  var myvar int = 10
  var myvar1 = 10
  var myvar2 int
  var (myvar3 int = 10;) // Note: the ';' is used to break the line
  var (myvar4 = 10;)
  var (myvar5, myvar6 int = 10,20)
  var (myvar7, myvar8 = 10,20)
  var myvar9, myvar10 = 10,20
  fmt.Printf("%v,%v,%v,%v,%v,%v,%v,%v,%v,%v,\n",myvar,myvar1,myvar2,myvar3,myvar4,myvar5,myvar6,
                                              myvar7,myvar8,myvar9,myvar10)
  /*
  See also:
    https://golang.org/ref/spec#Predeclared_identifiers
    The following identifiers are implicitly declared in the universe block:

   Types:
	bool byte complex64 complex128 error float32 float64
	int int8 int16 int32 int64 rune string
	uint uint8 uint16 uint32 uint64 uintptr

   Constants:
	true false iota

   Zero value:
	nil

   Functions:
	append cap close complex copy delete imag len
	make new panic print println real recover

  Note: The universe block encompasses all Go source text.
    See https://golang.org/ref/spec#Blocks

  */
  
}
