 /*
1)主要函数
void list_dir(char *pathname, int param);
void display_DIR(DIR *ret_opendir, int filecolor);
void ls_err(const char *err_string, int line);
void display_attribute(struct stat buf, char *name, int filecolor)
void display_single(char *name, int filecolor)
void display_st_ino(struct stat buf, char *name, int filecolor)
void display(int flag, char *pathname)
void display_dir(int flag_param, char *path)
void display_R(int flag_param, char *path)
void list_dir(char *pathname, int param)
void display_DIR(DIR *ret_opendir, int filecolor)
 
2）函数流程
  （1）获取该目录下文件的总数和最长文件名
  （2）若获取该目录下所有文件的文件名，存放于变量filenames中
  （3）使用冒泡法对文件名按字母顺序存储于filenames中
  （4）调用display()函数来显示每个文件的信息
3)程序中主要的结构体：
参数struct stat *buf 是一个保存文件状态信息的结构体
A>  struct stat{
      dev st_ dev;//文件设备号
      ino_t st_ino;//文件的i-node
      mode_t st_mode;//文件类型和存储权限
      nlink_t st_nlike;//连接到该文件的硬连接数目
      uid_t st_uid;//文件所有者的用户id
      git_t st_gid;//文件所有者的组id
      dev_t st_rdev;//若此文件为设备文件，则为其设备编号
      off_t st_size;//文件大小
      blksize_t st_blksize;//文件系统的I/O缓冲区大小
      blkcnt_t st_blocks;//占用文件区块的个数
      time_t st_atime;//文件最近一次被访问的时间
      time_t st_ctime;//文件最近一次被更改的时间
  }
  对于st_mode包含的文件类型信息，POSIX标准定义了一系列的宏：
  S_ISLNK(st_mode)//判断是否为符号链接
  S_ISREG(st_mode)//判断是否为一般文件
  S_ISDIR(st_mode)//判断是否为目录文件
  S_ISCHR(st_mode)//判断是否为字符设备文件
  S_IBLK(st_mode)//判断是否为块设备文件
  S_ISFIFO(st_mode)//判断是否为先进先出FIFO
  S_ISFOCK(st_mode)//判断是否为socket
B>:struct passwd *psd;//从该结构体中获取文件所有者的用户名
c>:struct group *grp;//从该结构体重获取文件所有者所属组的组名
命令的大概解析
-a :显示目录下的所有文件，包括以‘.’字符开始的隐藏文件
-l ：使用长格式列出文件及目录信息
-r :以文件名反序排列并输出目录内容列表
-R :递归处理，将制定目录下的所有文件以及子目录都处理
-i :显示文件的节点号
-s :显示文件和目录的大小，以区快为单位
-t :显示用文件和目录的更改时间(因为都需要排序，所以把 R r t放在一起实现)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <linux/limits.h>
#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include <errno.h>
#include <signal.h>

//命令行参数(用二进制进行设计，就会对后面组合改写比较方便)
#define PARAM_NONE 0
#define PARAM_A 1    //a
#define PARAM_L 2    //l
#define PARAM_I 4    //i
#define PARAM_r 8    //r
#define PARAM_T 16   //t
#define PARAM_R 32   //R
#define PARAM_S 64   //s
#define MAXROWLEN 80 // 一行显示的最多的字符数

void list_dir(char *pathname, int param);
void display_DIR(DIR *ret_opendir, int filecolor);
void ls_err(const char *err_string, int line);
void display_attribute(struct stat buf, char *name, int filecolor);
void display_single(char *name, int filecolor);
void display_st_ino(struct stat buf, char *name, int filecolor);
void display(int flag, char *pathname);
void display_dir(int flag_param, char *path);
void display_R(int flag_param, char *path);
void list_dir(char *pathname, int param);
void display_DIR(DIR *ret_opendir, int filecolor);
 

int main(int argc, char *argv[])
{
    signal(SIGINT, SIG_IGN); // 解决ctrl +c 终止进程
    int i, j, k, num;
    char path[PATH_MAX + 1]; //文件路径名
    char param[32];          //保存命令行参数，目标文件名和目录名不在此列
    int flag_param = PARAM_NONE;
    struct stat buf;
    j = 0;
    num = 0;
    
/* 
首先对命令行参数进行解析，获得命令行参数中的‘-’后面的内容{ls -l-a,ls -la}
用两层循环类来解析参数，
外层循环对argv[]数组中的元素一次进行内层循环的解析，
内层循环对以‘-’为首的字符串进行选项提取，
把每个选项存放于parameter[]数组里面，用num记录‘-’的数量，
命令行参数中的总选项数目用j计数
*/
    for (i = 1; i < argc; i++)
    {
        if (argv[i][0] == '-')
        {
            for (k = 1; k < strlen(argv[i]); j++, k++)
            {
                param[j] = argv[i][k]; //获取-后面的参数保存到数组parameter中
            }
            num++; //保存‘-’的个数
        }
    }

    //用或运算记录参数，最后为选项数组的末尾元素赋‘/0’
    
    for (i = 0; i < j; i++)
    {
        if (param[i] == 'a')
        {
            flag_param |= PARAM_A;
        }

        else if (param[i] == 'l')
        {
            flag_param |= PARAM_L;
        }

        else if (param[i] == 'R')
        {
            flag_param |= PARAM_R;
        }

        else if (param[i] == 'r')
        {
            flag_param |= PARAM_r;
        }

        else if (param[i] == 't')
        {
            flag_param |= PARAM_T;
        }

        else if (param[i] == 'i')
        {
            flag_param |= PARAM_I;
        }

        else if (param[i] == 's')
        {
            flag_param |= PARAM_S;
        }

        else
        {
            printf("ls:  %s", param[i]);
            exit(1);
        }
    }

    if (flag_param & PARAM_R)
    {
        flag_param -= PARAM_R;
        if (num + 1 == argc)
        {
            strcpy(path, "./"); //./是当前目录
            path[2] = '\0';
            display_R(flag_param, path);
            return 0;
        }

/*
如果命令行参数包括目录或者文件名，需要检查参数中的目录或者文件是否存在
可以利用stat族函数来获取文件的属性，完成上面的检查
stat族函数通常有两个参数：文件路径/文件描述符，struct stat *buf 类型的结构体
如果操作成功啦，那么buf就会保存文件的属性
如果可以的话，利用宏S_ISDIR(buf.st_mode),判断此文件是否是目录文件
如果是目录文件，就可进入display_dir函数，要不然的话进去display函数
display_dir函数是获取path目录下所有文件的完整路径名，再使每个文件执行display函数
所以的话，如果参数中指定的文件名，就可以跳过display_dir函数，直接进入display函数
*/

        i = 1;
        do
        {
            //如果不是目标文件名或者目录，就解析下一个命令行参数
            if (argv[i][0] == '-')
            {
                i++;
                continue;
            }
            else
            {

                strcpy(path, argv[i]); //如果目标文件或者目录不存在，报错之后退出程序
                if (stat(path, &buf) == -1)
                    ls_err("stat", __LINE__);
                if (S_ISDIR(buf.st_mode)) //argv[i]是一个目录
                {

                    if (path[strlen(argv[i]) - 1] != '/') //如果目录的最后一个字符不是/就添加/
                    {
                        path[strlen(argv[i])] = '/';
                        path[strlen(argv[i]) + 1] = '\0';
                    }
                    else
                        path[strlen(argv[i])] = '\0';
                    display_R(flag_param, path);
                }
            }
        } while (i < argc);
    }

    else
    {
        //判断是否有目录输入，没有则打开根目录./
        if (num + 1 == argc)
        {
            strcpy(path, "./");
            path[2] = '\0';
            display_dir(flag_param, path);
            return 0;
        }

        i = 1;
        do
        {
            if (argv[i][0] == '-')
            {
                i++;
                continue;
            }
            else
            {
                //得到具体路径(目录名)
                strcpy(path, argv[i]);
                if (stat(path, &buf) == -1)
                    ls_err("stat", __LINE__);
                //判断是否为目录文件
                if (S_ISDIR(buf.st_mode))
                {
                    //如果目录最后忘记了/则加上
                    if (path[strlen(argv[i]) - 1] != '/')
                    {
                        path[strlen(argv[i])] = '/';
                        path[strlen(argv[i]) + 1] = '\0';
                    }
                    else
                        path[strlen(argv[i])] = '\0';
                    display_dir(flag_param, path); //按照目录输出
                    i++;
                }
                else
                {
                    //argv[i]是一个文件
                    display(flag_param, path);
                    i++;
                }
            }
        } while (i < argc);
    }
    return 0;
}

