# POSD2017F Homework

## Homework assignment 3

Please use [the files that were used in course](https://github.com/yccheng66/posd2017f) and copy test header to your repository from this project. 

// TODO
In this homework...

:zap: And unfortunately, the theft of plagiarism occurred again and again, in order to protect the rights and interests of students, we decided to ask you to move your repository from Github to [Gitlab](https://gitlab.com). Please follow [the steps](https://github.com/posd2017f/homework#setup-gitlab-repository) below to change your repository host.

#### Assignment requirement

#### Marks

#### Deadline

#### Note

#### Setup gitlab repository

  1.  Create a gitlab repository
      
      You can create a whole new repository in gitlab or copy it from github by importing or using repository link.
      ![Imgur](https://i.imgur.com/4h7ZWvI.png)

      And note that **visibility level should be private**.

  2.  Copy webhook

      Copy your webhook from github, and go to the Integrations page (Project Settings->Integrations) to paste the link.
      ```
      http://140.124.181.114:8080/buildByToken/build?job=<studentId>&token=<studentId>
      ```

  3.  Set ssh key

      Unlike github has a public nature, it must to get the permission or through a secure manner if someone tries to access the private repository in gitlab, so we use ssh on CI server to pull your repository. 
      
      Copy the ssh key below, paste on SSH Keys page (User Settings->SSH Keys).
      ```
      ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABAQDMMTP1WbetmLz+xXaMO06EQD8kOyNoyExklFjM2Ws8AWPKKwBpD9eP2Inq4gD+j28S94Z/TpnvIKB5XmC+BgGtgbsN0VU2efENq2uygMHzqc/fmehHpDvdU8UnS4O/zPhebbaLZsbKWVWKEyHdVp1OzgH+IZPQXGvaQ5umbGacKYsqnHOMDa4gY3VLWJLijLeg4nUfmdIzMn78bWu7KumQ/5I4IjxDkZo/JCZdWXo7gFHif0ManJ5QMmoQL6ncRMIVZti7cc7xM0NW+lJc6i5drlnyScSQ21GhT7jDCebqtHG3KmxPl/tFBpuTfA8DfUcT1AhwVJFHL3wvqf+zF65Z 
      ```
      
      Name the key title whatever you want and ensure that key has been added.
      ![Imgur](https://i.imgur.com/pohwFe8.png)
  
  Complete all steps above you can test your webhook with push event to check status.

#### Change log
