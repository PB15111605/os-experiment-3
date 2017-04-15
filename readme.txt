文件夹osLab中为第三次实验作业
osLab中文件层次目录如下：
osLab
-----pipe
     -----pipe.c
          pipe
     fifo
     -----fifo_client.c
          fifo_server.c
          fifo_client
          fifo_server
     msg
     -----msg_client.c
          msg_server.c
          msg_client
          meg_server

pipe编译命令：gcc /<directory>/pipe.c -o pipe
pipe执行命令：./pipe

fifo编译命令：gcc /<directory>/fifo_client.c -o fifo_client
	      gcc /<directory>/fifo_server.c -o fifo_server
fifo执行命令：./fifo_server
	      ./fifo_client <string>

msg编译命令：gcc /<directory>/msg_client.c -o msg_client
	      gcc /<directory>/msg_server.c -o msg_server
msg执行命令：./msg_server
             ./msg_client <string>
notice:执行./msg_client quit后msg_server退出
