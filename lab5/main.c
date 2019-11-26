#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int msgget(key_t key, int msgflg);

int main() {
    uid_t uid = getuid();
    pid_t pid =  getpid();
    gid_t gid = getgid();
    printf("%u \n", uid);
    printf("%u \n", pid);
    printf("%u \n", gid);
    return 0;
}