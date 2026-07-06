#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>

class Library;

class FileManager
{
public:

    bool saveData(const Library& library,
                  const std::string& booksFile,
                  const std::string& membersFile);

    bool loadData(Library& library,
                  const std::string& booksFile,
                  const std::string& membersFile);

};

#endif