int g_maxlen; //最长文件名长度
int g_leave_len = MAXROWLEN;
int all = 0; //文件的大小总和
int l = 0;     //每行已输出文件名的个数，用来判断是否换行
int fpnum = 4; //一行输出文件名的个数

void ls_err(const char *err_string, int line) //错误处理函数，打印错误所在行的行数和错误信息
{
    fprintf(stderr, "line:%d ", line);
    perror(err_string);
    exit(1);
}

//添加了文件显示颜色filecolor

void display_attribute(struct stat buf, char *name, int filecolor)
{
    char buff_link[256];
    char colorname_link[NAME_MAX + 30];
    char colorname[NAME_MAX + 30];
    char buf_time[32];  //存放时间的
    struct passwd *psd; //从这个结构体中获取文件所有者的用户名
    struct group *grp;  //从这个结构体中获取文件所有者所属组的组名

    //获取并且打印文件类型
    //st_mode  文件内容和存储权限

    if (S_ISLNK(buf.st_mode)) //判断是否为符号链接
    {
        printf("l");
    }
    else if (S_ISREG(buf.st_mode)) //判断是否是目录
    {
        printf("-");
    }
    else if (S_ISDIR(buf.st_mode))
    {
        printf("d");
    }
    else if (S_ISCHR(buf.st_mode)) //判断是否是字符设备文件
    {
        printf("c");
    }
    else if (S_ISBLK(buf.st_mode)) //判断是否是块设备文件
    {
        printf("b");
    }
    else if (S_ISFIFO(buf.st_mode)) //判断是否是先进先出的FIFO
    {
        printf("f");
    }
    else if (S_ISSOCK(buf.st_mode)) //判断是否是socket
    {
        printf("s");
    }

    //获取并且打印文件所有者的权限
    if (buf.st_mode & S_IRUSR)
    {
        printf("r");
    }
    else
    {
        printf("-");
    }
    if (buf.st_mode & S_IWUSR)
    {
        printf("w");
    }
    else
    {
        printf("-");
    }
    if (buf.st_mode & S_IXUSR)
    {
        printf("x");
    }
    else
    {
        printf("-");
    }

    //获取并且打印与文件所有者同组的用户对该文件的操作权限

    if (buf.st_mode & S_IRGRP)
    {
        printf("r");
    }
    else
    {
        printf("-");
    }
    if (buf.st_mode & S_IWGRP)
    {
        printf("w");
    }
    else
    {
        printf("-");
    }
    if (buf.st_mode & S_IXGRP)
    {
        printf("x");
    }
    else
    {
        printf("-");
    }

    //获取并且打印其他用户的对该文件的操作权限

    if (buf.st_mode & S_IROTH)
    {
        printf("r");
    }
    else
    {
        printf("-");
    }
    if (buf.st_mode & S_IWOTH)
    {
        printf("w");
    }
    else
    {
        printf("-");
    }
    if (buf.st_mode & S_IXOTH)
    {
        printf("x");
    }
    else
    {
        printf("-");
    }
    printf(" ");

    //根据uid和gid获取文件所有者的用户名与组名
    readlink(name, buff_link, sizeof(buff_link));
    psd = getpwuid(buf.st_uid);
    grp = getgrgid(buf.st_gid);
    printf("%4d ", buf.st_nlink);           //打印文件的硬链接数
    printf("%-8s", psd->pw_name);           //打印用户的名字
    printf("%-8s", grp->gr_name);           //打印用户组的名字
    printf("%8d", buf.st_size);             //打印文件大小
    strcpy(buf_time, ctime(&buf.st_mtime)); //把时间转换成普通表示格式
    buf_time[strlen(buf_time) - 1] = '\0';  //去掉换行符
    printf("  %s", buf_time);               //输出时间
    if (S_ISLNK(buf.st_mode))
    {
        sprintf(colorname, "\037[%dm%s\037[0m", filecolor, name);
        printf(" %-s -> %s\n", colorname, buff_link);
    }
    else
    {
        sprintf(colorname, "\037[%dm%s\037[0m", filecolor, name);
        printf(" %-s\n", colorname);
    }
}

