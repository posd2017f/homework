#ifndef UTPARSER_H
#define UTPARSER_H

#include <string>

#include "parser.h"
#include "scanner.h"

class ParserTest : public ::testing::Test {
protected:
  void SetUp() {
    symtable.clear();
  }
};

TEST_F(ParserTest, createTerm_Var){
  Scanner scanner("X");
  Parser parser(scanner);
  ASSERT_EQ("X", parser.createTerm()->symbol());
}

TEST_F(ParserTest, createTerm_Num){
  Scanner scanner("123");
  Parser parser(scanner);
  ASSERT_EQ("123", parser.createTerm()->symbol());
}

TEST_F(ParserTest, createTerm_Atom)
{
  Scanner scanner("tom");
  Parser parser(scanner);
  ASSERT_EQ("tom", parser.createTerm()->symbol());
}

TEST_F(ParserTest, createTerm_Struct)
{
  Scanner scanner("s(1, X, tom)");
  Parser parser(scanner);
  Term * term = parser.createTerm();
  ASSERT_NE(nullptr, term);
  ASSERT_EQ("s(1, X, tom)", term->symbol());
}

TEST_F(ParserTest, createArgs)
{
  Scanner scanner("1, X, tom");
  Parser parser(scanner);
  parser.createTerms();
  vector<Term*> terms = parser.getTerms();
  ASSERT_EQ("1", terms[0]->symbol());
  ASSERT_EQ("X", terms[1]->symbol());
  ASSERT_EQ("tom", terms[2]->symbol());
}

TEST_F(ParserTest,ListOfTermsEmpty)
{
  Scanner scanner;
  Parser parser(scanner);
  parser.createTerms();
  vector<Term*> terms = parser.getTerms();
  ASSERT_EQ(0,terms.size());
}

TEST_F(ParserTest, createTerm_underscoredVar)
{
  Scanner scanner("_date");
  Parser parser(scanner);
  ASSERT_EQ("_date", parser.createTerm()->symbol());
}

TEST_F(ParserTest,listofTermsTwoNumber)
{
  Scanner scanner("12345 , 68");
  Parser parser(scanner);
  parser.createTerms();
  vector<Term*> terms = parser.getTerms();
  ASSERT_EQ("12345" , terms[0]->symbol());
  ASSERT_EQ("68" , terms[1]->symbol());
}

TEST_F(ParserTest, createTerm_StructWithoutArgs) {
  Scanner scanner("point()");
  Parser parser(scanner);
  EXPECT_EQ("point()",parser.createTerm()->symbol());
}

TEST_F(ParserTest, createTerm_StructWithNumber) {
  Scanner scanner("point(11)");
  Parser parser(scanner);
  EXPECT_EQ("point(11)",parser.createTerm()->symbol());
}

TEST_F(ParserTest, createTerm_StructWithTwoNumber) {
  Scanner scanner("point(11,12)");
  Parser parser(scanner);
  EXPECT_EQ("point(11, 12)",parser.createTerm()->symbol());
}

TEST_F(ParserTest, createTerm_StructWithThreeTerms) {
  Scanner scanner("point(1, X, z)");
  Parser parser(scanner);
  EXPECT_EQ("point(1, X, z)",parser.createTerm()->symbol());
}

TEST_F( ParserTest, createTerm_StructWithStruct){
  Scanner scanner( "point(1, X, z(1,2,3))");
  Parser parser( scanner );
  ASSERT_EQ( "point(1, X, z(1, 2, 3))", parser.createTerm()->symbol());
}

TEST_F(ParserTest, createTerm_nestedStruct)
{
  Scanner scanner("s(s(1))");
  Parser parser(scanner);
  ASSERT_EQ("s(s(1))", parser.createTerm()->symbol());
}

TEST_F( ParserTest, createTerm_nestedStruct2){
  Scanner scanner( "s(s(s(s(1))))");
  Parser parser( scanner );
  ASSERT_EQ( "s(s(s(s(1))))", parser.createTerm()->symbol());
}

