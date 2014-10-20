#include <gtest/gtest.h>
#include <string>
#include "NextDate.h"
//"" for Error
// year range : 1993~2014
//month range : 1~12
//Day range : 1~31
TEST(NextDate, BoundaryTest) {
	ASSERT_STREQ("1993/1/2",NextDate(1993, 1, 1).c_str());
	ASSERT_STREQ("1994/1/2",NextDate(1994, 1, 1).c_str());
	ASSERT_STREQ("2000/1/2",NextDate(2000, 1, 1).c_str());
	ASSERT_STREQ("2013/1/2",NextDate(2013, 1, 1).c_str());
	ASSERT_STREQ("2014/1/2",NextDate(2014, 1, 1).c_str());
	ASSERT_STREQ("",NextDate(1992, 1, 1).c_str());
	ASSERT_STREQ("",NextDate(2015, 1, 1).c_str());

	ASSERT_STREQ("2000/1/2",NextDate(2000, 1, 1).c_str());
	ASSERT_STREQ("2000/2/2",NextDate(2000, 2, 1).c_str());
	ASSERT_STREQ("2000/6/2",NextDate(2000, 6, 1).c_str());
	ASSERT_STREQ("2000/11/2",NextDate(2000, 11, 1).c_str());
	ASSERT_STREQ("2000/12/2",NextDate(2000, 12, 1).c_str());
	ASSERT_STREQ("",NextDate(2000, 0, 1).c_str());
	ASSERT_STREQ("",NextDate(2000, 13, 1).c_str());

	ASSERT_STREQ("2000/1/2",NextDate(2000, 1, 1).c_str());
	ASSERT_STREQ("2000/1/3",NextDate(2000, 1, 2).c_str());
	ASSERT_STREQ("2000/1/16",NextDate(2000, 1, 15).c_str());
	ASSERT_STREQ("2000/1/31",NextDate(2000, 1, 30).c_str());
	ASSERT_STREQ("2000/2/1",NextDate(2000, 1, 31).c_str());
	ASSERT_STREQ("",NextDate(2000, 1, 0).c_str());
	ASSERT_STREQ("",NextDate(2000, 1, 32).c_str());

}	

TEST(NextDate, EquivalenceClass_WeakRobust) {
	ASSERT_STREQ("2000/6/16",NextDate(2000, 6, 15).c_str());
	ASSERT_STREQ("",NextDate(2000, -1, 15).c_str());
	ASSERT_STREQ("",NextDate(2000, 13, 15).c_str());
	ASSERT_STREQ("",NextDate(2000, 6, 32).c_str());
	ASSERT_STREQ("",NextDate(1992, 6, 15).c_str());
	ASSERT_STREQ("",NextDate(2015, 6, 15).c_str());
}

TEST(NextDate, EquivalenceClass_StrongRobust) {
	ASSERT_STREQ("",NextDate(2000, -1, 15).c_str());
	ASSERT_STREQ("",NextDate(2000, 6, -1).c_str());
	ASSERT_STREQ("",NextDate(1992, 6, 15).c_str());
	ASSERT_STREQ("",NextDate(2000, -1, -1).c_str());
	ASSERT_STREQ("",NextDate(1992, 6, -1).c_str());
	ASSERT_STREQ("",NextDate(1992, -1, 15).c_str());
	ASSERT_STREQ("",NextDate(1992, -1, -1).c_str());
}

TEST(NextDate, EquivalenceClass_WeakNormal) {
	ASSERT_STREQ("2000/6/15",NextDate(2000, 6, 14).c_str());
	ASSERT_STREQ("2004/7/30",NextDate(2004, 7, 29).c_str());
	ASSERT_STREQ("",NextDate(1993, 2, 30).c_str());
	ASSERT_STREQ("",NextDate(1992, 6, 31).c_str());
}

TEST(NextDate, DecisionTable) {
	ASSERT_STREQ("1993/6/16",NextDate(1993, 6, 15).c_str());
	ASSERT_STREQ("1993/7/1",NextDate(1993, 6, 30).c_str());
	ASSERT_STREQ("",NextDate(1993, 6, 31).c_str());
	ASSERT_STREQ("1993/3/16",NextDate(1993, 3, 15).c_str());
	ASSERT_STREQ("1993/4/1",NextDate(1993, 3, 31).c_str());
	ASSERT_STREQ("1993/12/16",NextDate(1993, 12, 15).c_str());
	ASSERT_STREQ("1994/1/1",NextDate(1993, 12, 31).c_str());
	ASSERT_STREQ("1993/2/16",NextDate(1993, 2, 15).c_str());
	ASSERT_STREQ("2000/2/29",NextDate(2000, 2, 28).c_str());
	ASSERT_STREQ("1993/3/1",NextDate(1993, 2, 28).c_str());
	ASSERT_STREQ("2000/3/1",NextDate(2000, 2, 29).c_str());
	ASSERT_STREQ("",NextDate(1993, 2, 29).c_str());
	ASSERT_STREQ("",NextDate(1993, 2, 30).c_str());


}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