//在没有使用-l选项的时候，打印一个文件名，打印时上下行之间进行对齐
void display_single(char *name, int filecolor) //添加了filecolorcanshu
{
    char buf[256];
    char colorname[NAME_MAX + 30];
    int i, len, j = 0;
    len = strlen(name);
    for (i = 0; i < len; i++)
    {
        if (name[i] < 0)
        {
            j++;
        }
    }
    len = len - (1 / 3) * j;
    if (len < 40)
    {
        len = 40 - len;
    }
    else
    {
        printf("\n");
    }
    sprintf(colorname, "\033[%dm%s\033[0m", filecolor, name);
    printf("%-s", colorname);
    for (i = 0; i < len + 10; i++)
    {
        printf(" ");
    }
    g_leave_len = g_leave_len - 45;
    if (g_leave_len < 45)
    {
        printf("\n");
        g_leave_len = MAXROWLEN;
    }
}

//-i
void display_st_ino(struct stat buf, char *name, int filecolor)
{
    char colorname[NAME_MAX + 30];
    //在ls没有限定的参数条件的时候，在这个之前对文件名进行排序，这样就可以整齐美观一点啦
    int i, len, j = 0;
    l++;
    len = strlen(name);
    for (i = 0; i < len; i++)
    {
        if (name[i] < 0)
        {
            j++;
        }
    }
    len = len - (1 / 3) * j;
    if (len < 40)
    {
        len = 40 - len;
    }
    else
    {
        printf("\n");
    }
    printf("%d ", buf.st_ino);
    sprintf(colorname, "\035[%dm%s\035[0m", filecolor, name);
    printf(" %-s", colorname);
    //补够空格
    for (i = 0; i <=len + 5; i++)
        printf(" ");
    g_leave_len = g_leave_len - 35;
    if (g_leave_len < 35)
    {
        printf("\n");
        g_leave_len = MAXROWLEN;
    }
}

