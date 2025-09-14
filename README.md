<div id="top"></div>

[![AGPL License][AGPL-shield]][AGPL_Link]
[![CC BY-NC-SA 4.0][cc_by_nc_sa_4_0_shield]][cc_by_nc_sa_4_0]
[![CC BY-NC-SA 4.0][cc_by_nc_sa_4_0_image]][cc_by_nc_sa_4_0]

[![Github Releases][release-shield]][release-url]
[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]

<br />
<div align="center">

<h3 align="center">CS203-DSAA-template</h3>

  <p align="center">
    An awesome Algorithm Template for IO-Driven Single-File Problem(like Online-Judge Problem) ! </br>
    分布式<sup title="由git保证">1</sup> 去中心化<sup title="推荐使用template生成仓库,不设置主库;没有易受打击的web页">2</sup> 的IO驱动型单文件问题<sup title="包括但不限于OJ平台题目">4</sup>解题模板
    <br />
    <a href="https://github.com/Certseeds/CS203_DSAA_template/blob/dev/README.md"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/Certseeds/CS203_DSAA_template/tree/release">View Demo</a>
    ·
    <a href="https://github.com/Certseeds/CS203_DSAA_template/issues/new?template=bug_report.md">Report Bug</a>
    ·
    <a href="https://github.com/Certseeds/CS203_DSAA_template/issues/new?template=feature_request.md">Request Feature</a>
  </p>
</div>

<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>

## About The Project

OJ系统存在着一些特殊要求-因此考虑到下面的因素,设计了一套代码模板,以适应OJ系统的独特环境.

+ 上交题目无需修改类名,方法名等等内容,只需复制粘贴.
+ 支持为每个问题撰写测试用例,并支持用户之间方便的交换测试用例
+ 只依赖于Unix-Like系统,支持C++17的编译器与仓库本身,没有依赖包
+ 易于拓展, 提供基本算法接口与实现

### Built With

