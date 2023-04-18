# MultiCommand-flamekm
多命令，可用于单片机裸机编程中,将发送的命令进入查找,从而实现对应的函数。

注册任务后通过查找字符串,如果添加过则进入注册时候的回调函数。

更方便的接收上位机的命令，从而进行对应的处理。

使用方法
C++

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

    comm.search((char*)"msg1a");
    comm.search((char*)"msg2b");
    comm.search((char*)"msg3c");
    comm.search((char*)"msg4d");
}
返回数值
1 a
2 b
3 c
4 d

C
类似C++
multiCommandInit(&comm);
comm.add(&comm,"msg1", 1, dst);
