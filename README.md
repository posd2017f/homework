# POSD2017F Homework

## Homework assignment 3

Please use [the files that were used in course](https://github.com/yccheng66/posd2017f) and copy test header to your repository from this project.

~~And unfortunately, the theft of plagiarism occurred again and again, in order to protect the rights and interests of students, we decided to ask you to move your repository from Github to [Gitlab](https://gitlab.com). Please follow [the steps](https://github.com/posd2017f/homework#setup-gitlab-repository) below to change your repository host.~~

:zap: After we discussed with Professor, we decided to remain github host. So if you already created a new gitlab repository, sorry for that.

#### Assignment requirement

  1. Need `number.h` and its class implementation `Number`, you can use the previous one(hw2). And the interface of `Number` should follow the code block below:

      ```c++
      Number(double value);
      std::string symbol();
      std::string value();
      ```

  2. Implement all tests in `utStrcut.h` and `utVariable.h`. The describe of test have been written on each test.

  4. Write the corresponding makefile to generate executable file which named `hw3`. Note that it is the executable name, not the test file name.

  5. Make sure your CI jobs are both passed before deadline.

#### Marks

  You totally have 15 tests in your own, each one is 2 points.
  And TA's tests totally have 20 tests, each one is 3 points.
  The sum of this homework is 90 points.

#### Deadline

  Thus Oct 19 2017 23:59:59 

#### Note

  * **About project structure**. In pervious homework, some people will place test file into folder and write the corresponding makefile. (e.g. `variable.h` in *include* folder ) This will result the executable in .ut job that still contains your test script but not ours because we just replace the test file at root directory. Thus, the report of test result shows all tests are passed, but in the fact it may isn't. So, if you place your files into some folder, please check the test report in .ut job that test script is still yours or not.

  * Try to read building information in console log and fix the hw problem  by yourself as possible as you can.
  
  * If your CI job can not pull your repository, email to us.

#### Change log
