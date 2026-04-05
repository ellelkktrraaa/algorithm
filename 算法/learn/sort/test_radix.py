import subprocess
import os
import statistics
import re

os.chdir(r"e:\CPPPro\算法\learn\sort")

def compile():
    result = subprocess.run("g++ -o rad rad.cpp", shell=True, capture_output=True, text=True)
    return result.returncode == 0

def test_radix(lim, num, runs=31):
    times = []
    for _ in range(runs):
        try:
            proc = subprocess.Popen("./rad", stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
            stdout, _ = proc.communicate(input=f"{lim}\n{num}\n", timeout=30)
            output = stdout.strip()
            if output:
                match = re.search(r'[\d.e+-]+', output.split('\n')[0])
                if match:
                    times.append(float(match.group()))
        except:
            pass
    return statistics.mean(times) * 1000 if times else None

def main():
    print("正在编译...")
    if not compile():
        print("编译失败!")
        return
    print("编译成功!\n")

    nums = [100, 1000, 5000, 10000, 100000]
    lims = [0.01,0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9]

    results = {}
    for num in nums:
        print(f"测试 num={num}...")
        results[num] = []
        for lim in lims:
            t = test_radix(lim, num)
            if t:
                results[num].append((lim, t))
                print(f"  lim={lim}: {t:.2f}ms")
            else:
                print(f"  lim={lim}: 失败")

        if results[num]:
            best = min(results[num], key=lambda x: x[1])
            print(f"  -> 最佳 lim={best[0]}, 时间={best[1]:.2f}ms\n")

    print("=" * 50)
    print("总结:")
    print("=" * 50)
    for num in nums:
        if results[num]:
            best = min(results[num], key=lambda x: x[1])
            print(f"num={num}: 最佳lim={best[0]}")

    print("""
分析:
- lim参数控制提前终止的阈值,当n <= j*lim时会检查是否已排序完成
- 其中n是当前处理的元素数,j是最大数的位数
- 数据量小时lim影响不大,数据量大时lim在0.3-0.5之间效果较好
- 建议使用lim=0.5作为平衡选择
""")

if __name__ == "__main__":
    main()
