#include <gtest/gtest.h>
#include <string>
#include <string_view>

bool isPalindrome(std::string_view s)
{
    std::string userInput{ s };
    bool isPalindrome = true;
    auto startInput = userInput.length();

    for (int i = 0; i < s.length(); i++)
        if (userInput[i] == ' ') userInput.erase(i, 1);


    for (int i = 0; i < (startInput / 2); i++) {
        if (userInput[i] != userInput[(startInput - 1) - i])
            isPalindrome = false;
    }
    return isPalindrome;
}

struct Param
{
    std::string_view s;
    bool expected_result;
};

class PalindromeTest : public testing::TestWithParam<Param>
{};

TEST_P(PalindromeTest, ReturnsExpectedValue)
{
    EXPECT_EQ(GetParam().expected_result, isPalindrome(GetParam().s));
}

constexpr Param data[]{
    {"", true},
    {"a", true},
    {"aa", true},
    {"ab", false},
    {"abc", false},
    {"aba", true},
    {"ab ba", true},
    {"abbc", false},
    {"abca", false},
};

INSTANTIATE_TEST_SUITE_P(X, PalindromeTest, testing::ValuesIn(data));
int main()
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
