CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lcurl -lwebsockets

# 默认目标
all: http_test websocket_test

# 编译 HTTP 压测
http_test: src/http_test.c
	$(CC) $(CFLAGS) -o bin/http_test src/http_test.c $(LDFLAGS)

# 编译 WebSocket 压测
websocket_test: src/websocket_test.c
	$(CC) $(CFLAGS) -o bin/websocket_test src/websocket_test.c $(LDFLAGS)

# 清理目标
clean:
	rm -f bin/*

# 安装依赖库
install-deps:
	sudo apt-get install libcurl4-openssl-dev libwebsockets-dev
