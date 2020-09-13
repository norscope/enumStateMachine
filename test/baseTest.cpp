/**
 * @file ${FILE}
 * @author Alf
 * @date 13.09.2020.
 * @brief
 */
#define BOOST_TEST_MAIN
//#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#define BOOST_TEST_MODULE fixture_01
struct TestFixture {
  /**
   * Create the test fixture
   */
  TestFixture(){
    BOOST_TEST_MESSAGE("MSG: SETUP FIXTURE");
  }
  /**
   * Clean up after ourself.
   */
  ~TestFixture(){
    BOOST_TEST_MESSAGE("MSG: TEARDOWN FIXTURE");
  }
};

BOOST_FIXTURE_TEST_SUITE(s,TestFixture)

BOOST_AUTO_TEST_CASE(nameOfTest){
BOOST_TEST(true);
}
BOOST_AUTO_TEST_SUITE_END()