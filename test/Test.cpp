#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include "Test.h"
CPPUNIT_TEST_SUITE_REGISTRATION(FunctionTest);

//テスト起動時に実行
void FunctionTest::setUp(){
    sample = new Sample();
}

//テスト終了時に実行
void FunctionTest::testDown(){
    delete sample;
}

void FunctionTest::testSubtract() {    
    CPPUNIT_ASSERT_EQUAL(100,sample->Subtract(101, 1));
}
void FunctionTest::testMultiply() {    
    CPPUNIT_ASSERT_EQUAL(100,sample->Multiply(1, 100));
}
void FunctionTest::testDivide() {    
    CPPUNIT_ASSERT_EQUAL(100,sample->Divide(1000, 10));
}
void FunctionTest::testSum() {    
    CPPUNIT_ASSERT_EQUAL(100,sample->Sum(0, 100));
}


int main(int argc, char const *argv[]){
    CPPUNIT_NS::TestResult controller;

    //結果収集
    CPPUNIT_NS::TestResultCollector result;
    controller.addListener(&result);

    //途中結果の収集
    CPPUNIT_NS::BriefTestProgressListener progress;
    controller.addListener(&progress);

    //テストを走らせる。テストを入れて走る
    CPPUNIT_NS::TestRunner runner;
    runner.addTest( CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest() );
    runner.run(controller);

    //結果を標準出力にする。
    CPPUNIT_NS::CompilerOutputter outputter(&result,CPPUNIT_NS::stdCOut());
    outputter.write();

    return result.wasSuccessful() ? 0 : 1;
}
