# POSD2017F Homework

## Homework assignment 5

Please use [the files that were used in course](https://github.com/yccheng66/posd2017f) and copy test header to your repository from this project.

In this assignment, you are required to implement the more complete parser through each test. It will use the interface written in the course. And then, there are few tests will need some new methods of different term class, please follow the description of test, implement each method.

And from this week, we start to run [Mob programming](https://www.google.com.tw/search?q=mob+programming). There will be one or two group in every week until the end of semester, they are required to show the demonstration which how they run the mob programming and how to solve the problem that in the assignment. It needs to do rehearse and prior planning with us. See below to get more detail.


#### Update

  * Fri Nov 03 2017 15:06:12

    The method `args()`, it should return `Term *`, not `Term &`. please correct it in your assignment.

    ```diff
    class Struct {
        public:
          int arity(); // return the number of args (terms)
    -     Term & args(int index); // according to index return the term
    +     Term * args(int index); // according to index return the term
      }
    ```

  * Fri Nov 03 2017 11:55:51
  
    The description of test `TEST_F(ParserTest, ListAsStruct)` is wrong, please correct it in your assignment.

    ```diff
    // Then it should return a Struct which contains two terms.
    // And #arity() of the Struct should be 2.
    // And #symbol() of Struct should return ".(1, [])".
    - // And the first term should be number: "1", the second term should be another Strcut: "[]".
    + // And the first term should be number: "1", the second term should be another List: "[]".
    TEST_F(ParserTest, ListAsStruct) {

    }
    ```
  
  * Thu Nov 02 2017 17:30:46
  
    1. The date of each team has been changed because we skip the week of mid-exam.
    
    2. Some people cannot attend the activity on that week, so we adjust them to other week.
        \
        \
          **Team #2 (11/18)&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;Team #3 (11/25)&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;Team #1 (11/04)&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;Team #9 (01/06)**
        \
        ![Imgur](https://i.imgur.com/nkO111j.png) ![Imgur](https://i.imgur.com/mLcnZIb.png) ![Imgur](https://i.imgur.com/ipW1Gvm.png) ![Imgur](https://i.imgur.com/vgN8huc.png)
        
    3. If you also cannot attend the activity on that week, please email to us before at least one week.
    
    4. ~~About the method: `arity()` and `args()`, sorry for vague explanation. Here is the detail of interface:~~
    
    
#### Assignment requirement

  1. Complete the parser with the description of each test

  2. Implement the new method `arity()`, `args()` in `Struct`.
  
  3. Write the corresponding makefile to generate executable file which named hw5. Note that it is the executable name, not the test file name.
  
  4. Make sure your CI jobs are both passed before deadline.

#### Marks

  You totally have 20 tests in your own, each one is 2 points.
  And TA's test also have 20 tests, each one is 3 points.
  The sum of this homework is 90 points.

#### Deadline

  Thur Nov 9 2017 23:59:59

#### Note

  * Try to read building information in console log and fix the hw problem by yourself as possible as you can.
  
  * If your CI job can not pull your repository, email to us.


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

#### Demonstration

  In following Friday, Each team have **50 minutes** to show the demonstration which how they run the mob programming and how to solve the problem that in the assignment. 

#### Schedule on Saturday

  This is temporary and may be adjusted according to the actual situation.

  If you are on the week, please fill out the [lunch questionnaire](https://docs.google.com/forms/d/e/1FAIpQLSecaGZM_WujJToLXw9CfXtfg-8c-gXzbxOb9TT5TXlqZOsNxg/viewform?c=0&w=1&usp=mail_form_link), and **launch is free**.

  Break ice and lunch(free): **12 : 00 ~ 13 :00**

  Mob programming: **13 : 00 ~ 16 : 00**

  Location: **宏裕科技大樓 13F Lab1321**

#### Team list：

Ctrl+f for finding your name.

### Team #1 (11/04)
|   Number  |  Name |
| --------- | ----- | 
| 105598052 | 吳育呈 |
| 106598024 | 鍾承翰 |
| 106598038 | 李柏霖 | 
| 106598048 | 郭士銓 | 
| 106598053 | 陳韻文 | 
| 106598054 | 楊子冊 |
| 106598060 | 吳彥銘 |


### Team #2 (11/18)
|   Number  |  Name |
| --------- | ----- | 
| 103590028 | 簡育聲 |
| 105598043 | 蔡兆霖 | 
| 105598062 | 李昀展 | 
| 106598006 | 林照晟 | 
| 106598016 | 王暐淇 |
| 106598027 | 林進偉 |
| 106598029 | 孫暐媜 |
| 106598069 | 林琨皓 |

### Team #3 (11/25)
|   Number  |  Name |
| --------- | ----- | 
| 103590006 | 曹暘鑫 |
| 104598046 | 蘇翊棠 | 
| 105598060 | 黃釋鋐 | 
| 106598004 | 李鋒 | 
| 106598011 | 李宜倫 |
| 106598013 | 陳泓欣 |
| 106598042 | 陳彥霖 |
| 106598035 | 黃靖幃 |

### Team #4 (12/02)
|   Number  |  Name |
| --------- | ----- | 
| 103590452 | 陳厚安 |
| 105598072 | 方范濠麒| 
| 106598034 | 劉宸佑 |
| 106598040 | 何鎮宇 | 
| 106598045 | 林翰隆 | 
| 106598056 | 謝柏鋒 | 
| 106598064 | 賴偉程 |
| 106598067 | 周妤珊 |


### Team #5 (12/09)
|   Number  |  Name |
| --------- | ----- | 
| 103590026 | 周冠勳 |
| 105598046 | 莊承蓉 | 
| 105598059 | 蘇哲弘 | 
| 106598007 | 何威杭 | 
| 106598014 | 陳日揚 |
| 106598043 | 吳揚聲 |
| 106598052 | 張家豪 |
| 106598059 | 翁晁宇 |


### Team #6 (12/16)
|   Number  |  Name |
| --------- | ----- | 
| 103590019 | 黃麟傑 |
| 105598061 | 宋正倫 | 
| 106598009 | 蕭家瑜 | 
| 106598017 | 梁冬昇 | 
| 106598026 | 陳登正 |
| 106598037 | 許釋文 |
| 106598047 | 劉宸宗 |
| 106598057 | 曾辰豫 |


### Team #7 (12/23)
|   Number  |  Name |
| --------- | ----- | 
| 103590450 | 馬茂源 |
| 105598073 | 林翰廷 | 
| 106598005 | 盧家馨 | 
| 106598020 | 李炘潤 | 
| 106598028 | 范植承 |
| 106598051 | 洪宇頡 |
| 106598055 | 劉德均 |
| 106598068 | 吳承軒 |


### Team #8 (12/30)
|   Number  |  Name |
| --------- | ----- | 
| 105598401 | 鍾宇佳 |
| 106598010 | 洪紹晏 | 
| 106598018 | 萬俊瑋 | 
| 106598025 | 翁翊桓 | 
| 106598033 | 黃鈺珉 |
| 106598039 | 林亮勳 |
| 106598044 | 李家豪 |
| 106598063 | 廖愷鈞 |


### Team #9 (01/06)
|   Number  |  Name |
| --------- | ----- |
| 103590002 | 洪子軒 |
| 106598012 | 陳人鳳 |
| 106598019 | 郭建陞 |
| 106598022 | 李修豪 |
| 106598041 | 劉宗瑋 | 
| 106598049 | 謝宗佑 | 
| 106598065 | 李玠民 | 
| 106598401 | 余俊穎 |


#### Change log
