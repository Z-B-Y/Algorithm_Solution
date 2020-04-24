//////////////////////////////////////////////////////////////////////////
// 同元软控信息技术有限公司 C++ 程序试题
// 警告：苏州同元软控版权所有，请勿扩散传播，否则讲追究法律责任！
// Vertion 4.1
// 2019.9
//////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <sstream>
#include <vector>
#include <Windows.h>

using namespace std;
//////////////////////////////////////////////////////////////////////////
// 计时器类，4-B题目需要使用此类型
// Start()启动计时器，Elapsed()获取自启动计时器后经过的时间（单位ms）
// 不需要关心这个类的实现细节。
//////////////////////////////////////////////////////////////////////////
class MyTimer
{
public:
    MyTimer()
    {
        QueryPerformanceFrequency(&sysFreq);//获取系统频率
    }
    //启动计时器
    void Start()
    {
        QueryPerformanceCounter(&startTime);//获取起始时间
    }
    // 返回启动计时器后经过的时间，单位为ms
    int Elapsed()
    {
        LARGE_INTEGER cur_time;
        QueryPerformanceCounter(&cur_time);//获取当前时间
        //计算从起始时间开始，到当前的时间间隔，单位毫秒
        int elapsed_time = (int)((cur_time.QuadPart - startTime.QuadPart) / (double)sysFreq.QuadPart * 1000);
        return elapsed_time;
    }

private:
    LARGE_INTEGER sysFreq;
    LARGE_INTEGER startTime;
};

//////////////////////////////////////////////////////////////////////////
// (1) 改错题
//////////////////////////////////////////////////////////////////////////
//修改后的代码如下所示：
void Get100Memory(char **p)
{
        *p = new char[100];
}

void main()
{
        char *str = NULL;
        Get100Memory(&str);
        strcpy(str,"hello world");
        cout << str;
}

//////////////////////////////////////////////////////////////////////////
// (2) 改错题
//////////////////////////////////////////////////////////////////////////

class Shape
{
public:
	Shape(const char* id, const char* name)
	{
        shapeName = new char[strlen(name) + strlen(id)];
        strcpy(shapeName, name);
        strcpy(shapeName + strlen(name), id);
	}

	virtual ~Shape()
	{
                //delete shapeName; 修改为：
            delete [] shapeName;
	}

	const char * getName()
    {
        return shapeName;
    }

private:
    char* shapeName;
};


void PrintShape(Shape* shape)
{
    cout << "name: " << shape->getName() << endl;
}

void TestTheShapeClass()
{
    vector<Shape> shapes;
   // shapes.push_back(Shape("1", "Rect: "));
   // shapes.push_back(Shape("2", "Circle: "));
//修改为：
    Shape a = Shape("1", "Rect: ");
    shapes.push_back(a);
    Shape b = Shape("2", "Circle: ");
    shapes.push_back(b);
    for (size_t i = 0; i < shapes.size(); ++i)
    {
        PrintShape(&shapes[i]);
    }

    shapes.clear();    
}

//////////////////////////////////////////////////////////////////////////
// (3) 改错题
//////////////////////////////////////////////////////////////////////////

void TestVectorTraversor()
{
	vector<int> array;
	array.push_back( 1 );
	array.push_back( 2 );
	array.push_back( 3 );
        //for(unsigned int i=array.size()-1; i>=0; --i) 修改为：
        for(int i=array.size()-1; i>=0; --i)
	{
		cout << array[i] << endl;
	}
}

//////////////////////////////////////////////////////////////////////////
// (4) 算法实现题（4-A、4-B 题二选一）
//////////////////////////////////////////////////////////////////////////

/* 4-A 题：CombineTest
	已知n个数字序列，每个序列中包含n(i)个数字，求这n个序列数字的所有可能的排列组合
    示例：
	编写函数，列举出数组中所有元素的索引值。例如：
	input1 = {{1,2,3},
             {1,3}}
	output1 = {
		{1,1}, {1,3},
        {2,1}, {2,3},
        {3,1}, {3,3)
	}

    input2 = {{1,2,3},
             {1,3},
             {2,5,6}}
	output2 = {
		{1,1,2}, {1,1,5}, {1,1,6},
        {1,3,2}, {1,3,5}, {1,3,6},
        {2,1,2}, {2,1,5}, {2,1,6},
        {2,3,2}, {2,3,5}, {2,3,6},
        {3,1,2}, {3,1,5}, {3,1,6},
        {3,3,2}, {3,3,5}, {3,3,6}
	}
	
	注意：n 不是常数，算法要能适应不同的 n
*/
void CreateInputData(vector<vector<int>> &input)
{
    // 可以调整此函数代码，创建不同的输入数据来测试Combine算法
    vector<int> n1;
    n1.push_back(1);
    n1.push_back(2);
    n1.push_back(3);
    input.push_back(n1);

    vector<int> n2;
    n2.push_back(1);
    n2.push_back(3);
    input.push_back(n2);
}


