#include <iostream>
#include <iostream>
#include <string>
#include <cctype>
#include <cassert>

using namespace std;

int strcmp_case_insensitive(const string& str1, const string& str2)
{
    size_t i = 0;

    while (i < str1.length() && i < str2.length())
    {
        char c1 = tolower(str1[i]);
        char c2 = tolower(str2[i]);

        if (c1 < c2)
            return -1;
        if (c1 > c2)
            return 1;

        i++;
    }

    if (str1.length() < str2.length())
        return -1;
    if (str1.length() > str2.length())
        return 1;

    return 0;
}

int main()
{
    // Equal strings (different cases)
    assert(strcmp_case_insensitive("Hi", "hi") == 0);
    assert(strcmp_case_insensitive("HELLO", "hello") == 0);
    assert(strcmp_case_insensitive("Computer", "cOmPuTeR") == 0);

    // First string comes before second
    assert(strcmp_case_insensitive("apple", "banana") == -1);
    assert(strcmp_case_insensitive("cat", "catalog") == -1);
    assert(strcmp_case_insensitive("", "abc") == -1);

    // First string comes after second
    assert(strcmp_case_insensitive("banana", "apple") == 1);
    assert(strcmp_case_insensitive("catalog", "cat") == 1);
    assert(strcmp_case_insensitive("abc", "") == 1);

    // Empty strings
    assert(strcmp_case_insensitive("", "") == 0);

    cout << "All tests passed!" << endl;

    return 0;
}