#pragma comment(lib, "libcurl_a.lib")
#pragma warning(disable : 4251)

@echo off
start /b /d "D:\Jupiter_RF_328C\SIP-JUPITER_RF_AUTO_CS3_V1_20240327_328C" WLAN_TCP_Server.exe

////////////    vector    ////////////////
const int size = 5;
constexpr int size = 42;
int vec[size];  // 初始化vec大小必须是常量。

// ptrs是含有10个整形指针的数组
int *ptrs[10];
//不存在引用的数组
// int &refs[10] = /*?*/;
int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
// 数组的引用 arrRef是arr的引用
int(&arrRef)[10] = arr;
// Parray指向一个含有10个整数的数组
int(*Parray)[10] = &arr;

vector<int> v1 = {1, 3, 5, 7, 9};
vector<int> v2(v1);
int a[] = {2, 4, 6, 8, 10};
vector<int> v3(begin(a), end(a));

/////////////////////////////////////////
	
//////////// 对指针的使用 ////////////////
std::shared_ptr<Type> m_pType;
m_pType = std::make_shared<Type>();

std::unique_ptr<Type> m_pType;
m_pType = std::make_unique<Type>();

Type* GetType() { return m_pType.get(); }


using ConfigFn = QString(AwinicMesConfig::*)();
    static QMap<QString, ConfigFn> toText {
        {"lot_no",          &AwinicMesConfig::LotID },
        {"device_name",     &AwinicMesConfig::Device },
        {"Assemble lot",     &AwinicMesConfig::AssemblyLot }
}

//////////// typedef ////////////////////
typedef char* String; String s = "char";
typedef struct {
	int x; 
	int y;
} point;
point p;
typedef void (*FuncPtr)(int);
void myFunction(int a) {
    // 函数实现
}
FuncPtr ptr = myFunction; // 现在可以使用 FuncPtr 作为函数指针类型
ptr(5); // 调用 myFunction(5)

//////////// -> 操作符 ///////////////////
1. 成员访问符号 (->):
MyClass* ptr = new MyClass();
ptr->memberFunction();  // 调用类的成员函数
ptr->memberVariable = 10;  // 访问类的成员变量并赋值

2. 箭头成员运算符 (->):
当重载时，用于在智能指针类和迭代器类中，方便地访问对象的成员。这种情况下，箭头成员运算符 -> 可以返回指针成员的成员，以及访问对象的成员。

3. 在Lambda函数中，-> 符号用于指定返回类型或函数体的开头:
[] (int x = 1) -> void { std::cout << x; }

4. 尾返回类型（trailing return type）
inline auto 
operator-(const reverse_iterator<_IteratorL>& __x,
const reverse_iterator<_IteratorL>& __y)
-> decltype(__y.base() - x.base());
“-> 在这里用于指定函数 operator- 的返回类型，这个返回类型是通过 decltype 推导得出的，具体来说是 __y.base() - __x.base() 的类型;”

//////////// 对数组initialize操作 ///////////////////
double d[8] = {0};
memset(d, 0, 8 * sizeof(double));
std::fill(std::begin(d), std::end(d), 0);
doulble newD[8] = {0};
std::copy(std::begin(newD), std::end(newD), std::begin(d));

//////////// 对字符串的操作 ////////////////
boost::algorithm::replace_all(latestName, "/", "\\");
boost::algorithm::replace_all(latestName, "\\\\", "\\");
curproject = latestName.substr(0, latestName.rfind('\\'));
curproject = curproject.substr(curproject.rfind('\\') + 1);

std::vector<std::string> StringSplit(const std::string& str, const char& delimiter)
{
	std::vector<std::string> res;
	std::stringstream ss(str);
	std::string item;
	while (std::getline(ss, item, delimiter))
	{
		res.push_back(item);
	}

	return res;
}

std::string str = "apple,orange,banana,grape";
// 使用 std::stringstream 分割字符串
std::stringstream ss(str);
std::string token;
std::vector<std::string> tokens;
while (std::getline(ss, token, ',')) {
tokens.push_back(token);
}

bool isStringDouble(const std::string& s) {
	std::istringstream iss(s);
	double d;
	iss >> d;
	return iss.eof() && !iss.fail();
}

double stringToDouble(const std::string& s) {
	double d;
	try {
		d = std::stod(s);
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Invalid argument: " << e.what() << std::endl;
		throw;
	}
	catch (const std::out_of_range& e) {
		std::cerr << "Out of range: " << e.what() << std::endl;
		throw;
	}
	return d;
}

#include <algorithm> // 包含std::transform
#include <cctype>    // 包含std::tolower

