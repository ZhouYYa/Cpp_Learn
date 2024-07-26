#include "TextFileHandler.h"

TextFileHandler::TextFileHandler(const std::string& fname) : m_filename(fname) 
{
}

bool TextFileHandler::openFileToRead() 
{
    //std::lock_guard<std::mutex> lock(m_mtx);
    m_inFile.open(m_filename);
    return m_inFile.is_open();
}

bool TextFileHandler::openFileToWrite(bool append)
{
    std::lock_guard<std::mutex> lock(m_mtx);
    if (append)
        m_outFile.open(m_filename, std::ios_base::app); // 追加模式打开文件
    else
        m_outFile.open(m_filename);
    return m_outFile.is_open();
}

bool TextFileHandler::readFromFile(std::vector<std::string>& content)
{
    std::lock_guard<std::mutex> lock(m_mtx);
    if (!m_inFile.is_open())
    {
        this->openFileToRead();
    }
    if (m_inFile.is_open()) {
        content.clear();
        std::string line;
        while (std::getline(m_inFile, line))
        {
            //content += line + "\n";
            content.push_back(line);
        }
        return true;
    }
    return false;
}

bool TextFileHandler::writeToFile(const std::string& content) 
{
    std::lock_guard<std::mutex> lock(m_mtx);
    if (m_outFile.is_open()) 
    {
        m_outFile << content << "\n";
        return true;
    }
    else
    {
        try
        {
            m_outFile.open(m_filename, std::ios_base::app);
            m_outFile << content << "\n";
            return true;
        }
        catch (std::exception e)
        {
            return false;
        }
    }
    return false;
}

void TextFileHandler::closeFile()
{
    std::lock_guard<std::mutex> lock(m_mtx);
    if (m_inFile.is_open()) 
        m_inFile.close();
    if (m_outFile.is_open()) 
        m_outFile.close();
}