//判断各种组合

void display(int flag, char *pathname)
{
    int filecolor = 37;
    int i, j;
    struct stat buf;         //文件信息buf
    char name[NAME_MAX + 1]; //从路径中解析出文件名
    for (i = 0, j = 0; i < strlen(pathname); i++)
    {
        if (pathname[i] == '/')
        {
            j = 0;
            continue;
        }
        name[j++] = pathname[i];
    }
    name[j] = '\0';

    //用lstat而不是stat以方便解析链接文件
    if (lstat(pathname, &buf) == -1) //lstat返回的是符号链接文件，文件本身的状态信息
    {
        printf("%s cuowu\n", pathname);
        return;
    }
    //关于颜色的处理
    if (S_ISLNK(buf.st_mode))
    {
        filecolor = 36;
    }
    else if (S_ISREG(buf.st_mode))
    {
        filecolor = 36;
    }
    else if (S_ISDIR(buf.st_mode))
    {
        filecolor = 34;
    }
    else if (S_ISCHR(buf.st_mode))
    {
        filecolor = 34;
    }
    else if (S_ISBLK(buf.st_mode))
    {
        filecolor = 34;
    }
    else if (S_ISFIFO(buf.st_mode))
    {
        filecolor = 35;
    }
    else if (S_ISSOCK(buf.st_mode))
    {
    }
    if (filecolor == 37 &&
        ((buf.st_mode & S_IXUSR) ||
         (buf.st_mode & S_IXGRP) ||
         (buf.st_mode & S_IXOTH)))
    {
        filecolor = 32;
    }
    //记得在前面加关于颜色的处理


    switch (flag)
    {
    case PARAM_NONE: //没有-l和-a选项
        if (name[0] != '.')
        {
            display_single(name, filecolor);
        }
        break;
    case PARAM_I:
        if (name[0] != '.')
        {
            display_st_ino(buf, name, filecolor);
        }
        break;

    case PARAM_S:
        if (name[0] != '.')
        {
            printf("%2d  ", buf.st_blocks / 2);
            display_single(name, filecolor);
        }
        break;

    case PARAM_A: // -a显示包括隐藏文件在内的所有文件
        display_single(name, filecolor);
        break;

    case PARAM_L: //每个文件单独占一行，显示文件的详细属性信息
        if (name[0] != '.')
        {
            display_attribute(buf, name, filecolor);
        }
        break;

    case PARAM_A | PARAM_L: //同时有-a和-l选项的情况
        display_attribute(buf, name, filecolor);
        break;

    case PARAM_A | PARAM_I:
        display_st_ino(buf, name, filecolor);
        break;

    case PARAM_A | PARAM_S:
        printf("%2d  ", buf.st_blocks / 2);
        display_single(name, filecolor);
        break;

    case PARAM_L | PARAM_S:
        if (name[0] != '.')
        {
            printf("%d  ", buf.st_blocks / 2);
            display_attribute(buf, name, filecolor);
        }
        break;

    case PARAM_L | PARAM_I:
        if (name[0] != '.')
        {
            printf("%d ", buf.st_ino);
            display_attribute(buf, name, filecolor);
        }
        break;

    case PARAM_I | PARAM_S:
        if (name[0] != '.')
        {
            printf("%2d  ", buf.st_ino);
            printf("%2d  ", buf.st_blocks / 2);
            display_single(name, filecolor);
        }
        break;

    case PARAM_A | PARAM_L | PARAM_S:
        printf("%d  ", buf.st_blocks / 2);
        display_attribute(buf, name, filecolor);

        break;

    case PARAM_A | PARAM_I | PARAM_S:
        printf("%d  ", buf.st_ino);
        printf("%2d  ", buf.st_blocks / 2);
        display_single(name, filecolor);
        break;

    case PARAM_L | PARAM_I | PARAM_S:
        if (name[0] != '.')
        {
            printf("%d\t", buf.st_ino);
            printf("%d\t", buf.st_blocks / 2);
            display_attribute(buf, name, filecolor);
        }
        break;
    case PARAM_A | PARAM_L | PARAM_I:
        printf("%d ", buf.st_ino);
        display_attribute(buf, name, filecolor);
        break;

    case PARAM_A | PARAM_I | PARAM_L | PARAM_S:
        printf("%d  ", buf.st_ino);
        printf("%d  ", buf.st_blocks / 2);
        display_attribute(buf, name, filecolor);
        break;

    case PARAM_r:
        if (name[0] != '.')
        {
            display_single(name, filecolor);
        }
        break;
    default:
        break;
    }
}


