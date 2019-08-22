# 序章：Linux操作系统
+ 是Unix衍生版
### 1、Linux版本
+ Redhat系列 
	+ RHEL 收费 
	+ CentOS （RHEL社区克隆版）免费
+ Debian系列
	+ Debian
	+ Ubuntu
### 2、Ubuntu
+ 主版本号（年份）双数年：长期稳定版，单数年：短期支持版
+ 副版本号（月份）4月：年度稳定版，10月：年度测试版
+ 总之就是选双数年10月份之前的版本

# 第一章：文件和磁盘
### 1、命令解析器
+ 作用：解析命令并调用响应的程序
+ shall
### 2、快捷键和常用命令
+ date 日期
+ history 显示用户之前敲过得命令
	+ ctrl+p 向上滚动命令
	+ ctrl+n 向下滚动命令
	+ ctrl+b 光标向前移动
	+ ctrl+f 光标向后移动
	+ ctrl+a 光标移动到行首
	+ ctrl+e 光标移动到行尾
	+ backspace 或 ctrl+h 删除光标前面的字符
	+ delete 或 ctrl+d 删除光标后面的字符
	+ ctrl+u 删除光标前面的所有字符
+ tab 智能补全命令
+ cd 进入目录
+ clear 或 ctrl+l 清屏
### 3、Linux目录结构
+ 树结构
+ 根目录 /
+ 家目录 ~
+ 当前用户名@主机名
+ $ 普通用户
+ "#" 管理员用户
+ sudo su 进入管理员用户
+ exit 退出管理员用户
+ /bin 存放常用的命令的可执行程序
+ /boot 核心文件
+ /dev 设备文件
+ /etc 配置文件
+ /home 所有普通用户的目录
+ /lib 动态连接库
+ /lost+found 系统非正常关机产生的文件碎片
+ /media 自动挂载目录
+ /mnt 手动挂载目录
+ /opt 存放第三方软件
+ /proc 内存映射
+ /root 管理员目录
+ /sbin 管理员命令
+ /user 用户应用程序和文件
+ 绝对路径 从 / 开始
+ 相对路径 相对于当前的工作目录
	+ . 当前目录
	+ .. 当前的上一级目录
	+ - 切换临近的两个目录
+ pwd  查看当前目录路径
### 4、文件和目录的操作
+ 查看目录
	+ tree 插件
+ 颜色
	+ 白色 普通文件
	+ 蓝色 目录
	+ 绿色 可执行文件
	+ 红色 压缩包
	+ 青色 链接文件   
	+ 黄色 设备文件
	+ 灰色 其他文件
+ ls 查看目录下的内容 
	+ ls -a 查看当前目录下的全部内容
		+ 名字第一个字符是.的表示这个是隐藏文件（目录）
	+ ls -l 显色详细信息
		+ 1 文件类型
			+ . 普通文件
			+ d 目录
			+ l 链接符号
			+ b 块设备
			+ c 字符设备
			+ s socket文件
			+ p 管道
		+ rwx-- 权限
			+ r 可读
			+ w 可写
			+ x 可执行
			+ - 无权限
			+ 用户 从左到右依次为 所有者 同组用户 其他人
		+ 2 文件的硬连接计数
		+ itcast 该文件的所有者
		+ itcast 文件所属的组
		+ 4096 文件所占用的磁盘空间 目录的所占的空间为4096 （不包括目录下文件的大小）
		+ 月 日 年 文件最后创建或修改的时间、
		+ name 文件名
			+ capy 软连接
+ mkdir 创建目录 
	+ mkdir -p dir/dir1/dir2 创建嵌套目录
+ rm 永久删除文件
	+ rm aa.cpp
	+ rm -r bb  删除目录，-r表示递归删除
	+ rm -ri bb 递归确认删除
+ touch 创建文件 touch aa 
	+ 如果文件存在，更新文件的修改时间
