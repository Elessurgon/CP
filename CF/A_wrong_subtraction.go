package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
)

func solve(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, k int64
	Fscan(in, &n, &k)
	for n > 0 && k > 0 {
		r := n % 10
		if r == 0 {
			n /= 10
		} else {
			n -= 1
		}
		k--
	}
	Fprint(out, n)
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
