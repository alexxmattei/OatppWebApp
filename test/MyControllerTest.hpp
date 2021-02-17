#ifndef MyControllerTest_hpp
#define MyControllerTest_hpp

#include "oatpp-test/UnitTest.hpp"

class MyClientControllerTest : public oatpp::test::UnitTest {
public:

  MyClientControllerTest() : UnitTest("TEST[MyClientControllerTest]"){}
  void onRun() override;

};

#endif // MyControllerTest_hpp
