#include <fstream>
#include <iostream>
#include <string>

int main(int, char **)
{

    std::ifstream fileread;
    std::ofstream filewrite;
    std::string readpath = "..\\..\\points.txt";
    std::string writepath = "..\\..\\out_data.txt";

    fileread.open(readpath);
    filewrite.open(writepath);

    if (!fileread.is_open() && !filewrite.is_open())
    {
        std::cout << "ERROR OPEN FILES" << std::endl;
    }

    std::string line;

    int line_counter = 0;
    int number_outs = 0;
    bool count_flag = false;
    bool space_flag = false;
    while (!fileread.eof())
    {
        fileread >> line;

        if (line == "x" || line == "y")
            count_flag = true;

        if (count_flag)
            line_counter++;

        if (line_counter == 3)
        {
            filewrite << std::stod(line);
            number_outs++;
            count_flag = false;
            line_counter = 0;
        }

        switch (number_outs)
        {
        case (1):
            if (!space_flag)
            filewrite << " ";
            space_flag = true;
            break;

        case (2):
            filewrite << std::endl;
            number_outs = 0;
            space_flag = false;
            break;
        }
    }

    fileread.close();
    filewrite.close();
}
