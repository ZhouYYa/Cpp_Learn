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