TEST_F(ParserTest, createTerm_nestedStruct3) {
  Scanner scanner("s(s(s(s(1)))), b(1,2,3)");
  Parser parser(scanner);
  parser.createTerms();
  vector<Term*> terms = parser.getTerms();
  EXPECT_EQ(2, terms.size());
  EXPECT_EQ("s(s(s(s(1))))",terms[0]->symbol());
  EXPECT_EQ("b(1, 2, 3)",terms[1]->symbol());
}

TEST_F(ParserTest, createTerm_DotStruct){
  Scanner scanner("...(11,12)");
  Parser parser( scanner );
  ASSERT_EQ( "...(11, 12)", parser.createTerm()->symbol());
}

TEST_F(ParserTest, createTerm_emptyList){
  Scanner scanner("   [   ]");
  Parser parser( scanner );
  ASSERT_EQ( "[]", parser.createTerm()->symbol());
}

TEST_F(ParserTest, createTerm_listWithTwoTerms){
  Scanner scanner("   [1, 2]");
  Parser parser( scanner );
  ASSERT_EQ( "[1, 2]", parser.createTerm()->symbol());
}

TEST_F(ParserTest, createTerm_nestedList){
  Scanner scanner("   [  [1], [] ]");
  Parser parser( scanner );
  ASSERT_EQ( "[[1], []]", parser.createTerm()->symbol());
}

TEST_F(ParserTest, createTerm_ListOfListAndStruct){
  Scanner scanner("   [  [1], [], s(s(1)) ]   ");
  Parser parser( scanner );
  ASSERT_EQ( "[[1], [], s(s(1))]", parser.createTerm()->symbol());
}

TEST_F(ParserTest, createTerm_illeageTerm){
  Scanner scanner("[1,2)");
  Parser parser( scanner );
  try {
    parser.createTerm();
    ASSERT_TRUE(false) << "It should throw a string; \"unexpected token\" as exception.";
  } catch (std::string exception) {
    EXPECT_EQ(exception, std::string("unexpected token"));
  }
}

TEST_F(ParserTest, createTerm_ListAsStruct) {
  Scanner scanner(".(1,[])");
  Parser parser(scanner);
  Term* term = parser.createTerm();
  EXPECT_EQ(".(1, [])", term->symbol());
  EXPECT_EQ(2, ((Struct *) term)->arity());
  Number * n = dynamic_cast<Number *>(((Struct *) term)->args(0));
  EXPECT_EQ("1", n->symbol());
  List * l = dynamic_cast<List *>(((Struct *) term)->args(1));
  EXPECT_EQ("[]", l->symbol());
}

TEST_F(ParserTest, createTerm_ListAsStruct2) {
  Scanner scanner(".(2,.(1,[]))");
  Parser parser(scanner);
  Term* term = parser.createTerm();
  EXPECT_EQ(".(2, .(1, []))", term->symbol());
  EXPECT_EQ(2, ((Struct *) term)->arity());
  Number * n = dynamic_cast<Number *>(((Struct *) term)->args(0));
  EXPECT_EQ("2", n->symbol());
  Struct * s = dynamic_cast<Struct *>(((Struct *) term)->args(1));
  EXPECT_EQ(".(1, [])", s->symbol());
}

TEST_F(ParserTest, OneMatching) {
  Scanner scanner("X=1.");
  Parser parser(scanner);
  parser.matchings();
  vector<Term *> terms = parser.getTerms();
  EXPECT_EQ(2, terms.size());
  EXPECT_EQ("X", terms[0]->symbol());
  EXPECT_EQ("1", terms[1]->symbol());
  EXPECT_NE("1", terms[0]->value());

  Node * et = parser.expressionTree();
  EXPECT_EQ(EQUALITY, et->payload);

  EXPECT_TRUE(et->evaluate());
  EXPECT_EQ("1", terms[0]->value());
}

TEST_F(ParserTest, OneMatchingFalse) {
  Scanner scanner("1=2.");
  Parser parser(scanner);
  EXPECT_NO_THROW(parser.matchings());
  vector<Term *> terms = parser.getTerms();
  EXPECT_EQ(2, terms.size());
  EXPECT_EQ("1", terms[0]->symbol());
  EXPECT_EQ("2", terms[1]->symbol());

  Node * et = parser.expressionTree();
  EXPECT_FALSE(et->evaluate());
}