//为了显示目录下的文件做准备
void display_dir(int flag_param, char *path)
{
    DIR *dir;
    long t;
    int count = 0;
    int i, j, len;
    struct dirent *ptr;
    int flag_param_temp;
    struct stat buf;
    struct stat name;
    char temp[PATH_MAX + 10];
    flag_param_temp = flag_param;

    // 获取该目录下文件总数和最长的文件名
    dir = opendir(path);

    if (dir == NULL)
    {
        ls_err("oppendir", __LINE__);
        return;
    }

    //解析文件个数，及文件名的最长值
    while ((ptr = readdir(dir)) != NULL)
    {
        int a = 0; //用来统计汉字的个数，个数 = a/3
        int b = 0; //用来统计非汉字的个数 b
        for (i = 0; i < strlen(ptr->d_name); i++)
        {
            if (ptr->d_name[i] < 0)
            {
                a++;
            }
            else
            {
                b++;
            }
        }
        len = a + b;
        if (g_maxlen < len)
        {
            g_maxlen = len;
        }
        count++; //文件个数
    }
    fpnum = g_leave_len / (g_maxlen + 15);
    if (g_maxlen > 40)
    {
        fpnum = 1;
    }

    closedir(dir);

    char **filename = (char **)malloc(sizeof(char *) * 256*256*256);//申请内存
    long **filetime = (long **)malloc(sizeof(long *) * 256*256*256);
    len = strlen(path);
    dir = opendir(path);

    //得到该目录下的所有文件的路径
    for (i = 0; i < count; i++)
    {
        filename[i] = (char *)malloc(sizeof(char) * 1000*1000*1000);
        ptr = readdir(dir);
        if (ptr == NULL)
        {
            ls_err("readdir", __LINE__);
        }
        strncpy(filename[i], path, len); //存放目录下所有文件名
        filename[i][len] = '\0';
        strcat(filename[i], ptr->d_name);
        filename[i][len + strlen(ptr->d_name)] = '\0';
    }
    closedir(dir);
    //插入排序
    if (flag_param & PARAM_T) //根据时间排序
    {
        flag_param -= PARAM_T;
        for (i = 0; i < count; i++)
        {
            filetime[i] = (long *)malloc(sizeof(long));
            stat(filename[i], &buf); //用buf获取文件filename[i]中的数据
            filetime[i][0] = buf.st_mtime;
        }

        for (i = 0; i < count; i++)
        {
            for (j = i; j < count; j++)
            {
                if (filetime[i][0] < filetime[j][0])
                {
                    t = filetime[i][0];
                    filetime[i][0] = filetime[j][0];
                    filetime[j][0] = t;
                    strcpy(temp, filename[i]);
                    strcpy(filename[i], filename[j]);
                    strcpy(filename[j], temp);
                }
            }
        }
    }
    else
    {
        for (i = 0; i < count - 1; i++)
        {
            for (j = 0; j < count - 1 - i; j++)
            {
                if (strcmp(filename[j], filename[j + 1]) > 0)
                {
                    strcpy(temp, filename[j]);
                    strcpy(filename[j], filename[j + 1]);
                    strcpy(filename[j + 1], temp);
                }
            }
        }
    }

    //计算总用量all
    if (flag_param & PARAM_A)
    {
        for (i = 0; i < count; i++)
        {
            stat(filename[i], &name);
            all = all + name.st_blocks / 2;
        }
    }
    else
    {
        for (i = 0; i < count; i++)
        {
            stat(filename[i], &name);
            if (filename[i][2] != '.')
            {
                all = all + name.st_blocks / 2;
            }
        }
    }
    if (flag_param & PARAM_L)
    {
        printf("all： %d\n", all);
    }

    /* 打印文件 */
    if (flag_param & PARAM_r)
    {
        for (i = count - 2; i > 0; i--)
        {
            display(flag_param, filename[i]);
        }
    }
    else
    {
        for (i = 0; i < count - 1; i++)
        {
            display(flag_param, filename[i]);
        }
    }
    closedir(dir);
}

