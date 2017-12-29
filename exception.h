
/**
 * 
 * Here are some examples for exception handling,
 * the actual testing way is base on your implementation.
 * 
 */

TEST(Shell, exception_OnlyVariable) {
  Scanner s("X."); // this is our wrong expression.
  Parser p(s);
  try {
    p.buildExpression(); // according to your implementation.
    FAIL() << "It should throw an exception: X does never get assignment"; // fail if not exception is thrown.
  } catch (std::string &msg) {
    ASSERT_EQ("X does never get assignment", msg); // it should throw an exception like this.
  }
}

TEST_F(Shell, exceptionMissingPeriodToken) {
  Scanner s("X=1");
  Parser p(s);
  try {
    p.buildExpression();
    FAIL() << "It should throw an exception: Missing token '.'";
  } catch (std::string &msg) {
    ASSERT_EQ("Missing token '.'", msg);
  }
}

TEST(Shell, exception_UnexpectedDisjTokenBeforePeriod) {
  Scanner s("X;.");
  Parser p(s);
  try {
    p.buildExpression();
    FAIL() << "It should throw an exception: Unexpected ';' before '.'";
  } catch (std::string &msg) {
    ASSERT_EQ("Unexpected ';' before '.'", msg);
  }
}

TEST(Shell, exception_UnexpectedConjTokenBeforePeriod1) {
  Scanner s("X,.");
  Parser p(s);
  try {
    p.buildExpression();
    FAIL() << "It should throw an exception: Unexpected ',' before '.'";
  } catch (std::string &msg) {
    ASSERT_EQ("Unexpected ',' before '.'", msg);
  }
}

TEST(Shell, exception_UnexpectedConjTokenBeforePeriod2) {
  Scanner s("X=1,.");
  Parser p(s);
  try {
    p.buildExpression();
    FAIL() << "It should throw an exception: Unbalanced operator";
  } catch (std::string &msg) {
    ASSERT_EQ("Unexpected ',' before '.'", msg);
  }
}

TEST(Shell, exception_UnbalancedOperator1) {
  Scanner s("X = match(tom, marry;)");
  Parser p(s);
  try {
    p.buildExpression();
    FAIL() << "It should throw an exception: Unbalanced operator";
  } catch (std::string &msg) {
    ASSERT_EQ("Unbalanced operator", msg);
  }
}

TEST(Shell, exception_UnbalancedOperator2) {
  Scanner s("X = [tom, marry ;]");
  Parser p(s);
  try {
    p.buildExpression();
    FAIL() << "It should throw an exception: Unbalanced operator";
  } catch (std::string &msg) {
    ASSERT_EQ("Unbalanced operator", msg);
  }
}
