#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libwebsockets.h>
#include "utils.h"
#include "websocket_test.h"

static int ws_callback(struct lws *wsi, enum lws_callback_reasons reason,
                       void *user, void *in, size_t len) {
    switch (reason) {
        case LWS_CALLBACK_CLIENT_ESTABLISHED:
            printf("Connection established\n");
            break;
        case LWS_CALLBACK_CLIENT_RECEIVE:
            printf("Received data: %s\n", (char *)in);
            break;
        case LWS_CALLBACK_CLIENT_CLOSED:
            printf("Connection closed\n");
            break;
        default:
            break;
    }
    return 0;
}

void websocket_test(const char *url, int connection_count) {
    struct lws_context_creation_info info = {0};
    struct lws_client_connect_info ccinfo = {0};
    struct lws_context *context;
    struct lws_protocols protocols[] = {
            {"ws", ws_callback, 0, 0},
            {NULL, NULL, 0, 0}
    };

    info.port = CONTEXT_PORT_NO_LISTEN;
    info.protocols = protocols;

    context = lws_create_context(&info);

    if (!context) {
        fprintf(stderr, "Failed to create context\n");
        return;
    }

    for (int i = 0; i < connection_count; i++) {
        ccinfo.context = context;
        ccinfo.address = url;
        ccinfo.path = "/";
        ccinfo.port = 80;
        ccinfo.protocol = protocols[0].name;

        if (!lws_client_connect_via_info(&ccinfo)) {
            fprintf(stderr, "Connection %d failed\n", i + 1);
        }
    }

    lws_service(context, 1000);
    lws_context_destroy(context);

    printf("WebSocket Test Completed: %d connections\n", connection_count);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <url> <connection_count>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *url = argv[1];
    int connection_count = atoi(argv[2]);

    websocket_test(url, connection_count);
    return EXIT_SUCCESS;
}