/* 递归输出-R*/
void display_R(int flag_param, char *path)
{
    DIR *dir;
    struct dirent *ptr;
    int count = 0;
    int filecolor;
    int y = 0;
    int flag_param_temp;
     char filenames[256][PATH_MAX + 1], temp[PATH_MAX+1];
     char muluname[256][PATH_MAX +1];
    /*char temp[PATH_MAX + 1];
    char muluname[256][PATH_MAX + 1];
    
    char ** filenames;

    long long int a ;
    long long int row= 51200;
    long long int colum =51200;
    filenames =(char**)malloc(sizeof(char*)*row*row);
    for(a=0;a<row;a++)
    {
        filenames[a]=(char*)malloc(sizeof(char)*colum *colum);
    }
    */
    long long filetime[256][1];
    long long t;
    struct stat buf;
    struct stat name;
    flag_param_temp = flag_param;

    
    //获取该目录下文件总数和最长的文件名
    dir = opendir(path); 
    if (dir == NULL)
    {
        ls_err("opendir", __LINE__);
    }
    while ((ptr = readdir(dir)) != NULL)
    {
        if (g_maxlen < strlen(ptr->d_name))
            g_maxlen = strlen(ptr->d_name);
        count++;
    }
    closedir(dir);
    //if (count > 256)
      //  ls_err(" 文件太多", __LINE__);
    
    int i, j, len = strlen(path);

    //获取该目录下所有的文件名
    dir = opendir(path);
    for (i = 0; i < count; i++)
    {
        ptr = readdir(dir);
        if (ptr == NULL)
        {
            ls_err("readdir", __LINE__);
        }
        strncpy(filenames[i], path, len);
        filenames[i][len] = '\0';
        strcat(filenames[i], ptr->d_name);
        filenames[i][len + strlen(ptr->d_name)] = '\0';
    }


    //使用冒泡法对文件名进行排序，排序后文件名按照字母顺序存储于filenames
    if (flag_param & PARAM_T)
    {
        flag_param -= PARAM_T;
        for (i = 0; i < count; i++)
        {
            stat(filenames[i], &buf);
            filetime[i][0] = buf.st_mtime;
        }
        for (i = 0; i < count; i++)
            for (j = i; j < count; j++)
            {
                if (filetime[i][0] < filetime[j][0])
                {
                    t = filetime[j][0];
                    filetime[j][0] = filetime[i][0];
                    filetime[i][0] = t;
                    strcpy(temp, filenames[j]);
                    strcpy(filenames[j], filenames[i]);
                    strcpy(filenames[i], temp);
                }
            }
    }
    else if (flag_param & PARAM_r)
    {
        flag_param -= PARAM_r;
        for (i = 0; i < count - 1; i++)
            for (j = 0; j < count - 1 - i; j++)
            {
                if (strcmp(filenames[j], filenames[j + 1]) < 0)
                {
                    strcpy(temp, filenames[j + 1]);
                    temp[strlen(filenames[j + 1])] = '\0';
                    strcpy(filenames[j + 1], filenames[j]);
                    filenames[j + 1][strlen(filenames[j])] = '\0';
                    strcpy(filenames[j], temp);
                    filenames[j][strlen(temp)] = '\0';
                }
            }
    }
    else
    {
        for (i = 0; i < count - 1; i++)
            for (j = 0; j < count - 1 - i; j++)
            {
                if (strcmp(filenames[j], filenames[j + 1]) > 0)
                {
                    strcpy(temp, filenames[j + 1]);
                    temp[strlen(filenames[j + 1])] = '\0';
                    strcpy(filenames[j + 1], filenames[j]);
                    filenames[j + 1][strlen(filenames[j])] = '\0';
                    strcpy(filenames[j], temp);
                    filenames[j][strlen(temp)] = '\0';
                }
            }
    }

    //计算总用量all
    if (flag_param & PARAM_A)
    {
        for (i = 0; i < count; i++)
        {
            stat(filenames[i], &name);
            all = all + name.st_blocks / 2;
        }
    }
    else
    {
        for (i = 0; i < count; i++)
        {
            stat(filenames[i], &name);
            if (filenames[i][2] != '.')
            {
                all= all + name.st_blocks / 2;
            }
        }
    }
    printf("all:%d", all);
    printf("\n%s:\n", path);
    for (i = 0; i < count; i++)
    {
        stat(filenames[i], &buf);
        if (S_ISDIR(buf.st_mode))
        {
            len = strlen(filenames[i]);
            if ((filenames[i][len - 1] == '.' && filenames[i][len - 2] == '/') || 
            (filenames[i][len - 1] == '.' && filenames[i][len - 2] == '.' && filenames[i][len - 3] == '/'))
                continue;
            strncpy(muluname[y], filenames[i], len);
            len = strlen(muluname[y]);
            muluname[y][len] = '/';
            muluname[y][len + 1] = '\0';
            y++;
        }
        display(flag_param, filenames[i]);
    }
    for (i = 2; i < y; i++)
    {
        list_dir(muluname[i], flag_param);
    }
}

