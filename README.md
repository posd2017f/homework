# POSD2017F Homework

## Homework assignment 6

Please use [the files that were used in course](https://github.com/yccheng66/posd2017f) and copy test header to your repository from this project.

In this assignment, you are required to implement the complete matching like `X=1.` through parser. And for test, you don't need to write the test by yourself, we will provide the test to you. Therefore on the CI server, you will only have one job. Please follow the test to implement the necessary class and its interface.

And for the coming Saturday(11/25), there will be two teams need to attend the mob programming. Some adjustment here, please check your name and time, reply to us if you cannot attend the activity on Saturday. And for the demonstration , there is a difference from the previous time, please check [the demonstration  part](https://github.com/posd2017f/homework#demonstration) to get the more information.

### Update

  * Fri Nov 24 2017 10:04:53
  
  1. [Remove the assertion for symtable](https://github.com/posd2017f/homework/commit/044104f7f0cde0602c5034c330aad790eb6233bb#diff-d6ccfd1db8c6193d6118db3625f88da7).
  2. [Add the description for the parser method](https://github.com/posd2017f/homework/blob/master/README.md#assignment-requirement).


### Mob programming team on 11/25
|   Team#2  |   Team#3  |
| --------- | --------- |
| 103590028 | 103590006 |
| 105598043 | 104598046 |
| 105598062 | 105598060 |
| 106598006 | 106598004 |
| 106598016 | 106598011 |
| 106598027 | 106598045 | 
| 106598029 | 106598042 |
| 106598041 | 106598035 |

#### Assignment requirement

  1. Complete the parser through the test. 
  
      There are some methods different from before, especially the `createTerms` is no longer public and we use `matchings` to make term and pares sentence instead of `createTerms`. Basically it is the difference concept between parsing the complete sentence and parsing a part within the sentence. The `createTerms` should be responsible for getting the arguments if there is a list or structure, therefore it should be named `getArgs` rather then `createTerms`.
      
      We create a new method called `matchings` to parse the whole sentence. It take the sentence as the input, and __generates all terms in the sentence and make the corresponding tree__ to ready to do the real matching. The matching will call the `createTerm` method in serval times, and if it meets a list or structure, it will call `createTerms`(getArgs) to get the arguments for that.

      After `matchings`, the client will get __the root node of the tree by `expressionTree`__, and __do the real matching through the `evaluate` method of the root node__. And after `evaluate` the whole tree, client will get the final status of the matching. E.g. `X=1.`, the X will be the number 1 after the process.

  2. Implement the new class `Node` and its interface. The `Node` class is used to create the expression tree, and the tree represents the structure of a sentence. Each node is an operator or an operand, so you need to visit the whole tree to do the real matching.
  ![tree](https://i.imgur.com/JYVvY2s.png)
  The class has the `two constructors` to generate an node or connect two child nodes, and the `evaluate` method is used to evaluate that when to do the matching.
  
  3. Write the corresponding makefile to generate executable file which named `hw6`. Note that it is the executable name, not the test file name.
  
  4. Make sure your CI job is passed before deadline.

#### Marks

  You totally have 11 tests, each one is 9 points.
  And for easier calculating, the sum score of assignment is 100 points.

#### Deadline

  Wed Nov 29 2017 23:59:59

#### Note

  * Try to read building information in console log and fix the hw problem by yourself as possible as you can.
  

## POSD Mob programming

#### What is mob programming

  >Mob programming is a software development approach where the whole team works on the same thing, at the same time, in the same space, and at the same computer. This is similar to pair programming where two people sit at the same computer and collaborate on the same code at the same time. With Mob Programming the collaboration is extended to everyone on the team, while still using a single computer for writing the code and inputting it into the code base.

  from [Wikipedia: Mob programming](https://en.wikipedia.org/wiki/Mob_programming).

  [Mob Programming, A Whole Team Approach](https://www.youtube.com/watch?v=8cy64qkgTyI)

#### Description

  TA will divide all students into 9 teams, 8 people each team. This will be decided randomly, everyone will work with someone else you are not familiar with. By this way, you need to have good communication with team member to organize, plan and practice.

  It begins from this weekend(10/31), each team need to practice every Saturday afternoon before the demo in POSD class on coming Friday. The practice look like picture below, you will code together with a big screen, and discuss issues by using whiteboard.

  ![Mob](https://i.imgur.com/SoIxm5P.jpg)

  The practice will takes you about 3~4 hours, we will stay there with you for process smooth.
  **Mob programming will be counted as a score, and each of you only need to submit the same code that you *mob***

  The topic of mob programming is your POSD assignment, complete the program according to the test step by step. The team will discuss about design or each decision for the solution, and the whole process is treated as a standard for scoring.

  In practice, everyone has to be `Driver`/`Navigator` alternatively. For `Driver`, your job is to controll keyboard and implement all instructions from `Navigator`. For `Navigator`, your job is to think about the design issue, solution, all stuff of decision, and instruct `Driver` to implement it.

#### Prepare for Mob

  1. Understand what's mob programming: see the introduction video above.

  2. For each one student, you will get a questonnaire before mob, the questonnaire is about personal planning that what do you want to get from this time(like what's mob programming in reality? or how does other guy do his/her assignment, etc.). So, think about it before mob.

  3. Plan the solution for assignmnet: do not just come here and wait for other guy share their wonderful solution. Think about problem first by yourself, therefore results a good communication and no wasting time.
`
#### Demonstration

  On the Friday of next week, Each team have about **20 minutes** to show the demonstration which how they run the mob programming and how to solve the problem that in the assignment.
  
  Two teams will do the demonstration in order, the first team done a part of the code with three tests, the second team will need to continue to do the demo with the code.

  Each team will demo about three tests in the class, you don't have to complete the all tests. The three tests is specified by TA, and we will pick the simple, medium and complex test for each team.
  
  About the code that you write through the mob, it will not be used in the later course, so you don't need to push it to repository of the course.

#### Schedule on Saturday

  This is temporary and may be adjusted according to the actual situation.

  If you are on the week, please fill out the [lunch questionnaire](https://docs.google.com/forms/d/e/1FAIpQLSecaGZM_WujJToLXw9CfXtfg-8c-gXzbxOb9TT5TXlqZOsNxg/viewform?c=0&w=1&usp=mail_form_link), and **launch is free**.

  Break ice and lunch(free): **12 : 00 ~ 13 :00**

  Mob programming: **13 : 00 ~ 16 : 00**

  Location: **宏裕科技大樓 13F Lab1321**

#### Team list：

Ctrl+f for finding your name.

### Team #2 (11/25)
|   Number  |
| --------- |
| 103590028 |
| 105598043 |
| 105598062 | 
| 106598006 |
| 106598016 |
| 106598027 |
| 106598029 |
| 106598041 |

### Team #3 (11/25)
|   Number  |
| --------- |
| 103590006 |
| 104598046 |
| 105598060 | 
| 106598004 |
| 106598011 |
| 106598045 |
| 106598042 |
| 106598035 |

### Team #4 ()
|   Number  |
| --------- |
| 103590452 |
| 105598072 |
| 106598034 |
| 106598040 |
| 106598013 |
| 106598056 |
| 106598064 |
| 106598067 |


### Team #5 ()
|   Number  |
| --------- |
| 103590026 |
| 105598046 |
| 105598059 |
| 106598007 |
| 106598014 |
| 106598043 |
| 106598052 |
| 106598059 |


### Team #6 ()
|   Number  |
| --------- |
| 103590019 |
| 105598061 |
| 106598009 |
| 106598017 |
| 106598026 |
| 106598037 |
| 106598047 |
| 106598057 |


### Team #7 ()
|   Number  |
| --------- |
| 103590450 |
| 105598073 |
| 106598005 |
| 106598020 |
| 106598028 |
| 106598051 |
| 106598055 |
| 106598068 |


### Team #8 ()
|   Number  |
| --------- |
| 105598401 |
| 106598010 |
| 106598018 | 
| 106598025 |
| 106598033 |
| 106598039 |
| 106598044 |
| 106598063 |


### Team #9 ()
|   Number  |
| --------- |
| 103590002 |
| 106598012 |
| 106598019 |
| 106598022 |
| 106598069 |
| 106598049 |
| 106598065 |
| 106598401 |


### Team #1 (11/04 Done)
|   Number  |
| --------- |
| 105598052 |
| 106598024 |
| 106598038 |
| 106598048 |
| 106598053 |
| 106598054 |
| 106598060 |

#### Change log