void Combine(const vector<vector<int>>& input, vector<vector<int> >* output)
{
	// 此处答题：
    int size = input.size();
    vector<int>data;
    sort(input,size,0,output,data);
}
void sort(const vector<vector<int>>& input,int size,int index, vector<vector<int> >* output,vector<int> data){

    if(index == size){
        output.push_back(data);
        data.clear();
        return;
    }
    for(int j = 0;j < input[index].size();j++){
        data.push_back(input[index][j]);
        sort(input,size,index+1,output,data);
    }
}


void PrintResult(vector<vector<int> >& result, int s)
{
    // 此函数代码无需修改
    int line = 0;
    cout << "{";
    for (auto i = result.begin(); i != result.end(); ++i)
    {
        if ( line++%s == 0)
        {
            cout << "\n  ";
        }
        cout << "{";

        for (auto j = i->begin(); j != i->end(); ++j)
        {
            cout << *j << ",";
        }

        cout << "},";
    }
    cout << "\n}\n";
}

void TestCombineAlgorithm()
{
    vector<vector<int>> input;
    vector<vector<int>> output;
    CreateInputData(input);
    Combine(input, &output);
    PrintResult(output, input.size());
}

/* 4-B 题：编写一个跟实际时间同步的模拟时间，可以调节加速比，其关系为：模拟时间 = 实际时间 * 加速比，例如：
    （1）当加速比为1时，模拟时间跟实际时间一致；
    （2）当加速比为10时，实际时间过了1s，模拟时间过了10s；
    （3）当加速比为0.1时，实际时间过了1s，模拟时间过了0.1s；
    程序以指定的输出频率在控制台屏幕上打印实际时间和模拟时间，模拟总时间为固定100s。
    例如仿真当加速比为10.0，输出频率为10/s时，输出格式大致为：

    Speed ratio is: 10.0, Frequency is: 10/s

    Real time: 0.0s,  Simulation time: 0.0s;
    Real time: 0.1s,  Simulation time: 1.0s;
    Real time: 0.2s,  Simulation time: 2.0s;
    (中间过程省略......)
    Real time: 99.9s,  Simulation time: 999.0s;
    Real time: 100.0s,  Simulation time: 1000.0s;

    Simulation finished.

    注意事项：
    （1）避免时间同步算法的累积误差（可以有单步误差，但不能有累积误差）；
    （2）要求时间精确到 ms，但是以 s 为单位打印时间。
*/
void TestSynchronize(double speed_ratio/*加速比*/,
    int freq/* 输出频率，即每秒钟在屏幕上输出当前时间值的次数*/)
{
    const double cSimulationTime = 100*1000; //模拟总时间：100s，换算为ms

    //>>> 以下代码展示了获取系统计时器的方法（可以删除）
    MyTimer my_timer;
    my_timer.Start();
    Sleep(1000); //休眠等待1000ms
    cout << my_timer.Elapsed() << "ms" << endl; //输出1000ms（可能有误差）
    Sleep(1500); //休眠等待1500ms
    cout << my_timer.Elapsed() << "ms" << endl; //输出2500ms（可能有误差）
    //<<< 以上代码展示了计时器的用法（可以删除）

    // 此处答题：

}

//////////////////////////////////////////////////////////////////////////
// Main 此处为测试代码，可以按需修改以测试前面编写的函数
//////////////////////////////////////////////////////////////////////////
int main()
{
    cout << "Case1: TestGetMemory()..." << endl;
    TestGetMemory();

    cout << "Case2: TestTheShapeClass()..." << endl;
    TestTheShapeClass();

    cout << "Case3: TestVectorTraversor()..." << endl;
    TestVectorTraversor();

    cout << "Case4-A: TestCombineAlgorithm()..." << endl;
    TestCombineAlgorithm();

    cout << "Case4-B: TestSynchronize()..." << endl;
    TestSynchronize(3.0, 2);

	return 0;
}
