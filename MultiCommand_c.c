//
// Created by FlameKm on 2022/11/26.
//

#include "MultiCommand_c.h"

#include <stdlib.h>
#include <string.h>

static bool isEqual(const char *ch, char *str);
/**
 * 添加命令
 * @param sign 信号
 * @param id id代号
 * @param callback 回调
 */
static bool add(MultiCommand_t *mc, const char *sign, CommandCallback_t callback,
                uint8_t id) {
    Command_t *p = mc->command;
    char *ch = (char *) malloc(sizeof(sign));
    strcpy(ch, sign);
    //! 检查是否重复或者不符合要求,即当前的信号前部分包含sign
    for (; p != NULL; p = p->next) {
        if (isEqual(sign, (char *) p->sign)) {
            return false;
        }
    }
    Command_t *newCommand = (Command_t *) malloc(sizeof(Command_t));
    newCommand->sign = sign;
    newCommand->id = id;
    newCommand->callback = callback;
    newCommand->next = mc->command;
    mc->command = newCommand;
    return true;
}
/**
 * 查找,查找成功进入回调函数
 * @param str 待查找的命令
 * return 查找成功返回true,查找失败返回false
 */
static bool search(MultiCommand_t *mc, char *str) {
    Command_t *p = mc->command;
    for (; p != NULL; p = p->next) {
        if (isEqual(p->sign, str)) {
            p->callback(p->id, str + strlen(p->sign));
            break;
        }
    }
    return (p != NULL);
}
/**
 * 判断str2前部分是否是ch
 * @param ch
 * @param str
 * @return
 */
static bool isEqual(const char *ch, char *str) {
    char s[strlen(ch) + 1];
    strncpy(s, str, strlen(ch));
    s[strlen(ch)] = '\0';  // strncpy need add end '\0'
    return (strcmp(ch, s) == 0);
}

void multiCommandInit(MultiCommand_t *mc) {
    mc->command = NULL;
    mc->add = add;
    mc->search = search;
}