+ cp 拷贝文件或目录
	+ cp hello.c aa 复制helloc.c 覆盖到aa文件
		+ aa若不存在 则新建一个aa到当前目录
	+ cp dir1/ dir2 -r 如果dir2不存在，拷贝dir1目录里的所有文件到dir2中
	+ 如果dir2存在 怎把dir1以及dir1下的所有文件 拷贝到dir2里面
+ cat 查看文件 cat aa 只能显示一部分
+ more 回车翻一行 空格翻一页 不能往前看 退出 ctrl+c或q
+ less 可以往前和向后翻页   
+ head 查看前10行 head -5 aa 查看前5行的内容
+ tail 查看后10行 tail -5 aa 查看后5行的内容
+ mv 
	+ 重命名 mv oldname newname
	+ 移动文件 mv aa dir
### 5、链接
+ ln -s 创建软链接（相当于windows创建快捷方式）
	+ ln -s hello.c hello.soft 相对路径写法
		+ hello.soft移动到其他目录后不可用
	+ ln -s ~/dir/hello.c hello.soft 绝对路径写法
		+ hello.soft移动到其他目录后可用
	+ ln -s ~/dir/ dir.soft 给目录创建软链接 
+ ln 创建硬链接（相当于c++的引用）创建之后不会消耗磁盘空间，硬链接计数会显示该文件的硬链接数
	+ ln hello.c hello.soft
	+ 目录不可以创建硬链接，只有文件可以 
	+ 硬链接直接映射磁盘上的文件，所以不需要写绝对路径
### 6、文件和目录属性 
+ wc 获取文本文件的信息 
	+ wc hello.c 
	+ 输出： 7 19 83 hello.c
	+ [行数] 【单词个数】 【字节数】 【文件名】
+ od 查看二进制文件
	+ od -t 指定显示格式 
	+ od -tx 十六进制
	+ od -tc ASCII
	+ f 八进制  o 十六进制 d 有符号十进制 u无符号十进制
+ du 查看当前目录的大小
	+ du -h 以人类能看懂的方式做展示
+ df 磁盘使用情况  
	+ df -h 以人类能看懂的方式做展示
+ which 查找命令所在的目录
	+ which ls
### 7、文件权限 
+ 修改文件的权限
+ 文字设定法 chmod [who] [+|-|=] [mode] filename
		+ chmod o+w  aa
	+ who :
		+ 文件所有者： u
		+ 文件所属组： g
		+ 其他人	   ： f	
		+ 所有的人  ：a(默认)
	+ 增加权限     ： +
	+ 减少权限     ： -
	+ 覆盖原来的权限： =
	+ mode：
		+ r w x
+ 数字设定法 chmod xxx filename
	+ chmod 777 aa 修改权限
	+ chmod -001 aa 减少权限
	+ 每个用户的权限为3位二进制 0：无 1：有
### 8、文件的用户 用户组
+ 改变所有者 chown newowner filename
	+ chown zhangsan aa.c
+ 改变所有者和其所属的组 chown newowner：group filename 
+ 改变组 chgrp groupname fliename  
### 9、文件的查找和检索
+ 查找文件
+ 文件名  find 路径 -name “文件名”
	+ find /home/itcast -name "hello.c"
	+ 通配符 ?一个  *多个
+ 文件大小 
  	+ find ~ -size -10k 小于10k的
  	+ find ~ -size +10M 大于10M的
  	+ find ~ -size +10k -size -100M 10k ~ 100M 
+ 文件类型 find 路径 -type 类型
	+ f：普通文件	 剩下和标准文件类型相同
+ 按文件内容查找 grep -r “内容” 路径
	+ grep -r "#include <stdio.h>" ~ 
### 10、文件下载和卸载
+ apt-get 在线安装
	+ sudo apt-get install name 安装  
	+ sudo apt-get remove name 卸载
	+ sudo apt-get update 更新软件列表
	+ sudo apt-get clean 清理所有软件安装包
+ dpkg 安装包安装
	+ sudo dpkg -i xxx.deb 安装
	+ sudo dpkg -r xxx 卸载
