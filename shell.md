
  
    Scenario: Wait for the period
      Given user type the clause that doesn't have the period
      When user type the enter
      Then it should keep revice the clause until there is a period.

The terminal session -> [https://asciinema.org/a/ZL1XxKiQJvEcBs7LqxN9yot4N](https://asciinema.org/a/ZL1XxKiQJvEcBs7LqxN9yot4N)

    Scenario: Ignore empty input
      Given user doesn't type anything.
      When user type enter.
      Then it should return new input line and nothing happen.

The terminal session -> [https://asciinema.org/a/bU8s1QIyQTogjScn1SpBD5dfR](https://asciinema.org/a/bU8s1QIyQTogjScn1SpBD5dfR)

    Scenario: "halt." for exit
      Given user type "halt.".
      When user type enter.
      Then the program should shutdown.

The terminal session -> like sessions above.