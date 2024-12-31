CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lcurl -lwebsockets -pthread

# 默认目标
all: bin/http_test bin/websocket_test

# HTTP 压测可执行文件
bin/http_test: src/http_test.c src/utils.c include/utils.h include/http_test.h
	$(CC) $(CFLAGS) -o $@ src/http_test.c src/utils.c $(LDFLAGS)

# WebSocket 压测可执行文件
bin/websocket_test: src/websocket_test.c src/utils.c include/utils.h include/websocket_test.h
	$(CC) $(CFLAGS) -o $@ src/websocket_test.c src/utils.c $(LDFLAGS)

# 清理目标
clean:
	rm -f bin/* build/*

# 安装依赖
install-deps:
	sudo apt-get install libcurl4-openssl-dev libwebsockets-dev
