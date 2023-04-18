//
// Created by FlameKm on 2022/11/26.
//
#include <stdint.h>
#include <stdbool.h>
#ifndef TEST_PRJ_MULTICOMMAND_H
#define TEST_PRJ_MULTICOMMAND_H
typedef void (*CommandCallback_t)(uint8_t id, char *);
#ifdef __cplusplus
extern "C" {
#endif

typedef struct Command {
    const char *sign;
    uint8_t id;
    CommandCallback_t callback;
    struct Command *next;
} Command_t;

typedef struct MultiCommand {
    Command_t *command;
    bool (*add)(struct MultiCommand *mc,const char *sign, CommandCallback_t callback, uint8_t id);
    bool (*search)(struct MultiCommand *mc,char *str);
} MultiCommand_t;

void multiCommandInit(MultiCommand_t *mc);

#ifdef __cplusplus
}
#endif
#endif  // TEST_PRJ_MULTICOMMAND_H
