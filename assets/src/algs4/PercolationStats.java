import java.lang.Math;
import edu.princeton.cs.algs4.StdStats;
import edu.princeton.cs.algs4.StdRandom;

public class PercolationStats {
    private double[] threshold;
    private int sz;

    // perform independent trials on an n-by-n grid
    public PercolationStats(int n, int trials) throws IllegalArgumentException {
        if (n <= 0 || trials <= 0) {
            throw new IllegalArgumentException();
        }
        this.sz = trials;
        Percolation[] p = new Percolation[trials];
        this.threshold = new double[trials];

        for (int i = 0; i < trials; i++) {
            p[i] = new Percolation(n);
            while (!p[i].percolates()) {
                int x = StdRandom.uniform(n) + 1,
                    y = StdRandom.uniform(n) + 1;
                if (!p[i].isOpen(x, y)) {
                    p[i].open(x, y);
                }
            }
            this.threshold[i] = p[i].numberOfOpenSites() * 1.0 / (n * n);
        }
    }

    // sample mean of percolation threshold
    public double mean() {
        return StdStats.mean(this.threshold, 0, this.sz);
    }

    // sample standard deviation of percolation threshold
    public double stddev() {
        if (this.sz == 1) {
            return 0;
        }
        return StdStats.stddev(this.threshold, 0, this.sz);
    }

    // low endpoint of 95% confidence interval
    public double confidenceLo() {
        return this.mean() - 1.96 * this.stddev() / Math.sqrt(this.sz);
    }

    // high endpoint of 95% confidence interval
    public double confidenceHi() {
        return this.mean() + 1.96 * this.stddev() / Math.sqrt(this.sz);
    }

    // test client
    public static void main(String[] args) {
        int n = Integer.parseInt(args[0]), T = Integer.parseInt(args[1]);
        PercolationStats s = new PercolationStats(n, T);
        System.out.printf("mean\t\t\t= %g\nstddev\t\t\t= %g\n95%% confidence interval = [%g, %g]\n",
                          s.mean(),
                          s.stddev(),
                          s.confidenceLo(),
                          s.confidenceHi());
    }
}
