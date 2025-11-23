#ifndef SOLUTION
#define SOLUTION

#include <filesystem>
#include <iostream>

using namespace std;
namespace fs = std::filesystem;  

bool isFolderValid(const fs::path& dir) {
    // your code here...
    error_code ec;

    if (!fs::exists(dir, ec)) return false;
    if (fs::is_symlink(dir, ec)) return false;

    if (fs::is_regular_file(dir, ec)) return fs::file_size(dir, ec) > 0;

    if (fs::is_directory(dir, ec)) {
        if (fs::is_empty(dir, ec)) return false;

        for (const auto& entry :
             fs::directory_iterator(dir, fs::directory_options::skip_permission_denied, ec))
        {
            if (ec) return false;
            if (!isFolderValid(entry.path())) return false;
        }

        return true;
    }

    return false;
}

#endif