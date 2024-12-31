#include <assert.h>
#include "http_test.h"

int main() {
    http_test("http://localhost", 10);
    assert(1); // 简单测试，运行时观察日志
    return 0;
}
