#include <gtest/gtest.h>
#include "triangle.h"
//0 for Error, 1 for Equilateral, 2 for Isosceles, 3 for Scalene
//input range is 1~200
TEST(triangle, BoundaryTest) {
    ASSERT_EQ(2, triangle(100, 100, 1));
	ASSERT_EQ(2, triangle(100, 100, 2));
	ASSERT_EQ(1, triangle(100, 100, 100));
	ASSERT_EQ(2, triangle(100, 100, 199));
	ASSERT_EQ(0, triangle(100, 100, 200));
	ASSERT_EQ(2, triangle(100, 1, 100));
	ASSERT_EQ(2, triangle(100, 2, 100));
	ASSERT_EQ(2, triangle(100, 199, 100));
	ASSERT_EQ(0, triangle(100, 200, 100));
	ASSERT_EQ(2, triangle(1, 100, 100));
	ASSERT_EQ(2, triangle(2, 100, 100));
	ASSERT_EQ(2, triangle(199, 100, 100));
	ASSERT_EQ(0, triangle(200, 100, 100));
	ASSERT_EQ(0, triangle(0, 100, 100));
	ASSERT_EQ(0, triangle(201, 100, 102));
	ASSERT_EQ(0, triangle(100, 0, 100));
	ASSERT_EQ(0, triangle(100, 201, 102));
	ASSERT_EQ(0, triangle(100, 100, 0));
	ASSERT_EQ(0, triangle(100, 102, 201));


}	
 
TEST(triangle, EquivalenceClass) {
//normal
	ASSERT_EQ(1, triangle(5, 5, 5));
	ASSERT_EQ(2, triangle(2, 2, 3));
	ASSERT_EQ(3, triangle(3, 4, 5));
	ASSERT_EQ(0, triangle(4, 1, 2));
//weak
	ASSERT_EQ(0, triangle(-1, 5, 5));
	ASSERT_EQ(0, triangle(5, -1, 5));
	ASSERT_EQ(0, triangle(5, 5, -1));
	ASSERT_EQ(0, triangle(201, 5, 5));
	ASSERT_EQ(0, triangle(5, 201, 5));
	ASSERT_EQ(0, triangle(5, 5, 201));
//strong
	ASSERT_EQ(0, triangle(-1, 5, 5));
	ASSERT_EQ(0, triangle(5, -1, 5));
	ASSERT_EQ(0, triangle(5, 5, -1));
	ASSERT_EQ(0, triangle(-1, -1, 5));
	ASSERT_EQ(0, triangle(5, -1, -1));
	ASSERT_EQ(0, triangle(-1, 5, -1));
	ASSERT_EQ(0, triangle(-1, -1, -1));
}

TEST(triangle, DecisionTable) {
	ASSERT_EQ(0, triangle(4, 1, 2));
	ASSERT_EQ(0, triangle(1, 4, 2));
	ASSERT_EQ(0, triangle(1, 2, 4));
	ASSERT_EQ(1, triangle(5, 5, 5));
	ASSERT_EQ(2, triangle(2, 2, 3));
	ASSERT_EQ(2, triangle(2, 3, 2));
	ASSERT_EQ(2, triangle(3, 2, 2));
	ASSERT_EQ(3, triangle(3, 4, 5));
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
