# LeetCode 本地调试运行工程

## 简介

本项目基于 Google Test（gtest）框架，旨在提供一个可在本地环境中调试和运行 LeetCode 题目的工程。其中题目选择参考了[代码随想录](https://programmercarl.com/)

## 环境要求

- **编程语言**：C++
- **构建工具**：CMake
- **测试框架**：Google Test (gtest)
- **编译器**：支持 C++14 或更高版本的编译器（如 GCC, Clang, MSVC）

## 代码编译

gtest库已存放在thirdparty目录中，直接编译即可

```bash
git clone https://github.com/hzn-neu/local-leetcode.git
cd local-leetcode
git submodule update --init --recursive
mkdir build
cd build
cmake .. && make
```

## 代码运行
* 编译后的可执行文件位于 build/problems/题型/题
* 为了方便代码在vscode环境调试，vscode_config目录下提供了相关配置文件

## 题目编写模板
为了更好的在本地刷题，可以按以下模板编写代码
```c++
#include "base.hpp"

//题目
T func() {
  
}

//测试用例，包括输入和期望输出
struct TestCase {
  T input;
  T output;
};

class Tester : public testing::TestWithParam<TestCase> {};

TEST_P(Tester, FindsTargetIndex) {
  TestCase test = GetParam();
  T input = test.input;
  T result = func(input);

  //测试用例验证逻辑
  EXPECT_EQ(result, test.output)
      << "Failed for input: " << input << " with target: " << test.output;
}

INSTANTIATE_TEST_SUITE_P(
    VariousInputs, Tester,
    testing::Values(
		//补充测试用例
        TestCase{{}, {}}}));

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
```

## 贡献

欢迎任何形式的贡献！请按照以下步骤进行：

1. Fork 本仓库。
2. 创建新分支：git checkout -b feature/YourFeature
3. 提交更改：git commit -m '添加了某某功能'
4. 推送分支：git push origin feature/YourFeature
5. 创建 Pull Request。