import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;
import edu.princeton.cs.algs4.UF;

public class Percolation {
    private int[][] matrix;
    private int sz;
    private int start, end;     // two additional points
    private UF uf;
    private static int[][] direction = {
        {0, 1}, {0, -1},
        {1, 0}, {-1, 0},
    };

    private void checkBounds(int row, int col) throws IllegalArgumentException {
        if (row < 1 || row > sz || col < 1 || col > sz) {
            throw new IllegalArgumentException();
        }
    }

    private boolean inBounds(int row, int col) {
        return !(row < 1 || row > sz || col < 1 || col > sz);
    }

    private int getKey(int row, int col) throws IllegalArgumentException {
        this.checkBounds(row, col);
        return (row - 1) * sz + col;
    }

    // create n-by-n grid, with all sites initially blocked
    public Percolation(int n) throws IllegalArgumentException {
        if (n <= 0) {
            throw new IllegalArgumentException();
        }

        this.sz = n;
        this.matrix = new int[n + 1][n + 1];
        this.uf = new UF(n * n + 2);
        int p;
        this.start = 0;
        this.end = n * n + 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                p = this.getKey(i + 1, j + 1);
                if (i == 0) {
                    uf.union(start, p);
                } else if (i == n - 1) {
                    uf.union(end, p);
                }
                matrix[i + 1][j + 1] = 0;
            }
        }
    }

    // open the site (row, col) if it is not open already
    public void open(int row, int col) throws IllegalArgumentException {
        checkBounds(row, col);
        if (isOpen(row, col)) {
            return;
        }
        for (int i = 0; i < 4; i++) {
            int x = row + Percolation.direction[i][0], y = col + Percolation.direction[i][1];
            if (this.inBounds(x, y) && this.isOpen(x, y)) {
                this.uf.union(this.getKey(row, col),
                        this.getKey(x, y));
            }
        }
        matrix[row][col] = 1;
    }

    // is the site (row, col) open?
    public boolean isOpen(int row, int col) throws IllegalArgumentException {
        checkBounds(row, col);
        return matrix[row][col] == 1;
    }

    // is the site (row, col) full?
    public boolean isFull(int row, int col) throws IllegalArgumentException {
        this.checkBounds(row, col);
        int p = (row-1)*sz+col;
        return uf.find(p) == uf.find(start);
    }

    // returns the number of open sites
    public int numberOfOpenSites() {
        int res = 0;
        for (int i = 1; i <= sz; i++) {
            for (int j = 1; j <= sz; ++j) {
                if (isOpen(i, j)) {
                    ++res;
                }
            }
        }
        return res;
    }

    // does the system percolate?
    public boolean percolates() {
        return uf.find(start) == uf.find(end);
    }

    public static void main(String[] args) {
        System.out.println("Hello World!");
    }
}