+ aptitude 安装
+ 源码安装
	+ 解压
	+ cd dir
	+ ./configure
	+ make
	+ sudo make install
### 11、磁盘管理
+ fdisk -l 查看磁盘的名字
+ mount /dev/sdb1 /mnt 挂载u盘
+ umount /mnt 卸载u盘（注意不能工作在卸载目录中执行该命令，否则执行无效）
+ 磁盘的扩展分区是从sda5开始的
+ 挂载一定要挂载到 /mnt 目录，因为挂载会暂时覆盖该目录中的文件
# 第二章：压缩包管理
### 1、tar
+ 参数 
	+ c 创建 压缩时用
	+ x 释放 解压时用
	+ v 显示提示信息
	+ f 指定压缩文件的名字
	+ 
	+ z 使用gzip方式压缩
	+ j 使用bzip2的方式压缩
		+ 不使用z或j参数只能打包 不能压缩
+ 压缩 
	+ tar zcvf xxx.tar.gz 要压缩的文件目录
	+ tar jcvf xxx.tar.bz2 要压缩的文件目录
	+ 例:
		+ tar zcvf alltxt.tar.gz *.txt
		+ 压缩目录： tar jcvf ani.tar.bz2 anmal/ 
		+ 压缩多个内容： tar jcvf ani.tar.bz2 anmal/ *.txt 
+ 解压
	+ 解压到当前目录： tar zxvf xxx.tar.gz 
	+ 解压到当前目录： tar jxvf xxx.tar.bz2 
	+ 解压到指定目录： tar zxvf xxx.tar.gz -C 解压到的目录
### 2、rar
+ 压缩 rar a temp.rar 压缩文件或目录
+ 解压 rar x 压缩文件名 （解压目录）
### 3、zip
+ 压缩 zip 压缩的名字 压缩的文件或目录
	+ 压缩目录要加 -r
+ 解压 
	+ unzip 压缩包的名字 
	+ unzip 压缩包的名字 -d 解压目录
# 第三章：进程管理
+ 终端：TTY  
	+ tty7 图形终端 tty1~6 文字终端 pts 设备终端
	+ ？：无终端
+ 查看进程：ps 
	+ 参数 
		+ a 
		+ u 查看详细信息
		+ x 包括无终端进程
+ 管道：|
+ ps aux | grep bash
	+  管道的作用就是将|前面的输出作为|后面的输入
	+  注：使用管道后，最后一条进程是当前的查询进程
+ 杀死进程：kill 
	+ -l 查看信号
	+ 杀死进程：-信号 （例如-SIGKILL或id 比如9 ）进程id  
+ 查看当前进程的环境变量：env 
	+ 只着和XXX有关的环境变量，比如 PATH：env | grep PATH 
	+ Linux的环境变量格式：key-value 
		+ key=value：value：value 
+ 查看任务管理器：top
	+ top不能对进程进行管理 
# 第四章：网络管理
### 1、常用命令
+ 查看网络配置信息 ifconfig
	+ 第一个eth0或者enp0s3 表示网卡
	+ 第二个lo表示回环
+ ping 会一直发包
	+ 可以指定包的数量 例如发四个包 ping 192.168.40.2 -c 4
	+ ping 域名
+ nslookup 访问DNS服务器查找域名对应的ip地址
### 2、ftp服务器
+ vsftpd
+ 修改/etc/vsftpd.conf
+ 重启服务器 sudo service vsftpd restart
+ 实名登录 ftp ip 用户名 密码
	+ 根目录就是服务器用户的家目录
	+ 登录用户可以访问所有目录
	+ 登录用户视为该计算机的用户，拥有其权限
+ 匿名登录 ftp ip anonymous 密码：直接回车
	+ 默认根目录 /srv/ftp/
	+ 可以有服务器指定其根目录，注意根目录的权限不可以设置为777
	+ 在/etc/vsftpd.conf 下 添加根目录 anon_root=/home/itcast/cnonftp/
	+ 登录用户只能访问指定的根目录
	+ 登录用户的权限视为“其他用户”
