#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <mutex> 
#include <vector>

class TextFileHandler {
private:
    std::string m_filename;
    std::ifstream m_inFile;
    std::ofstream m_outFile;
    std::mutex m_mtx; 

public:
    TextFileHandler(const std::string& fname);

    bool openFileToRead();

    bool openFileToWrite(bool append = true);

    bool readFromFile(std::vector<std::string>& content);

    bool writeToFile(const std::string& content);

    void closeFile();

    void initSummary();

}
