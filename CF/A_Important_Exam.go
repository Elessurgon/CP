package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
)

func solve(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, m int
	Fscan(in, &n, &m)
	a := make([]string, n)
	f := make(map[byte]int)
	score := make([]int, m)

	for i := 0; i < n; i++ {
		Fscan(in, &a[i])
	}

	for i := 0; i < m; i++ {
		Fscan(in, &score[i])
	}
	ans := 0
	for j := 0; j < m; j++ {
		mx := 0
		for k := range f {
			delete(f, k)
		}
		for i := 0; i < n; i++ {
			f[a[i][j]]++
		}
		for _, v := range f {
			mx = max(v, mx)
		}
		ans += mx * score[j]
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
