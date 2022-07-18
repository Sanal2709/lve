#ifndef LVE_PIPELINE_HPP
#define LVE_PIPELINE_HPP

#include <string>
#include <vector>

namespace lve
{
    class LvePipeline
    {
    public:
        LvePipeline(const std::string &vertFilepath, const std::string &fragFilepath);

    private:
        static std::vector<char> readFile(const std::string &filepath);

        void createGrahicsPipeline(const std::string &vertFilepath, const std::string &fragFilepath);
    };

} // namespace lve

#endif