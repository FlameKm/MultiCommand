//
// Created by FlameKm on 2022/11/26.
//
#include <cstdint>

#ifndef TEST_PRJ_MULTICOMMAND_H
#define TEST_PRJ_MULTICOMMAND_H
typedef void (*CommandCallback_t)(uint8_t id, char *);

struct Command_t {
    const char *sign;
    uint8_t id;
    CommandCallback_t callback;
    Command_t *next;
};

class MultiCommand {
public:
    MultiCommand();
    void add(const char *sign, uint8_t id, CommandCallback_t callback);
    void search(char *str);
    bool isEqual(const char *ch, char *str);
private:
    Command_t *command;
};

#endif //TEST_PRJ_MULTICOMMAND_H