+ 上传 put xxx
+ 下载 get xxx
+ lftp 更加强大的第三方ftp客户端
	+ 登录 ftp ip 
		+ login 匿名
	+ lpwd 和 lcd 可以切换本机的工作目录
	+ mget 下载多问价
	+ mirror 下载整个目录
	+ mirror -R 上传整个目录
### 3、nfs共享服务器
+ nfs-kernel-server
+ 在/etc/exports里面添加共享文件夹 /home/itcast/NfsShare *(ro,sync)
	+ *表示ip地址，可以写成像192.168.12.*来决定在哪个网段共享
	+ 括号里的是权限 ro（只读） wo（只写）rw，sync（实时更新磁盘）  
+ 客户端访问（已挂载的方式 一般是挂载到/mnt）
	+ mount 服务器ip:服务器的共享路径 挂载目录
### 4、ssh远程操控服务器
+ openssh-server
+ 登录方式 ssh 用户名@ip
+ 注意一定要写yes而不是y
+ 退出 logout
+ scp 超级拷贝 scp -r 目标用户名@ip：需要拷贝的绝对路径 拷贝到本地的绝对路径
# 第五章：用户管理
+ 查看当前用户 who
+ 可以去 /etc/passwd 里面查看用户
### 1、 adduser 创建用户
+ 创建用户：adduser+用户名
+ 实质上是个脚本
+ sudo adduser xiaoming 
+ 登录用户： su + 用户名
+ 不能创建含有大写字母的用户名
+ 会要求输入密码
### 2、useradd 创建用户
+ 参数 
	+ -s 使用什么命令解析器 -s /bin/bash
	+ -g 用户所属的组 -g xxx组
	+ -d 用户的目录 -d /home/XiaoMing
	+ -m 创建home/的用户名目录 -m XiaoMing
+ 不同于adduser，useradd是命令
+ 可以创建大写字母的用户名 
+ 不会要求输入密码
### 3、groupadd 创建用户组
+ groupadd XXX组
### 4、passwd 修改密码
+ passwd xiaoming
+ passwd 修改当前用户密码
+ sudo passwd 修改root密码
### 5、deluser 删除用户
+ deluser xiaoming
### 6、userdel -r 删除用户
+ userdel -r xiaoming 
+ 会删除对应的目录

# 第六章：vim
+ vim从vi发展而来
### 1、vim的三种模式 命令 编辑 末行
+ 光标移动 
	+ h j k l 前 下 上 后 
	+ 行首 0 行尾 $
	+ 文件开始 gg
	+ 文件结尾 G
	+ 跳转 数字+G 到第几行
	+ 数字+j或k 下或上移动几行
+ 删除 （删除的本质是剪切）
	+ x删除光标后面
	+ X删除光标前面
	+ dw 删除单词 光标必须在单词的第一个字符
	+ d0 删除到行首 d$ 删除到行尾同D
	+ dd 删除当前行 数字+dd 删除多行
+ 撤销 u
	+ 反撤销 ctrl+r
+ p粘贴（光标下一行）P光标所在行
+ [数字] yy [多行]复制
+ 可视模式 v
	+ 可视模式下p不会换行，会直接粘贴到光标所在位置的后面
	+ P 会粘贴到前面
+ 查找
	+ /查找的内容 （n切换 N网上查找）
	+ ?查找的内容
	+ #标记一个单词 并查找
+ 缩进 >> <<
+ 切换文本模式
	+ a 光标后插入
	+ A 当前行尾
	+ i 光标前插入
	+ I 当前行首
	+ o 下面开辟新的行
	+ O 上面开辟新的行
	+ s 删除光标后面的字符
	+ S 删除当前行
