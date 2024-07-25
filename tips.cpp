//////////// 对指针的使用 ////////////////
std::shared_ptr<Type> m_pType;
m_pType = std::make_shared<Type>();

std::unique_ptr<Type> m_pType;
m_pType = std::make_unique<Type>();

Type* GetType() { return m_pType.get(); }
//////////// 对指针的使用 ////////////////

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
