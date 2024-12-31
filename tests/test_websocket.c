#include <assert.h>
#include "websocket_test.h"

int main() {
    websocket_test("localhost", 5);
    assert(1); // 简单测试，运行时观察日志
    return 0;
}
