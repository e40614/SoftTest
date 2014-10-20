#include <gtest/gtest.h>
#include "Comission.h"
//-1 for Error,there are 70 locks ,80 stocks ,90 barrels
TEST(Comission, BoundaryTest) {
	ASSERT_EQ(640, Comission(35, 40, 45));
	ASSERT_EQ(-1, Comission(0, 40, 45));
	ASSERT_EQ(334, Comission(1, 40, 45));
	ASSERT_EQ(343, Comission(2, 40, 45));
	ASSERT_EQ(946, Comission(69, 40, 45));
	ASSERT_EQ(955, Comission(70, 40, 45));
	ASSERT_EQ(-1, Comission(71, 40, 45));
	ASSERT_EQ(-1, Comission(35, 0, 45));
	ASSERT_EQ(406, Comission(35, 1, 45));
	ASSERT_EQ(412, Comission(35, 2, 45));
	ASSERT_EQ(874, Comission(35, 79, 45));
	ASSERT_EQ(880, Comission(35, 80, 45));
	ASSERT_EQ(-1, Comission(35, 81, 45));
	ASSERT_EQ(-1, Comission(35, 40, 0));
	ASSERT_EQ(420, Comission(35, 40, 1));
	ASSERT_EQ(425, Comission(35, 40, 2));
	ASSERT_EQ(860, Comission(35, 40, 89));
	ASSERT_EQ(865, Comission(35, 40, 90));
	ASSERT_EQ(-1, Comission(35, 40, 91));


}	
 
TEST(Comission, EquivalenceClass_WR) {
//weak
	ASSERT_EQ(100, Comission(10, 10, 10));
	ASSERT_EQ(-1, Comission(0, 40, 45));
	ASSERT_EQ(-1, Comission(71, 40, 45));
	ASSERT_EQ(-1, Comission(35, 0, 45));
	ASSERT_EQ(-1, Comission(35, 81, 45));
	ASSERT_EQ(-1, Comission(35, 40, 0));
	ASSERT_EQ(-1, Comission(35, 40, 91));
}

TEST(Comission, EquivalenceClass_SR) {
//strong
	ASSERT_EQ(-1, Comission(0, 40, 45));
	ASSERT_EQ(-1, Comission(35, 0, 45));
	ASSERT_EQ(-1, Comission(35, 40, 0));
	ASSERT_EQ(-1, Comission(0, 0, 45));
	ASSERT_EQ(-1, Comission(0, 40, 0));
	ASSERT_EQ(-1, Comission(35, 0, 0));
	ASSERT_EQ(-1, Comission(0, 0, 0));

}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
