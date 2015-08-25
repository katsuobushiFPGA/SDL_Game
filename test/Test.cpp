#include "/usr/include/CppUTest/CommandLineTestRunner.h"
#include "../src/include/Sample.h"

TEST_GROUP(TestBullet)
{
    Sample *sample;
    TEST_SETUP() {
        sample = new Sample();
    }

    TEST_TEARDOWN() {
        delete sample;
    }
};

TEST(TestBullet, TestCaseLimitation)
{
    CHECK_EQUAL(2,sample->Subtract(3,1));
}

TEST(TestBullet, TestCaseMistery)
{
    CHECK_EQUAL(2,sample->Sum(1,1));
}
int main(int argc,char** argv)
{
    return CommandLineTestRunner::RunAllTests(argc, argv);
}
