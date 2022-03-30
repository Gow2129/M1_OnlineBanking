#include "unity.h"

#include "methodfunction.h"
#include "user.h"





/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}




/* Prototypes for all the test functions */


void test_Topicindex(void){
        
  	TEST_ASSERT_EQUAL("Your current balance is Rs.0.00",fun1());
      
}




int main(void)
{
UNITY_BEGIN();
RUN_TEST(test_Topicindex);

return UNITY_END();
}
