// 
//#include <stdio.h>
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

//     gets(keyStr);
//     printf("key send is: %s \n", keyStr);

//     key = ftok(keyStr, 65);

//     msgid = msgget(key, 0666 | IPC_CREAT);
//     message.type = 1;

//     printf("Write data: ");
//     gets(message.msg);

//     msgsnd(msgid, &message, sizeof(message), 0);

//     printf("Data send is: %s \n", message.msg);


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
#define CLIENT_MTYPE 42L

struct message{ 
    long mtype;
    char mtext[MSGSIZE]; 
};

int main() {
    int qid;
    struct message sbuf , rbuf; key_t the_key;
    the_key = ftok("/home/ad/SysProMaterial/Set008/src/fileA", 226);


    if ( (qid = msgget(the_key, PERMS | IPC_CREAT)) < 0 ){ perror("megget"); exit(1);
    }

    printf("Creating message queue with identifier %d \n",qid);

    sbuf.mtype = SERVER_MTYPE;
strcpy(sbuf.mtext ,"A message from server");
if (msgsnd(qid, &sbuf, strlen(sbuf.mtext)+1, 0) < 0){
perror("msgsnd");
 exit(1);
}
printf("Sent message: %s\n",sbuf.mtext);

if ( msgrcv(qid, &rbuf, MSGSIZE, CLIENT_MTYPE, 0) < 0){ perror("msgrcv");
 exit(1);
}
printf("Received message: %s\n",rbuf.mtext);

if ( msgrcv(qid, &rbuf, MSGSIZE, 43, 0) < 0){ perror("msgrcv");
 exit(1);
}
printf("Received message: %s\n",rbuf.mtext);

// if (msgctl(qid, IPC_RMID, (struct msqid_ds *)0) < 0){ perror("msgctl");
//  exit(1);
// }
printf("Removed message queue with identifier %d\n",qid);

    return 0;
}
