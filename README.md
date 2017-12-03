# POSD2017F Homework

## Homework assignment 7

Please use [the files that were used in course](https://github.com/yccheng66/posd2017f) and copy test header to your repository from this project.

In this time, you have to design your tests for the iterator of `Struct` and `List`. A structure contains several terms, it can be expanded into a tree structure like the picture below. We will make two kinds of way to traverse the structure, the first is [deep-first search](https://en.wikipedia.org/wiki/Depth-first_search), and the second is [breadth-first search](https://en.wikipedia.org/wiki/Breadth-first_search). When traversing the structure, iterator gets each item in structure orderly.

You need to design the tests to test your iterator, the function signature of iterator and its usage must follow the way that defined on the course. There is also ours tests to test your program on the CI server (.ut job). 

For mob programming, there are some changes of schedule and its activity. We add a activity called `Retrospective` in last step, which is the same as the retrospective in [Scrum](http://teddy-chen-tw.blogspot.tw/2011/12/scrum-1.html). In retrospective, team will discuss about some issue related to team's development process, and it will help you to review the way when you write code and give you some feedback so you can improve to yourself.

## Chagne history

12/03

first() in our example should return bigmac not combo1.

![Imgur](https://i.imgur.com/v1GyjBX.png)

### Mob programming team on 12/02
|   Team#4 (at 1622)  |   Team#5 (at 1321) |
| --------- | --------- |
| 103590452 | 103590026 |
| ~~105598072~~ | 105598046 |
| 106598034 | 105598059 |
| 106598040 | 106598007 |
| 106598013 | 106598014 |
| 106598056 | 106598043 | 
| 106598064 | 106598052 |
| 106598067 | 106598059 |

#### Assignment requirement

  1. Redo the creation of iterator, use aggregate(e.g. `Struct`) to create iterator instead of client, and re-write the test of that.

  2.  As we can handle difference type on function through *template\<T>*, make the template on `Iterator` so it can handle the type other than `Term`.

  3. Design test for the iterator by yourself. The function signature and usage is not allow to change. 
     
     * Two kind of way for traversing: Deep-first search, Breadth-first search, so there will be two methods on the aggregate: `createBFSIterator`, `createDFSIterator`.

     * You need to design 2 test data for each type, `Struct` and `List`, and use BFS and DFS to traverse each test data. So it totally has 8 tests.
 
  4. Write the corresponding makefile to generate executable file which named `hw7`. Note that it is the executable name, not the test file name.

  5. Make sure your CI job is passed before deadline.

#### Marks

  You totally have 12 tests, include the test written on the course. Each one is 5 points.
  And we will have 8 tests, each one is also 5 points.
  The sum score of assignment is 100 points.

#### Deadline

  Fri Dec 8 2017 23:59:59

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

  Break ice and lunch(free): **12 : 00 ~ 12 : 50**

  Prepared: **12 : 50 ~ 13 : 00**

  Mob programming: **13 : 00 ~ 16 : 00**

  Retrospective: **16 : 00 ~ 16 : 30**

  Location: **宏裕科技大樓 13F Lab1321 or 16F 1622**

#### Team list：

Ctrl+f for finding your name.

### Team #4 (12/02)
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


### Team #5 (12/02)
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

### Team #2 (11/25 Done)
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

### Team #3 (11/25 Done)
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

#### Change log
