#include <string>
#include <assert.h>

static void
test_heartbeat_notimeout (int is_curve)
{
    assert(is_curve==0);

}

int main (void)
{
    test_heartbeat_notimeout(0);
    test_heartbeat_notimeout(1);
}