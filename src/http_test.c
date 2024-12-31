#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include "utils.h"
#include "http_test.h"

void http_test(const char *url, int request_count) {
    CURL *curl;
    CURLcode res;
    long total_time = 0;

    curl_global_init(CURL_GLOBAL_ALL);

    for (int i = 0; i < request_count; i++) {
        curl = curl_easy_init();
        if (curl) {
            curl_easy_setopt(curl, CURLOPT_URL, url);

            long start_time = get_timestamp();
            res = curl_easy_perform(curl);
            long end_time = get_timestamp();

            if (res != CURLE_OK) {
                fprintf(stderr, "Request %d failed: %s\n", i + 1, curl_easy_strerror(res));
            } else {
                total_time += (end_time - start_time);
            }

            curl_easy_cleanup(curl);
        }
    }

    curl_global_cleanup();

    printf("HTTP Test Completed: %d requests, Avg Latency: %ld ms\n",
           request_count, total_time / request_count);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <url> <request_count>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *url = argv[1];
    int request_count = atoi(argv[2]);

    http_test(url, request_count);
    return EXIT_SUCCESS;
}
