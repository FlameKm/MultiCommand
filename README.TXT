# MultiCommand-flamekm
多命令，可用于单片机裸机编程中,将发送的命令进入查找,从而实现对应的函数。

使用方法

//添加
MultiCommand comm;
void dst(uint8_t id, char *s) {
    std::cout << (int)id << " " << s <<std::endl;
}
int main() {
    comm.add("msg1", 1, dst);
    comm.add("msg2", 2, dst);
    comm.add("msg3", 3, dst);
    comm.add("msg4", 4, dst);

    comm.search((char*)"msg11");
    comm.search((char*)"msg22");
    comm.search((char*)"msg33");
    comm.search((char*)"msg44");
}

