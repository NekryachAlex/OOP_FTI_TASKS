#include "gtest/gtest.h"
#include "../HashMapStrategy/HashMap.h"
#include "../HashMapStrategy/NoStrategy.h"
#include "../HashMapStrategy/NumberOfRequests.h"
#include "../HashMapStrategy/TimeoutStrategy.h"

TEST(NoStrategy, InsertTestInt) {
	HashMap<int, int, NoStrategy> testMap; 
	
}