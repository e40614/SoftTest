#include <gtest/gtest.h>
#include "triangle.h"
//0 for Error, 1 for Equilateral, 2 for Isosceles, 3 for Scalene
//input range is 1~200
TEST(triangle, BoundaryTest) {
    ASSERT_EQ(triangle(100, 100, 1), 2);
	ASSERT_EQ(triangle(100, 100, 2), 2);
	ASSERT_EQ(triangle(100, 100, 100), 1);
	ASSERT_EQ(triangle(100, 100, 199), 2);
	ASSERT_EQ(triangle(100, 100, 200), 0);
	ASSERT_EQ(triangle(100, 1, 100), 2);
	ASSERT_EQ(triangle(100, 2, 100), 2);
	ASSERT_EQ(triangle(100, 199, 100), 2);
	ASSERT_EQ(triangle(100, 200, 100), 0);
	ASSERT_EQ(triangle(1, 100, 100), 2);
	ASSERT_EQ(triangle(2, 100, 100), 2);
	ASSERT_EQ(triangle(199, 100, 100), 2);
	ASSERT_EQ(triangle(200, 100, 100), 0);
	ASSERT_EQ(triangle(0, 100, 100), 0);
	ASSERT_EQ(triangle(201, 100, 102), 0);
	ASSERT_EQ(triangle(100, 0, 100), 0);
	ASSERT_EQ(triangle(100, 201, 102), 0);
	ASSERT_EQ(triangle(100, 100, 0), 0);
	ASSERT_EQ(triangle(100, 102, 201), 0);


}	
 
TEST(triangle, EquivalenceClass) {
//normal
	ASSERT_EQ(triangle(5, 5, 5), 1);
	ASSERT_EQ(triangle(2, 2, 3), 2);
	ASSERT_EQ(triangle(3, 4, 5), 3);
	ASSERT_EQ(triangle(4, 1, 2), 0);
//weak
	ASSERT_EQ(triangle(-1, 5, 5), 0);
	ASSERT_EQ(triangle(5, -1, 5), 0);
	ASSERT_EQ(triangle(5, 5, -1), 0);
	ASSERT_EQ(triangle(201, 5, 5), 0);
	ASSERT_EQ(triangle(5, 201, 5), 0);
	ASSERT_EQ(triangle(5, 5, 201), 0);
//strong
	ASSERT_EQ(triangle(-1, 5, 5), 0);
	ASSERT_EQ(triangle(5, -1, 5), 0);
	ASSERT_EQ(triangle(5, 5, -1), 0);
	ASSERT_EQ(triangle(-1, -1, 5), 0);
	ASSERT_EQ(triangle(5, -1, -1), 0);
	ASSERT_EQ(triangle(-1, 5, -1), 0);
	ASSERT_EQ(triangle(-1, -1, -1), 0);
}

TEST(triangle, DecisionTable) {
	ASSERT_EQ(triangle(4, 1, 2), 0);
	ASSERT_EQ(triangle(1, 4, 2), 0);
	ASSERT_EQ(triangle(1, 2, 4), 0);
	ASSERT_EQ(triangle(5, 5, 5), 1);
	ASSERT_EQ(triangle(2, 2, 3), 2);
	ASSERT_EQ(triangle(2, 3, 2), 2);
	ASSERT_EQ(triangle(3, 2, 2), 2);
	ASSERT_EQ(triangle(3, 4, 5), 3);
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
