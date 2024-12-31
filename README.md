# WebSocket 和 HTTP 压测工具

## 项目简介

这个项目是一个支持 HTTP 和 WebSocket 压测的工具，能够根据用户输入的 URL 和请求/连接次数进行性能测试。压测结果包括 QPS（每秒请求数）和平均延迟等。

该工具适用于对 Web 服务进行性能压力测试，帮助开发者了解服务的负载能力及响应性能。

## 项目结构

```plaintext
websocket_http_stress_test/
├── bin/                  # 可执行文件输出目录
├── build/                # 中间编译文件存放目录（可选）
├── src/                  # 源代码目录
│   ├── http_test.c       # HTTP 压测代码
│   ├── websocket_test.c  # WebSocket 压测代码
│   ├── utils.c           # 公共工具函数，如时间戳、日志等
│   └── Makefile          # 编译脚本（可选）
├── include/              # 头文件目录
│   ├── utils.h           # 公共工具函数头文件
│   ├── http_test.h       # HTTP 压测相关头文件
│   └── websocket_test.h  # WebSocket 压测相关头文件
├── docs/                 # 项目文档
│   └── README.md         # 项目介绍、使用说明
├── tests/                # 测试用例目录
│   ├── test_http.c       # HTTP 压测单元测试
│   └── test_websocket.c  # WebSocket 压测单元测试
├── examples/             # 示例代码目录
│   ├── example_http.sh   # HTTP 压测示例脚本
│   └── example_ws.sh     # WebSocket 压测示例脚本
├── Makefile              # 顶层Makefile，简化编译过程
└── README.md             # 项目简介和说明文档
