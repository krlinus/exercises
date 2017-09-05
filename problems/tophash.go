package main

import (
  "crypto/md5"
  "os"
  "bufio"
  "fmt"
  "strings"
)
// Implement top hash as per Merkle tree https://en.wikipedia.org/wiki/Merkle_tree

func main() {
  var d [][]byte
  input := bufio.NewScanner(os.Stdin)
  var i int
  i=0
  // get the first parents of leaves
  outer:
  for input.Scan() {
  for _,r:= range strings.Fields(input.Text())  {
    if r == "end" {
      break outer
    }
    fmt.Println("Got ", r)
    t := []byte(r)
    d = append(d,t)
    b := md5.Sum(t)
    d[i] = b[:]
    i = i+1
  }
  }
  // At this point i should be a power of 2. I am ignoring
  // this error checking for the sake of the exercise
  var h_idx int
  h_idx = 0
  for {
    for h_idx = 0; (h_idx*2)+1 < len(d); h_idx++ {
      b0 := d[h_idx*2]
      b1 := d[h_idx*2+1]
      bb := append(b0, b1...)
      b := md5.Sum([]byte(bb))
      d[h_idx] = b[:]
    }
    d=d[0:h_idx]
    if len(d) == 1 {
      break
    }
  }
  fmt.Printf("Topmost hash = %x\n", d[0])
}