+ 末行模式 ：
	+ 跳转 输入数字
	+ 字符串替换
		+  s/原字符串/替换字符串/ 当前行第一个
		+ s/原字符串/替换字符串/g 替换当前行所有的
		+ %s/原字符串/替换字符串/ 替换文件中所有的每一行的第一个
		+ %s/原字符串/替换字符串/g 替换所有
		+ x1，x2s/原字符串/替换字符串/g 替换x1 到 x2的
	+ ！+命令 可以执行命令
	+ w 保存
	+ q 退出
	+ q！退出不保存
	+ 分屏
		+ 水平分屏 sp 
			+ ctrl + ww 切换
			+ wqall 全关 不加all只关一个
		+ vsp 垂直分屏
+ zz保存退出
### 2、vim配置文件
+ 系统级 /etc/vim/vimrc
+ 用户级 ~/.vim/vimrc
# 第七章：Linux下的c编程环境
### 1、gcc
+ gcc *.c -o test
+ 编译过程 
	+ 预处理 -E c文件 .i
	+ 编译 -S 汇编文件 .s
	+ 汇编 -C 二进制文件 .o
	+ 链接 无参数 可执行文件 .out
+ 参数
	+ -o 文件名 输出的文件(不写会默认创建一个a.out)
	+ -I 指定头文件的路径
	+ -D 指定宏 视为#define了一个宏
	+ -O0~3 优化等级	
	+ -Wall 输出警告
	+ -g 添加调试信息 （可用gdb调试）
### 2、静态库
+ 命名规则 lib文件名.a 如libmytest.a
+ 制作静态库 
	+ 先将.c文件编译成.o文件 gcc *.c -c
	+ 将.o文件打包成静态库 ar rcs libMyTest.a *.o
	+ 移动到lib目录 mv ../lib
+ nm 查看.a 文件
+ 使用静态库文件（需要include和lib）
	+  gcc main.c lib/libMyTest.a -I include/ -o myapp
		+  直接添加静态库的目录即可
	+  gcc main.c -L lib -l MyCalc -I include/ -o myapp
		+  -L 指定库的目录 
		+  -l 指定库的名字 注意名字掐头去尾
+ 静态库在编译成可执行文件时，只编译用到的.o文件
+ 静态库的优点
	+ 发布程序的时候，不需要提供对应的库（因为库被打包到了可执行文件中）
	+ 库的加载速度很快
+ 静态库的缺点
	+ 库的体积很大
	+ 库发生改变，需要重新编译程序  
### 3、共享库(动态库)
+ 命名规则 lib文件名.so 如libMyTest.so
+ 制作共享库
	+ 生成与位置无关的.o gcc -fPIC -c *.c -I ../include 
		+ 所谓与位置无关：linux创建进程会分配0~4G虚拟地址，与位置有关的（静态库）会在代码段固定位置添加代码，与位置无关会在栈和堆之间不确定位置放置一个共享库段，往这里面放共享库的标记
	+  打包成共享库 gcc -shared -o libMyTest.so -I ../include *.0
+ 使用共享库 
	+ gcc main.c lib/libMyTest.so -I include/ -o myapp
	+ gcc main.c -L lib -l MyTest -I include/ -o myapp 
		+ 执行会出现找不到库的问题
		+ ldd myapp 可以查看可执行程序所依赖的共享库
		+ export LD\_LIBRARY\_PATH=./lib 将lib的路径导入到环境变量里去，但是此方法在关机后就会消失
		+ 在动态链接库的配置文件/etc/ld.so.conf 中添加动态库的绝对路径
			+ 更新 sudo ldconfig -v
+ 动态库的优点
	+ 可执行程序体积小
	+ 动态库更新（函数接口不变）不需要重新编译程序
+ 动态库的缺点
	+ 发布需要提供动态库
	+ 加载库的速度相对较慢 
### 4、gdb  
+ gcc -g 添加调试信息
+ gdb 可执行文件 开始调试
+ set args + 参数 可以指定命令行参数
+ l 查看源代码
	+  l Test.c:20 查看Test.c文件的第20行
	+  l + 函数名 查看函数
	+  l Test.c:main 查看函数
	+  回车 l默认展示10行 摁回车可以继续往下展示
+ break或者b下断点、
	+ break 17 在第17行设置断点
	+ break 17  if i==0 加条件 当i==0时才会停
