#include "gtest/gtest.h"
#include "../HashMapStrategy/HashMap.h"
#include "../HashMapStrategy/NoStrategy.h"
#include "../HashMapStrategy/NumberOfRequests.h"
#include "../HashMapStrategy/TimeoutStrategy.h"
#include <chrono>
#include <thread>
using namespace std::this_thread;   
using namespace std::chrono_literals;
TEST(NoSrategy, InsertValue) {
	HashMap<int, int, NoStrategy> testMap1;
	testMap1.insert(std::pair<int, int> {1, 10});
	EXPECT_EQ(10, testMap1.begin()->second);
}


TEST(NoSrategy, InsertKey) {
	HashMap<int, int, NoStrategy> testMap1;
	testMap1.insert(std::pair<int, int> {1, 10});
	EXPECT_EQ(1, testMap1.begin()->first);
}

TEST(NoSrategy, StarOperator) {
	HashMap<int, int, NoStrategy> testMap1;
	testMap1.insert(std::pair<int, int> {1, 10});
	EXPECT_EQ(1, (*testMap1.begin()).first);
}

TEST(NoSrategy, PlusPlusOperator) {
	HashMap<int, int, NoStrategy> testMap1;
	testMap1.insert(std::pair<int, int> {1, 10});
	testMap1.insert(std::pair<int, int> {2, 20});
	EXPECT_EQ(2, (*(++(testMap1.begin()))).first);
}

TEST(NoSrategy, ArrowOperator) {
	HashMap<int, int, NoStrategy> testMap1;
	testMap1.insert(std::pair<int, int> {1, 10});
	EXPECT_EQ(1, (testMap1.begin()->first));
}

TEST(NoSrategy, BracketOperator) {
	HashMap<int, int, NoStrategy> testMap1;
	testMap1.insert(std::pair<int, int> {1, 10});
	EXPECT_EQ(10, testMap1[1]);
}

TEST(NoSrategy, Erase) {
	HashMap<int, int, NoStrategy> testMap1;
	testMap1.insert(std::pair<int, int> {1, 10});
	testMap1.erase(1);
	EXPECT_EQ(0, testMap1[1]);
}

//

TEST(NumberOfRequestStrategy, InsertValue) {
	size_t limit = 1;
	HashMap<int, int, NumberOfRequestStrategy, size_t> testMap1(limit);
	testMap1.insert(std::pair<int, int> {1, 10});
	EXPECT_EQ(10, testMap1.begin()->second);
}


TEST(NumberOfRequestStrategy, InsertKey) {
	size_t limit = 1;
	HashMap<int, int, NumberOfRequestStrategy, size_t> testMap1(limit);
	testMap1.insert(std::pair<int, int> {1, 10});
	EXPECT_EQ(1, testMap1.begin()->first);
}

TEST(NumberOfRequestStrategyrategy, StarOperator) {
	size_t limit = 1;
	HashMap<int, int, NumberOfRequestStrategy, size_t> testMap1(limit);
	testMap1.insert(std::pair<int, int> {1, 10});
	EXPECT_EQ(1, (*testMap1.begin()).first);
}

TEST(NumberOfRequestStrategy, PlusPlusOperator) {
	size_t limit = 1;
	HashMap<int, int, NumberOfRequestStrategy, size_t> testMap1(limit);
	testMap1.insert(std::pair<int, int> {1, 10});
	testMap1.insert(std::pair<int, int> {2, 20});
	EXPECT_EQ(2, (*(++(testMap1.begin()))).first);
}

TEST(NumberOfRequestStrategy, ArrowOperator) {
	size_t limit = 1;
	HashMap<int, int, NumberOfRequestStrategy, size_t> testMap1(limit);
	testMap1.insert(std::pair<int, int> {1, 10});
	EXPECT_EQ(1, (testMap1.begin()->first));
}

TEST(NumberOfRequestStrategy, BracketOperator) {
	size_t limit = 1;
	HashMap<int, int, NumberOfRequestStrategy, size_t> testMap1(limit);
	testMap1.insert(std::pair<int, int> {1, 10});
	EXPECT_EQ(10, testMap1[1]);
}