std::string toLowerCase(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

std::string toUpperCase(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

MatchFile 
{
	void getFileNameFromSN(std::string path, std::vector<std::string>& file, std::string SN)
	{
	    intptr_t file_handle = 0;
	    struct _finddata_t file_info;
	    std::string temp;
	    if ((file_handle = _findfirst(temp.assign(path).append("/*" + SN + "*").c_str(), &file_info)) != -1)
	    {
	        do
	        {
	            file.push_back(temp.assign(path).append("\\").append(file_info.name));
	        } while (_findnext(file_handle, &file_info) == 0);
	        _findclose(file_handle);
	    }
	    int fileSize = file.size();
	    std::vector<std::string> tmpFile;
	    for (int i = 0; i < fileSize; ++i)
	    {
	        std::vector<std::string> v_tmpFileSplit;
	        v_tmpFileSplit = StringSplit(file[i], "\\");
	        v_tmpFileSplit = StringSplit(v_tmpFileSplit[v_tmpFileSplit.size() - 1], "_");
	        if (v_tmpFileSplit[0] == SN)
	        {
	            tmpFile.push_back(file[i]);
	        }
	    }
	    file = tmpFile;
	}
	
	std::vector<std::string> my_file;
	getFileNameFromSN(rootPath, my_file, SN);
	std::string resCSVFilePath = "";
	
	for (int i = 0; i < my_file.size(); i++)
	{
		//std::cout << my_file[i] << std::endl;
		struct _stat stat_buffer;
		int result = _stat(my_file[i].c_str(), &stat_buffer);
		int curCrateTime = static_cast<int>(stat_buffer.st_mtime);
		if (curCrateTime > createTime)
		{
		    resCSVFilePath = my_file[i];
		    createTime = curCrateTime;
		}
	}
	
	bool EndsWith(const std::string& str, const std::string& suffix)
	{
	    if (str.size() < suffix.size())
	        return false;
	    std::string tstr = str.substr(str.size() - suffix.size());
	
	    if (tstr.length() == suffix.length())
	    {
	        return std::equal(suffix.begin(), suffix.end(), tstr.begin(), comparePred);
	    }
	    else
	    {
	        return false;
	    }
	}
}

/////////// 区分大小端（小端：低字节在低地址） /////////////////
union endian {
    int i;
    char c[4];
}u;
int is_big_endian() {
    u.i = 1;
    return (u.c[0] == 0);
}

int main()
{
    u.c[0] = 0x11;
    u.c[1] = 0x22;
    std::cout << std::hex << u.i << std::endl;
    u.i = 0x01;
    //std::cout << std::hex << *(u.c + 0) << std::endl;
    printf("%x\n", *(u.c + 0));
    std::cout << std::hex << static_cast<int>(*(u.c)) << std::endl;
    std::cout << std::hex << (0xff & (u.c[0])) << std::endl;
    int testCode = 0x1122;
    char* c = (char*)(&testCode);
    printf("0x%x\n", *(c + 0)); //大端为 0x11 小端为 0x22
    printf("0x%x\n", *(c + 1));
}

/////////// check 进程是否存在 ///////////////
bool IsEverestProcessExit(const wstring& processName)
{
    bool bRet = false;
    HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hProcessSnap == INVALID_HANDLE_VALUE)
        return false;

    PROCESSENTRY32 pe32 = { 0 };
    pe32.dwSize = sizeof(PROCESSENTRY32);
    if (Process32First(hProcessSnap, &pe32)) {
        do {
            if (_wcsicmp(pe32.szExeFile, processName.c_str()) == 0)
            {
                bRet = true;
                break;
            }
        } while (Process32Next(hProcessSnap, &pe32));
    }
    else {
        bRet = false;
    }
    CloseHandle(hProcessSnap);
    return bRet;
}


// todo: 判断进程是否启动(down)
    if (!IsEverestProcessExit(L"WLAN_TCP_Server.exe"))
    {
        WinExec(WT328CServerPath.c_str(), SW_HIDE);
        Sleep(100);
    }


/////////// 获取日期 ////////////////////
SYSTEMTIME systemTime;
GetLocalTime(&systemTime);
std::stringstream ss;
ss << std::setw(4) << std::setfill('0') << systemTime.wYear << "-"
    << std::setw(2) << std::setfill('0') << systemTime.wMonth << "-"
    << std::setw(2) << std::setfill('0') << systemTime.wDay;
std::string curDate = ss.str();

///////////  获取时间  /////////////////////
std::chrono::time_point<std::chrono::steady_clock> m_TimeEnd = std::chrono::steady_clock::now();
double dTime = std::chrono::duration_cast<std::chrono::nanoseconds>(m_TimeEnd - m_TimeStart).count() / 1e+6;

#include <iostream>
#include <chrono>
#include <thread>

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    std::this_thread::sleep_for(std::chrono::seconds(2));

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end - start;

    double elapsed_milliseconds = duration.count();

    std::cout << "Elapsed time: " << elapsed_milliseconds << " milliseconds" << std::endl;

    return 0;
}


///////////获取当前程序路径////////////////
    TCHAR rootPath[MAX_PATH];
    GetModuleFileName(NULL, rootPath, MAX_PATH);
    std::string uiRootPath;
#ifdef _UNICODE
    std::wstring ws(rootPath);
    uiRootPath = std::string(ws.begin(), ws.end());
#else
    uiRootPath = std::string(tcharString);
#endif
    uiRootPath = uiRootPath.substr(0, uiRootPath.rfind('\\'));
    uiRootPath += "/uilogs/";
    QString localUiLog = QString::fromStdString(uiRootPath);
    QString serverUiLog = "/UiLog";

//////////// union ////////////////
typedef union
    {
        struct
        {
            unsigned int triggerData : 12;
            unsigned int slotIdLo : 4;
            unsigned int slotIdHi : 4;
            unsigned int waitAux : 1;
            unsigned int multiSeg : 1;
            unsigned int multiChassis : 1;
            unsigned int waitBus : 1;
            unsigned int cardType : 8;
        }BitField;
        uint32_t m_value;
    }EVT_TRIGGER_REG_TRIGGER_WORD;

/////////////////class template//////////////////
template<typename T>
auto GetRaw(T& configPtr, const QString& fileName) -> typename T::pointer
{
    using RawType = typename T::element_type;
    if (!configPtr || (!fileName.isEmpty() && configPtr->ConfigFile() != fileName))
    {
        configPtr.reset(new RawType());
        if (!configPtr->Init(fileName))
            return nullptr;
    }

    return configPtr.get();
}
