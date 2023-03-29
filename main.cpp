#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

int main(void) {
    char line[MAX_LINE_LENGTH];
    char key[MAX_LINE_LENGTH];
    char value[MAX_LINE_LENGTH];
    FILE *fp = fopen("../config.txt", "r");  // 打开配置文件
    if (fp == NULL) {
        printf("无法打开配置文件：config.txt\n");
        return 1;
    }
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {  // 逐行读取配置文件
        if (line[0] == '#' || line[0] == '\n') {  // 跳过注释和空行
            continue;
        }
        if (sscanf(line, "%s = %s", key, value) == 2) {  // 解析配置项
            if (strcmp(key, "name") == 0) {
                printf("姓名：%s\n", value);
            } else if (strcmp(key, "age") == 0) {
                printf("年龄：%s\n", value);
            } else if (strcmp(key, "address") == 0) {
                printf("地址：%s\n", value);
            } else {
                printf("未知配置项：%s\n", key);
            }
        } else {
            printf("无法解析配置项：%s", line);
        }
    }
    fclose(fp);  // 关闭配置文件
    return 0;
}
