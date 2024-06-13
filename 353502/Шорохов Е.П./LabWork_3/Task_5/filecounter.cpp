#include "filecounter.h"

//I am booored
FileCounter::FileCounter() = default;

int64_t FileCounter::fileCount(const std::string& path)
{
    try {
        int64_t counter = 0;

        for (const auto& file : std::filesystem::directory_iterator(path))
        {
            if (file.is_directory() && !file.is_symlink())
            {
                counter += 1 + fileCount(file.path());
            }
            else
            {
                counter++;
            }
        }

        return counter;
    } catch (...) {
        return 0;
    }
}
