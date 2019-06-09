// #include <stdio.h>
// #include <sys/ipc.h>
// #include <sys/msg.h>


// struct buffer {
//     long type;
//     char msg[100];
// } message;

// int main() {

//     key_t key;

//     int msgid;

//     char keyStr[100];

//       gets(keyStr);


//     key = ftok(keyStr, 65);

//     msgid = msgget(key, 0666 | IPC_CREAT);

//     msgrcv(msgid, &message, sizeof(message), 1, 0);

//     printf("Data received is: %s \n", message.msg);

//     //
//     // msgctl(msgid, IPC_RMID, NULL);


//     return 0;
// }



#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#define MSGSIZE 128 
#define PERMS 0666 
#define SERVER_MTYPE 27L 
#define CLIENT_MTYPE 43L

struct message{ 
    long mtype;
    char mtext[MSGSIZE]; 
};


int main() {
                  int qid; struct message sbuf, rbuf;
                   key_t the_key;
                  
the_key = ftok("/home/ad/SysProMaterial/Set008/src/fileA", 226);
 if ( (qid = msgget(the_key, PERMS)) < 0 ){
perror("megget");
 exit(1);
 }
printf("Accessing message queue with identifier %d \n",qid);
 sbuf.mtype = CLIENT_MTYPE;

strcpy(sbuf.mtext ,"A message from client 1");

if (msgsnd(qid, &sbuf, strlen(sbuf.mtext)+1, 0) < 0){
perror("msgsnd");
 exit(1);

}
printf("Sent message: %s\n",sbuf.mtext);



    return 0;
}