void list_dir(char *pathname, int param)
{
    char nextpath[PATH_MAX + 1];
    DIR *ret_opendir = opendir(pathname); //打开目录
    if (ret_opendir == NULL)
        ls_err("ret_opendir", __LINE__);
    printf("%s:\n", pathname);    //显示pathname的路径
    display_DIR(ret_opendir, 33); //显示pathname目录下所有非隐藏的文件名称
    struct dirent *ret_readdir = NULL;           //定义readdir函数返回的结构体变量
    while ((ret_readdir = readdir(ret_opendir))) //判断是否读取到目录尾
    {
        char *filename = ret_readdir->d_name; //获取文件名
        int end = 0;                          //处理路径中
        while (pathname[end])
            end++;
        strcpy(nextpath, pathname);
        if (pathname[end - 1] != '/')
            strcat(nextpath, "/");
        strcat(nextpath, filename);
        struct stat file_message = {};                 //定义stat函数返回结构体变量
        int ret_stat = lstat(nextpath, &file_message); //获取文件信息
        if (ret_stat == -1) //stat读取文件错误则显示提示信息
            printf("%s 错啦!", filename);
        else if (S_ISDIR(file_message.st_mode) && filename[0] != '.') //‘.''..'与隐藏文件的不同选择
        {
            list_dir(nextpath, param);
        }
    }
    closedir(ret_opendir);
}

void display_DIR(DIR *ret_opendir, int filecolor)
{
    char colorname[NAME_MAX + 30];
    int loop = 0;
    struct dirent *ret_readdir = NULL;         //定义readir函数返回结构体变量
    while (ret_readdir = readdir(ret_opendir)) //判断是否读取到目录尾
    {
        char *filename = ret_readdir->d_name;
        if (filename[0] != '.')
        {
            sprintf(colorname, "\033[%dm%s\033[0m", filecolor, filename);
            printf("%-s\t", colorname); //打印文件名
        }
        loop++;
        if (!(loop % 5))
        {
            printf("\n");
            loop = 0;
        }
    }
    rewinddir(ret_opendir); //回到最开始
    printf(" \t");
}

 
