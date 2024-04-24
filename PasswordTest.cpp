#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test {
protected:
    PasswordTest(){} //constructor runs before each test
    virtual ~PasswordTest(){} //destructor cleans up after tests
    virtual void SetUp(){} //sets up before each test (after constructor)
    virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, Single_Letter_Password) {
    Password my_password;
    int actual = my_password.count_leading_characters("Z");
    ASSERT_EQ(1, actual);
}

TEST(PasswordTest, Multiple_Leading_Characters) {
    Password my_password;
    int actual = my_password.count_leading_characters("AAAA");
    ASSERT_EQ(4, actual);
}

TEST(PasswordTest, No_Repeating_Characters) {
    Password my_password;
    int actual = my_password.count_leading_characters("ABCDEFG");
    ASSERT_EQ(1, actual);
}

TEST(PasswordTest, Empty_String) {
    Password my_password;
    int actual = my_password.count_leading_characters("");
    ASSERT_EQ(0, actual);
}

TEST(PasswordTest, Mixed_Case_Sensitivity) {
    Password my_password;
    int actual = my_password.count_leading_characters("AaAaA");
    ASSERT_EQ(1, actual);
}

TEST(PasswordTest, Special_Characters) {
    Password my_password;
    int actual = my_password.count_leading_characters("!!!@@@");
    ASSERT_EQ(3, actual);
}

TEST(PasswordTest, MixedCaseValidation_True) {
    Password my_password;
    bool actual = my_password.has_mixed_case("Aa");
    ASSERT_TRUE(actual);
}

TEST(PasswordTest, MixedCaseValidation_False) {
    Password my_password;
    bool actual = my_password.has_mixed_case("AAA");
    ASSERT_FALSE(actual);
}

TEST(PasswordTest, Authentication_Success) {
    Password my_password;
    my_password.set("NewPassword1");
    bool actual = my_password.authenticate("NewPassword1");
    ASSERT_TRUE(actual);
}

TEST(PasswordTest, Authentication_Failure) {
    Password my_password;
    my_password.set("NewPassword1");
    bool actual = my_password.authenticate("newpassword1");
    ASSERT_FALSE(actual);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
