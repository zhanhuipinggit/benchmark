# WebSocket 和 HTTP 压测工具

## 项目简介

本项目是一个支持 HTTP 和 WebSocket 压测的开源工具，能够根据用户输入的 URL 和请求/连接次数进行性能测试。压测结果包括 QPS（每秒请求数）和平均延迟等指标。

### 功能特点

- **HTTP 压测**：支持同步方式进行多次 HTTP 请求。
- **WebSocket 压测**：支持并发多 WebSocket 连接。
- **延迟统计**：实时计算请求或连接的平均延迟。
- **高扩展性**：清晰的代码结构便于二次开发。

---

## **目录结构**

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
```

---

## **安装与依赖**

### **安装依赖**

项目依赖以下第三方库：

- **libcurl**：用于处理 HTTP 请求。
- **libwebsockets**：用于处理 WebSocket 连接。

#### 在 Ubuntu 上安装

```bash
sudo apt-get install libcurl4-openssl-dev libwebsockets-dev
```

#### 在 macOS 上安装

使用 Homebrew 包管理工具：

```bash
brew install curl libwebsockets
```

#### 在 Windows 上安装

1. 使用 vcpkg 包管理工具安装依赖：

   ```bash
   vcpkg install curl libwebsockets
   ```

2. 确保 vcpkg 的安装路径已添加到系统环境变量中。

---

## **编译说明**

项目提供了 Makefile 用于简化编译流程，以下为编译指引：

1. 进入项目目录：
   ```bash
   cd websocket_http_stress_test
   ```

2. 编译所有模块：
   ```bash
   make
   ```

3. 编译完成后，可执行文件将生成在 `bin/` 目录下。

4. 清理生成的文件：
   ```bash
   make clean
   ```

---

## **使用说明**

### **1. HTTP 压测**

执行 HTTP 压测的命令格式如下：

```bash
./bin/http_test <URL> <REQUEST_COUNT>
```

- **URL**: 目标服务器的地址，例如 `http://localhost:8080`。
- **REQUEST_COUNT**: 要发送的 HTTP 请求次数。

#### 示例：

```bash
./bin/http_test http://localhost:8080 1000
```

**输出示例：**

```plaintext
HTTP Test Completed: 1000 requests, Avg Latency: 50 ms
```

---

### **2. WebSocket 压测**

执行 WebSocket 压测的命令格式如下：

```bash
./bin/websocket_test <URL> <CONNECTION_COUNT>
```

- **URL**: 目标 WebSocket 服务器的地址，例如 `ws://localhost:8080`。
- **CONNECTION_COUNT**: 要建立的 WebSocket 连接数量。

#### 示例：

```bash
./bin/websocket_test ws://localhost:8080 500
```

**输出示例：**

```plaintext
WebSocket Test Completed: 500 connections
```

---

## **示例脚本**

项目提供了一些脚本示例，存放在 `examples/` 目录下。

### **1. HTTP 压测脚本**

文件路径：`examples/example_http.sh`

```bash
#!/bin/bash
./bin/http_test http://localhost:8080 100
```

### **2. WebSocket 压测脚本**

文件路径：`examples/example_ws.sh`

```bash
#!/bin/bash
./bin/websocket_test ws://localhost:8080 100
```

执行脚本：

```bash
bash examples/example_http.sh
bash examples/example_ws.sh
```

---

## **测试**

测试代码存放在 `tests/` 目录中，执行以下步骤运行单元测试：

1. 编译测试代码：
   ```bash
   gcc -o tests/test_http tests/test_http.c -Iinclude -lcurl
   gcc -o tests/test_websocket tests/test_websocket.c -Iinclude -lwebsockets
   ```

2. 运行测试：

    - HTTP 压测测试：
      ```bash
      ./tests/test_http
      ```

    - WebSocket 压测测试：
      ```bash
      ./tests/test_websocket
      ```

---

## **结果分析**

- **QPS（每秒请求数）**：测试运行完成后，根据日志信息可以计算出总请求数和总耗时，从而得出 QPS。
- **延迟统计**：程序会输出每次请求或连接的平均延迟时间（单位：毫秒）。

---

## **贡献指南**

欢迎贡献代码和提出建议！您可以通过以下方式参与：

1. 提交 Issue 反馈 Bug 或需求。
2. Fork 本项目并提交 Pull Request。
3. 编写更详细的文档或优化代码。

---

## **License**

MIT License

