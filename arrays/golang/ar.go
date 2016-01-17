
/*
1. Create a simple array for each form of declaration

2. Create a dynamically allocated array

3. For each functionality of an array, write a program to exercise it

4. Create a double dimension array

5. Create a double dimension array that is dynamically allocated
*/

package main

import (
  "fmt"
)

func main() {

/*
  ArrayType   = "[" ArrayLength "]" ElementType .
  ArrayLength = Expression .
  ElementType = Type .
*/
  var ar [10]int;
  ar1 := []int{1,2,3}
  // var ar2 [...]int{1,2,3} // doesn't work
  fmt.Println(ar)
  fmt.Println(ar1)
  // fmt.Println(ar2)
  var args []string = []string{"A", "B", "C"}
  //var args1 []string = []{"A", "B", "C"}
  var args1  = []string{"A", "B", "C"}
  fmt.Println(args)
  fmt.Println(args1)

  var ar3 = [][]string{}
  // ar3 = append(ar3, make([]string,1)) // ok
  // ar3 = append(ar3, []string{}) // ok
  // ar3 = append(ar3, []string{"one","two"}) // ok
  fmt.Println(ar3)
  // var ar4 [2][2]string // ok
  ar4 := [2][2]int{{6,7},{8,9}} // ok
  fmt.Println("-----------")
  for x,y := range ar4 {
    for x1, y1 := range ar4[x] {
      fmt.Println(ar4[x][x1])
      fmt.Println(y,y1,x,x1)
/*
prints the below:
6
[6 7] 6 0 0
7
[6 7] 7 0 1
8
[8 9] 8 1 0
9
[8 9] 9 1 1

*/
    }
  }
  //fmt.Println(ar4[0])




}

