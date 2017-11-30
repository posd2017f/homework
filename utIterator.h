#ifndef UTITERATOR_H
#define UTITERATOR_H

#include "iterator.h"

TEST(iterator, first) {
    Number one(1);
    Variable X("X");
    Variable Y("Y");
    Number two(2);
    Struct t(Atom("t"), { &X, &two });
    Struct s(Atom("s"), { &one, &t, &Y });
    StructIterator it(&s);
    Iterator& itStruct = it;
    itStruct.first();
    ASSERT_EQ("1", itStruct.currentItem()->symbol());
    ASSERT_FALSE(itStruct.isDone());
    itStruct.next();
    ASSERT_EQ("t(X, 2)", itStruct.currentItem()->symbol());
    ASSERT_FALSE(itStruct.isDone());
    itStruct.next();
    ASSERT_EQ("Y", itStruct.currentItem()->symbol());
    itStruct.next();
    ASSERT_TRUE(itStruct.isDone());
}

TEST(iterator, nested_iterator) {
  Number one(1);
  Variable X("X");
  Variable Y("Y");
  Number two(2);
  Struct t(Atom("t"), { &X, &two });
  Struct s(Atom("s"), { &one, &t, &Y });
  StructIterator it(&s);
  it.first();
  it.next();
  Struct *s2 = dynamic_cast<Struct *>(it.currentItem());

  StructIterator it2(s2);
  it2.first();
  ASSERT_EQ("X", it2.currentItem()->symbol());
  ASSERT_FALSE(it2.isDone());
  it2.next();
  ASSERT_EQ("2", it2.currentItem()->symbol());
  ASSERT_FALSE(it2.isDone());
  it2.next();
  ASSERT_TRUE(it2.isDone());
}

TEST(iterator, firstList) {
    Number one(1);
    Variable X("X");
    Variable Y("Y");
    Number two(2);
    Struct t(Atom("t"), { &X, &two });
    List l({ &one, &t, &Y });
    ListIterator it(&l);
    Iterator* itList = &it;
    itList->first();
    ASSERT_EQ("1", itList->currentItem()->symbol());
    ASSERT_FALSE(itList->isDone());
    itList->next();
    ASSERT_EQ("t(X, 2)", itList->currentItem()->symbol());
    ASSERT_FALSE(itList->isDone());
    itList->next();
    ASSERT_EQ("Y", itList->currentItem()->symbol());
    itList->next();
    ASSERT_TRUE(itList->isDone());
}

TEST(iterator, NullIterator){
  Number one(1); 
  NullIterator nullIterator(&one);
  nullIterator.first();
  ASSERT_TRUE(nullIterator.isDone());
  Iterator * it = one.createIterator();
  it->first();
  ASSERT_TRUE(it->isDone());
}

TEST(Iterator, DFS_OneMatching) {
  Scanner scanner("X=1.");
  Parser parser(scanner);
  parser.matchings();
  Node * et = parser.expressionTree();

  Iterator * it = et->createDFSIterator();
  it->first();

  ASSERT_EQ("=", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("X", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("1", it->currentItem()->symbol());
  ASSERT_TRUE(it->isDone());
}

TEST(Iterator, DFS_TwoTermsMatching) {
  Scanner scanner("X=1, Y=2.");
  Parser parser(scanner);
  parser.matchings();
  Node * et = parser.expressionTree();

  Iterator * it = et->createDFSIterator();
  it->first();

  ASSERT_EQ(",", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("=", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("X", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("1", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("=", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("Y", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("2", it->currentItem()->symbol());
  ASSERT_TRUE(it->isDone());
}

TEST(Iterator, DFS_ThreeTermsMatching1) {
  Scanner scanner("X=1, Y=2, Z=3.");
  Parser parser(scanner);
  parser.matchings();
  Node * et = parser.expressionTree();

  Iterator * it = et->createDFSIterator();
  it->first();

  ASSERT_EQ(",", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("=", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("X", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("1", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ(",", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("=", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("Y", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("2", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("=", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("Z", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("3", it->currentItem()->symbol());
  ASSERT_TRUE(it->isDone());
}

TEST(Iterator, DFS_ThreeTermsMatching2) {
  Scanner scanner("X=1, Y=2; Z=3.");
  Parser parser(scanner);
  parser.matchings();
  Node * et = parser.expressionTree();

  Iterator * it = et->createDFSIterator();
  it->first();

  ASSERT_EQ(",", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("=", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("X", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("1", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ(";", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("=", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("Y", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("2", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("=", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("Z", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("3", it->currentItem()->symbol());
  ASSERT_TRUE(it->isDone());
}

TEST(Iterator, DFS_ThreeTermsMatching3) {
  Scanner scanner("X=1; X=2, Y=s(s(X)).");
  Parser parser(scanner);
  parser.matchings();
  Node * et = parser.expressionTree();

  Iterator * it = et->createDFSIterator();

  it->first();
  ASSERT_EQ(";", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("=", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("X", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("1", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ(",", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("=", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("X", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("2", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("=", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("Y", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("s(s(X))", it->currentItem()->symbol());
  ASSERT_TRUE(it->isDone());
}

TEST(Iterator, BFS_OneMatching) {
  Scanner scanner("X=1.");
  Parser parser(scanner);
  parser.matchings();
  Node * et = parser.expressionTree();

  Iterator * it = et->createBFSIterator();
  it->first();

  ASSERT_EQ("=", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("X", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("1", it->currentItem()->symbol());
  ASSERT_TRUE(it->isDone());
}

TEST(Iterator, BFS_TwoTermsMatching) {
  Scanner scanner("X=1, Y=2.");
  Parser parser(scanner);
  parser.matchings();
  Node * et = parser.expressionTree();

  Iterator * it = et->createBFSIterator();
  it->first();

  ASSERT_EQ(",", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("=", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("=", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("X", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("1", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("Y", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("2", it->currentItem()->symbol());
  ASSERT_TRUE(it->isDone());
}

TEST(Iterator, BFS_ThreeTermsMatching1) {
  Scanner scanner("X=1, Y=2, Z=3.");
  Parser parser(scanner);
  parser.matchings();
  Node * et = parser.expressionTree();

  Iterator * it = et->createBFSIterator();

  it->first();
  ASSERT_EQ(",", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("=", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ(",", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("X", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("1", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("=", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("=", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("Y", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("2", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("Z", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("3", it->currentItem()->symbol());
  ASSERT_TRUE(it->isDone());
}

TEST(Iterator, BFS_ThreeTermsMatching2) {
  Scanner scanner("X=1, Y=2; Z=3.");
  Parser parser(scanner);
  parser.matchings();
  Node * et = parser.expressionTree();

  Iterator * it = et->createBFSIterator();
  it->first();

  ASSERT_EQ(",", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("=", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ(";", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("X", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("1", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("=", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("=", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("Y", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("2", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("Z", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("3", it->currentItem()->symbol());
  ASSERT_TRUE(it->isDone());
}

TEST(Iterator, BFS_ThreeTermsMatching3) {
  Scanner scanner("X=1; X=2, Y=s(s(X)).");
  Parser parser(scanner);
  parser.matchings();
  Node * et = parser.expressionTree();

  Iterator * it = et->createBFSIterator();

  it->first();
  ASSERT_EQ(";", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("=", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ(",", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("X", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("1", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("=", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("=", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("X", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("2", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("Y", it->currentItem()->symbol());
  it->next();
  ASSERT_EQ("s(s(X))", it->currentItem()->symbol());
  ASSERT_TRUE(it->isDone());
}

#endif