TEST_F(ParserTest, TwoTermsMatching) {
  Scanner scanner("X=1, Y=2.");
  Parser parser(scanner);
  parser.matchings();
  vector<Term *> terms = parser.getTerms();
  EXPECT_EQ(4, terms.size());
  EXPECT_EQ("X", terms[0]->symbol());
  EXPECT_EQ("1", terms[1]->symbol());
  EXPECT_EQ("Y", terms[2]->symbol());
  EXPECT_EQ("2", terms[3]->symbol());

  Node * et = parser.expressionTree();
  EXPECT_TRUE(et->evaluate());
  EXPECT_EQ(COMMA, et->payload);

  EXPECT_EQ("1", terms[0]->value());
  EXPECT_EQ("2", terms[2]->value());
}

TEST_F(ParserTest, ThreeTermsMatching) {
  Scanner scanner("X=1, Y=2, Z=3.");
  Parser parser(scanner);
  parser.matchings();
  vector<Term *> terms = parser.getTerms();
  EXPECT_EQ(6, terms.size());
  EXPECT_EQ("X", terms[0]->symbol());
  EXPECT_EQ("1", terms[1]->symbol());
  EXPECT_EQ("Y", terms[2]->symbol());
  EXPECT_EQ("2", terms[3]->symbol());

  Node * et = parser.expressionTree();
  EXPECT_TRUE(et->evaluate());
  EXPECT_EQ(COMMA, et->payload);
  EXPECT_EQ(EQUALITY, et->left->payload);
  EXPECT_EQ(COMMA, et->right->payload);
  EXPECT_EQ(EQUALITY, et->right->left->payload);
  EXPECT_EQ(EQUALITY, et->right->right->payload);

  EXPECT_EQ("1", terms[0]->value());
  EXPECT_EQ("2", terms[2]->value());
  EXPECT_EQ("3", terms[4]->value());

}

TEST_F(ParserTest, TwoVariableMatching2) {
  Scanner scanner("X=1, X=Y.");
  Parser parser(scanner);
  parser.matchings();
  vector<Term *> terms = parser.getTerms();
  EXPECT_EQ(4, terms.size());
  EXPECT_EQ("X", terms[0]->symbol());
  EXPECT_EQ("1", terms[1]->symbol());
  EXPECT_EQ("X", terms[2]->symbol());
  EXPECT_EQ("Y", terms[3]->symbol());

  Node * et = parser.expressionTree();
  EXPECT_TRUE(et->evaluate());

  EXPECT_EQ("1", terms[0]->value());
  EXPECT_EQ("1", terms[2]->value());
}

TEST_F(ParserTest, TwoVariableMatching3) {
  Scanner scanner("X=Y, X=1.");
  Parser parser(scanner);
  parser.matchings();
  vector<Term *> terms = parser.getTerms();
  EXPECT_EQ(4, terms.size());
  EXPECT_EQ("X", terms[0]->symbol());
  EXPECT_EQ("Y", terms[1]->symbol());
  EXPECT_EQ("X", terms[2]->symbol());
  EXPECT_EQ("1", terms[3]->symbol());

  Node * et = parser.expressionTree();
  EXPECT_TRUE(et->evaluate());

  EXPECT_EQ("1", terms[0]->value());
  EXPECT_EQ("1", terms[1]->value());
}

TEST_F(ParserTest, VarAStructOfVar) {
  Scanner scanner("X=s(Y).");
  Parser parser(scanner);
  parser.matchings();

  vector<Term *> terms = parser.getTerms();
  EXPECT_EQ(2, terms.size());

  EXPECT_EQ("X", terms[0]->symbol());
  EXPECT_EQ("X", terms[0]->value());
  EXPECT_EQ("s(Y)", terms[1]->symbol());

  Node * et = parser.expressionTree();
  EXPECT_EQ(EQUALITY, et->payload);
  EXPECT_EQ(TERM, et->left->payload);
  EXPECT_EQ(TERM, et->right->payload);
  EXPECT_EQ("X", et->left->term->symbol());
  EXPECT_EQ("s(Y)", et->right->term->symbol());
  EXPECT_TRUE(et->evaluate());
}