+ info或i 可以查看  i b查看断点 
+ start 开始调试
	+ n 单步调试
	+ c 执行到断点处
	+ s 进入到函数体内部
	+ p 查看变量的值 p i
		+ ptype 查看变量类型
	+ display 追踪变量
		+ undisplay + 编号 可以取消最终
			+ 查看编号 info display
	+ u跳出单次循环  
	+ finish 跳出当前函数（如果在循环里有未执行完的断点，无法跳出）
	+ delete或d删除断点 d 4
	+ set var i=10 将i的值设置为10
+ r 直接运行 
+ quit 退出 
### 5、makefile
+ 命名 makefile 或 Makefile
+ 规则
	+ 三要素：目标，依赖，命令
	+ 目标：依赖条件 
	+ 第一种：
	+ myapp:main.c a.c
		+ 命令 gcc *.c -o myapp
	 	+ 缺点 每次修改都要重新编译，浪费时间
	+ 第二种： 
	+ myapp:main.o a.o
		+ gcc *.o -o myapp
	+ main.o:main.c
		+ gcc -c main.c
	+ a.o:a.c
		+ gcc -c a.c
		+ 优点 ：只编译修改的.c文件，不需要把所有的都编译
+ makefile的工作原理
	+ 依赖是目标的准备工作
	+ 第一行是终极目标 后面的是次级目标
	+ 目标的修改时间一定是比依赖的时间更近，所以如果目标的时间比依赖的更晚，说明依赖是修改过的，所以根据时间可以确定哪些该执行哪些不用执行
+ makefile中的变量
	+ obj=main.o a.o
	+ target=app
	+ $(target):$(obj)
		+ gcc $(obj) -o $(target)
+ makefile系统维护变量（大写）
	+ CPPFLAGS ：预处理需要的选项 如 -I
	+ CFLAGS：编译的时候用的参数 -Wall -g -c
	+ LDFLAGS：链接库使用的选项 -L -l 
+ makefile中的模式规则
	+ %.o:%.c
		+ gcc -c $< -o $@
		+ % 匹配上一级规则中的依赖
		+ < 和 @ 是makefile中的自动变量
		+ $< :规则中的第一个依赖
		+ $@ :规则中的目标
		+ $^ :规则中的所有依赖
		+ 只能在命令中使用   
