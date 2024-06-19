## 配置git
在Ubuntu上配置Git环境的步骤如下：
    安装Git：`sudo apt-get install git`
    配置Git的全局环境：`git config --global user.name "你的用户名"` 和 `git config --global user.email "你的注册邮箱"`
    生成SSH密钥：`ssh-keygen -t rsa -C "你的github账号邮箱"`
    将公钥添加到GitHub：登录GitHub，点击右上角头像 -> Setting -> SSH and GPG keys，添加新的SSH key。
    测试SSH连接：`ssh -T git@github.com`12345。
## 配置cmake
安装cmake：`sudo apt-get install cmake`
## 含有pthread的文件链接失败
CMakeFiles.txt文件添加
`SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")`
