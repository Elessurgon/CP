package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
)

func solve(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n int
	Fscan(in, &n)
	ans := 0
	m := make(map[int]int)
	for true {
		if _, ok := m[n]; ok {
			break
		}
		m[n] = 1
		ans++
		n = n + 1
		for n%10 == 0 {
			n /= 10
		}
	}
	Fprint(out, ans)
}

func main() { solve(os.Stdin, os.Stdout) }
func min(a, b int) int {
	if b < a {
		return b
	}
	return a
}
func max(a, b int) int {
	if b > a {
		return b
	}
	return a
}