TEST(NumberOfRequestStrategy, BracketOperatorLimit1) {
	size_t limit = 1;
	HashMap<int, int, NumberOfRequestStrategy, size_t> testMap1(limit);
	testMap1.insert(std::pair<int, int> {1, 10});
	testMap1[1];
	EXPECT_EQ(0, testMap1[1]);
}

TEST(NumberOfRequestStrategy, BracketOperatorLimit2) {
	size_t limit = 2;
	HashMap<int, int, NumberOfRequestStrategy, size_t> testMap1(limit);
	testMap1.insert(std::pair<int, int> {1, 10});
	testMap1[1];
	testMap1[1];
	EXPECT_EQ(0, testMap1[1]);
}

TEST(NumberOfRequestStrategy, BracketOperatorLimit2But1call) {
	size_t limit = 2;
	HashMap<int, int, NumberOfRequestStrategy, size_t> testMap1(limit);
	testMap1.insert(std::pair<int, int> {1, 10});
	testMap1[1];
	EXPECT_EQ(10, testMap1[1]);
}

TEST(NumberOfRequestStrategy, Erase) {
	size_t limit = 1;
	HashMap<int, int, NumberOfRequestStrategy, size_t> testMap1(limit);
	testMap1.insert(std::pair<int, int> {1, 10});
	testMap1.erase(1);
	EXPECT_EQ(0, testMap1[1]);
}

//

TEST(TimeoutStrategy, InsertValue) {
	ULONGLONG limit = 100;
	HashMap<int, int, TimeoutStrategy, ULONGLONG> testMap1(limit);
	testMap1.insert(std::pair<int, int> {1, 10});
	EXPECT_EQ(10, testMap1.begin()->second);
}


TEST(TimeoutStrategy, InsertKey) {
	ULONGLONG limit = 100;
	HashMap<int, int, TimeoutStrategy, ULONGLONG> testMap1(limit);
	testMap1.insert(std::pair<int, int> {1, 10});
	EXPECT_EQ(1, testMap1.begin()->first);
}

TEST(TimeoutStrategy, StarOperator) {
	ULONGLONG limit = 100;
	HashMap<int, int, TimeoutStrategy, ULONGLONG> testMap1(limit);
	testMap1.insert(std::pair<int, int> {1, 10});
	EXPECT_EQ(1, (*testMap1.begin()).first);
}

TEST(TimeoutStrategy, PlusPlusOperator) {
	ULONGLONG limit = 100;
	HashMap<int, int, TimeoutStrategy, ULONGLONG> testMap1(limit);
	testMap1.insert(std::pair<int, int> {1, 10});
	testMap1.insert(std::pair<int, int> {2, 20});
	EXPECT_EQ(2, (*(++(testMap1.begin()))).first);
}

TEST(TimeoutStrategy, ArrowOperator) {
	ULONGLONG limit = 100;
	HashMap<int, int, TimeoutStrategy, ULONGLONG> testMap1(limit);
	testMap1.insert(std::pair<int, int> {1, 10});
	EXPECT_EQ(1, (testMap1.begin()->first));
}

TEST(TimeoutStrategy, BracketOperator) {
	ULONGLONG limit = 100;
	HashMap<int, int, TimeoutStrategy, ULONGLONG> testMap1(limit);
	testMap1.insert(std::pair<int, int> {1, 10});
	EXPECT_EQ(10, testMap1[1]);
}

TEST(TimeoutStrategy, BracketOperatorExceedLimit) {
	ULONGLONG limit = 10;
	HashMap<int, int, TimeoutStrategy, ULONGLONG> testMap1(limit);
	testMap1.insert(std::pair<int, int> {1, 10});
	sleep_for(2s);
	EXPECT_EQ(0, testMap1[1]);
}

TEST(TimeoutStrategy, Erase) {
	ULONGLONG limit = 100;
	HashMap<int, int, TimeoutStrategy, ULONGLONG> testMap1(limit);
	testMap1.insert(std::pair<int, int> {1, 10});
	testMap1.erase(1);
	EXPECT_EQ(0, testMap1[1]);
}

