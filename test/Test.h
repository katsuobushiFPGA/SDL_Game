#include "../src/include/Sample.h"
class FunctionTest : public CPPUNIT_NS::TestFixture{
    //テストクラス
    CPPUNIT_TEST_SUITE(FunctionTest);//登録のスタート
    CPPUNIT_TEST(testSum);//メンバ関数の登録
    CPPUNIT_TEST(testSubtract);//メンバ関数の登録
    CPPUNIT_TEST(testMultiply);//メンバ関数の登録
    CPPUNIT_TEST(testDivide);//メンバ関数の登録
    CPPUNIT_TEST_SUITE_END();//登録の終了

protected:
    Sample* sample;
    void testSum();    
    void testSubtract();    
    void testMultiply();    
    void testDivide();    

public:
    void setUp();
    void testDown();
};
