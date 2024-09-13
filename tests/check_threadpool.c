#include <check.h>
#include "../src/threadpool/libthreadpool.h"


START_TEST(test_tp_initilize) 
{
	ck_assert_int_eq(init(2, NULL), 0);
	destroy();
}
END_TEST

int main(void)
{
	return 0;
}
