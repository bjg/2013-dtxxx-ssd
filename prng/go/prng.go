package main

import (
  "fmt"
  "time"
)

var captured []uint32 = []uint32{
    210205973,
    22795300,
    58776750,
    121262470,
    264731963,
    140842553,
    242590528,
    195244728,
    86752752,
}

const P = 295075153
type Prng struct {
    x, y uint32
}

func (p *Prng) Next() (uint32) {
    p.x = (2 * p.x + 5) % P
    p.y = (3 * p.y + 7) % P
    return p.x ^ p.y
}

func Verify(p Prng) bool {
    var c uint32
    q := Prng{p.x, p.y}
    for _, c = range captured[2:] {
        if c != q.Next() {
            return false
        }
    }
    fmt.Println(q.Next())
    return true
}

func main() {
    startTime := time.Now().UTC()
    var x uint32
    for x = 0; x < P; x++ {
        p := Prng{x, captured[0] ^ x}
        if p.Next() == captured[1] && Verify(p){
            break
        }
    }
    fmt.Println(time.Since(startTime))
}