TEST_F(ParserTest, TwoVariableMatching4) {
  Scanner scanner("X=s(Y), Y=1.");
  Parser parser(scanner);
  parser.matchings();
  vector<Term *> terms = parser.getTerms();
  EXPECT_EQ(4, terms.size());
  EXPECT_EQ("X", terms[0]->symbol());
  EXPECT_EQ("X", terms[0]->value());
  EXPECT_EQ("s(Y)", terms[1]->symbol());
  EXPECT_EQ("Y", terms[2]->symbol());
  EXPECT_EQ("1", terms[3]->symbol());

  Node * et = parser.expressionTree();
  EXPECT_TRUE(et->evaluate());
  EXPECT_EQ(COMMA, et->payload);
  EXPECT_EQ(EQUALITY, et->left->payload);
  EXPECT_EQ("X", et->left->left->term->symbol());
  EXPECT_EQ("s(Y)", et->left->right->term->symbol());
  EXPECT_EQ("s(Y)", terms[1]->symbol());
  EXPECT_EQ(EQUALITY, et->right->payload);
  EXPECT_EQ("Y", et->right->left->term->symbol());
  EXPECT_EQ("1", et->right->right->term->symbol());

  EXPECT_EQ("X", terms[0]->symbol());
  EXPECT_EQ("s(1)", terms[0]->value());
  EXPECT_EQ("s(1)", terms[1]->value());
  EXPECT_EQ("Y", terms[2]->symbol());
  EXPECT_EQ("1", terms[2]->value());
}

TEST_F(ParserTest, ConjTwoMatchingFailure) {
  Scanner scanner("X=1, X=2.");
  Parser parser(scanner);
  parser.matchings();
  vector<Term *> terms = parser.getTerms();
  EXPECT_EQ(4, terms.size());
  EXPECT_EQ("X", terms[0]->symbol());
  EXPECT_EQ("1", terms[1]->symbol());
  EXPECT_EQ("X", terms[2]->symbol());
  EXPECT_EQ("2", terms[3]->symbol());

  Node * et = parser.expressionTree();
  EXPECT_EQ(COMMA, et->payload);
  EXPECT_EQ(EQUALITY, et->left->payload);
  EXPECT_EQ(EQUALITY, et->right->payload);
  EXPECT_EQ("X", et->left->left->term->symbol());
  EXPECT_EQ("1", et->left->right->term->symbol());
  EXPECT_EQ("X", et->right->left->term->symbol());
  EXPECT_EQ("2", et->right->right->term->symbol());

  EXPECT_FALSE(et->evaluate());
}

TEST_F(ParserTest, DisjTwoMatchingSuccess) {
  Scanner scanner("X=1; X=2.");
  Parser parser(scanner);
  parser.matchings();
  vector<Term *> terms = parser.getTerms();
  EXPECT_EQ(4, terms.size());
  EXPECT_EQ("X", terms[0]->symbol());
  EXPECT_EQ("1", terms[1]->symbol());
  EXPECT_EQ("X", terms[2]->symbol());
  EXPECT_EQ("2", terms[3]->symbol());

  Node * et = parser.expressionTree();
  EXPECT_EQ(SEMICOLON, et->payload);
  EXPECT_EQ(EQUALITY, et->left->payload);
  EXPECT_EQ(EQUALITY, et->right->payload);
  EXPECT_EQ("X", et->left->left->term->symbol());
  EXPECT_EQ("1", et->left->right->term->symbol());
  EXPECT_EQ("X", et->right->left->term->symbol());
  EXPECT_EQ("2", et->right->right->term->symbol());

  EXPECT_TRUE(et->evaluate());

  EXPECT_EQ("1", terms[0]->value());
  EXPECT_EQ("2", terms[2]->value());
}

TEST_F(ParserTest, MatchingSuccess) {
  Scanner scanner("X=1; X=2, Y=s(s(X)).");
  Parser parser(scanner);
  parser.matchings();
  vector<Term *> terms = parser.getTerms();
  Node * et = parser.expressionTree();
  EXPECT_TRUE(et->evaluate());

  EXPECT_EQ("1", terms[0]->value());
  EXPECT_EQ("2", terms[2]->value());
  EXPECT_EQ("s(s(2))", terms[4]->value());
}

#endif
