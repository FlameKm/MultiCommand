//
// Created by FlameKm on 2022/11/26.
//

#include "MultiCommand.h"
#include <cstring>

MultiCommand::MultiCommand() {
    command = nullptr;
}
/**
 * 添加命令
 * @param sign 信号
 * @param id id代号
 * @param callback 回调
 */
void MultiCommand::add(const char *sign, uint8_t id, CommandCallback_t callback) {
    auto *newCommand = new Command_t();
    newCommand->sign = sign;
    newCommand->id = id;
    newCommand->callback = callback;
    newCommand->next = command;
    command = newCommand;
}
/**
 * 查找,查找成功进入回调函数
 * @param str 待查找的命令
 */
void MultiCommand::search(char *str) {
    Command_t *p = command;
    for (; p != nullptr; p = p->next) {
        if (isEqual(p->sign, str)) {
            p->callback(p->id, str + strlen(p->sign));
            break;
        }
    }
}
/**
 * 判断str2前部分是否是ch
 * @param ch
 * @param str
 * @return
 */
bool MultiCommand::isEqual(const char *ch, char *str) {
    char s[strlen(ch) + 1];
    strncpy(s, str, strlen(ch));
    s[strlen(ch)] = '\0';  // strncpy need add end '\0'
    return (strcmp(ch, s) == 0);
}
