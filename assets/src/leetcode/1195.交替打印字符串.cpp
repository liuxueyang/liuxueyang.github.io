/*
 * @lc app=leetcode.cn id=1195 lang=cpp
 *
 * [1195] 交替打印字符串
 */

// @lc code=start
class FizzBuzz {
private:
    int n;

public:
    FizzBuzz(int n) {
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        if (this->n % 3 == 0) {
            printFizz();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        if (this->n % 5 == 0) {
            printBuzz();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        if (this->n % 15 == 0) {
            printFizzBuzz();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        if (this->n % 15 != 0) {
            printNumber(this->n);
        }
    }
};
// @lc code=end

