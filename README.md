# POSD2017F Homework

## Homework assignment 2

Please use [the files that were used in course](https://github.com/yccheng66/posd2017f) and copy test header to your repository from this project. 

For this time, not only run the test you write, but the test we prepared for your program.
So you will see two jobs, make sure 2 jobs will be passed before deadline. Then, everyone's CI job had updated, it should pull the repository automatically once you push your commit. If it does not work, email to us.

### Update

 * Sat Sep 30 2017 15:53:58
 
    If your CI job fails, you can click state icon to get the further information.
    ![consoleLog](https://i.imgur.com/wgXB8ap.png)

#### Assignment requirement 
 1. Need to create a header file by youself naming `Number.h`.
   In this header, there will be three method you should define: `symbol()`, `value()` and `match()`. As you define the Atom 
   and implement it, the `symbol` and `value` method should return value with string type. And for `match`, in this homework, 
   please use the method way to define instead of operator. 
    
 2. Also re-define and re-implement the `match()` in Atom via method way instead of operator.
 
 3. Implement all tests in utTerm.h. There are prompts in each test, follow the prompt to complete tests.
 
 4. Write the corresponding makefile to generate executable file which named `hw2`.
 
 5. Make sure your CI jobs are both passed before deadline.

#### Marks

On your own tests, each test has 2 points, total is 30 points.
On TA's tests, each test has 4 points, total is 60 points.
The sum of this homework marks is 90.

#### Deadline

Fri Oct 6 2017 23:59:59

#### Note

 * Clean all HW1 related files (Media.h, Shapes.h, Sort.h...and its implementation).
 * ~~The header's first letter should be capitalized so that we can caugth your header file on CI.~~
 * If you had any suggestions in HW1, improve it.