[![catch_2][catch2_image]](https://github.com/catchorg/Catch2)

<p align="right">(<a href="#top">back to top</a>)</p>

## Getting Started

1. 下载Release中的[压缩包][download_zip]或者[另一个压缩包][download_zip_refs],之后解压使用(简易)
2. 使用绿色按钮[Use This Template][Use_This_Template],生成仓库,clone下来使用(推荐)
3. fork repo, clone下来使用(不推荐,fork的仓库只有合入主仓库才被github计入提交图)

[download_zip]: https://github.com/Certseeds/CS203_DSAA_template/releases/latest/download/script_no_need.zip
[download_zip_refs]: https://github.com/Certseeds/CS203_DSAA_template/archive/refs/heads/release.zip
[Use_This_Template]: https://github.com/Certseeds/CS203_DSAA_template/generate

### Prerequisites

This is an example of how to list things you need to use the software and how to install them.

#### Windows

1. WSL(推荐ubuntu 22.04 | 20.04), `sudo apt install build-essential ccache`

+ 命令行检测gcc版本

``` bash
# username @ ${pcName} in ${path}
gcc --version
# username @ ${pcName} in ${path}
g++ --version
# username @ ${pcName} in ${path}
ccache --version
```

### Installation

+ generate

点击绿色按钮[Use This Template][Use_This_Template],生成仓库

+ clone生成的自己的仓库到本地

``` bash
# 在use this template之后
git clone https://github.com/${YOUE_GITHUB_USER_NAME}/CS203_DSAA_template.git
```

+ 使用CLion打开仓库

+ 可选项:
  + 使用脚本产生自定义的文件(适合source.zip或者有bonuslab):
    使用命令行,进入`./script`下,编辑`file_template`的`labs` & `problem_orders`,
    `python3 ./file_template.py`,出现`produce files finish`提示,即为创建成功.

<p align="right">(<a href="#top">back to top</a>)</p>

## Usage: 执行代码和测试

使用clion打开文件夹,配置好C++环境的基础上,会自动识别`CmakeList.txt`.

产生`CS203_lab${order}_${ques_Order}`,`CS203_lab${order}_${ques_Order}_test` 形式的复数个可以运行的可选项.

`lab${order}_${ques_Order}`为对应题号,比如`lab07_01`对应lab_07的C1题.

+ `CS203_lab07_01`将调用`lab_07\lab_07_C1\lab07_C1.cpp`,为将要提交的源文件.
+ `CS203_lab07_01_test`将调用`lab_07\lab_07_C1\lab07_C1_test.cpp`,对其进行测试.
+ `lab_*\lab_*_*\lab_*_*_test.cpp`目的为方便测试,同时便于分享测试用例.

<p align="right">(<a href="#top">back to top</a>)</p>

## Test Introduce

### 为什么要将 `读取` `数据处理` `输出` 分开?

1. 便于理清思路,读完题目之后,不管别的,先把数据读入,输出的函数写好,方便后续写作.
2. 交流代码逻辑的时候不会受到无关逻辑的影响
3. 可以互相分享少量代码而不触及核心逻辑,方便协作.
4. 便于使用测试.

### 基本测试用例展示 A+B: lab_00_A ,测试样例

+ 这个问题较为简单,见[A+B](./lab_00/lab_00_A/lab_00_A.cpp).解决起来不复杂.
+ 虽然可以手工一个一个输入,然后观察输出. 但是如果我们希望严谨的测试,要100组测试数据,难道每次出新版本都要手动输入100次吗?

显然,有更好的解决方式:使用测试框架.

+ 在本repo,使用`Catch2`测试框架.
  + 比如,我们有四组数据,第一组,第二组测试边界值,第三组使用随机数测试对偶性与正确性,第四组测试几个手动的随机值.
  + 参见[test_for_lab00_A](./lab_00/lab_00_A/lab_00_A_test.cpp).
+ 这样一来,我们只需要每次修改完主文件之后,run `CS203_DSAA_template_test`, 对其进行调用,就能验证其在所有的测试用例上的正确性.

### 多个输出值的检查:`Catch::Matchers`

上面的例子里,输出值只是一个值,所以手动检查的难度不大,但是如果目标输出是一个数组,那么手动检查的难度就非常大了.

举例:[Crzay Plan](https://acm.sustech.edu.cn/onlinejudge/problem.php?id=1250),输入可能有1.1*10^6个.

这种情况下对这么多值进行直接的观察就很难,所以我们预先将期望的值直接写在测试文件里,用Catch2内置的Matcher比较(见[test_for_lab00_B](./lab_00/lab_00_B/lab_00_B_test.cpp)的`CHECK_THAT()`部分.)

PS: 当然,这种情况也只适用于规模比较小的情况,规模再大的话,直接由人手动写在测试文件里也太占空间了.

### 输入输出重定向-Stage 1: 从文件中读取输入

常见于tree,graph类的问题,debug需要的数据集都比较大,不方便直接写在代码中.

比如[判断二分图](./lab_00/lab_00_C/lab_00_C.cpp),一张图可以有几十上百个node,写在内部占用空间太大.

而在这里,使用`CS203_redirect`对象,便可以省去手动输入的方式.

``` cpp
TEST_CASE("test case 1", "[test 00 C]") {
  const CS203_redirect cr{"01.data.in", ""};
  // 重定向开始,开始run
  // or CS203_redirect cr{"01.data.in"};
  const auto output_data = isBipartite(read());
  // 重定向结束
  CHECK_FALSE(output_data);
}
```

只需要准备好输入的数据与结果,就可以从文件中读取,执行后判断结果是否符合预期.

+ test case 1-5为最简单的逐个判断,最简单,代码量最大.
+ test case loop 则优化了一些,但是还是比较麻烦,for循环还需要了解测试样例的个数.
+ test case with tuple 则最优雅,修改起来的难度最小.
+ test case with sequence 比tuple更优雅,输入,输出全为自动产生.

PS: 此处注意,引用文件的相对路径,不是直接的`test/lab_00/lab_00_C/resource/01.data.in`,

而是编译出的文件相对于测试数据的相对路径.

在样例中,编译出的文件在`CS203_DSAA_template/cmake-build-debug`下,所以需要加`./../`

### 输入输出重定向-Stage 2: 从文件中读取输入,将输出定向到文件中

+ 一般来说,题目的输出不会太复杂,但是反例也不是没有.:比如专门考输出的[立体图](./lab_00/lab_00_D/lab_00_D.cpp)
+ 这种情况下,使用c++的重定向输出就可以较为方便的对输入进行处理,同时保存输出方便调试.

``` cpp
  TEST_CASE("test case 2", "[test 00 D]") {
    SECTION("do") {
      const CS203_redirect cr{"01.data.in", "01.test.out"};
      auto input_data = read();
      cal(input_data);
    } SECTION("compare files") {
      CHECK(compareFiles("01.test.out", "01.data.out"));
    }
  }
```

这样就将标准输出重定向到了01.test.out中,并与01.data.out比对.

PS: 至于比较文件之间的差异,可以使用内置的`compareFiles(string path1,string path2)`函数进行比较.

参考[文本比对_test_case_2](./lab_00/lab_00_D/lab_00_D_test.cpp)

## Details

### 为什么要选择C++做题?

1. C++是dalao们的选择
直接去
[dalao1](https://acm.sustech.edu.cn/onlinejudge/status.php?user_id=11710724&jresult=4)
[dalao2](https://acm.sustech.edu.cn/onlinejudge/status.php?user_id=11612908&jresult=4)
[dalao3](https://acm.sustech.edu.cn/onlinejudge/status.php?user_id=11712510&jresult=4)
等等dalao的解题页面看看,会发现在排行榜榜首的人,绝大多数题目使用的都是C++.

2. 速度.

+ oj内一般java的最大运行时间都会是c++的2倍,显然是暗示速度之间的差别.
+ 其次,C++可以通过一些魔法操作,比如下文的优化等操作再获取一些时间上的优势.

3. 对数据结构的友好性

DSAA既然内含Data structure,就势必涉及到类似Node,Tree,Graph等等数据结构,这类数据结构使用C++写,比较方便理解.

4. 对算法友好的性能:

之前写树和图相关的题目时,最头疼的就是Java的爆栈,有一段时间只要用递归就爆栈,相同算法修改为C++之后问题就消失了.

5. 相关资源的丰富程度

不管怎么说,c++是dalao的选择,所以在网络上搜索题目,得到的大多数答案都是C/C++,java的数量很少.

### 如何手动开优化

1. 将[magic_optimize](./include/magic_macro/magic_macro.hpp)内的内容粘贴到代码最上方.
2. 关闭同步,

``` cpp
static const auto faster_streams = [] {
    srand(time(nullptr)); 
    // use time to init the random seed
    std::ios::sync_with_stdio(false);
    std::istream::sync_with_stdio(false);
    std::ostream::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // 关闭c++风格输入输出 , 与C风格输入输出的同步,提高性能.
    return 0;
}();
```

已放置在源文件最下方,注意**不要混用**C风格输入输出(`scanf`,`printf`)与c++风格输入输出(`cin`,`cout`)

通常情况下,可以将运行时间缩短到1/2甚至更少.

### Why choose Catch?

1. 先来看可选项有哪些

|        FrameWork         | Catch2 | Google Test | CPPUnit | Boost.Test |    Microsoft 单元测试框架    |
| :----------------------: | :----: | :---------: | :-----: | :--------: | :--------------------------: |
|          跨平台          |   √    |      √      |    √    |     √      |              X               |
| 是否需要提前在系统内安装 |   X    |      √      |    √    |     √      | √(and visual studio make it) |
|           语法           |  简单  |    简单     |  复杂   |    简单    |           Unknown            |

先筛选跨平台,去掉了Microsoft,再筛选不需要安装,只剩Catch2, 结束.

## Roadmap

+ [x] 基础框架
+ [x] Catch2 接入
+ [x] 测试用例接入文件
+ [x] 算法模块添加
  + [x] FFT
  + [x] Tree
    + [x] Trie
    + [x] RB-Tree
    + [x] AVL-Tree
  + [x] Matrix
  + [ ] AND MORE...
+ [ ] 跨平台
  + [ ] Windows(No Support becuase ccache do not support MSVC, compile cost too much time and product size)
  + [x] Unix-Like
+ [x] CI-CD
  + [x] CI: GitHub-Actions提交触发
  + [x] CD: Tag触发的自动Release
+ [x] leetcode题目
+ [x] ~~预编译头文件~~ccache加速编译
+ [x] basic文件夹添加CS205内容,方便入门C++
  + [x] 以及一部分rust代码
+ [ ] Cyaron测试数据生成
+ [ ] WiKi Page

<p align="right">(<a href="#top">back to top</a>)</p>

## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<p align="right">(<a href="#top">back to top</a>)</p>

## License

### AGPLv3.0+ LICENSE

绝大多数代码(`*.cpp`,`*.hpp`,etc)基于 AGPLv3.0+协议: 限制最强的主流开源协议

+ 由于本仓库设计只包括"上交"源码这一种场景, 因此实际上不存在二进制分发以及被云服务使用这种场景.
+ 具体内容请看[`LICENSE_AGPL_V3_0.md`](./LICENSE_AGPL_V3_0.md)
some code is based on this license

### CC-BY-NC-SA-4.0+ LICENSE

所有其他非代码部分(主要是*.md)基于CC-BY-NC-SA-4.0(或以后版本)协议.

+ 相同方式共享-署名-非商业性使用的知识共享协议4.0或任何以后版本.
+ 署名(BY)-使用到相应内容的其他地方,应该加以注释,保留来源.
+ 非商业性使用(NC)-默认情况下,只要署名,可以在不盈利的情况下使用.(并不是指商业情况不能用,而是需要和原作者沟通)
+ 相同方式共享(SA)-使得协议具有传染性,只要其他内容采用了本repo的内容,就需要在署名的同时,保证其协议也是CC-BY-NC-SA-4.0 or later version.
+ 具体内容请看[`LICENSE_CC_BY_NC_SA_V4_0.md`](./LICENSE_CC_BY_NC_SA_V4_0.md)

<p align="right">(<a href="#top">back to top</a>)</p>

## Contact

格式/版权/转载/etc 这类非内容相关问题，请提 [issue][issue_LINK]

添加/删除/修改内容，修改repo相关的，请提 [pull_request][pr_LINK]

讨论内容相关的，请到 [Discussion][discussion_LINK]

Project Link: [https://github.com/Certseeds/CS203_DSAA_template][Project_LINK]

<p align="right">(<a href="#top">back to top</a>)</p>

## Acknowledgments

Use this space to list resources you find helpful and would like to give credit to. I've included a few of my favorites to kick things off!

+ [Img Shields](https://shields.io)
+ [Best-Readme-Template][Best-Readme-Template]
+ [Choose an Open Source License](https://choosealicense.com)

<p align="right">(<a href="#top">back to top</a>)</p>

## Thanks

考虑到[whexy][GitHub-Whexy] 的博客文章[用两个晚上做超简易 OpenJudge][Two-Night-Online-Judge]里`因平台显著降低了作业难度。按任课教师要求已经关停。`这一句.

设计时将分布式<sup title="由git保证">1</sup> 去中心化<sup title="推荐使用template生成仓库,不设置主库;没有易受打击的web页">2</sup> 跨平台<sup title="对拍功能由原生实现(虽然MSVC因为换行符原因不太好用)">3</sup>都纳入考虑.

<p align="right">(<a href="#top">back to top</a>)</p>

[Best-Readme-Template]: https://github.com/othneildrew/Best-README-Template
[Project_LINK]: https://github.com/Certseeds/CS203_DSAA_template
[issue_LINK]: https://github.com/Certseeds/CS203_DSAA_template/issues
[pr_LINK]: https://github.com/Certseeds/CS203_DSAA_template/pulls
[discussion_LINK]: https://github.com/Certseeds/CS203_DSAA_template/discussions
[catch2_image]: https://raw.githubusercontent.com/catchorg/Catch2/v2.x/artwork/catch2-logo-small.png
[AGPL-shield]: https://img.shields.io/badge/License-AGPL-orange?style=for-the-badge
[AGPL_Link]: http://opensource.org/licenses/AGPL
[cc_by_nc_sa_4_0_shield]: https://img.shields.io/badge/License-CC%20BY--NC--SA%204.0-orange?style=for-the-badge
[cc_by_nc_sa_4_0]: https://creativecommons.org/licenses/by-nc-sa/4.0/
[cc_by_nc_sa_4_0_image]: https://licensebuttons.net/l/by-nc-sa/4.0/88x31.png
[contributors-shield]: https://img.shields.io/github/contributors/Certseeds/CS203_DSAA_template.svg?style=for-the-badge
[contributors-url]: https://github.com/Certseeds/CS203_DSAA_template/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/Certseeds/CS203_DSAA_template.svg?style=for-the-badge
[forks-url]: https://github.com/Certseeds/CS203_DSAA_template/network/members
[stars-shield]: https://img.shields.io/github/stars/Certseeds/CS203_DSAA_template.svg?style=for-the-badge
[stars-url]: https://github.com/Certseeds/CS203_DSAA_template/stargazers
[issues-shield]: https://img.shields.io/github/issues/Certseeds/CS203_DSAA_template.svg?style=for-the-badge
[issues-url]: https://github.com/Certseeds/CS203_DSAA_template/issues
[license-shield]: https://img.shields.io/github/license/Certseeds/CS203_DSAA_template.svg?style=for-the-badge
[license-url]: https://github.com/Certseeds/CS203_DSAA_template/blob/master/LICENSE.md
[release-shield]: https://img.shields.io/github/release/Certseeds/CS203_DSAA_template.svg?style=for-the-badge
[release-url]: https://github.com/Certseeds/CS203_DSAA_template/releases
[GitHub-Whexy]: https://github.com/whexy
[Two-Night-Online-Judge]: https://www.whexy.com/posts/wannaAC
