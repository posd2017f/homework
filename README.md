# POSD2017F Homework

## Homework assignment 2

Please use [the files that were used in course](https://github.com/yccheng66/posd2017f) and copy test header to your repository from this project. 

For this time, not only run the test you write, but the test we prepared for your program.
So you will see two jobs, make sure 2 jobs will be passed before deadline. Then, everyone's CI job had updated, it should pull the repository automatically once you push your commit. If it does not work, email to us.

### Update
 * Tue Oct 03 2017 17:12:30
 
   Because some classmates are not sure about the result of building, we add the sign to help you understand, for example:![Imgur](https://i.imgur.com/rszFNxO.png) is test fail, ![Imgur](https://i.imgur.com/IK5hq0j.png) is build fail.
 * Tue Oct 03 2017 09:46:22

   * About `Number`,  its constructor should take an argument with int type, as the test prompt in utTerm.h that we give you.
    Some people may think that it could take a double number or string value, but in this time we just consider some simple situation. 
    Maybe in the following course you will modity some define in a perfect way.
    
   * For all header files, **the first letter of file name, please use lowercase.** In the early day, we ask you use uppercase, 
    but it's wrong and it is our mistake, we just didn't have enough communication on it. So if you are using uppercase on each header, 
    please change to lowercase.
    
   * For each class, **the first letter of class name, please use uppercase.** And note that the Variable class in utTerm.h, we wrote
   `Var`, but it is also wrong. Please follow the way in course using `Variable`.
   
   Sorry for this time there are so many places need to be modify, we will improve that at the next homework. After this update, if your 
   jobs already pass, please rebuild it and check it still pass or not.

 * Mon Oct 02 2017 14:07:39
 
    Some people met the error like this:
    ![Imgur](https://i.imgur.com/ft0F8ZC.png)
    
    It's because the building environment on CI serve is on windows paltform. So you need to write additional instructions against 
    windows. You can refer [this homework](https://github.com/e8315402/myProject/blob/master/makefile) using in homework 1, and make 
    sure that each instruction has same arguments.
    
```diff
foo.o: foo.h foo.cpp
 g++ --std=c++11 foo.h foo.cpp

bar.o: bar.h bar.cpp
+ ✓ g++ --std=c++11 bar.h bar.cpp
- ✗ g++ bar.h bar.cpp
```
    
 
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
