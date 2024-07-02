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
