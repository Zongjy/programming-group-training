#pragma once
#include "pch.h"
#include "Lab4_data.h"
#define confMenu "配置参数修改菜单：\n\t\
1. 默认数据存储文件路径\n\t\
2. 默认数据存储文件名\n\t\
3. 三元组中第1、2个元素取值的上限\n\t\
4. 三元组中第1、2个元素取值的下限\n\t\
5. 三元组中第3个元素取值的上限\n\t\
6. 三元组中第3个元素取值的下限\n\t\
7. 随机生成记录条数时条数值的上限\n\t\
8. 随机生成记录条数时条数值的下限\n\t\
9. 默认数据读取文件路径\n\t\
10. 默认数据读取文件名\n\t\
11. 默认运行模式\n\t\
0. 退出\n"
void confModify();
void update();