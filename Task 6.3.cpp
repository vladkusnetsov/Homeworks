#include <boost/filesystem/operations.hpp>
#include <iostream>
#include "string"



int main()
{
    std::string way;
    std::cout << "Input way to directory" << std::endl;
    std::cin >> way;
    boost::filesystem::path p{ way };

    boost::system::error_code ec;
    boost::uintmax_t filesize = boost::filesystem::file_size(way, ec);
    if (!ec)
        std::cout << filesize << '\n';
    else
        std::cout << ec << '\n';
    try
    {
        std::time_t t = last_write_time(p);
        std::cout << std::ctime(&t) << '\n';
    }
    catch (boost::filesystem::filesystem_error& e)
    {
        std::cerr << e.what() << '\n';
    }

    int cnt =
        std::count_if(boost::filesystem::directory_iterator(p),
            boost::filesystem::directory_iterator(),
            bind(static_cast<bool(*)(const boost::filesystem::path&)>(boost::filesystem::is_regular_file),
                bind(&boost::filesystem::directory_entry::path,
                    boost::lambda::_1)));

    std::cout << "Number of files in \""
        << p.string()
        << "\" = "
        << cnt
        << std::endl;
}