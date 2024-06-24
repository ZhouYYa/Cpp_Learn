#include <regex> 

// 通过regex正则表达式，将字符替换为'_'
std::string SanitizeString(const std::string& strName)
{
    std::regex specialCharsRegex(R"([\\/:*?"<>|])");
    return std::regex_replace(strName, specialCharsRegex, "_");
}