+ makefile中的函数
	+ 都要有返回值 使用$获得返回值
	+ src=(wildcard main.c src/*.c)
		+ 函数名：wildcard 参数 mian.c src/*.c 功能是提取参数中的文件并返回给src
 	+ obj=$(patsunst %.c, %.o, $(src)) 
	 	+ 将src中的.c 文件编译成 .o文件并返回
+ 指定目标
	+ clean：
		+  rm $(obj) $(app) 
	+ make clean 指定该目标，并且执行时不会执行其他目标
+ 命令前加-表示：如果该命令执行失败，则忽略并继续向下执行
# 第九章：Linux下c文件操作
### 1、FILE结构体
+ FILE * 文件指针
+ FILE包含：
+ 文件描述符
+ 文件读写指针
+ I/O缓冲区（内存地址）
	+  默认大小8kb
	+  将缓冲区写入磁盘的情况： 
		+  调用fflush
		+  缓冲区已满
		+  正常关闭问价 fclose， return(main函数)， exit（main函数）
### 2、32位操作系统的虚拟地址空间
+ 每当运行一个进程，就会开辟0~4G的虚拟地址空间，其中0~3G为用户地址空间，3~4G为系统内核区
+ 内核区有一个PCB（进程控制块，是一个结构体），在PCB中有一个文件描述表（是一个数组，下标为0~1023）没一个位置防止文件描述符（宏定义），每打开一个文件，会将该文件的文件描述符存到第一个空闲位置
	+ 其中前三个系统会默认打开，分别是
		+ STDIN_FILENO 标准输入
		+ STDOUT_FILENO 标准输出
		+ STDERR_FILENO 标准错误
+ file 查看文件类型
+ 用户区从高到低分别是
	+ 环境变量
	+ 命令行参数 int argc, char*argv[]
	+ 栈 向下增长
	+ 共享库
	+ 堆 向上增长
	+ .bss 初始化为0的全局变量
	+ .data 初始化不为0的全局变量
	+ .text代码段，c语句编译成的二进制指令
	+ 受保护地址 0~4k 不可读写，如NULL
	+ 参考资料：https://www.cnblogs.com/clover-toeic/p/3754433.html 
+ 虚拟地址的作用，为什么不直接使用物理地址?
	+ 可用物理地址是分散的，虚拟地址可以映射多个不连续的物理地址，从而合理的利用内存
	+ 方便进程之间的隔离
### 3、c系统函数(系统IO)
+ 应用层函数调用系统函数，系统函数调用内核函数
+ open() 打开文件 返回文件描述符
+ 创建文件时的权限值=给定的权限值&~本地掩码
	+ 查看本地掩码 umask
	+ 设置本地掩码 umask 0002
+ close() 关闭文件 返回值 0：关闭成功
+ read() 读文件 返回值：
	+ -1 读文件失败
	+ 0 文件读完了
	+ >0 读取的字节数 
+ write() 写文件
+ lseek() 文件指针的移动 
	+ off_t lseek(int handle, off_t offset, int fromwhere)
		+  handle 文件描述符
		+  offset 相对于fromwhere的偏移量，整数向前，负数向后，0就是fromwhere的位置
		+  fromwhere 一般用下面三个
			+ SEEK_SET 将读写位置指向文件头后再增加offset个位移量。
			+ SEEK_CUR 以目前的读写位置往后增加offset个位移量。
			+ SEEK_END 将读写位置指向文件尾后再增加offset个位移量
	+ 返回值返回区里文件头多少个字节 
	+ 获取文件大小
		+ lseek(fd, 0, SEEK_END)
	+ 获得文件指针当前位置
		+ lseek(fd, 0, SEEK_CUR)
	+ 文件拓展
		+ 只等向后拓展
		+ lseek(fd, 2000, SEEK_END) //拓展2000字节
		+ 必须进行一次写操作才能完成拓展
		+ write(fd, "a", 1);
		+ 空洞文件 lseek扩展的部分是空洞
+ stat() 查看文件的属性 追踪 查看软链接的源文件
	+ lstat 不追踪 如果是软链接 只查看软链接的文件
	+ 比如rm就是不追踪的 vim 就是追踪的
	+ 需要一个struct stat 保存文件的信息,传入 *
+ access() 查询文件的读写权限 
+ chmod() 修改文件的权限
+ chown() 修改文件的所有者
+ trubcate() 文件拓展/截断
+ link() 创建一个硬链接
+ symlink() 创建一个软连接
+ readlink() 读取软连接对应的文件名
+ unlink() 删除链接
	+ 删除软连接
	+ 减少硬链接计数，如果硬链接为0，释放数据块和inode
	+ 如果硬链接数为0，且该文件被一个进程打卡，会在进程关闭该文件时删除，改特性可用于创建临时文件
+ rename() 文件重命名 
### 4、目录操作函数
+  chdir() 改变当期进程的路径
+  getpwd() 获取当前进程的目录
+  mkdir() 创建目录，一定要有执行权限
+  opendir() 打开目录 
	+  返回DIR *
+  readdir() 读取目录
	+  返回struct dirent *
		+  dirent保存的目录的信息
+  closedir() 关闭目录
+  dup() 拷贝文件描述符，会拷贝文件描述符表的第一个空闲位置
	+  dup2() 拷贝到指定的文件描述，如果该位置已经存在文件描述符，则将释放该文件描述符再覆盖
		+  多个文件描述符指向同一个文件，且文件指针只有一个
+ fcntl()改变已经打开文件的权限，且会立即生效
	+  获取/设置文件状态标记 有可 写 修改为 追加写
	+  设置阻塞或非阻塞
